using System;
using System.Collections;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using Newtonsoft.Json;
using Oxide.Core;
using UnityEngine;

namespace Oxide.Plugins
{
    [Info("Rust Data Exporter", "dactill", "1.2.0")]
    [Description("Exports Rust item, weapon, projectile and held-item type data to C++ headers and optional JSON.")]
    public class RustDataExporter : RustPlugin
    {
        private const string PermissionUse = "rustdataexporter.use";
        private const int PrefabsPerTick = 200;
        private const int MaxProjectileDamageTypes = 16;
        private static readonly CultureInfo Invariant = CultureInfo.InvariantCulture;

        private DumpJob _activeJob;

        private void Init()
        {
            permission.RegisterPermission(PermissionUse, this);
        }

        private void Unload()
        {
            _activeJob = null;
        }

        [ConsoleCommand("rustdata.dump")]
        private void CommandDump(ConsoleSystem.Arg arg)
        {
            if (!HasAccess(arg))
            {
                arg.ReplyWith("You do not have permission to use rustdata.dump.");
                return;
            }

            if (_activeJob != null)
            {
                arg.ReplyWith("A Rust data export is already running.");
                return;
            }

            string target;
            bool includeJson;
            string error;
            string[] commandArgs = arg.Args == null
                ? null
                : arg.Args.Select(x => x.ToString()).ToArray();

            if (!TryParseArguments(commandArgs, out target, out includeJson, out error))
            {
                arg.ReplyWith(error);
                arg.ReplyWith("Usage: rustdata.dump [all|items|weapons|projectiles|held] [json]");
                return;
            }

            GameManifest manifest = GameManifest.Current;
            bool needsManifest = target == "all" || target == "weapons" || target == "projectiles";
            if (needsManifest && (manifest == null || manifest.prefabProperties == null))
            {
                arg.ReplyWith("GameManifest is not loaded. Run the command after server startup completes.");
                return;
            }

            DumpJob job = new DumpJob
            {
                Target = target,
                TargetBuild = GetCurrentTargetBuild(),
                IncludeJson = includeJson,
                GeneratedUtc = DateTime.UtcNow,
                Prefabs = manifest == null || manifest.prefabProperties == null
                    ? new GameManifest.PrefabProperties[0]
                    : manifest.prefabProperties
                        .Where(x => x != null && !string.IsNullOrEmpty(x.name))
                        .OrderBy(x => x.name, StringComparer.Ordinal)
                        .ToArray()
            };

            _activeJob = job;

            try
            {
                BuildItemIndex(job);

                if (WantsHeld(job))
                {
                    CaptureHeldItems(job);
                }
            }
            catch (Exception ex)
            {
                _activeJob = null;
                PrintError("Failed to initialize export: " + ex);
                arg.ReplyWith("Export failed while indexing item definitions. See the server log.");
                return;
            }

            arg.ReplyWith(string.Format(
                "Rust data export started: target={0}, JSON={1}, prefabs={2}, item definitions={3}.",
                target,
                includeJson ? "yes" : "no",
                job.Prefabs.Length,
                job.Items.Count));

            if (WantsWeapons(job) || WantsProjectiles(job))
            {
                ProcessPrefabBatch();
            }
            else
            {
                CompleteExport();
            }
        }

        private bool HasAccess(ConsoleSystem.Arg arg)
        {
            if (arg == null)
            {
                return false;
            }

            if (arg.Connection == null)
            {
                return true;
            }

            BasePlayer player = arg.Player();
            return player != null &&
                   (player.IsAdmin || permission.UserHasPermission(player.UserIDString, PermissionUse));
        }

        private static bool TryParseArguments(string[] args, out string target, out bool includeJson, out string error)
        {
            target = "all";
            includeJson = false;
            error = null;

            if (args == null || args.Length == 0)
            {
                return true;
            }

            bool targetSeen = false;
            foreach (string raw in args)
            {
                string value = (raw ?? string.Empty).Trim().ToLowerInvariant();
                if (value.Length == 0)
                {
                    continue;
                }

                if (value == "json")
                {
                    includeJson = true;
                    continue;
                }

                if (value == "all" || value == "items" || value == "weapons" ||
                    value == "projectiles" || value == "held")
                {
                    if (targetSeen)
                    {
                        error = "Specify only one export target.";
                        return false;
                    }

                    target = value;
                    targetSeen = true;
                    continue;
                }

                error = "Unknown argument: " + value;
                return false;
            }

            return true;
        }

        private static bool WantsWeapons(DumpJob job)
        {
            return job.Target == "all" || job.Target == "weapons";
        }

        private static bool WantsItems(DumpJob job)
        {
            return job.Target == "all" || job.Target == "items";
        }

        private static bool WantsProjectiles(DumpJob job)
        {
            return job.Target == "all" || job.Target == "projectiles";
        }

        private static bool WantsHeld(DumpJob job)
        {
            return job.Target == "all" || job.Target == "held";
        }

        private void BuildItemIndex(DumpJob job)
        {
            if (ItemManager.itemList == null)
            {
                throw new InvalidOperationException("ItemManager.itemList is null.");
            }

            foreach (ItemDefinition definition in ItemManager.itemList)
            {
                if (definition == null)
                {
                    continue;
                }

                if (WantsItems(job))
                {
                    job.Items.Add(CaptureItemDefinition(definition));
                }

                if (WantsProjectiles(job))
                {
                    CaptureAmmoLinks(job, definition);
                }

                if (!WantsHeld(job) && !WantsWeapons(job))
                {
                    continue;
                }

                ItemModEntity entityMod = FindItemModEntity(definition);
                if (entityMod == null || entityMod.entityPrefab == null)
                {
                    continue;
                }

                string path = NormalizePath(entityMod.entityPrefab.resourcePath);
                if (string.IsNullOrEmpty(path))
                {
                    continue;
                }

                SortedSet<string> names;
                if (!job.ItemNamesByPrefab.TryGetValue(path, out names))
                {
                    names = new SortedSet<string>(StringComparer.Ordinal);
                    job.ItemNamesByPrefab.Add(path, names);
                }

                if (!string.IsNullOrEmpty(definition.shortname))
                {
                    names.Add(definition.shortname);
                }

                if (!job.ItemDefinitionsByPrefab.ContainsKey(path))
                {
                    job.ItemDefinitionsByPrefab.Add(path, definition);
                }
            }
        }

        private static ItemRecord CaptureItemDefinition(ItemDefinition definition)
        {
            object displayName = ReadMember(definition, "displayName");
            object displayDescription = ReadMember(definition, "displayDescription");
            object condition = ReadMember(definition, "condition");
            object foundCondition = ReadMember(condition, "foundCondition");
            object breakEffect = ReadMember(condition, "breakEffect");
            object parent = ReadMember(definition, "Parent", "parent");
            object redirect = ReadMember(definition, "isRedirectOf");
            object worldModel = ReadMember(definition, "worldModelPrefab");

            ItemModEntity entityMod = FindItemModEntity(definition);
            object entityPrefab = entityMod == null ? null : entityMod.entityPrefab;

            return new ItemRecord
            {
                item_id = ReadIntMember(definition, 0, "itemid"),
                shortname = definition.shortname ?? string.Empty,
                definition_name = ValueText(ReadMember(definition, "name")),
                definition_type = definition.GetType().FullName ?? definition.GetType().Name,
                display_name = ReadPhrase(displayName),
                display_description = ReadPhrase(displayDescription),
                category = ValueText(ReadMember(definition, "category")),
                selection_panel = ValueText(ReadMember(definition, "selectionPanel")),
                era = ValueText(ReadMember(definition, "era")),
                era_restrictions = ValueText(ReadMember(definition, "eraRestrictions")),
                loot_distribution_type = ValueText(ReadMember(definition, "lootDistributionType")),
                rarity = ValueText(ReadMember(definition, "rarity")),
                despawn_rarity = ValueText(ReadMember(definition, "despawnRarity")),
                item_type = ValueText(ReadMember(definition, "itemType")),
                amount_type = ValueText(ReadMember(definition, "amountType")),
                occupy_slots = ValueText(ReadMember(definition, "occupySlots")),
                occupy_slots_value = ReadLongMember(definition, 0L, "occupySlots"),
                max_draggable = ReadIntMember(definition, 0, "maxDraggable"),
                stackable = ReadIntMember(definition, 0, "stackable"),
                crafting_stackable = ReadIntMember(definition, 0, "craftingStackable"),
                volume = ReadIntMember(definition, 0, "volume"),
                base_radioactivity = ReadFloatMember(definition, 0f, "baseRadioactivity"),
                apartment_tax_per_stack = ReadFloatMember(definition, 0f, "ApartmentTaxPerStack"),
                quick_despawn = ReadBoolMember(definition, false, "quickDespawn"),
                block_stealing_in_safe_zone =
                    ReadBoolMember(definition, false, "blockStealingInSafeZone"),
                allow_burying = ReadBoolMember(definition, false, "allowBurying"),
                tutorial_allowance = ValueText(ReadMember(definition, "tutorialAllowance")),
                supports_stackable_ownership =
                    ReadBoolMember(definition, false, "supportsStackableOwnership"),
                spawn_as_blueprint = ReadBoolMember(definition, false, "spawnAsBlueprint"),
                hidden = ReadBoolMember(definition, false, "hidden"),
                flags = ValueText(ReadMember(definition, "flags")),
                flags_value = ReadLongMember(definition, 0L, "flags"),
                hide_selected_panel = ReadBoolMember(definition, false, "hideSelectedPanel"),
                supports_accessories = ReadBoolMember(definition, false, "supportsAccessories"),
                traits = ValueText(ReadMember(definition, "Traits", "traits")),
                traits_value = ReadLongMember(definition, 0L, "Traits", "traits"),
                vehicle_item = ReadBoolMember(definition, false, "vehicleItem"),
                vehicle_category = ValueText(ReadMember(definition, "vehicleCategory")),
                is_holdable = ReadBoolMember(definition, false, "isHoldable"),
                is_usable = ReadBoolMember(definition, false, "isUsable"),
                is_wearable = ReadBoolMember(definition, false, "isWearable"),
                has_skins = ReadBoolMember(definition, false, "HasSkins"),
                built_in_skin_count = ReadCollectionCount(ReadMember(definition, "skins")),
                workshop_skin_count = ReadCollectionCount(ReadMember(definition, "skins2")),
                parent_shortname = ValueText(ReadMember(parent, "shortname")),
                redirect_shortname = ValueText(ReadMember(redirect, "shortname")),
                redirect_vending_behaviour =
                    ValueText(ReadMember(definition, "redirectVendingBehaviour")),
                world_model_prefab = ReadResourcePath(worldModel),
                held_entity_prefab = ReadResourcePath(entityPrefab),
                held_entity_prefab_id = ReadUIntMember(entityPrefab, 0U, "resourceID"),
                treat_as_component_for_repairs =
                    ReadBoolMember(definition, false, "treatAsComponentForRepairs"),
                align_world_model_on_drop =
                    ReadBoolMember(definition, false, "AlignWorldModelOnDrop"),
                world_model_drop_offset =
                    ReadVector3Member(definition, "WorldModelDropOffset"),
                adjust_center_of_mass_on_drop =
                    ReadBoolMember(definition, false, "AdjustCenterOfMassOnDrop"),
                drop_center_of_mass =
                    ReadVector3Member(definition, "DropCenterOfMass"),
                condition = new ItemConditionRecord
                {
                    enabled = ReadBoolMember(condition, false, "enabled"),
                    max = ReadFloatMember(condition, 0f, "max"),
                    repairable = ReadBoolMember(condition, false, "repairable"),
                    maintain_max_condition =
                        ReadBoolMember(condition, false, "maintainMaxCondition"),
                    oven_condition = ReadBoolMember(condition, false, "ovenCondition"),
                    found_fraction_min =
                        ReadFloatMember(foundCondition, 1f, "fractionMin"),
                    found_fraction_max =
                        ReadFloatMember(foundCondition, 1f, "fractionMax"),
                    hide_condition_bar =
                        ReadBoolMember(condition, false, "hideConditionBar"),
                    break_effect_prefab = ReadResourcePath(breakEffect)
                },
                item_mod_types = ReadTypeNames(ReadMember(definition, "itemMods")),
                children = ReadDefinitionShortnames(ReadMember(definition, "Children"))
            };
        }

        private static PhraseRecord ReadPhrase(object phrase)
        {
            return new PhraseRecord
            {
                token = ValueText(ReadMember(phrase, "token", "Token")),
                english = ValueText(ReadMember(phrase, "english", "English"))
            };
        }

        private static string ReadResourcePath(object reference)
        {
            return NormalizePath(ValueText(ReadMember(reference, "resourcePath")));
        }

        private static List<string> ReadTypeNames(object collection)
        {
            List<string> names = new List<string>();
            IEnumerable enumerable = collection as IEnumerable;
            if (enumerable == null)
            {
                return names;
            }

            foreach (object value in enumerable)
            {
                if (value != null)
                {
                    names.Add(value.GetType().FullName ?? value.GetType().Name);
                }
            }

            return names
                .Distinct(StringComparer.Ordinal)
                .OrderBy(x => x, StringComparer.Ordinal)
                .ToList();
        }

        private static List<string> ReadDefinitionShortnames(object collection)
        {
            List<string> names = new List<string>();
            IEnumerable enumerable = collection as IEnumerable;
            if (enumerable == null)
            {
                return names;
            }

            foreach (object value in enumerable)
            {
                string shortname = ValueText(ReadMember(value, "shortname"));
                if (!string.IsNullOrEmpty(shortname))
                {
                    names.Add(shortname);
                }
            }

            return names
                .Distinct(StringComparer.Ordinal)
                .OrderBy(x => x, StringComparer.Ordinal)
                .ToList();
        }

        private static int ReadCollectionCount(object collection)
        {
            ICollection values = collection as ICollection;
            if (values != null)
            {
                return values.Count;
            }

            int count = 0;
            IEnumerable enumerable = collection as IEnumerable;
            if (enumerable != null)
            {
                foreach (object ignored in enumerable)
                {
                    count++;
                }
            }
            return count;
        }

        private static void CaptureAmmoLinks(DumpJob job, ItemDefinition definition)
        {
            ItemModProjectile projectileMod = definition.GetComponent<ItemModProjectile>();
            if (projectileMod == null)
            {
                return;
            }

            AddAmmoLink(
                job,
                definition,
                projectileMod,
                projectileMod.projectileObject,
                0U);

            if (projectileMod.SkinOverrides == null)
            {
                return;
            }

            foreach (ItemModProjectile.SkinOverride skinOverride in projectileMod.SkinOverrides)
            {
                uint skinnedWeaponPrefabId = skinOverride.SkinnedWeapon != null
                    ? skinOverride.SkinnedWeapon.resourceID
                    : 0U;

                AddAmmoLink(
                    job,
                    definition,
                    projectileMod,
                    skinOverride.OverrideProjectile,
                    skinnedWeaponPrefabId);
            }
        }

        private static void AddAmmoLink(
            DumpJob job,
            ItemDefinition definition,
            ItemModProjectile projectileMod,
            GameObjectRef projectileReference,
            uint skinnedWeaponPrefabId)
        {
            if (projectileReference == null)
            {
                return;
            }

            string path = NormalizePath(projectileReference.resourcePath);
            if (string.IsNullOrEmpty(path))
            {
                return;
            }

            List<AmmoSourceRecord> sources;
            if (!job.AmmoByProjectilePrefab.TryGetValue(path, out sources))
            {
                sources = new List<AmmoSourceRecord>();
                job.AmmoByProjectilePrefab.Add(path, sources);
            }

            sources.Add(new AmmoSourceRecord
            {
                item_shortname = definition.shortname,
                ammo_type = projectileMod.ammoType.ToString(),
                ammo_sub_type = projectileMod.ammoSubType.ToString(),
                num_projectiles = projectileMod.numProjectiles,
                projectile_spread = projectileMod.projectileSpread,
                projectile_velocity = projectileMod.projectileVelocity,
                projectile_velocity_spread = projectileMod.projectileVelocitySpread,
                min_velocity = projectileMod.GetMinVelocity(),
                average_velocity = projectileMod.GetAverageVelocity(),
                max_velocity = projectileMod.GetMaxVelocity(),
                barrel_condition_loss = projectileMod.barrelConditionLoss,
                category = projectileMod.category,
                skinned_weapon_prefab_id = skinnedWeaponPrefabId
            });
        }

        private static ItemModEntity FindItemModEntity(ItemDefinition definition)
        {
            ItemModEntity component = definition.GetComponent<ItemModEntity>();
            if (component != null)
            {
                return component;
            }

            if (definition.itemMods == null)
            {
                return null;
            }

            foreach (ItemMod mod in definition.itemMods)
            {
                ItemModEntity entityMod = mod as ItemModEntity;
                if (entityMod != null)
                {
                    return entityMod;
                }
            }

            return null;
        }

        private void CaptureHeldItems(DumpJob job)
        {
            Dictionary<string, HeldTypeInfo> typesByPrefab =
                new Dictionary<string, HeldTypeInfo>(StringComparer.OrdinalIgnoreCase);

            foreach (KeyValuePair<string, SortedSet<string>> pair in job.ItemNamesByPrefab)
            {
                HeldTypeInfo typeInfo;
                if (!typesByPrefab.TryGetValue(pair.Key, out typeInfo))
                {
                    GameObject prefab = GameManager.server.FindPrefab(pair.Key);
                    typeInfo = GetHeldTypeInfo(prefab);
                    typesByPrefab[pair.Key] = typeInfo;
                }

                if (typeInfo == null)
                {
                    continue;
                }

                foreach (string shortname in pair.Value)
                {
                    job.HeldItems.Add(new HeldItemRecord
                    {
                        name = shortname,
                        concrete_type = typeInfo.ConcreteType,
                        type_chain = new List<string>(typeInfo.TypeChain),
                        prefab_path = pair.Key
                    });
                }
            }
        }

        private static HeldTypeInfo GetHeldTypeInfo(GameObject prefab)
        {
            if (prefab == null)
            {
                return null;
            }

            HeldEntity held = prefab.GetComponent<HeldEntity>();
            if (held == null)
            {
                return null;
            }

            List<string> typeChain = new List<string>();
            Type type = held.GetType();
            while (type != null && typeof(HeldEntity).IsAssignableFrom(type))
            {
                typeChain.Add(type.Name);
                type = type.BaseType;
            }

            return typeChain.Count == 0
                ? null
                : new HeldTypeInfo
                {
                    ConcreteType = typeChain[0],
                    TypeChain = typeChain
                };
        }

        private void ProcessPrefabBatch()
        {
            DumpJob job = _activeJob;
            if (job == null)
            {
                return;
            }

            int end = Math.Min(job.PrefabIndex + PrefabsPerTick, job.Prefabs.Length);
            for (; job.PrefabIndex < end; job.PrefabIndex++)
            {
                GameManifest.PrefabProperties properties = job.Prefabs[job.PrefabIndex];
                try
                {
                    CapturePrefab(job, properties);
                }
                catch (Exception ex)
                {
                    job.ErrorCount++;
                    if (job.Errors.Count < 25)
                    {
                        job.Errors.Add(properties.name + ": " + ex.Message);
                    }
                }
            }

            if (job.PrefabIndex < job.Prefabs.Length)
            {
                if (job.PrefabIndex >= job.NextProgressLog)
                {
                    Puts(string.Format(
                        "Rust data export progress: {0}/{1} prefabs.",
                        job.PrefabIndex,
                        job.Prefabs.Length));
                    job.NextProgressLog += 2000;
                }

                timer.Once(0.01f, ProcessPrefabBatch);
                return;
            }

            CompleteExport();
        }

        private void CapturePrefab(DumpJob job, GameManifest.PrefabProperties properties)
        {
            string path = NormalizePath(properties.name);
            if (string.IsNullOrEmpty(path) ||
                !path.EndsWith(".prefab", StringComparison.OrdinalIgnoreCase))
            {
                return;
            }

            GameObject prefab = GameManager.server.FindPrefab(path);
            if (prefab == null)
            {
                return;
            }

            if (WantsWeapons(job))
            {
                BaseProjectile weapon = prefab.GetComponent<BaseProjectile>();
                if (weapon != null)
                {
                    string name = GetWeaponName(job, path);
                    string key = properties.hash.ToString(Invariant) + "\n" + name;
                    if (job.WeaponKeys.Add(key))
                    {
                        job.Weapons.Add(CaptureWeapon(name, path, properties.hash, weapon));
                    }
                }
            }

            if (WantsProjectiles(job))
            {
                Projectile projectile = prefab.GetComponent<Projectile>();
                if (projectile != null && job.ProjectileHashes.Add(properties.hash))
                {
                    job.Projectiles.Add(CaptureProjectile(job, path, properties.hash, projectile));
                }
            }
        }

        private static string GetWeaponName(DumpJob job, string path)
        {
            SortedSet<string> names;
            if (job.ItemNamesByPrefab.TryGetValue(path, out names) && names.Count > 0)
            {
                return names.First();
            }

            string fileName = Path.GetFileNameWithoutExtension(path) ?? "unknown_weapon";
            if (fileName.EndsWith(".entity", StringComparison.OrdinalIgnoreCase))
            {
                fileName = fileName.Substring(0, fileName.Length - ".entity".Length);
            }

            return fileName;
        }

        private static WeaponRecord CaptureWeapon(string name, string path, uint hash, BaseProjectile weapon)
        {
            RecoilProperties recoil = weapon.recoil;
            if (recoil != null)
            {
                RecoilProperties resolved = recoil.GetRecoil();
                if (resolved != null)
                {
                    recoil = resolved;
                }
            }

            WeaponRecord record = new WeaponRecord
            {
                name = name,
                alias = MakeIdentifier(name),
                prefab_path = path,
                hash = hash,
                damage_scale = weapon.damageScale,
                distance_scale = weapon.distanceScale,
                projectile_velocity_scale = weapon.projectileVelocityScale,
                automatic = weapon.automatic,
                noise_radius = weapon.NoiseRadius,
                aim_sway = weapon.aimSway,
                aim_sway_speed = weapon.aimSwaySpeed,
                has_ads = weapon.hasADS,
                can_change_fire_modes = weapon.canChangeFireModes,
                default_on = weapon.defaultOn,
                manual_cycle = weapon.manualCycle,
                no_aiming_while_cycling = weapon.noAimingWhileCycling,
                reset_duration = weapon.resetDuration,
                magazine_capacity = GetMagazineCapacity(weapon),
                wants_recoil_comp = weapon.wantsRecoilComp,
                recoil_comp_delay_override = weapon.recoilCompDelayOverride,
                no_headshots = weapon.noHeadshots,
                aimcone = new AimConeRecord
                {
                    aim_cone = weapon.aimCone,
                    hip_aim_cone = weapon.hipAimCone,
                    penalty_per_shot = weapon.aimconePenaltyPerShot,
                    penalty_max = weapon.aimConePenaltyMax,
                    penalty_recover_time = weapon.aimconePenaltyRecoverTime,
                    penalty_recover_delay = weapon.aimconePenaltyRecoverDelay,
                    stance_penalty_scale = weapon.stancePenaltyScale
                },
                reload = new ReloadRecord
                {
                    time = weapon.reloadTime,
                    start_duration = weapon.reloadStartDuration,
                    fraction_duration = weapon.reloadFractionDuration,
                    end_duration = weapon.reloadEndDuration,
                    fractional = weapon.fractionalReload,
                    can_unload_ammo = weapon.canUnloadAmmo
                },
                burst = new BurstRecord
                {
                    enabled = weapon.isBurstWeapon,
                    recoil_scale = weapon.internalBurstRecoilScale,
                    fire_rate_scale = weapon.internalBurstFireRateScale,
                    aim_cone_scale = weapon.internalBurstAimConeScale
                },
                turret = new TurretRecord
                {
                    usable = weapon.usableByTurret,
                    large_turret = weapon.largeTurretWeapon,
                    damage_scale = weapon.turretDamageScale,
                    reload_duration_override = weapon.turretReloadDurationOverride
                },
                attack = new AttackRecord
                {
                    deploy_delay = weapon.deployDelay,
                    repeat_delay = weapon.repeatDelay,
                    animation_delay = weapon.animationDelay
                },
                npc = new NpcWeaponRecord
                {
                    effective_range = weapon.effectiveRange,
                    damage_scale = weapon.npcDamageScale,
                    attack_length_min = weapon.attackLengthMin,
                    attack_length_max = weapon.attackLengthMax,
                    attack_spacing = weapon.attackSpacing,
                    aim_sway_offset = weapon.aiAimSwayOffset,
                    aim_cone = weapon.aiAimCone,
                    only_in_range = weapon.aiOnlyInRange,
                    close_range_addition = weapon.CloseRangeAddition,
                    medium_range_addition = weapon.MediumRangeAddition,
                    long_range_addition = weapon.LongRangeAddition,
                    can_use_at_medium_range = weapon.CanUseAtMediumRange,
                    can_use_at_long_range = weapon.CanUseAtLongRange
                },
                held = new HeldRecord
                {
                    can_use_with_shield = weapon.canBeUsedWithShield,
                    is_building_tool = weapon.isBuildingTool,
                    hostility_score = weapon.hostileScore,
                    first_person_arm_offset = Vec3Record.From(weapon.FirstPersonArmOffset),
                    first_person_arm_rotation = Vec3Record.From(weapon.FirstPersonArmRotation),
                    first_person_rotation_strength = weapon.FirstPersonRotationStrength
                }
            };

            record.recoil = recoil == null
                ? new RecoilRecord()
                : new RecoilRecord
                {
                    yaw_min = recoil.recoilYawMin,
                    yaw_max = recoil.recoilYawMax,
                    pitch_min = recoil.recoilPitchMin,
                    pitch_max = recoil.recoilPitchMax,
                    time_to_take_min = recoil.timeToTakeMin,
                    time_to_take_max = recoil.timeToTakeMax,
                    ads_scale = recoil.ADSScale,
                    movement_penalty = recoil.movementPenalty,
                    clamp_pitch = recoil.clampPitch,
                    shots_until_max = recoil.shotsUntilMax,
                    use_curves = recoil.useCurves,
                    curves_as_scalar = recoil.curvesAsScalar,
                    max_recoil_radius = recoil.maxRecoilRadius,
                    override_aimcone_with_curve = recoil.overrideAimconeWithCurve,
                    aimcone_curve_scale = recoil.aimconeCurveScale,
                    ammo_aimcone_scale_multi_projectile = recoil.ammoAimconeScaleMultiProjectile,
                    ammo_aimcone_scale_single_projectile = recoil.ammoAimconeScaleSingleProjectile
                };

            return record;
        }

        private static int GetMagazineCapacity(BaseProjectile weapon)
        {
            if (weapon == null || weapon.primaryMagazine == null)
            {
                return 0;
            }

            // On prefab assets Magazine.capacity is usually still the runtime default (0).
            // Magazine.ServerInit later copies the serialized builtInSize into capacity.
            int builtInSize = weapon.primaryMagazine.definition.builtInSize;
            return builtInSize > 0 ? builtInSize : weapon.primaryMagazine.capacity;
        }

        private static ProjectileRecord CaptureProjectile(
            DumpJob job,
            string path,
            uint hash,
            Projectile projectile)
        {
            ProjectileRecord record = new ProjectileRecord
            {
                name = MakeIdentifier(Path.GetFileNameWithoutExtension(path) ?? "unknown_projectile"),
                prefab_path = path,
                hash = hash,
                initial_velocity = Vec3Record.From(projectile.initialVelocity),
                drag = projectile.drag,
                gravity_modifier = projectile.gravityModifier,
                thickness = projectile.thickness,
                initial_distance = projectile.initialDistance,
                initial_orientation = Vec3Record.From(projectile.initialOrientation),
                penetration_power = projectile.penetrationPower,
                ricochet_chance = projectile.ricochetChance,
                stick_probability = projectile.stickProbability,
                break_probability = projectile.breakProbability,
                condition_loss = projectile.conditionLoss,
                water_integrity_loss = projectile.waterIntegrityLoss,
                damage_distances = ReadMinMax(projectile.damageDistances),
                damage_multipliers = ReadMinMax(projectile.damageMultipliers),
                remain_in_world = projectile.remainInWorld,
                can_refract = projectile.canRefract,
                penetrates_vehicles = projectile.penetratesVehicles,
                create_decals = projectile.createDecals
            };

            List<AmmoSourceRecord> ammoSources;
            if (job.AmmoByProjectilePrefab.TryGetValue(path, out ammoSources))
            {
                record.ammo_sources = ammoSources
                    .OrderBy(x => x.item_shortname, StringComparer.Ordinal)
                    .ThenBy(x => x.skinned_weapon_prefab_id)
                    .ToList();
            }

            if (projectile.damageTypes != null)
            {
                foreach (object entry in projectile.damageTypes)
                {
                    if (entry == null)
                    {
                        continue;
                    }

                    object typeValue = ReadMember(entry, "type", "Type");
                    float amount = ReadFloatMember(entry, 0f, "amount", "Amount");
                    if (typeValue == null || amount == 0f)
                    {
                        continue;
                    }

                    record.damage_types.Add(new DamageTypeRecord
                    {
                        type = typeValue.ToString(),
                        amount = amount
                    });

                    if (record.damage_types.Count == MaxProjectileDamageTypes)
                    {
                        break;
                    }
                }
            }

            return record;
        }

        private static Vec2Record ReadMinMax(object value)
        {
            return new Vec2Record
            {
                x = ReadFloatMember(value, 0f, "min", "Min", "x", "X"),
                y = ReadFloatMember(value, 0f, "max", "Max", "y", "Y")
            };
        }

        private static float ReadFloatMember(object instance, float fallback, params string[] names)
        {
            object value = ReadMember(instance, names);
            if (value == null)
            {
                return fallback;
            }

            try
            {
                return Convert.ToSingle(value, Invariant);
            }
            catch
            {
                return fallback;
            }
        }

        private static int ReadIntMember(object instance, int fallback, params string[] names)
        {
            object value = ReadMember(instance, names);
            if (value == null)
            {
                return fallback;
            }

            try
            {
                return Convert.ToInt32(value, Invariant);
            }
            catch
            {
                return fallback;
            }
        }

        private static uint ReadUIntMember(object instance, uint fallback, params string[] names)
        {
            object value = ReadMember(instance, names);
            if (value == null)
            {
                return fallback;
            }

            try
            {
                return Convert.ToUInt32(value, Invariant);
            }
            catch
            {
                return fallback;
            }
        }

        private static long ReadLongMember(object instance, long fallback, params string[] names)
        {
            object value = ReadMember(instance, names);
            if (value == null)
            {
                return fallback;
            }

            try
            {
                return Convert.ToInt64(value, Invariant);
            }
            catch
            {
                return fallback;
            }
        }

        private static bool ReadBoolMember(object instance, bool fallback, params string[] names)
        {
            object value = ReadMember(instance, names);
            if (value == null)
            {
                return fallback;
            }

            try
            {
                return Convert.ToBoolean(value, Invariant);
            }
            catch
            {
                return fallback;
            }
        }

        private static Vec3Record ReadVector3Member(object instance, params string[] names)
        {
            object value = ReadMember(instance, names);
            if (value is Vector3)
            {
                return Vec3Record.From((Vector3)value);
            }

            return new Vec3Record
            {
                x = ReadFloatMember(value, 0f, "x", "X"),
                y = ReadFloatMember(value, 0f, "y", "Y"),
                z = ReadFloatMember(value, 0f, "z", "Z")
            };
        }

        private static object ReadMember(object instance, params string[] names)
        {
            if (instance == null)
            {
                return null;
            }

            const BindingFlags flags =
                BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.IgnoreCase;

            Type type = instance.GetType();
            foreach (string name in names)
            {
                FieldInfo field = type.GetField(name, flags);
                if (field != null)
                {
                    try
                    {
                        return field.GetValue(instance);
                    }
                    catch
                    {
                        continue;
                    }
                }

                PropertyInfo property = type.GetProperty(name, flags);
                if (property != null && property.GetIndexParameters().Length == 0)
                {
                    try
                    {
                        return property.GetValue(instance, null);
                    }
                    catch
                    {
                        continue;
                    }
                }
            }

            return null;
        }

        private static string GetCurrentTargetBuild()
        {
            Type protocolType = FindRuntimeType("Rust.Protocol", "Protocol");
            string protocol = ValueText(ReadStaticMember(protocolType, "printable", "Printable"));

            if (string.IsNullOrEmpty(protocol))
            {
                string network = ValueText(ReadStaticMember(protocolType, "network", "Network"));
                string save = ValueText(ReadStaticMember(protocolType, "save", "Save"));
                string report = ValueText(ReadStaticMember(protocolType, "report", "Report"));

                if (!string.IsNullOrEmpty(network))
                {
                    protocol = network;
                    if (!string.IsNullOrEmpty(save))
                    {
                        protocol += "." + save;
                    }
                    if (!string.IsNullOrEmpty(report))
                    {
                        protocol += "." + report;
                    }
                }
            }

            Type buildInfoType = FindRuntimeType("BuildInfo", "Facepunch.BuildInfo");
            object buildInfo = ReadStaticMember(buildInfoType, "Current", "current");
            object scm = ReadMember(buildInfo, "Scm", "SCM", "scm");
            string changeset = ValueText(ReadMember(scm, "ChangeId", "ChangeID", "Changeset", "changeset"));
            string oxideVersion = ValueText(ReadMember(Interface.Oxide, "Version", "version"));

            List<string> parts = new List<string>();
            parts.Add("Protocol " + (string.IsNullOrEmpty(protocol) ? "unknown" : protocol));
            parts.Add("Changeset " + (string.IsNullOrEmpty(changeset) ? "unknown" : changeset));

            if (!string.IsNullOrEmpty(oxideVersion))
            {
                parts.Add("Oxide.Rust " + oxideVersion);
            }

            return string.Join(" / ", parts.ToArray());
        }

        private static Type FindRuntimeType(params string[] names)
        {
            foreach (Assembly assembly in AppDomain.CurrentDomain.GetAssemblies())
            {
                foreach (string name in names)
                {
                    Type type = assembly.GetType(name, false, true);
                    if (type != null)
                    {
                        return type;
                    }
                }
            }

            return null;
        }

        private static object ReadStaticMember(Type type, params string[] names)
        {
            if (type == null)
            {
                return null;
            }

            const BindingFlags flags =
                BindingFlags.Static | BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.IgnoreCase;

            foreach (string name in names)
            {
                FieldInfo field = type.GetField(name, flags);
                if (field != null)
                {
                    return field.GetValue(null);
                }

                PropertyInfo property = type.GetProperty(name, flags);
                if (property != null && property.GetIndexParameters().Length == 0)
                {
                    return property.GetValue(null, null);
                }
            }

            return null;
        }

        private static string ValueText(object value)
        {
            return value == null
                ? string.Empty
                : Convert.ToString(value, Invariant);
        }

        private void CompleteExport()
        {
            DumpJob job = _activeJob;
            if (job == null)
            {
                return;
            }

            try
            {
                job.Items = job.Items
                    .OrderBy(x => x.shortname, StringComparer.Ordinal)
                    .ThenBy(x => x.item_id)
                    .ToList();

                job.Weapons = job.Weapons
                    .OrderBy(x => x.name, StringComparer.Ordinal)
                    .ThenBy(x => x.prefab_path, StringComparer.Ordinal)
                    .ToList();

                job.Projectiles = job.Projectiles
                    .OrderBy(x => x.name, StringComparer.Ordinal)
                    .ThenBy(x => x.prefab_path, StringComparer.Ordinal)
                    .ToList();

                job.HeldItems = job.HeldItems
                    .GroupBy(x => x.name, StringComparer.Ordinal)
                    .Select(x => x.First())
                    .OrderBy(x => x.name, StringComparer.Ordinal)
                    .ToList();

                string directory = Path.Combine(Interface.Oxide.DataDirectory, "RustDataExporter");
                Directory.CreateDirectory(directory);

                List<string> written = new List<string>();
                if (WantsItems(job))
                {
                    WriteText(directory, "RustItemData.hpp", BuildItemHeader(job), written);
                    if (job.IncludeJson)
                    {
                        WriteJson(
                            directory,
                            "RustItemData.json",
                            job.GeneratedUtc,
                            job.TargetBuild,
                            job.Items,
                            written);
                    }
                }

                if (WantsWeapons(job))
                {
                    WriteText(directory, "RustWeaponData.hpp", BuildWeaponHeader(job), written);
                    if (job.IncludeJson)
                    {
                        WriteJson(directory, "RustWeaponData.json", job.GeneratedUtc, job.TargetBuild, job.Weapons, written);
                    }
                }

                if (WantsProjectiles(job))
                {
                    WriteText(directory, "RustProjectileData.hpp", BuildProjectileHeader(job), written);
                    if (job.IncludeJson)
                    {
                        WriteJson(directory, "RustProjectileData.json", job.GeneratedUtc, job.TargetBuild, job.Projectiles, written);
                    }
                }

                if (WantsHeld(job))
                {
                    WriteText(directory, "RustHeldItemTypeMap.hpp", BuildHeldHeader(job), written);
                    if (job.IncludeJson)
                    {
                        WriteJson(directory, "RustHeldItemTypeMap.json", job.GeneratedUtc, job.TargetBuild, job.HeldItems, written);
                    }
                }

                Puts(string.Format(
                    "Rust data export complete. Items={0}, Weapons={1}, Projectiles={2}, Held items={3}, Errors={4}. Directory: {5}",
                    job.Items.Count,
                    job.Weapons.Count,
                    job.Projectiles.Count,
                    job.HeldItems.Count,
                    job.ErrorCount,
                    directory));

                foreach (string file in written)
                {
                    Puts("Wrote " + file);
                }

                if (job.Errors.Count > 0)
                {
                    PrintWarning("First prefab scan errors:\n" + string.Join("\n", job.Errors.ToArray()));
                }
            }
            catch (Exception ex)
            {
                PrintError("Failed to write Rust data export: " + ex);
            }
            finally
            {
                _activeJob = null;
            }
        }

        private static void WriteText(string directory, string fileName, string content, List<string> written)
        {
            string path = Path.Combine(directory, fileName);
            File.WriteAllText(path, content, new UTF8Encoding(false));
            written.Add(path);
        }

        private static void WriteJson<T>(
            string directory,
            string fileName,
            DateTime generatedUtc,
            string targetBuild,
            List<T> data,
            List<string> written)
        {
            JsonEnvelope<T> envelope = new JsonEnvelope<T>
            {
                generated_utc = generatedUtc.ToString("yyyy-MM-dd HH:mm:ss", Invariant),
                target_build = targetBuild,
                count = data.Count,
                data = data
            };

            WriteText(
                directory,
                fileName,
                JsonConvert.SerializeObject(envelope, Formatting.Indented),
                written);
        }

        private static string BuildItemHeader(DumpJob job)
        {
            StringBuilder sb = NewHeader("Rust Item Data", job.GeneratedUtc, job.TargetBuild, job.Items.Count);
            sb.AppendLine("#pragma once");
            sb.AppendLine("#ifndef RUST_DATA_ITEM_DATA_HPP");
            sb.AppendLine("#define RUST_DATA_ITEM_DATA_HPP");
            sb.AppendLine();
            sb.AppendLine("#include <cstddef>");
            sb.AppendLine("#include <cstdint>");
            sb.AppendLine("#include <cstring>");
            sb.AppendLine();
            sb.AppendLine("namespace RustData");
            sb.AppendLine("{");
            sb.AppendLine("namespace Items");
            sb.AppendLine("{");
            sb.AppendLine();
            sb.AppendLine("struct Vec3 { float x; float y; float z; };");
            sb.AppendLine("struct PhraseData { const char* token; const char* english; };");
            sb.AppendLine();
            sb.AppendLine("struct ConditionData");
            sb.AppendLine("{");
            sb.AppendLine("    bool enabled;");
            sb.AppendLine("    float max;");
            sb.AppendLine("    bool repairable;");
            sb.AppendLine("    bool maintain_max_condition;");
            sb.AppendLine("    bool oven_condition;");
            sb.AppendLine("    float found_fraction_min;");
            sb.AppendLine("    float found_fraction_max;");
            sb.AppendLine("    bool hide_condition_bar;");
            sb.AppendLine("    const char* break_effect_prefab;");
            sb.AppendLine("};");
            sb.AppendLine();
            sb.AppendLine("struct ItemData");
            sb.AppendLine("{");
            sb.AppendLine("    std::int32_t item_id;");
            sb.AppendLine("    const char* shortname;");
            sb.AppendLine("    const char* definition_name;");
            sb.AppendLine("    const char* definition_type;");
            sb.AppendLine("    PhraseData display_name;");
            sb.AppendLine("    PhraseData display_description;");
            sb.AppendLine("    const char* category;");
            sb.AppendLine("    const char* selection_panel;");
            sb.AppendLine("    const char* era;");
            sb.AppendLine("    const char* era_restrictions;");
            sb.AppendLine("    const char* loot_distribution_type;");
            sb.AppendLine("    const char* rarity;");
            sb.AppendLine("    const char* despawn_rarity;");
            sb.AppendLine("    const char* item_type;");
            sb.AppendLine("    const char* amount_type;");
            sb.AppendLine("    const char* occupy_slots;");
            sb.AppendLine("    std::int64_t occupy_slots_value;");
            sb.AppendLine("    std::int32_t max_draggable;");
            sb.AppendLine("    std::int32_t stackable;");
            sb.AppendLine("    std::int32_t crafting_stackable;");
            sb.AppendLine("    std::int32_t volume;");
            sb.AppendLine("    float base_radioactivity;");
            sb.AppendLine("    float apartment_tax_per_stack;");
            sb.AppendLine("    bool quick_despawn;");
            sb.AppendLine("    bool block_stealing_in_safe_zone;");
            sb.AppendLine("    bool allow_burying;");
            sb.AppendLine("    const char* tutorial_allowance;");
            sb.AppendLine("    bool supports_stackable_ownership;");
            sb.AppendLine("    bool spawn_as_blueprint;");
            sb.AppendLine("    bool hidden;");
            sb.AppendLine("    const char* flags;");
            sb.AppendLine("    std::int64_t flags_value;");
            sb.AppendLine("    bool hide_selected_panel;");
            sb.AppendLine("    bool supports_accessories;");
            sb.AppendLine("    const char* traits;");
            sb.AppendLine("    std::int64_t traits_value;");
            sb.AppendLine("    bool vehicle_item;");
            sb.AppendLine("    const char* vehicle_category;");
            sb.AppendLine("    bool is_holdable;");
            sb.AppendLine("    bool is_usable;");
            sb.AppendLine("    bool is_wearable;");
            sb.AppendLine("    bool has_skins;");
            sb.AppendLine("    std::int32_t built_in_skin_count;");
            sb.AppendLine("    std::int32_t workshop_skin_count;");
            sb.AppendLine("    const char* parent_shortname;");
            sb.AppendLine("    const char* redirect_shortname;");
            sb.AppendLine("    const char* redirect_vending_behaviour;");
            sb.AppendLine("    const char* world_model_prefab;");
            sb.AppendLine("    const char* held_entity_prefab;");
            sb.AppendLine("    std::uint32_t held_entity_prefab_id;");
            sb.AppendLine("    bool treat_as_component_for_repairs;");
            sb.AppendLine("    bool align_world_model_on_drop;");
            sb.AppendLine("    Vec3 world_model_drop_offset;");
            sb.AppendLine("    bool adjust_center_of_mass_on_drop;");
            sb.AppendLine("    Vec3 drop_center_of_mass;");
            sb.AppendLine("    ConditionData condition;");
            sb.AppendLine("    std::size_t first_mod_type;");
            sb.AppendLine("    std::size_t mod_type_count;");
            sb.AppendLine("    std::size_t first_child;");
            sb.AppendLine("    std::size_t child_count;");
            sb.AppendLine("};");
            sb.AppendLine();

            int totalMods = job.Items.Sum(x => x.item_mod_types.Count);
            sb.AppendLine("inline constexpr std::size_t kModTypeCount = " + totalMods + ";");
            sb.AppendLine("inline constexpr const char* kModTypes[kModTypeCount == 0 ? 1 : kModTypeCount] =");
            sb.AppendLine("{");
            foreach (ItemRecord item in job.Items)
            {
                foreach (string modType in item.item_mod_types)
                {
                    sb.AppendLine("    \"" + EscapeCpp(modType) + "\",");
                }
            }
            sb.AppendLine("};");
            sb.AppendLine();

            int totalChildren = job.Items.Sum(x => x.children.Count);
            sb.AppendLine("inline constexpr std::size_t kChildCount = " + totalChildren + ";");
            sb.AppendLine("inline constexpr const char* kChildren[kChildCount == 0 ? 1 : kChildCount] =");
            sb.AppendLine("{");
            foreach (ItemRecord item in job.Items)
            {
                foreach (string child in item.children)
                {
                    sb.AppendLine("    \"" + EscapeCpp(child) + "\",");
                }
            }
            sb.AppendLine("};");
            sb.AppendLine();

            sb.AppendLine("inline constexpr std::size_t kCount = " + job.Items.Count + ";");
            sb.AppendLine("inline constexpr ItemData kData[kCount == 0 ? 1 : kCount] =");
            sb.AppendLine("{");

            int firstMod = 0;
            int firstChild = 0;
            for (int i = 0; i < job.Items.Count; i++)
            {
                ItemRecord item = job.Items[i];
                AppendItem(sb, item, firstMod, firstChild, i + 1 < job.Items.Count);
                firstMod += item.item_mod_types.Count;
                firstChild += item.children.Count;
            }

            sb.AppendLine("};");
            sb.AppendLine();
            sb.AppendLine("inline const ItemData* GetByItemId(std::int32_t itemId) noexcept");
            sb.AppendLine("{");
            sb.AppendLine("    switch (itemId)");
            sb.AppendLine("    {");

            HashSet<int> emittedIds = new HashSet<int>();
            for (int i = 0; i < job.Items.Count; i++)
            {
                ItemRecord item = job.Items[i];
                if (emittedIds.Add(item.item_id))
                {
                    sb.AppendLine(
                        "    case " + item.item_id.ToString(Invariant) +
                        ": return &kData[" + i + "]; // " + item.shortname);
                }
            }

            sb.AppendLine("    default: return nullptr;");
            sb.AppendLine("    }");
            sb.AppendLine("}");
            sb.AppendLine();
            sb.AppendLine("inline const ItemData* GetByShortname(const char* shortname) noexcept");
            sb.AppendLine("{");
            sb.AppendLine("    if (!shortname) return nullptr;");
            sb.AppendLine("    for (std::size_t i = 0; i < kCount; ++i)");
            sb.AppendLine("        if (std::strcmp(kData[i].shortname, shortname) == 0) return &kData[i];");
            sb.AppendLine("    return nullptr;");
            sb.AppendLine("}");
            sb.AppendLine();
            sb.AppendLine("inline std::int32_t GetItemId(const char* shortname) noexcept");
            sb.AppendLine("{");
            sb.AppendLine("    const ItemData* item = GetByShortname(shortname);");
            sb.AppendLine("    return item ? item->item_id : 0;");
            sb.AppendLine("}");
            sb.AppendLine();
            sb.AppendLine("inline const char* GetShortname(std::int32_t itemId) noexcept");
            sb.AppendLine("{");
            sb.AppendLine("    const ItemData* item = GetByItemId(itemId);");
            sb.AppendLine("    return item ? item->shortname : nullptr;");
            sb.AppendLine("}");
            sb.AppendLine();
            sb.AppendLine("inline const char* const* GetModTypes(const ItemData* item, std::size_t& count) noexcept");
            sb.AppendLine("{");
            sb.AppendLine("    if (!item) { count = 0; return nullptr; }");
            sb.AppendLine("    count = item->mod_type_count;");
            sb.AppendLine("    return count ? &kModTypes[item->first_mod_type] : nullptr;");
            sb.AppendLine("}");
            sb.AppendLine();
            sb.AppendLine("inline const char* const* GetChildren(const ItemData* item, std::size_t& count) noexcept");
            sb.AppendLine("{");
            sb.AppendLine("    if (!item) { count = 0; return nullptr; }");
            sb.AppendLine("    count = item->child_count;");
            sb.AppendLine("    return count ? &kChildren[item->first_child] : nullptr;");
            sb.AppendLine("}");
            sb.AppendLine("} // namespace Items");
            sb.AppendLine("} // namespace RustData");
            sb.AppendLine();
            sb.AppendLine("#endif // RUST_DATA_ITEM_DATA_HPP");
            return sb.ToString();
        }

        private static void AppendItem(
            StringBuilder sb,
            ItemRecord x,
            int firstMod,
            int firstChild,
            bool comma)
        {
            sb.AppendLine("    // " + x.shortname);
            sb.AppendLine("    {");
            sb.AppendLine("        " + x.item_id.ToString(Invariant) +
                          ", \"" + EscapeCpp(x.shortname) +
                          "\", \"" + EscapeCpp(x.definition_name) +
                          "\", \"" + EscapeCpp(x.definition_type) + "\",");
            sb.AppendLine("        { \"" + EscapeCpp(x.display_name.token) +
                          "\", \"" + EscapeCpp(x.display_name.english) +
                          "\" }, { \"" + EscapeCpp(x.display_description.token) +
                          "\", \"" + EscapeCpp(x.display_description.english) + "\" },");
            sb.AppendLine("        \"" + EscapeCpp(x.category) +
                          "\", \"" + EscapeCpp(x.selection_panel) +
                          "\", \"" + EscapeCpp(x.era) +
                          "\", \"" + EscapeCpp(x.era_restrictions) +
                          "\", \"" + EscapeCpp(x.loot_distribution_type) + "\",");
            sb.AppendLine("        \"" + EscapeCpp(x.rarity) +
                          "\", \"" + EscapeCpp(x.despawn_rarity) +
                          "\", \"" + EscapeCpp(x.item_type) +
                          "\", \"" + EscapeCpp(x.amount_type) +
                          "\", \"" + EscapeCpp(x.occupy_slots) +
                          "\", " + x.occupy_slots_value.ToString(Invariant) + "LL,");
            sb.AppendLine("        " + x.max_draggable + ", " + x.stackable + ", " +
                          x.crafting_stackable + ", " + x.volume + ", " +
                          F(x.base_radioactivity) + ", " + F(x.apartment_tax_per_stack) + ",");
            sb.AppendLine("        " + B(x.quick_despawn) + ", " +
                          B(x.block_stealing_in_safe_zone) + ", " + B(x.allow_burying) +
                          ", \"" + EscapeCpp(x.tutorial_allowance) + "\", " +
                          B(x.supports_stackable_ownership) + ", " + B(x.spawn_as_blueprint) + ",");
            sb.AppendLine("        " + B(x.hidden) +
                          ", \"" + EscapeCpp(x.flags) + "\", " +
                          x.flags_value.ToString(Invariant) + "LL, " +
                          B(x.hide_selected_panel) + ", " + B(x.supports_accessories) +
                          ", \"" + EscapeCpp(x.traits) + "\", " +
                          x.traits_value.ToString(Invariant) + "LL,");
            sb.AppendLine("        " + B(x.vehicle_item) +
                          ", \"" + EscapeCpp(x.vehicle_category) + "\", " +
                          B(x.is_holdable) + ", " + B(x.is_usable) + ", " +
                          B(x.is_wearable) + ", " + B(x.has_skins) + ", " +
                          x.built_in_skin_count + ", " + x.workshop_skin_count + ",");
            sb.AppendLine("        \"" + EscapeCpp(x.parent_shortname) +
                          "\", \"" + EscapeCpp(x.redirect_shortname) +
                          "\", \"" + EscapeCpp(x.redirect_vending_behaviour) +
                          "\", \"" + EscapeCpp(x.world_model_prefab) +
                          "\", \"" + EscapeCpp(x.held_entity_prefab) +
                          "\", " + x.held_entity_prefab_id.ToString(Invariant) + "U,");
            sb.AppendLine("        " + B(x.treat_as_component_for_repairs) + ", " +
                          B(x.align_world_model_on_drop) + ", " +
                          V3(x.world_model_drop_offset) + ", " +
                          B(x.adjust_center_of_mass_on_drop) + ", " +
                          V3(x.drop_center_of_mass) + ",");
            sb.AppendLine("        { " + B(x.condition.enabled) + ", " +
                          F(x.condition.max) + ", " + B(x.condition.repairable) + ", " +
                          B(x.condition.maintain_max_condition) + ", " +
                          B(x.condition.oven_condition) + ", " +
                          F(x.condition.found_fraction_min) + ", " +
                          F(x.condition.found_fraction_max) + ", " +
                          B(x.condition.hide_condition_bar) +
                          ", \"" + EscapeCpp(x.condition.break_effect_prefab) + "\" },");
            sb.AppendLine("        " + firstMod + ", " + x.item_mod_types.Count +
                          ", " + firstChild + ", " + x.children.Count);
            sb.AppendLine(comma ? "    }," : "    }");
        }

        private static string BuildWeaponHeader(DumpJob job)
        {
            StringBuilder sb = NewHeader("Rust Weapon Data", job.GeneratedUtc, job.TargetBuild, job.Weapons.Count);
            sb.AppendLine("#pragma once");
            sb.AppendLine("#ifndef RUST_DATA_WEAPON_DATA_HPP");
            sb.AppendLine("#define RUST_DATA_WEAPON_DATA_HPP");
            sb.AppendLine();
            sb.AppendLine("#include <cstddef>");
            sb.AppendLine("#include <cstdint>");
            sb.AppendLine("#include <cstring>");
            sb.AppendLine("#include <limits>");
            sb.AppendLine();
            sb.AppendLine("namespace RustData");
            sb.AppendLine("{");
            sb.AppendLine("struct Vec3 { float x; float y; float z; };");
            sb.AppendLine();
            sb.AppendLine("struct RecoilData");
            sb.AppendLine("{");
            sb.AppendLine("    float yaw_min;");
            sb.AppendLine("    float yaw_max;");
            sb.AppendLine("    float pitch_min;");
            sb.AppendLine("    float pitch_max;");
            sb.AppendLine("    float time_to_take_min;");
            sb.AppendLine("    float time_to_take_max;");
            sb.AppendLine("    float ads_scale;");
            sb.AppendLine("    float movement_penalty;");
            sb.AppendLine("    float clamp_pitch;");
            sb.AppendLine("    int shots_until_max;");
            sb.AppendLine("    bool use_curves;");
            sb.AppendLine("    bool curves_as_scalar;");
            sb.AppendLine("    float max_recoil_radius;");
            sb.AppendLine("    bool override_aimcone_with_curve;");
            sb.AppendLine("    float aimcone_curve_scale;");
            sb.AppendLine("    float ammo_aimcone_scale_multi_projectile;");
            sb.AppendLine("    float ammo_aimcone_scale_single_projectile;");
            sb.AppendLine("};");
            sb.AppendLine();
            sb.AppendLine("struct AimConeData");
            sb.AppendLine("{");
            sb.AppendLine("    float aim_cone;");
            sb.AppendLine("    float hip_aim_cone;");
            sb.AppendLine("    float penalty_per_shot;");
            sb.AppendLine("    float penalty_max;");
            sb.AppendLine("    float penalty_recover_time;");
            sb.AppendLine("    float penalty_recover_delay;");
            sb.AppendLine("    float stance_penalty_scale;");
            sb.AppendLine("};");
            sb.AppendLine();
            sb.AppendLine("struct ReloadData");
            sb.AppendLine("{");
            sb.AppendLine("    float time;");
            sb.AppendLine("    float start_duration;");
            sb.AppendLine("    float fraction_duration;");
            sb.AppendLine("    float end_duration;");
            sb.AppendLine("    bool fractional;");
            sb.AppendLine("    bool can_unload_ammo;");
            sb.AppendLine("};");
            sb.AppendLine();
            sb.AppendLine("struct BurstData { bool enabled; float recoil_scale; float fire_rate_scale; float aim_cone_scale; };");
            sb.AppendLine("struct TurretData { bool usable; bool large_turret; float damage_scale; float reload_duration_override; };");
            sb.AppendLine("struct AttackData { float deploy_delay; float repeat_delay; float animation_delay; };");
            sb.AppendLine();
            sb.AppendLine("struct NpcWeaponData");
            sb.AppendLine("{");
            sb.AppendLine("    float effective_range;");
            sb.AppendLine("    float damage_scale;");
            sb.AppendLine("    float attack_length_min;");
            sb.AppendLine("    float attack_length_max;");
            sb.AppendLine("    float attack_spacing;");
            sb.AppendLine("    float aim_sway_offset;");
            sb.AppendLine("    float aim_cone;");
            sb.AppendLine("    bool only_in_range;");
            sb.AppendLine("    float close_range_addition;");
            sb.AppendLine("    float medium_range_addition;");
            sb.AppendLine("    float long_range_addition;");
            sb.AppendLine("    bool can_use_at_medium_range;");
            sb.AppendLine("    bool can_use_at_long_range;");
            sb.AppendLine("};");
            sb.AppendLine();
            sb.AppendLine("struct HeldData");
            sb.AppendLine("{");
            sb.AppendLine("    bool can_use_with_shield;");
            sb.AppendLine("    bool is_building_tool;");
            sb.AppendLine("    float hostility_score;");
            sb.AppendLine("    Vec3 first_person_arm_offset;");
            sb.AppendLine("    Vec3 first_person_arm_rotation;");
            sb.AppendLine("    float first_person_rotation_strength;");
            sb.AppendLine("};");
            sb.AppendLine();
            sb.AppendLine("struct WeaponData");
            sb.AppendLine("{");
            sb.AppendLine("    const char* name;");
            sb.AppendLine("    const char* alias;");
            sb.AppendLine("    const char* prefab_path;");
            sb.AppendLine("    std::uint64_t hash;");
            sb.AppendLine("    float damage_scale;");
            sb.AppendLine("    float distance_scale;");
            sb.AppendLine("    float projectile_velocity_scale;");
            sb.AppendLine("    bool automatic;");
            sb.AppendLine("    float noise_radius;");
            sb.AppendLine("    float aim_sway;");
            sb.AppendLine("    float aim_sway_speed;");
            sb.AppendLine("    bool has_ads;");
            sb.AppendLine("    bool can_change_fire_modes;");
            sb.AppendLine("    bool default_on;");
            sb.AppendLine("    bool manual_cycle;");
            sb.AppendLine("    bool no_aiming_while_cycling;");
            sb.AppendLine("    float reset_duration;");
            sb.AppendLine("    int magazine_capacity;");
            sb.AppendLine("    bool wants_recoil_comp;");
            sb.AppendLine("    float recoil_comp_delay_override;");
            sb.AppendLine("    bool no_headshots;");
            sb.AppendLine("    RecoilData recoil;");
            sb.AppendLine("    AimConeData aimcone;");
            sb.AppendLine("    ReloadData reload;");
            sb.AppendLine("    BurstData burst;");
            sb.AppendLine("    TurretData turret;");
            sb.AppendLine("    AttackData attack;");
            sb.AppendLine("    NpcWeaponData npc;");
            sb.AppendLine("    HeldData held;");
            sb.AppendLine("};");
            sb.AppendLine("} // namespace RustData");
            sb.AppendLine();
            sb.AppendLine("namespace RustData");
            sb.AppendLine("{");
            sb.AppendLine("namespace Weapons");
            sb.AppendLine("{");
            sb.AppendLine();
            sb.AppendLine("inline constexpr std::size_t kCount = " + job.Weapons.Count + ";");
            sb.AppendLine("inline constexpr WeaponData kData[kCount == 0 ? 1 : kCount] =");
            sb.AppendLine("{");

            for (int i = 0; i < job.Weapons.Count; i++)
            {
                AppendWeapon(sb, job.Weapons[i], i + 1 < job.Weapons.Count);
            }

            sb.AppendLine("};");
            sb.AppendLine();
            sb.AppendLine("inline const WeaponData* GetByName(const char* name) noexcept");
            sb.AppendLine("{");
            sb.AppendLine("    if (!name) return nullptr;");
            sb.AppendLine("    for (std::size_t i = 0; i < kCount; ++i)");
            sb.AppendLine("    {");
            sb.AppendLine("        if (std::strcmp(kData[i].name, name) == 0 || std::strcmp(kData[i].alias, name) == 0)");
            sb.AppendLine("            return &kData[i];");
            sb.AppendLine("    }");
            sb.AppendLine("    return nullptr;");
            sb.AppendLine("}");
            sb.AppendLine();
            AppendHashLookup(sb, "WeaponData", job.Weapons.Select(x => new HashEntry(x.hash, x.name)).ToList());
            sb.AppendLine("} // namespace Weapons");
            sb.AppendLine("} // namespace RustData");
            sb.AppendLine();
            sb.AppendLine("#endif // RUST_DATA_WEAPON_DATA_HPP");
            return sb.ToString();
        }

        private static void AppendWeapon(StringBuilder sb, WeaponRecord x, bool comma)
        {
            sb.AppendLine("    // " + x.prefab_path);
            sb.AppendLine("    {");
            sb.AppendLine(string.Format(
                Invariant,
                "        \"{0}\", \"{1}\", \"{2}\", {3}ULL,",
                EscapeCpp(x.name),
                EscapeCpp(x.alias),
                EscapeCpp(x.prefab_path),
                x.hash));
            sb.AppendLine("        " + F(x.damage_scale) + ", " + F(x.distance_scale) + ", " +
                          F(x.projectile_velocity_scale) + ", " + B(x.automatic) + ",");
            sb.AppendLine("        " + F(x.noise_radius) + ", " + F(x.aim_sway) + ", " +
                          F(x.aim_sway_speed) + ",");
            sb.AppendLine("        " + B(x.has_ads) + ", " + B(x.can_change_fire_modes) + ", " +
                          B(x.default_on) + ", " + B(x.manual_cycle) + ", " +
                          B(x.no_aiming_while_cycling) + ",");
            sb.AppendLine("        " + F(x.reset_duration) + ", " + x.magazine_capacity + ", " +
                          B(x.wants_recoil_comp) + ", " + F(x.recoil_comp_delay_override) + ", " +
                          B(x.no_headshots) + ",");
            sb.AppendLine("        { " +
                          F(x.recoil.yaw_min) + ", " + F(x.recoil.yaw_max) + ", " +
                          F(x.recoil.pitch_min) + ", " + F(x.recoil.pitch_max) + ", " +
                          F(x.recoil.time_to_take_min) + ", " + F(x.recoil.time_to_take_max) + ", " +
                          F(x.recoil.ads_scale) + ", " + F(x.recoil.movement_penalty) + ", " +
                          F(x.recoil.clamp_pitch) + ", " + x.recoil.shots_until_max + ", " +
                          B(x.recoil.use_curves) + ", " + B(x.recoil.curves_as_scalar) + ", " +
                          F(x.recoil.max_recoil_radius) + ", " +
                          B(x.recoil.override_aimcone_with_curve) + ", " +
                          F(x.recoil.aimcone_curve_scale) + ", " +
                          F(x.recoil.ammo_aimcone_scale_multi_projectile) + ", " +
                          F(x.recoil.ammo_aimcone_scale_single_projectile) + " },");
            sb.AppendLine("        { " +
                          F(x.aimcone.aim_cone) + ", " + F(x.aimcone.hip_aim_cone) + ", " +
                          F(x.aimcone.penalty_per_shot) + ", " + F(x.aimcone.penalty_max) + ", " +
                          F(x.aimcone.penalty_recover_time) + ", " +
                          F(x.aimcone.penalty_recover_delay) + ", " +
                          F(x.aimcone.stance_penalty_scale) + " },");
            sb.AppendLine("        { " +
                          F(x.reload.time) + ", " + F(x.reload.start_duration) + ", " +
                          F(x.reload.fraction_duration) + ", " + F(x.reload.end_duration) + ", " +
                          B(x.reload.fractional) + ", " + B(x.reload.can_unload_ammo) + " },");
            sb.AppendLine("        { " + B(x.burst.enabled) + ", " + F(x.burst.recoil_scale) + ", " +
                          F(x.burst.fire_rate_scale) + ", " + F(x.burst.aim_cone_scale) + " },");
            sb.AppendLine("        { " + B(x.turret.usable) + ", " + B(x.turret.large_turret) + ", " +
                          F(x.turret.damage_scale) + ", " + F(x.turret.reload_duration_override) + " },");
            sb.AppendLine("        { " + F(x.attack.deploy_delay) + ", " + F(x.attack.repeat_delay) + ", " +
                          F(x.attack.animation_delay) + " },");
            sb.AppendLine("        { " +
                          F(x.npc.effective_range) + ", " + F(x.npc.damage_scale) + ", " +
                          F(x.npc.attack_length_min) + ", " + F(x.npc.attack_length_max) + ", " +
                          F(x.npc.attack_spacing) + ", " + F(x.npc.aim_sway_offset) + ", " +
                          F(x.npc.aim_cone) + ", " + B(x.npc.only_in_range) + ", " +
                          F(x.npc.close_range_addition) + ", " + F(x.npc.medium_range_addition) + ", " +
                          F(x.npc.long_range_addition) + ", " + B(x.npc.can_use_at_medium_range) + ", " +
                          B(x.npc.can_use_at_long_range) + " },");
            sb.AppendLine("        { " +
                          B(x.held.can_use_with_shield) + ", " + B(x.held.is_building_tool) + ", " +
                          F(x.held.hostility_score) + ", " + V3(x.held.first_person_arm_offset) + ", " +
                          V3(x.held.first_person_arm_rotation) + ", " +
                          F(x.held.first_person_rotation_strength) + " }");
            sb.AppendLine(comma ? "    }," : "    }");
        }

        private static string BuildProjectileHeader(DumpJob job)
        {
            StringBuilder sb = NewHeader("Rust Projectile Data", job.GeneratedUtc, job.TargetBuild, job.Projectiles.Count);
            sb.AppendLine("#pragma once");
            sb.AppendLine("#ifndef RUST_DATA_PROJECTILE_DATA_HPP");
            sb.AppendLine("#define RUST_DATA_PROJECTILE_DATA_HPP");
            sb.AppendLine();
            sb.AppendLine("#include <cstddef>");
            sb.AppendLine("#include <cstdint>");
            sb.AppendLine("#include <cstring>");
            sb.AppendLine("#include <limits>");
            sb.AppendLine();
            sb.AppendLine("namespace RustData");
            sb.AppendLine("{");
            sb.AppendLine("struct ProjectileVec2 { float x; float y; };");
            sb.AppendLine("struct ProjectileVec3 { float x; float y; float z; };");
            sb.AppendLine("struct DamageTypeData { const char* type; float amount; };");
            sb.AppendLine("inline constexpr std::size_t kProjectileMaxDamageTypes = " +
                          MaxProjectileDamageTypes + ";");
            sb.AppendLine("struct ProjectileData");
            sb.AppendLine("{");
            sb.AppendLine("    const char* name;");
            sb.AppendLine("    const char* prefab_path;");
            sb.AppendLine("    std::uint64_t hash;");
            sb.AppendLine("    ProjectileVec3 initial_velocity;");
            sb.AppendLine("    float drag;");
            sb.AppendLine("    float gravity_modifier;");
            sb.AppendLine("    float thickness;");
            sb.AppendLine("    float initial_distance;");
            sb.AppendLine("    ProjectileVec3 initial_orientation;");
            sb.AppendLine("    float penetration_power;");
            sb.AppendLine("    float ricochet_chance;");
            sb.AppendLine("    float stick_probability;");
            sb.AppendLine("    float break_probability;");
            sb.AppendLine("    float condition_loss;");
            sb.AppendLine("    float water_integrity_loss;");
            sb.AppendLine("    ProjectileVec2 damage_distances;");
            sb.AppendLine("    ProjectileVec2 damage_multipliers;");
            sb.AppendLine("    DamageTypeData damage_types[kProjectileMaxDamageTypes];");
            sb.AppendLine("    std::uint8_t damage_type_count;");
            sb.AppendLine("    bool remain_in_world;");
            sb.AppendLine("    bool can_refract;");
            sb.AppendLine("    bool penetrates_vehicles;");
            sb.AppendLine("    bool create_decals;");
            sb.AppendLine("};");
            sb.AppendLine("} // namespace RustData");
            sb.AppendLine();
            sb.AppendLine("namespace RustData");
            sb.AppendLine("{");
            sb.AppendLine("namespace Projectiles");
            sb.AppendLine("{");
            sb.AppendLine();
            sb.AppendLine("inline constexpr std::size_t kCount = " + job.Projectiles.Count + ";");
            sb.AppendLine("inline constexpr ProjectileData kData[kCount == 0 ? 1 : kCount] =");
            sb.AppendLine("{");

            for (int i = 0; i < job.Projectiles.Count; i++)
            {
                AppendProjectile(sb, job.Projectiles[i], i + 1 < job.Projectiles.Count);
            }

            sb.AppendLine("};");
            sb.AppendLine();
            sb.AppendLine("inline const ProjectileData* GetByName(const char* name) noexcept");
            sb.AppendLine("{");
            sb.AppendLine("    if (!name) return nullptr;");
            sb.AppendLine("    for (std::size_t i = 0; i < kCount; ++i)");
            sb.AppendLine("        if (std::strcmp(kData[i].name, name) == 0) return &kData[i];");
            sb.AppendLine("    return nullptr;");
            sb.AppendLine("}");
            sb.AppendLine();
            AppendHashLookup(
                sb,
                "ProjectileData",
                job.Projectiles.Select(x => new HashEntry(x.hash, x.name)).ToList());
            sb.AppendLine("} // namespace Projectiles");
            sb.AppendLine("} // namespace RustData");
            sb.AppendLine();
            sb.AppendLine("#endif // RUST_DATA_PROJECTILE_DATA_HPP");
            return sb.ToString();
        }

        private static void AppendProjectile(StringBuilder sb, ProjectileRecord x, bool comma)
        {
            sb.AppendLine("    // " + x.prefab_path);
            sb.AppendLine("    {");
            sb.AppendLine(string.Format(
                Invariant,
                "        \"{0}\", \"{1}\", {2}ULL,",
                EscapeCpp(x.name),
                EscapeCpp(x.prefab_path),
                x.hash));
            sb.AppendLine("        " + V3(x.initial_velocity) + ", " + F(x.drag) + ", " +
                          F(x.gravity_modifier) + ", " + F(x.thickness) + ",");
            sb.AppendLine("        " + F(x.initial_distance) + ", " + V3(x.initial_orientation) + ",");
            sb.AppendLine("        " + F(x.penetration_power) + ", " + F(x.ricochet_chance) + ", " +
                          F(x.stick_probability) + ", " + F(x.break_probability) + ",");
            sb.AppendLine("        " + F(x.condition_loss) + ", " + F(x.water_integrity_loss) + ",");
            sb.AppendLine("        " + V2(x.damage_distances) + ", " + V2(x.damage_multipliers) + ",");
            sb.AppendLine("        {");

            for (int i = 0; i < MaxProjectileDamageTypes; i++)
            {
                if (i < x.damage_types.Count)
                {
                    DamageTypeRecord damage = x.damage_types[i];
                    sb.AppendLine("            { \"" + EscapeCpp(damage.type) + "\", " +
                                  F(damage.amount) + " },");
                }
                else
                {
                    sb.AppendLine("            { \"\", 0.0f },");
                }
            }

            sb.AppendLine("        },");
            sb.AppendLine("        " + x.damage_types.Count + ", " + B(x.remain_in_world) + ", " +
                          B(x.can_refract) + ", " + B(x.penetrates_vehicles) + ", " +
                          B(x.create_decals));
            sb.AppendLine(comma ? "    }," : "    }");
        }

        private static string BuildHeldHeader(DumpJob job)
        {
            StringBuilder sb = NewHeader("Rust Held Item Type Map", job.GeneratedUtc, job.TargetBuild, job.HeldItems.Count);
            sb.AppendLine("#pragma once");
            sb.AppendLine("#ifndef RUST_DATA_ITEM_TYPE_MAP_HPP");
            sb.AppendLine("#define RUST_DATA_ITEM_TYPE_MAP_HPP");
            sb.AppendLine();
            sb.AppendLine("#include <cstddef>");
            sb.AppendLine("#include <cstring>");
            sb.AppendLine();
            sb.AppendLine("namespace RustData");
            sb.AppendLine("{");
            sb.AppendLine("namespace ItemTypes");
            sb.AppendLine("{");
            sb.AppendLine();
            sb.AppendLine("struct ItemTypeEntry");
            sb.AppendLine("{");
            sb.AppendLine("    const char* name;");
            sb.AppendLine("    const char* prefab_path;");
            sb.AppendLine("    const char* concrete_type;");
            sb.AppendLine("    std::size_t first_type;");
            sb.AppendLine("    std::size_t type_count;");
            sb.AppendLine("};");
            sb.AppendLine();

            int totalTypes = job.HeldItems.Sum(x => x.type_chain.Count);
            sb.AppendLine("inline constexpr std::size_t kTypeCount = " + totalTypes + ";");
            sb.AppendLine("inline constexpr const char* kTypeNames[kTypeCount == 0 ? 1 : kTypeCount] =");
            sb.AppendLine("{");

            foreach (HeldItemRecord item in job.HeldItems)
            {
                foreach (string typeName in item.type_chain)
                {
                    sb.AppendLine("    \"" + EscapeCpp(typeName) + "\",");
                }
            }

            sb.AppendLine("};");
            sb.AppendLine();
            sb.AppendLine("inline constexpr std::size_t kCount = " + job.HeldItems.Count + ";");
            sb.AppendLine("inline constexpr ItemTypeEntry kData[kCount == 0 ? 1 : kCount] =");
            sb.AppendLine("{");

            int firstType = 0;
            for (int i = 0; i < job.HeldItems.Count; i++)
            {
                HeldItemRecord item = job.HeldItems[i];
                string suffix = i + 1 < job.HeldItems.Count ? "," : string.Empty;
                sb.AppendLine(
                    "    { \"" + EscapeCpp(item.name) +
                    "\", \"" + EscapeCpp(item.prefab_path) +
                    "\", \"" + EscapeCpp(item.concrete_type) +
                    "\", " + firstType +
                    ", " + item.type_chain.Count +
                    " }" + suffix);
                firstType += item.type_chain.Count;
            }

            sb.AppendLine("};");
            sb.AppendLine();
            sb.AppendLine("inline const ItemTypeEntry* Get(const char* name) noexcept");
            sb.AppendLine("{");
            sb.AppendLine("    if (!name) return nullptr;");
            sb.AppendLine("    for (std::size_t i = 0; i < kCount; ++i)");
            sb.AppendLine("        if (std::strcmp(kData[i].name, name) == 0) return &kData[i];");
            sb.AppendLine("    return nullptr;");
            sb.AppendLine("}");
            sb.AppendLine();
            sb.AppendLine("inline const char* GetConcreteType(const char* name) noexcept");
            sb.AppendLine("{");
            sb.AppendLine("    const ItemTypeEntry* item = Get(name);");
            sb.AppendLine("    return item ? item->concrete_type : nullptr;");
            sb.AppendLine("}");
            sb.AppendLine();
            sb.AppendLine("inline const char* const* GetTypes(const char* name, std::size_t& count) noexcept");
            sb.AppendLine("{");
            sb.AppendLine("    const ItemTypeEntry* item = Get(name);");
            sb.AppendLine("    if (!item)");
            sb.AppendLine("    {");
            sb.AppendLine("        count = 0;");
            sb.AppendLine("        return nullptr;");
            sb.AppendLine("    }");
            sb.AppendLine("    count = item->type_count;");
            sb.AppendLine("    return &kTypeNames[item->first_type];");
            sb.AppendLine("}");
            sb.AppendLine();
            sb.AppendLine("inline bool HasType(const char* name, const char* type) noexcept");
            sb.AppendLine("{");
            sb.AppendLine("    if (!type) return false;");
            sb.AppendLine("    const ItemTypeEntry* item = Get(name);");
            sb.AppendLine("    if (!item) return false;");
            sb.AppendLine("    for (std::size_t i = 0; i < item->type_count; ++i)");
            sb.AppendLine("        if (std::strcmp(kTypeNames[item->first_type + i], type) == 0) return true;");
            sb.AppendLine("    return false;");
            sb.AppendLine("}");
            sb.AppendLine("} // namespace ItemTypes");
            sb.AppendLine("} // namespace RustData");
            sb.AppendLine();
            sb.AppendLine("#endif // RUST_DATA_ITEM_TYPE_MAP_HPP");
            return sb.ToString();
        }

        private static StringBuilder NewHeader(
            string title,
            DateTime generatedUtc,
            string targetBuild,
            int count)
        {
            StringBuilder sb = new StringBuilder(1024 * 64);
            sb.AppendLine("//");
            sb.AppendLine("// Auto-generated " + title);
            sb.AppendLine("// Generated: " + generatedUtc.ToString("yyyy-MM-dd HH:mm:ss", Invariant) + " UTC");
            sb.AppendLine("// Target: " + targetBuild);
            sb.AppendLine("// Total entries: " + count);
            sb.AppendLine("// Generator: RustDataExporter");
            sb.AppendLine("//");
            sb.AppendLine("// This file is generated from server-side Rust prefabs/components.");
            sb.AppendLine("// Do not edit by hand.");
            sb.AppendLine("//");
            sb.AppendLine();
            return sb;
        }

        private static void AppendHashLookup(StringBuilder sb, string typeName, List<HashEntry> hashes)
        {
            sb.AppendLine("inline const " + typeName + "* GetByHash(std::uint64_t hash) noexcept");
            sb.AppendLine("{");
            sb.AppendLine("    switch (hash)");
            sb.AppendLine("    {");

            HashSet<uint> emitted = new HashSet<uint>();
            for (int i = 0; i < hashes.Count; i++)
            {
                HashEntry entry = hashes[i];
                if (!emitted.Add(entry.Hash))
                {
                    continue;
                }

                sb.AppendLine("    case " + entry.Hash.ToString(Invariant) + "ULL: return &kData[" + i +
                              "]; // " + entry.Name);
            }

            sb.AppendLine("    default: return nullptr;");
            sb.AppendLine("    }");
            sb.AppendLine("}");
        }

        private static string NormalizePath(string path)
        {
            return string.IsNullOrEmpty(path)
                ? string.Empty
                : path.Replace('\\', '/').Trim().ToLowerInvariant();
        }

        private static string MakeIdentifier(string value)
        {
            if (string.IsNullOrEmpty(value))
            {
                return "_";
            }

            StringBuilder sb = new StringBuilder(value.Length + 1);
            foreach (char c in value)
            {
                sb.Append(char.IsLetterOrDigit(c) || c == '_' ? c : '_');
            }

            if (sb.Length == 0 || char.IsDigit(sb[0]))
            {
                sb.Insert(0, '_');
            }

            return sb.ToString();
        }

        private static string EscapeCpp(string value)
        {
            if (value == null)
            {
                return string.Empty;
            }

            return value
                .Replace("\\", "\\\\")
                .Replace("\"", "\\\"")
                .Replace("\r", "\\r")
                .Replace("\n", "\\n")
                .Replace("\t", "\\t");
        }

        private static string F(float value)
        {
            if (float.IsNaN(value))
            {
                return "std::numeric_limits<float>::quiet_NaN()";
            }

            if (float.IsPositiveInfinity(value))
            {
                return "std::numeric_limits<float>::infinity()";
            }

            if (float.IsNegativeInfinity(value))
            {
                return "-std::numeric_limits<float>::infinity()";
            }

            return value.ToString("0.0########", Invariant) + "f";
        }

        private static string B(bool value)
        {
            return value ? "true" : "false";
        }

        private static string V2(Vec2Record value)
        {
            return "{ " + F(value.x) + ", " + F(value.y) + " }";
        }

        private static string V3(Vec3Record value)
        {
            return "{ " + F(value.x) + ", " + F(value.y) + ", " + F(value.z) + " }";
        }

        private sealed class DumpJob
        {
            public string Target;
            public string TargetBuild;
            public bool IncludeJson;
            public DateTime GeneratedUtc;
            public GameManifest.PrefabProperties[] Prefabs;
            public int PrefabIndex;
            public int NextProgressLog = 2000;
            public int ErrorCount;
            public List<string> Errors = new List<string>();
            public Dictionary<string, SortedSet<string>> ItemNamesByPrefab =
                new Dictionary<string, SortedSet<string>>(StringComparer.OrdinalIgnoreCase);
            public Dictionary<string, ItemDefinition> ItemDefinitionsByPrefab =
                new Dictionary<string, ItemDefinition>(StringComparer.OrdinalIgnoreCase);
            public Dictionary<string, List<AmmoSourceRecord>> AmmoByProjectilePrefab =
                new Dictionary<string, List<AmmoSourceRecord>>(StringComparer.OrdinalIgnoreCase);
            public HashSet<string> WeaponKeys = new HashSet<string>(StringComparer.Ordinal);
            public HashSet<uint> ProjectileHashes = new HashSet<uint>();
            public List<ItemRecord> Items = new List<ItemRecord>();
            public List<WeaponRecord> Weapons = new List<WeaponRecord>();
            public List<ProjectileRecord> Projectiles = new List<ProjectileRecord>();
            public List<HeldItemRecord> HeldItems = new List<HeldItemRecord>();
        }

        private sealed class JsonEnvelope<T>
        {
            public string generated_utc;
            public string target_build;
            public int count;
            public List<T> data;
        }

        private sealed class HashEntry
        {
            public readonly uint Hash;
            public readonly string Name;

            public HashEntry(uint hash, string name)
            {
                Hash = hash;
                Name = name;
            }
        }

        private sealed class Vec2Record
        {
            public float x;
            public float y;
        }

        private sealed class Vec3Record
        {
            public float x;
            public float y;
            public float z;

            public static Vec3Record From(Vector3 value)
            {
                return new Vec3Record { x = value.x, y = value.y, z = value.z };
            }
        }

        private sealed class PhraseRecord
        {
            public string token;
            public string english;
        }

        private sealed class ItemConditionRecord
        {
            public bool enabled;
            public float max;
            public bool repairable;
            public bool maintain_max_condition;
            public bool oven_condition;
            public float found_fraction_min;
            public float found_fraction_max;
            public bool hide_condition_bar;
            public string break_effect_prefab;
        }

        private sealed class ItemRecord
        {
            public int item_id;
            public string shortname;
            public string definition_name;
            public string definition_type;
            public PhraseRecord display_name;
            public PhraseRecord display_description;
            public string category;
            public string selection_panel;
            public string era;
            public string era_restrictions;
            public string loot_distribution_type;
            public string rarity;
            public string despawn_rarity;
            public string item_type;
            public string amount_type;
            public string occupy_slots;
            public long occupy_slots_value;
            public int max_draggable;
            public int stackable;
            public int crafting_stackable;
            public int volume;
            public float base_radioactivity;
            public float apartment_tax_per_stack;
            public bool quick_despawn;
            public bool block_stealing_in_safe_zone;
            public bool allow_burying;
            public string tutorial_allowance;
            public bool supports_stackable_ownership;
            public bool spawn_as_blueprint;
            public bool hidden;
            public string flags;
            public long flags_value;
            public bool hide_selected_panel;
            public bool supports_accessories;
            public string traits;
            public long traits_value;
            public bool vehicle_item;
            public string vehicle_category;
            public bool is_holdable;
            public bool is_usable;
            public bool is_wearable;
            public bool has_skins;
            public int built_in_skin_count;
            public int workshop_skin_count;
            public string parent_shortname;
            public string redirect_shortname;
            public string redirect_vending_behaviour;
            public string world_model_prefab;
            public string held_entity_prefab;
            public uint held_entity_prefab_id;
            public bool treat_as_component_for_repairs;
            public bool align_world_model_on_drop;
            public Vec3Record world_model_drop_offset;
            public bool adjust_center_of_mass_on_drop;
            public Vec3Record drop_center_of_mass;
            public ItemConditionRecord condition;
            public List<string> item_mod_types;
            public List<string> children;
        }

        private sealed class DamageTypeRecord
        {
            public string type;
            public float amount;
        }

        private sealed class AmmoSourceRecord
        {
            public string item_shortname;
            public string ammo_type;
            public string ammo_sub_type;
            public int num_projectiles;
            public float projectile_spread;
            public float projectile_velocity;
            public float projectile_velocity_spread;
            public float min_velocity;
            public float average_velocity;
            public float max_velocity;
            public float barrel_condition_loss;
            public string category;
            public uint skinned_weapon_prefab_id;
        }

        private sealed class RecoilRecord
        {
            public float yaw_min;
            public float yaw_max;
            public float pitch_min;
            public float pitch_max;
            public float time_to_take_min;
            public float time_to_take_max;
            public float ads_scale;
            public float movement_penalty;
            public float clamp_pitch;
            public int shots_until_max;
            public bool use_curves;
            public bool curves_as_scalar;
            public float max_recoil_radius;
            public bool override_aimcone_with_curve;
            public float aimcone_curve_scale;
            public float ammo_aimcone_scale_multi_projectile;
            public float ammo_aimcone_scale_single_projectile;
        }

        private sealed class AimConeRecord
        {
            public float aim_cone;
            public float hip_aim_cone;
            public float penalty_per_shot;
            public float penalty_max;
            public float penalty_recover_time;
            public float penalty_recover_delay;
            public float stance_penalty_scale;
        }

        private sealed class ReloadRecord
        {
            public float time;
            public float start_duration;
            public float fraction_duration;
            public float end_duration;
            public bool fractional;
            public bool can_unload_ammo;
        }

        private sealed class BurstRecord
        {
            public bool enabled;
            public float recoil_scale;
            public float fire_rate_scale;
            public float aim_cone_scale;
        }

        private sealed class TurretRecord
        {
            public bool usable;
            public bool large_turret;
            public float damage_scale;
            public float reload_duration_override;
        }

        private sealed class AttackRecord
        {
            public float deploy_delay;
            public float repeat_delay;
            public float animation_delay;
        }

        private sealed class NpcWeaponRecord
        {
            public float effective_range;
            public float damage_scale;
            public float attack_length_min;
            public float attack_length_max;
            public float attack_spacing;
            public float aim_sway_offset;
            public float aim_cone;
            public bool only_in_range;
            public float close_range_addition;
            public float medium_range_addition;
            public float long_range_addition;
            public bool can_use_at_medium_range;
            public bool can_use_at_long_range;
        }

        private sealed class HeldRecord
        {
            public bool can_use_with_shield;
            public bool is_building_tool;
            public float hostility_score;
            public Vec3Record first_person_arm_offset;
            public Vec3Record first_person_arm_rotation;
            public float first_person_rotation_strength;
        }

        private sealed class WeaponRecord
        {
            public string name;
            public string alias;
            public string prefab_path;
            public uint hash;
            public float damage_scale;
            public float distance_scale;
            public float projectile_velocity_scale;
            public bool automatic;
            public float noise_radius;
            public float aim_sway;
            public float aim_sway_speed;
            public bool has_ads;
            public bool can_change_fire_modes;
            public bool default_on;
            public bool manual_cycle;
            public bool no_aiming_while_cycling;
            public float reset_duration;
            public int magazine_capacity;
            public bool wants_recoil_comp;
            public float recoil_comp_delay_override;
            public bool no_headshots;
            public RecoilRecord recoil;
            public AimConeRecord aimcone;
            public ReloadRecord reload;
            public BurstRecord burst;
            public TurretRecord turret;
            public AttackRecord attack;
            public NpcWeaponRecord npc;
            public HeldRecord held;
        }

        private sealed class ProjectileRecord
        {
            public string name;
            public string prefab_path;
            public uint hash;
            public Vec3Record initial_velocity;
            public float drag;
            public float gravity_modifier;
            public float thickness;
            public float initial_distance;
            public Vec3Record initial_orientation;
            public float penetration_power;
            public float ricochet_chance;
            public float stick_probability;
            public float break_probability;
            public float condition_loss;
            public float water_integrity_loss;
            public Vec2Record damage_distances;
            public Vec2Record damage_multipliers;
            public List<DamageTypeRecord> damage_types = new List<DamageTypeRecord>();
            public List<AmmoSourceRecord> ammo_sources = new List<AmmoSourceRecord>();
            public bool remain_in_world;
            public bool can_refract;
            public bool penetrates_vehicles;
            public bool create_decals;
        }

        private sealed class HeldItemRecord
        {
            public string name;
            public string concrete_type;
            public List<string> type_chain;
            public string prefab_path;
        }

        private sealed class HeldTypeInfo
        {
            public string ConcreteType;
            public List<string> TypeChain;
        }
    }
}
