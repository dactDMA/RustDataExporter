//
// Auto-generated Rust TimedExplosive Data
// Generated: 2026-08-06 18:36:45 UTC
// Target: Protocol 2632.287.1 / Changeset 160450
// Total entries: 45
// Generator: RustDataExporter
//
// This file is generated from server-side Rust prefabs/components.
// Do not edit by hand.
//

#pragma once
#ifndef RUST_DATA_TIMED_EXPLOSIVE_DATA_HPP
#define RUST_DATA_TIMED_EXPLOSIVE_DATA_HPP

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <limits>

namespace RustData
{
namespace TimedExplosives
{

struct Vec2 { float x; float y; };
struct Vec3 { float x; float y; float z; };
struct DamageData { const char* type; float amount; };
struct ResourceRefData { const char* path; std::uint32_t id; bool is_valid; };
struct ExtraFieldData { const char* name; const char* declaring_type; const char* value_type; const char* value; };
struct RigidbodyData
{
    bool present; float mass; float drag; float angular_drag;
    bool use_gravity; bool is_kinematic; const char* collision_detection_mode;
};

struct TimedExplosiveData
{
    const char* name;
    const char* prefab_path;
    std::uint32_t hash;
    const char* concrete_type;
    std::size_t first_type;
    std::size_t type_count;
    float timer_min;
    float timer_max;
    float min_explosion_radius;
    float explosion_radius;
    bool explode_on_contact;
    bool can_stick;
    bool force_run_clipping_checks;
    bool only_damage_parent;
    bool ignore_ai;
    bool blind_ai;
    float ai_blind_duration;
    float ai_blind_range;
    const char* explosion_offset_mode;
    Vec3 explosion_effect_offset;
    bool explosion_matches_normal;
    bool explosion_uses_forward;
    bool explosion_matches_orientation;
    bool explosion_matches_velocity;
    bool explosion_matches_inverse_velocity;
    ResourceRefData explosion_effect;
    ResourceRefData underwater_explosion_effect;
    ResourceRefData stick_effect;
    ResourceRefData bounce_effect;
    ResourceRefData watersurface_explosion_effect;
    float underwater_explosion_depth;
    Vec2 watersurface_explosion_depth;
    bool water_causes_explosion;
    bool always_run_water_check;
    int vibration_level;
    std::size_t first_damage;
    std::size_t damage_count;
    std::size_t first_player_damage;
    std::size_t player_damage_count;
    bool splash_wallpaper_through_walls;
    RigidbodyData rigidbody;
    std::size_t first_extra_field;
    std::size_t extra_field_count;
};

inline constexpr std::size_t kTypeNamesCount = 112;
inline constexpr const char* kTypeNames[kTypeNamesCount == 0 ? 1 : kTypeNamesCount] =
{
    "MLRSRocket",
    "TimedExplosive",
    "BaseEntity",
    "TimedExplosive",
    "BaseEntity",
    "BeeGrenade",
    "TimedExplosive",
    "BaseEntity",
    "TimedExplosive",
    "BaseEntity",
    "TimedExplosive",
    "BaseEntity",
    "FlameExplosive",
    "TimedExplosive",
    "BaseEntity",
    "FlameExplosive",
    "TimedExplosive",
    "BaseEntity",
    "TimedExplosive",
    "BaseEntity",
    "TimedExplosive",
    "BaseEntity",
    "TimedExplosive",
    "BaseEntity",
    "SmokeGrenade",
    "TimedExplosive",
    "BaseEntity",
    "TimedExplosive",
    "BaseEntity",
    "TimedExplosive",
    "BaseEntity",
    "FlameExplosive",
    "TimedExplosive",
    "BaseEntity",
    "FlameExplosive",
    "TimedExplosive",
    "BaseEntity",
    "TimedExplosive",
    "BaseEntity",
    "TimedExplosive",
    "BaseEntity",
    "TimedExplosive",
    "BaseEntity",
    "TimedExplosive",
    "BaseEntity",
    "TimedExplosive",
    "BaseEntity",
    "TimedExplosive",
    "BaseEntity",
    "TimedExplosive",
    "BaseEntity",
    "TimedExplosive",
    "BaseEntity",
    "StringFirecracker",
    "TimedExplosive",
    "BaseEntity",
    "SeasonalTimedExplosive",
    "TimedExplosive",
    "BaseEntity",
    "SeasonalTimedExplosive",
    "TimedExplosive",
    "BaseEntity",
    "TimedExplosive",
    "BaseEntity",
    "TimedExplosive",
    "BaseEntity",
    "TimedExplosive",
    "BaseEntity",
    "FlameExplosive",
    "TimedExplosive",
    "BaseEntity",
    "TimedExplosive",
    "BaseEntity",
    "TimedExplosive",
    "BaseEntity",
    "RFTimedExplosive",
    "TimedExplosive",
    "BaseEntity",
    "RoadFlare",
    "TimedExplosive",
    "BaseEntity",
    "SmokeGrenade",
    "TimedExplosive",
    "BaseEntity",
    "SupplySignal",
    "TimedExplosive",
    "BaseEntity",
    "SurveyCharge",
    "TimedExplosive",
    "BaseEntity",
    "DudTimedExplosive",
    "TimedExplosive",
    "BaseEntity",
    "BeeGrenade",
    "TimedExplosive",
    "BaseEntity",
    "TimedExplosive",
    "BaseEntity",
    "Flashbang",
    "TimedExplosive",
    "BaseEntity",
    "FlameExplosive",
    "TimedExplosive",
    "BaseEntity",
    "DudTimedExplosive",
    "TimedExplosive",
    "BaseEntity",
    "TimedExplosive",
    "BaseEntity",
    "SmokeGrenade",
    "TimedExplosive",
    "BaseEntity",
};

inline constexpr std::size_t kDamageTypesCount = 76;
inline constexpr DamageData kDamageTypes[kDamageTypesCount == 0 ? 1 : kDamageTypesCount] =
{
    { "Explosion", 350.0f },
    { "Blunt", 75.0f },
    { "AntiVehicle", 75.0f },
    { "Blunt", 80.0f },
    { "AntiVehicle", 50.0f },
    { "Blunt", 20.0f },
    { "Explosion", 275.0f },
    { "Blunt", 75.0f },
    { "Explosion", 160.0f },
    { "Blunt", 75.0f },
    { "Heat", 50.0f },
    { "Heat", 50.0f },
    { "Blunt", 40.0f },
    { "AntiVehicle", 25.0f },
    { "Blunt", 20.0f },
    { "AntiVehicle", 12.0f },
    { "Explosion", 35.0f },
    { "Blunt", 55.0f },
    { "Explosion", 275.0f },
    { "Blunt", 75.0f },
    { "Explosion", 275.0f },
    { "Blunt", 75.0f },
    { "Heat", 50.0f },
    { "Heat", 50.0f },
    { "Explosion", 10.0f },
    { "Bullet", 20.0f },
    { "AntiVehicle", 500.0f },
    { "Explosion", 30.0f },
    { "Bullet", 150.0f },
    { "AntiVehicle", 300.0f },
    { "Explosion", 30.0f },
    { "Bullet", 150.0f },
    { "AntiVehicle", 300.0f },
    { "Poison", 5.0f },
    { "Explosion", 10.0f },
    { "AntiVehicle", 300.0f },
    { "Bullet", 120.0f },
    { "AntiVehicle", 50.0f },
    { "Bullet", 100.0f },
    { "Blunt", 100.0f },
    { "Cannon", 50.0f },
    { "Explosion", 60.0f },
    { "Blunt", 75.0f },
    { "AntiVehicle", 100.0f },
    { "Blunt", 75.0f },
    { "AntiVehicle", 50.0f },
    { "Arrow", 18.0f },
    { "Arrow", 20.0f },
    { "Blunt", 40.0f },
    { "Blunt", 175.0f },
    { "Explosion", 100.0f },
    { "Blunt", 75.0f },
    { "Explosion", 200.0f },
    { "Heat", 25.0f },
    { "AntiVehicle", 120.0f },
    { "Blunt", 35.0f },
    { "Poison", 5.0f },
    { "Explosion", 550.0f },
    { "Explosion", 8.0f },
    { "Blunt", 12.0f },
    { "Explosion", 15.0f },
    { "Blunt", 50.0f },
    { "Stab", 50.0f },
    { "Blunt", 10.0f },
    { "Slash", 10.0f },
    { "Blunt", 100.0f },
    { "AntiVehicle", 50.0f },
    { "Bullet", 75.0f },
    { "Blunt", 20.0f },
    { "Heat", 35.0f },
    { "Explosion", 75.0f },
    { "Blunt", 200.0f },
    { "Stab", 200.0f },
    { "Blunt", 100.0f },
    { "AntiVehicle", 50.0f },
    { "Bullet", 75.0f },
};

inline constexpr std::size_t kPlayerDamageCount = 18;
inline constexpr DamageData kPlayerDamage[kPlayerDamageCount == 0 ? 1 : kPlayerDamageCount] =
{
    { "Explosion", 325.0f },
    { "Explosion", 225.0f },
    { "Explosion", 90.0f },
    { "Explosion", 350.0f },
    { "Explosion", 350.0f },
    { "Explosion", 30.0f },
    { "Explosion", 180.0f },
    { "Explosion", 180.0f },
    { "Explosion", 130.0f },
    { "Explosion", 25.0f },
    { "Bullet", 100.0f },
    { "Explosion", 350.0f },
    { "Explosion", 250.0f },
    { "Explosion", 115.0f },
    { "Explosion", 175.0f },
    { "Explosion", 10.0f },
    { "Explosion", 400.0f },
    { "Explosion", 70.0f },
};

inline constexpr std::size_t kExtraFieldsCount = 114;
inline constexpr ExtraFieldData kExtraFields[kExtraFieldsCount == 0 ? 1 : kExtraFieldsCount] =
{
    { "explosionGroundFXPrefab", "MLRSRocket", "GameObjectRef", "assets/content/vehicles/mlrs/effects/pfx_mlrs_rocket_explosion_ground.prefab|1161374517" },
    { "launchBlastFXPrefab", "MLRSRocket", "GameObjectRef", "assets/content/vehicles/mlrs/effects/pfx_mlrs_backfire.prefab|1350996199" },
    { "mapMarkerPrefab", "MLRSRocket", "GameObjectRef", "assets/content/vehicles/mlrs/mlrsrocketmarker.prefab|187601267" },
    { "serverProjectile", "MLRSRocket", "ServerProjectile", "rocket_mlrs (MLRSServerProjectile)" },
    { "beeSwarmAmount", "BeeGrenade", "System.Int32", "3" },
    { "beeSwarmPrefab", "BeeGrenade", "GameObjectRef", "assets/prefabs/npc/beeswarm/beemasterswarm.prefab|3827650729" },
    { "spawnRadius", "BeeGrenade", "System.Single", "5" },
    { "blockCreateUnderwater", "FlameExplosive", "System.Boolean", "False" },
    { "createOnExplode", "FlameExplosive", "GameObjectRef", "assets/bundled/prefabs/fireball_catapult.prefab|1409563449" },
    { "forceUpForExplosion", "FlameExplosive", "System.Boolean", "False" },
    { "maxVelocity", "FlameExplosive", "System.Single", "6" },
    { "minVelocity", "FlameExplosive", "System.Single", "2" },
    { "numToCreate", "FlameExplosive", "System.Single", "4" },
    { "spreadAngle", "FlameExplosive", "System.Single", "90" },
    { "spreadCurve", "FlameExplosive", "UnityEngine.AnimationCurve", "UnityEngine.AnimationCurve" },
    { "velocityCurve", "FlameExplosive", "UnityEngine.AnimationCurve", "UnityEngine.AnimationCurve" },
    { "blockCreateUnderwater", "FlameExplosive", "System.Boolean", "False" },
    { "createOnExplode", "FlameExplosive", "GameObjectRef", "assets/bundled/prefabs/fireball_catapult.prefab|1409563449" },
    { "forceUpForExplosion", "FlameExplosive", "System.Boolean", "False" },
    { "maxVelocity", "FlameExplosive", "System.Single", "6" },
    { "minVelocity", "FlameExplosive", "System.Single", "2" },
    { "numToCreate", "FlameExplosive", "System.Single", "4" },
    { "spreadAngle", "FlameExplosive", "System.Single", "90" },
    { "spreadCurve", "FlameExplosive", "UnityEngine.AnimationCurve", "UnityEngine.AnimationCurve" },
    { "velocityCurve", "FlameExplosive", "UnityEngine.AnimationCurve", "UnityEngine.AnimationCurve" },
    { "fieldMax", "SmokeGrenade", "System.Single", "6" },
    { "fieldMin", "SmokeGrenade", "System.Single", "4" },
    { "igniteSound", "SmokeGrenade", "GameObjectRef", "assets/prefabs/tools/smoke grenade/effects/ignite.prefab|1277383634" },
    { "smokeDuration", "SmokeGrenade", "System.Single", "45" },
    { "smokeEffectPrefab", "SmokeGrenade", "GameObjectRef", "assets/prefabs/tools/smoke grenade/effects/smokegrenade_small.prefab|430600702" },
    { "soundLoop", "SmokeGrenade", "SoundPlayer", "" },
    { "blockCreateUnderwater", "FlameExplosive", "System.Boolean", "False" },
    { "createOnExplode", "FlameExplosive", "GameObjectRef", "assets/bundled/prefabs/fireball.prefab|3369311876" },
    { "forceUpForExplosion", "FlameExplosive", "System.Boolean", "False" },
    { "maxVelocity", "FlameExplosive", "System.Single", "6" },
    { "minVelocity", "FlameExplosive", "System.Single", "2" },
    { "numToCreate", "FlameExplosive", "System.Single", "10" },
    { "spreadAngle", "FlameExplosive", "System.Single", "90" },
    { "spreadCurve", "FlameExplosive", "UnityEngine.AnimationCurve", "UnityEngine.AnimationCurve" },
    { "velocityCurve", "FlameExplosive", "UnityEngine.AnimationCurve", "UnityEngine.AnimationCurve" },
    { "blockCreateUnderwater", "FlameExplosive", "System.Boolean", "False" },
    { "createOnExplode", "FlameExplosive", "GameObjectRef", "assets/bundled/prefabs/fireball.prefab|3369311876" },
    { "forceUpForExplosion", "FlameExplosive", "System.Boolean", "False" },
    { "maxVelocity", "FlameExplosive", "System.Single", "6" },
    { "minVelocity", "FlameExplosive", "System.Single", "2" },
    { "numToCreate", "FlameExplosive", "System.Single", "10" },
    { "spreadAngle", "FlameExplosive", "System.Single", "90" },
    { "spreadCurve", "FlameExplosive", "UnityEngine.AnimationCurve", "UnityEngine.AnimationCurve" },
    { "velocityCurve", "FlameExplosive", "UnityEngine.AnimationCurve", "UnityEngine.AnimationCurve" },
    { "clientFirecrackerTransform", "StringFirecracker", "UnityEngine.Transform", "" },
    { "clientMiddleBody", "StringFirecracker", "UnityEngine.Rigidbody", "" },
    { "clientParts", "StringFirecracker", "UnityEngine.Rigidbody[]", ";;;;;;;;;" },
    { "serverClientJoint", "StringFirecracker", "UnityEngine.SpringJoint", "" },
    { "serverRigidBody", "StringFirecracker", "UnityEngine.Rigidbody", "firecrackers.deployed (UnityEngine.Rigidbody)" },
    { "randomRenderer", "SeasonalTimedExplosive", "RandomRendererEnable", "" },
    { "randomRenderer", "SeasonalTimedExplosive", "RandomRendererEnable", "" },
    { "blockCreateUnderwater", "FlameExplosive", "System.Boolean", "True" },
    { "createOnExplode", "FlameExplosive", "GameObjectRef", "assets/bundled/prefabs/napalm.prefab|184893264" },
    { "forceUpForExplosion", "FlameExplosive", "System.Boolean", "True" },
    { "maxVelocity", "FlameExplosive", "System.Single", "7" },
    { "minVelocity", "FlameExplosive", "System.Single", "3" },
    { "numToCreate", "FlameExplosive", "System.Single", "3" },
    { "spreadAngle", "FlameExplosive", "System.Single", "120" },
    { "spreadCurve", "FlameExplosive", "UnityEngine.AnimationCurve", "UnityEngine.AnimationCurve" },
    { "velocityCurve", "FlameExplosive", "UnityEngine.AnimationCurve", "UnityEngine.AnimationCurve" },
    { "beepLoop", "RFTimedExplosive", "SoundPlayer", "" },
    { "minutesUntilDecayed", "RFTimedExplosive", "System.Single", "1440" },
    { "pickupDefinition", "RFTimedExplosive", "ItemDefinition", "explosive.timed.item (ItemDefinition)" },
    { "FlareLightEx", "RoadFlare", "LightEx", "" },
    { "fieldMax", "SmokeGrenade", "System.Single", "8" },
    { "fieldMin", "SmokeGrenade", "System.Single", "5" },
    { "igniteSound", "SmokeGrenade", "GameObjectRef", "assets/prefabs/tools/smoke grenade/effects/ignite.prefab|1277383634" },
    { "smokeDuration", "SmokeGrenade", "System.Single", "45" },
    { "smokeEffectPrefab", "SmokeGrenade", "GameObjectRef", "assets/prefabs/tools/smoke grenade/effects/smokegrenade.prefab|2143839482" },
    { "soundLoop", "SmokeGrenade", "SoundPlayer", "" },
    { "EntityToCreate", "SupplySignal", "GameObjectRef", "assets/prefabs/npc/cargo plane/cargo_plane.prefab|2383782438" },
    { "smokeEffectPrefab", "SupplySignal", "GameObjectRef", "assets/bundled/prefabs/fx/smoke_signal_full.prefab|2278592883" },
    { "craterPrefab", "SurveyCharge", "GameObjectRef", "assets/prefabs/tools/surveycharge/survey_crater.prefab|2955484243" },
    { "craterPrefab_Oil", "SurveyCharge", "GameObjectRef", "assets/prefabs/tools/surveycharge/survey_crater_oil.prefab|1917257452" },
    { "becomeDudInWater", "DudTimedExplosive", "System.Boolean", "True" },
    { "dudChance", "DudTimedExplosive", "System.Single", "0.15" },
    { "fizzleEffect", "DudTimedExplosive", "GameObjectRef", "assets/prefabs/weapons/beancan grenade/effects/fuse_extinguish_beancan.prefab|4026468358" },
    { "itemToGive", "DudTimedExplosive", "ItemDefinition", "grenade.beancan.item (ItemDefinition)" },
    { "wickSound", "DudTimedExplosive", "UnityEngine.AudioSource", "" },
    { "wickSpark", "DudTimedExplosive", "UnityEngine.GameObject", "" },
    { "beeSwarmAmount", "BeeGrenade", "System.Int32", "1" },
    { "beeSwarmPrefab", "BeeGrenade", "GameObjectRef", "assets/prefabs/npc/beeswarm/beemasterswarm.prefab|3827650729" },
    { "spawnRadius", "BeeGrenade", "System.Single", "2" },
    { "deafLoopDef", "Flashbang", "SoundDefinition", "flashbang-deafloop (SoundDefinition)" },
    { "flashMaxRange", "Flashbang", "System.Single", "10" },
    { "flashMinRange", "Flashbang", "System.Single", "5" },
    { "flashReductionPerSecond", "Flashbang", "System.Single", "0.5" },
    { "flashToAdd", "Flashbang", "System.Single", "5" },
    { "blockCreateUnderwater", "FlameExplosive", "System.Boolean", "True" },
    { "createOnExplode", "FlameExplosive", "GameObjectRef", "assets/bundled/prefabs/fireball_small_molotov.prefab|2673585394" },
    { "forceUpForExplosion", "FlameExplosive", "System.Boolean", "True" },
    { "maxVelocity", "FlameExplosive", "System.Single", "8" },
    { "minVelocity", "FlameExplosive", "System.Single", "5" },
    { "numToCreate", "FlameExplosive", "System.Single", "5" },
    { "spreadAngle", "FlameExplosive", "System.Single", "120" },
    { "spreadCurve", "FlameExplosive", "UnityEngine.AnimationCurve", "UnityEngine.AnimationCurve" },
    { "velocityCurve", "FlameExplosive", "UnityEngine.AnimationCurve", "UnityEngine.AnimationCurve" },
    { "becomeDudInWater", "DudTimedExplosive", "System.Boolean", "False" },
    { "dudChance", "DudTimedExplosive", "System.Single", "0.2" },
    { "fizzleEffect", "DudTimedExplosive", "GameObjectRef", "assets/prefabs/weapons/satchelcharge/effects/fuse_extinguish_satchel.prefab|725886450" },
    { "itemToGive", "DudTimedExplosive", "ItemDefinition", "explosive.satchel.item (ItemDefinition)" },
    { "wickSound", "DudTimedExplosive", "UnityEngine.AudioSource", "" },
    { "wickSpark", "DudTimedExplosive", "UnityEngine.GameObject", "Sparks (UnityEngine.GameObject)" },
    { "fieldMax", "SmokeGrenade", "System.Single", "8" },
    { "fieldMin", "SmokeGrenade", "System.Single", "5" },
    { "igniteSound", "SmokeGrenade", "GameObjectRef", "assets/prefabs/tools/smoke grenade/effects/ignite.prefab|1277383634" },
    { "smokeDuration", "SmokeGrenade", "System.Single", "15" },
    { "smokeEffectPrefab", "SmokeGrenade", "GameObjectRef", "assets/prefabs/tools/smoke grenade/effects/smokegrenade.prefab|2143839482" },
    { "soundLoop", "SmokeGrenade", "SoundPlayer", "" },
};

inline constexpr std::size_t kCount = 45;
inline constexpr TimedExplosiveData kData[kCount == 0 ? 1 : kCount] =
{
    // assets/content/vehicles/mlrs/rocket_mlrs.prefab
    {
        "rocket_mlrs", "assets/content/vehicles/mlrs/rocket_mlrs.prefab", 1467029527U, "MLRSRocket", 0, 3,
        60.0f, 70.0f, 10.0f, 15.0f,
        false, false, false, false,
        false, false, 2.5f, 4.0f,
        "Local", { 0.0f, 0.0f, 0.0f }, false, false, false, false, false,
        { "assets/content/vehicles/mlrs/effects/pfx_mlrs_rocket_explosion_air.prefab", 2513205737U, true },
        { "", 0U, false },
        { "", 0U, false },
        { "", 0U, false },
        { "", 0U, false },
        1.0f, { 0.5f, 10.0f }, false, false, 3,
        0, 3, 0, 0, false,
        { true, 300.0f, 0.0f, 0.01f, false, true, "Discrete" },
        0, 4
    },
    // assets/content/vehicles/siegeweapons/catapult/ammo/projectiles/boulder.prefab
    {
        "boulder", "assets/content/vehicles/siegeweapons/catapult/ammo/projectiles/boulder.prefab", 362061794U, "TimedExplosive", 3, 2,
        20.0f, 20.0f, 1.0f, 3.0f,
        true, false, false, false,
        false, false, 2.5f, 4.0f,
        "Local", { 0.0f, 0.0f, -0.75f }, true, true, false, false, false,
        { "assets/content/vehicles/siegeweapons/catapult/effects/boulder_explosion.prefab", 2469689133U, true },
        { "", 0U, false },
        { "", 0U, false },
        { "", 0U, false },
        { "", 0U, false },
        1.0f, { 0.5f, 10.0f }, false, false, 0,
        3, 2, 0, 0, false,
        { false, 0.0f, 0.0f, 0.0f, false, false, "" },
        4, 0
    },
    // assets/content/vehicles/siegeweapons/catapult/ammo/projectiles/boulder_bee.prefab
    {
        "boulder_bee", "assets/content/vehicles/siegeweapons/catapult/ammo/projectiles/boulder_bee.prefab", 2899117222U, "BeeGrenade", 5, 3,
        20.0f, 20.0f, 1.0f, 3.0f,
        true, false, false, false,
        false, false, 2.5f, 4.0f,
        "Local", { 0.0f, 0.0f, -0.75f }, true, true, false, false, false,
        { "assets/content/vehicles/siegeweapons/catapult/effects/boulder_explosion_bees.prefab", 553851056U, true },
        { "", 0U, false },
        { "", 0U, false },
        { "", 0U, false },
        { "", 0U, false },
        1.0f, { 0.5f, 10.0f }, false, false, 0,
        5, 1, 0, 0, false,
        { false, 0.0f, 0.0f, 0.0f, false, false, "" },
        4, 3
    },
    // assets/content/vehicles/siegeweapons/catapult/ammo/projectiles/boulder_explosive.prefab
    {
        "boulder_explosive", "assets/content/vehicles/siegeweapons/catapult/ammo/projectiles/boulder_explosive.prefab", 1913489021U, "TimedExplosive", 8, 2,
        8.0f, 10.0f, 1.0f, 5.2f,
        false, false, false, false,
        false, false, 2.5f, 4.0f,
        "Local", { 0.0f, 0.0f, -2.0f }, false, true, false, false, false,
        { "assets/content/effects/explosions/explosion large catapult canisters.prefab", 1572450471U, true },
        { "", 0U, false },
        { "", 0U, false },
        { "", 0U, false },
        { "", 0U, false },
        1.0f, { 0.5f, 10.0f }, false, false, 2,
        6, 2, 0, 1, true,
        { false, 0.0f, 0.0f, 0.0f, false, false, "" },
        7, 0
    },
    // assets/content/vehicles/siegeweapons/catapult/ammo/projectiles/boulder_explosive_deployed.prefab
    {
        "boulder_explosive_deployed", "assets/content/vehicles/siegeweapons/catapult/ammo/projectiles/boulder_explosive_deployed.prefab", 520730022U, "TimedExplosive", 10, 2,
        8.0f, 10.0f, 1.0f, 4.0f,
        false, false, false, false,
        false, false, 2.5f, 4.0f,
        "Local", { 0.0f, 0.0f, -2.0f }, false, true, false, false, false,
        { "", 0U, false },
        { "", 0U, false },
        { "", 0U, false },
        { "", 0U, false },
        { "", 0U, false },
        1.0f, { 0.5f, 10.0f }, false, false, 2,
        8, 2, 1, 1, true,
        { false, 0.0f, 0.0f, 0.0f, false, false, "" },
        7, 0
    },
    // assets/content/vehicles/siegeweapons/catapult/ammo/projectiles/boulder_incendiary.prefab
    {
        "boulder_incendiary", "assets/content/vehicles/siegeweapons/catapult/ammo/projectiles/boulder_incendiary.prefab", 3871024251U, "FlameExplosive", 12, 3,
        100.0f, 100.0f, 5.0f, 6.0f,
        false, false, false, false,
        false, false, 2.5f, 4.0f,
        "Local", { 0.0f, 0.0f, -1.5f }, true, true, true, false, false,
        { "assets/content/effects/explosions/explosion flame.prefab", 3922974043U, true },
        { "assets/content/effects/explosions/underwater/explosion_underwater_large.prefab", 2593130125U, true },
        { "assets/prefabs/tools/c4/effects/c4_stick.prefab", 2722086713U, true },
        { "", 0U, false },
        { "assets/content/effects/explosions/underwater/explosion_underwater_surface_medium.prefab", 4032387435U, true },
        1.0f, { 0.5f, 10.0f }, false, false, 1,
        10, 1, 2, 0, false,
        { false, 0.0f, 0.0f, 0.0f, false, false, "" },
        7, 9
    },
    // assets/content/vehicles/siegeweapons/catapult/ammo/projectiles/boulder_incendiary_deployed.prefab
    {
        "boulder_incendiary_deployed", "assets/content/vehicles/siegeweapons/catapult/ammo/projectiles/boulder_incendiary_deployed.prefab", 3051519634U, "FlameExplosive", 15, 3,
        100.0f, 100.0f, 5.0f, 6.0f,
        false, false, false, false,
        false, false, 2.5f, 4.0f,
        "Local", { 0.0f, 0.0f, -1.5f }, true, true, true, false, false,
        { "", 0U, false },
        { "", 0U, false },
        { "", 0U, false },
        { "", 0U, false },
        { "", 0U, false },
        1.0f, { 0.5f, 10.0f }, false, false, 1,
        11, 1, 2, 0, false,
        { false, 0.0f, 0.0f, 0.0f, false, false, "" },
        16, 9
    },
    // assets/content/vehicles/siegeweapons/catapult/ammo/projectiles/boulder_mid.prefab
    {
        "boulder_mid", "assets/content/vehicles/siegeweapons/catapult/ammo/projectiles/boulder_mid.prefab", 4081160652U, "TimedExplosive", 18, 2,
        20.0f, 20.0f, 1.0f, 3.0f,
        true, false, false, false,
        false, false, 2.5f, 4.0f,
        "Local", { 0.0f, 0.0f, -0.75f }, true, true, false, false, false,
        { "assets/content/vehicles/siegeweapons/catapult/effects/boulder_explosion_mid.prefab", 1290556078U, true },
        { "", 0U, false },
        { "", 0U, false },
        { "", 0U, false },
        { "", 0U, false },
        1.0f, { 0.5f, 10.0f }, false, false, 0,
        12, 2, 2, 0, false,
        { false, 0.0f, 0.0f, 0.0f, false, false, "" },
        25, 0
    },
    // assets/content/vehicles/siegeweapons/catapult/ammo/projectiles/boulder_small.prefab
    {
        "boulder_small", "assets/content/vehicles/siegeweapons/catapult/ammo/projectiles/boulder_small.prefab", 1034606242U, "TimedExplosive", 20, 2,
        20.0f, 20.0f, 1.0f, 3.0f,
        true, false, false, false,
        false, false, 2.5f, 4.0f,
        "Local", { 0.0f, 0.0f, -0.75f }, true, true, false, false, false,
        { "assets/content/vehicles/siegeweapons/catapult/effects/boulder_explosion_small.prefab", 2157156918U, true },
        { "", 0U, false },
        { "", 0U, false },
        { "", 0U, false },
        { "", 0U, false },
        1.0f, { 0.5f, 10.0f }, false, false, 0,
        14, 2, 2, 0, false,
        { false, 0.0f, 0.0f, 0.0f, false, false, "" },
        25, 0
    },
    // assets/prefabs/ammo/40mmgrenade/40mm_grenade_he.prefab
    {
        "_40mm_grenade_he", "assets/prefabs/ammo/40mmgrenade/40mm_grenade_he.prefab", 1859672190U, "TimedExplosive", 22, 2,
        8.0f, 10.0f, 1.0f, 4.0f,
        false, false, false, false,
        false, false, 2.5f, 4.0f,
        "Local", { 0.0f, 0.0f, -0.2f }, true, false, false, false, false,
        { "assets/prefabs/ammo/40mmgrenade/effects/40mm_he_explosion.prefab", 133790274U, true },
        { "assets/content/effects/explosions/underwater/explosion_underwater_medium.prefab", 3262650776U, true },
        { "assets/prefabs/tools/c4/effects/c4_stick.prefab", 2722086713U, true },
        { "", 0U, false },
        { "assets/content/effects/explosions/underwater/explosion_underwater_surface_medium.prefab", 4032387435U, true },
        1.0f, { 0.5f, 10.0f }, false, false, 2,
        16, 2, 2, 1, false,
        { false, 0.0f, 0.0f, 0.0f, false, false, "" },
        25, 0
    },
    // assets/prefabs/ammo/40mmgrenade/40mm_grenade_smoke.prefab
    {
        "_40mm_grenade_smoke", "assets/prefabs/ammo/40mmgrenade/40mm_grenade_smoke.prefab", 1502533292U, "SmokeGrenade", 24, 3,
        3.0f, 3.0f, 1.5f, 4.5f,
        false, false, false, false,
        false, false, 2.5f, 4.0f,
        "Local", { 0.0f, 0.0f, 0.0f }, false, false, false, false, false,
        { "", 0U, false },
        { "", 0U, false },
        { "", 0U, false },
        { "assets/prefabs/weapons/f1 grenade/effects/bounce.prefab", 977761430U, true },
        { "", 0U, false },
        1.0f, { 0.5f, 10.0f }, false, false, 3,
        18, 0, 3, 0, false,
        { false, 0.0f, 0.0f, 0.0f, false, false, "" },
        25, 6
    },
    // assets/prefabs/ammo/rocket/rocket_basic.prefab
    {
        "rocket_basic", "assets/prefabs/ammo/rocket/rocket_basic.prefab", 3046924118U, "TimedExplosive", 27, 2,
        8.0f, 10.0f, 1.0f, 3.8f,
        false, false, false, false,
        false, false, 2.5f, 4.0f,
        "Local", { 0.0f, 0.0f, -0.75f }, true, false, false, false, false,
        { "assets/prefabs/weapons/rocketlauncher/effects/rocket_explosion.prefab", 3053816283U, true },
        { "assets/content/effects/explosions/underwater/explosion_underwater_large.prefab", 2593130125U, true },
        { "assets/prefabs/tools/c4/effects/c4_stick.prefab", 2722086713U, true },
        { "", 0U, false },
        { "assets/content/effects/explosions/underwater/explosion_underwater_surface_medium.prefab", 4032387435U, true },
        1.0f, { 0.5f, 10.0f }, false, false, 3,
        18, 2, 3, 1, true,
        { false, 0.0f, 0.0f, 0.0f, false, false, "" },
        31, 0
    },
    // assets/prefabs/ammo/rocket/rocket_basic_rpg.prefab
    {
        "rocket_basic_rpg", "assets/prefabs/ammo/rocket/rocket_basic_rpg.prefab", 3967322771U, "TimedExplosive", 29, 2,
        8.0f, 10.0f, 1.0f, 3.8f,
        false, false, false, false,
        false, false, 2.5f, 4.0f,
        "Local", { 0.0f, 0.0f, -0.75f }, true, false, false, false, false,
        { "assets/prefabs/weapons/rocketlauncher/effects/rocket_explosion.prefab", 3053816283U, true },
        { "assets/content/effects/explosions/underwater/explosion_underwater_large.prefab", 2593130125U, true },
        { "assets/prefabs/tools/c4/effects/c4_stick.prefab", 2722086713U, true },
        { "", 0U, false },
        { "assets/content/effects/explosions/underwater/explosion_underwater_surface_medium.prefab", 4032387435U, true },
        1.0f, { 0.5f, 10.0f }, false, false, 3,
        20, 2, 4, 1, true,
        { false, 0.0f, 0.0f, 0.0f, false, false, "" },
        31, 0
    },
    // assets/prefabs/ammo/rocket/rocket_fire.prefab
    {
        "rocket_fire", "assets/prefabs/ammo/rocket/rocket_fire.prefab", 901927673U, "FlameExplosive", 31, 3,
        8.0f, 10.0f, 5.0f, 5.0f,
        false, false, false, false,
        false, false, 2.5f, 4.0f,
        "Local", { 0.0f, 0.0f, 0.0f }, false, false, false, false, false,
        { "assets/prefabs/weapons/rocketlauncher/effects/rocket_explosion_incendiary.prefab", 1437504946U, true },
        { "assets/content/effects/explosions/underwater/explosion_underwater_large.prefab", 2593130125U, true },
        { "assets/prefabs/tools/c4/effects/c4_stick.prefab", 2722086713U, true },
        { "", 0U, false },
        { "assets/content/effects/explosions/underwater/explosion_underwater_surface_medium.prefab", 4032387435U, true },
        1.0f, { 0.5f, 10.0f }, false, false, 1,
        22, 1, 5, 0, false,
        { false, 0.0f, 0.0f, 0.0f, false, false, "" },
        31, 9
    },
    // assets/prefabs/ammo/rocket/rocket_fire_rpg.prefab
    {
        "rocket_fire_rpg", "assets/prefabs/ammo/rocket/rocket_fire_rpg.prefab", 2649360180U, "FlameExplosive", 34, 3,
        8.0f, 10.0f, 5.0f, 5.0f,
        false, false, false, false,
        false, false, 2.5f, 4.0f,
        "Local", { 0.0f, 0.0f, 0.0f }, false, false, false, false, false,
        { "assets/prefabs/weapons/rocketlauncher/effects/rocket_explosion_incendiary.prefab", 1437504946U, true },
        { "assets/content/effects/explosions/underwater/explosion_underwater_large.prefab", 2593130125U, true },
        { "assets/prefabs/tools/c4/effects/c4_stick.prefab", 2722086713U, true },
        { "", 0U, false },
        { "assets/content/effects/explosions/underwater/explosion_underwater_surface_medium.prefab", 4032387435U, true },
        1.0f, { 0.5f, 10.0f }, false, false, 1,
        23, 1, 5, 0, false,
        { false, 0.0f, 0.0f, 0.0f, false, false, "" },
        40, 9
    },
    // assets/prefabs/ammo/rocket/rocket_heatseeker.prefab
    {
        "rocket_heatseeker", "assets/prefabs/ammo/rocket/rocket_heatseeker.prefab", 288982380U, "TimedExplosive", 37, 2,
        12.0f, 12.0f, 1.0f, 3.5f,
        false, false, false, false,
        false, false, 2.5f, 4.0f,
        "Local", { 0.0f, 0.0f, 0.0f }, false, false, false, false, false,
        { "assets/prefabs/weapons/homingmissilelauncher/effects/pfx_manpad_explosion.prefab", 3898459144U, true },
        { "assets/content/effects/explosions/underwater/explosion_underwater_large.prefab", 2593130125U, true },
        { "assets/prefabs/tools/c4/effects/c4_stick.prefab", 2722086713U, true },
        { "", 0U, false },
        { "assets/content/effects/explosions/underwater/explosion_underwater_surface_medium.prefab", 4032387435U, true },
        1.0f, { 0.5f, 10.0f }, false, false, 1,
        24, 3, 5, 1, false,
        { false, 0.0f, 0.0f, 0.0f, false, false, "" },
        49, 0
    },
    // assets/prefabs/ammo/rocket/rocket_hv.prefab
    {
        "rocket_hv", "assets/prefabs/ammo/rocket/rocket_hv.prefab", 1217937936U, "TimedExplosive", 39, 2,
        8.0f, 10.0f, 1.0f, 3.5f,
        false, false, false, false,
        false, false, 2.5f, 4.0f,
        "Local", { 0.0f, 0.0f, -0.75f }, true, false, false, false, false,
        { "assets/prefabs/weapons/rocketlauncher/effects/rocket_explosion_hv.prefab", 2253809414U, true },
        { "assets/content/effects/explosions/underwater/explosion_underwater_large.prefab", 2593130125U, true },
        { "assets/prefabs/tools/c4/effects/c4_stick.prefab", 2722086713U, true },
        { "", 0U, false },
        { "assets/content/effects/explosions/underwater/explosion_underwater_surface_medium.prefab", 4032387435U, true },
        1.0f, { 0.5f, 10.0f }, false, false, 1,
        27, 3, 6, 1, false,
        { false, 0.0f, 0.0f, 0.0f, false, false, "" },
        49, 0
    },
    // assets/prefabs/ammo/rocket/rocket_hv_rpg.prefab
    {
        "rocket_hv_rpg", "assets/prefabs/ammo/rocket/rocket_hv_rpg.prefab", 2062533425U, "TimedExplosive", 41, 2,
        8.0f, 10.0f, 1.0f, 3.5f,
        false, false, false, false,
        false, false, 2.5f, 4.0f,
        "Local", { 0.0f, 0.0f, -0.75f }, true, false, false, false, false,
        { "assets/prefabs/weapons/rocketlauncher/effects/rocket_explosion_hv.prefab", 2253809414U, true },
        { "assets/content/effects/explosions/underwater/explosion_underwater_large.prefab", 2593130125U, true },
        { "assets/prefabs/tools/c4/effects/c4_stick.prefab", 2722086713U, true },
        { "", 0U, false },
        { "assets/content/effects/explosions/underwater/explosion_underwater_surface_medium.prefab", 4032387435U, true },
        1.0f, { 0.5f, 10.0f }, false, false, 1,
        30, 3, 7, 1, false,
        { false, 0.0f, 0.0f, 0.0f, false, false, "" },
        49, 0
    },
    // assets/prefabs/ammo/rocket/rocket_smoke.prefab
    {
        "rocket_smoke", "assets/prefabs/ammo/rocket/rocket_smoke.prefab", 1790390506U, "TimedExplosive", 43, 2,
        8.0f, 10.0f, 5.0f, 5.0f,
        false, false, false, false,
        false, false, 2.5f, 4.0f,
        "Local", { 0.0f, 0.0f, 0.0f }, false, false, false, false, false,
        { "assets/prefabs/weapons/beancan grenade/effects/beancan_grenade_explosion.prefab", 701725454U, true },
        { "assets/content/effects/explosions/underwater/explosion_underwater_large.prefab", 2593130125U, true },
        { "assets/prefabs/tools/c4/effects/c4_stick.prefab", 2722086713U, true },
        { "", 0U, false },
        { "assets/content/effects/explosions/underwater/explosion_underwater_surface_medium.prefab", 4032387435U, true },
        1.0f, { 0.5f, 10.0f }, false, false, 1,
        33, 1, 8, 0, false,
        { false, 0.0f, 0.0f, 0.0f, false, false, "" },
        49, 0
    },
    // assets/prefabs/ammo/torpedo/torpedostraight.prefab
    {
        "torpedostraight", "assets/prefabs/ammo/torpedo/torpedostraight.prefab", 110435217U, "TimedExplosive", 45, 2,
        15.0f, 20.0f, 5.0f, 5.0f,
        false, false, false, false,
        false, false, 2.5f, 4.0f,
        "Local", { 0.0f, 0.0f, 0.0f }, false, false, false, false, false,
        { "assets/content/effects/explosions/underwater/explosion_underwater_surface_large.prefab", 2588596879U, true },
        { "assets/content/effects/explosions/underwater/explosion_underwater_large.prefab", 2593130125U, true },
        { "assets/prefabs/tools/c4/effects/c4_stick.prefab", 2722086713U, true },
        { "", 0U, false },
        { "assets/content/effects/explosions/underwater/explosion_underwater_surface_large.prefab", 2588596879U, true },
        1.0f, { 0.5f, 20.0f }, false, false, 2,
        34, 3, 8, 1, false,
        { false, 0.0f, 0.0f, 0.0f, false, false, "" },
        49, 0
    },
    // assets/prefabs/deployable/boatbuilding/cannon/cannonball.prefab
    {
        "cannonball", "assets/prefabs/deployable/boatbuilding/cannon/cannonball.prefab", 1199568476U, "TimedExplosive", 47, 2,
        8.0f, 10.0f, 0.5f, 3.0f,
        false, false, false, false,
        false, false, 2.5f, 4.0f,
        "Local", { 0.0f, 0.0f, -0.75f }, true, false, false, false, false,
        { "assets/prefabs/deployable/boatbuilding/cannon/effects/cannonball_explosion.prefab", 2284784967U, true },
        { "assets/content/effects/explosions/underwater/explosion_underwater_large.prefab", 2593130125U, true },
        { "assets/prefabs/tools/c4/effects/c4_stick.prefab", 2722086713U, true },
        { "", 0U, false },
        { "assets/prefabs/deployable/boatbuilding/cannon/effects/cannonball_explosion_water_surface.prefab", 869281U, true },
        1.0f, { 0.5f, 10.0f }, false, false, 1,
        37, 4, 9, 2, true,
        { false, 0.0f, 0.0f, 0.0f, false, false, "" },
        49, 0
    },
    // assets/prefabs/deployable/mortar/mortar_shell_basic.prefab
    {
        "mortar_shell_basic", "assets/prefabs/deployable/mortar/mortar_shell_basic.prefab", 3093831259U, "TimedExplosive", 49, 2,
        90.0f, 120.0f, 1.0f, 4.5f,
        false, false, false, false,
        false, false, 2.5f, 4.0f,
        "Local", { 0.0f, 0.0f, -0.75f }, true, false, false, false, false,
        { "assets/prefabs/deployable/mortar/effects/mortar_explosion_he.prefab", 2221146001U, true },
        { "assets/content/effects/explosions/underwater/explosion_underwater_large.prefab", 2593130125U, true },
        { "assets/prefabs/tools/c4/effects/c4_stick.prefab", 2722086713U, true },
        { "", 0U, false },
        { "assets/content/effects/explosions/underwater/explosion_underwater_surface_medium.prefab", 4032387435U, true },
        1.0f, { 0.5f, 10.0f }, false, false, 2,
        41, 3, 11, 1, true,
        { false, 0.0f, 0.0f, 0.0f, false, false, "" },
        49, 0
    },
    // assets/prefabs/deployable/mortar/mortar_shell_fragment.prefab
    {
        "mortar_shell_fragment", "assets/prefabs/deployable/mortar/mortar_shell_fragment.prefab", 799615933U, "TimedExplosive", 51, 2,
        90.0f, 120.0f, 1.0f, 6.0f,
        false, false, false, false,
        false, false, 2.5f, 4.0f,
        "Local", { 0.0f, 0.0f, -0.75f }, true, false, false, false, false,
        { "assets/prefabs/deployable/mortar/effects/mortar_explosion_frag.prefab", 1679407465U, true },
        { "assets/content/effects/explosions/underwater/explosion_underwater_large.prefab", 2593130125U, true },
        { "assets/prefabs/tools/c4/effects/c4_stick.prefab", 2722086713U, true },
        { "", 0U, false },
        { "assets/content/effects/explosions/underwater/explosion_underwater_surface_medium.prefab", 4032387435U, true },
        1.0f, { 0.5f, 10.0f }, false, false, 1,
        44, 2, 12, 1, true,
        { false, 0.0f, 0.0f, 0.0f, false, false, "" },
        49, 0
    },
    // assets/prefabs/misc/chinesenewyear/throwablefirecrackers/firecrackers.deployed.prefab
    {
        "firecrackers_deployed", "assets/prefabs/misc/chinesenewyear/throwablefirecrackers/firecrackers.deployed.prefab", 3428971889U, "StringFirecracker", 53, 3,
        15.0f, 15.0f, 0.0f, 1.0f,
        false, false, false, false,
        false, false, 2.5f, 4.0f,
        "Local", { 0.0f, 0.0f, 0.0f }, false, false, false, false, false,
        { "", 0U, false },
        { "", 0U, false },
        { "", 0U, false },
        { "", 0U, false },
        { "", 0U, false },
        1.0f, { 0.5f, 10.0f }, true, false, 3,
        46, 0, 13, 0, false,
        { true, 10.0f, 0.5f, 0.5f, true, false, "ContinuousDynamic" },
        49, 5
    },
    // assets/prefabs/misc/easter/easter basket/eastereggprojectile.prefab
    {
        "eastereggprojectile", "assets/prefabs/misc/easter/easter basket/eastereggprojectile.prefab", 3721260684U, "SeasonalTimedExplosive", 56, 3,
        8.0f, 10.0f, 1.0f, 2.0f,
        false, false, false, false,
        false, false, 2.5f, 4.0f,
        "Local", { 0.0f, 0.0f, 0.0f }, false, false, false, false, false,
        { "assets/prefabs/misc/easter/easter basket/effects/eggexplosion.prefab", 2172435534U, true },
        { "", 0U, false },
        { "assets/prefabs/tools/c4/effects/c4_stick.prefab", 2722086713U, true },
        { "", 0U, false },
        { "", 0U, false },
        1.0f, { 0.5f, 10.0f }, false, false, 0,
        46, 1, 13, 0, false,
        { false, 0.0f, 0.0f, 0.0f, false, false, "" },
        54, 1
    },
    // assets/prefabs/misc/halloween/candies/candyprojectile.prefab
    {
        "candyprojectile", "assets/prefabs/misc/halloween/candies/candyprojectile.prefab", 1465468950U, "SeasonalTimedExplosive", 59, 3,
        8.0f, 10.0f, 1.0f, 2.0f,
        false, false, false, false,
        false, false, 2.5f, 4.0f,
        "Local", { 0.0f, 0.0f, 0.0f }, false, false, false, false, false,
        { "assets/prefabs/misc/halloween/candies/candyexplosion.prefab", 256035807U, true },
        { "", 0U, false },
        { "assets/prefabs/tools/c4/effects/c4_stick.prefab", 2722086713U, true },
        { "", 0U, false },
        { "", 0U, false },
        1.0f, { 0.5f, 10.0f }, false, false, 0,
        47, 1, 13, 0, false,
        { false, 0.0f, 0.0f, 0.0f, false, false, "" },
        55, 1
    },
    // assets/prefabs/npc/m2bradley/maincannonshell.prefab
    {
        "maincannonshell", "assets/prefabs/npc/m2bradley/maincannonshell.prefab", 3032863244U, "TimedExplosive", 62, 2,
        8.0f, 10.0f, 2.0f, 8.0f,
        false, false, false, false,
        true, false, 2.5f, 4.0f,
        "Local", { 0.0f, 0.0f, 0.0f }, false, false, false, false, false,
        { "assets/prefabs/npc/m2bradley/effects/maincannonshell_explosion.prefab", 2977555271U, true },
        { "", 0U, false },
        { "", 0U, false },
        { "", 0U, false },
        { "", 0U, false },
        1.0f, { 0.5f, 10.0f }, false, false, 1,
        48, 1, 13, 0, false,
        { false, 0.0f, 0.0f, 0.0f, false, false, "" },
        56, 0
    },
    // assets/prefabs/npc/patrol helicopter/rocket_heli.prefab
    {
        "rocket_heli", "assets/prefabs/npc/patrol helicopter/rocket_heli.prefab", 129320027U, "TimedExplosive", 64, 2,
        8.0f, 10.0f, 2.0f, 6.0f,
        false, false, false, false,
        false, false, 2.5f, 4.0f,
        "Local", { 0.0f, 0.0f, 0.0f }, false, false, false, false, false,
        { "assets/prefabs/npc/patrol helicopter/effects/rocket_explosion.prefab", 1741616969U, true },
        { "assets/content/effects/explosions/underwater/explosion_underwater_large.prefab", 2593130125U, true },
        { "", 0U, false },
        { "", 0U, false },
        { "assets/content/effects/explosions/underwater/explosion_underwater_surface_large.prefab", 2588596879U, true },
        1.0f, { 0.5f, 10.0f }, false, false, 1,
        49, 2, 13, 0, false,
        { false, 0.0f, 0.0f, 0.0f, false, false, "" },
        56, 0
    },
    // assets/prefabs/npc/patrol helicopter/rocket_heli_airburst.prefab
    {
        "rocket_heli_airburst", "assets/prefabs/npc/patrol helicopter/rocket_heli_airburst.prefab", 3253859536U, "TimedExplosive", 66, 2,
        8.0f, 10.0f, 2.0f, 6.0f,
        false, false, false, false,
        false, false, 2.5f, 4.0f,
        "Local", { 0.0f, 0.0f, 0.0f }, false, true, false, false, false,
        { "", 0U, false },
        { "", 0U, false },
        { "", 0U, false },
        { "", 0U, false },
        { "", 0U, false },
        1.0f, { 0.5f, 10.0f }, false, false, 1,
        51, 2, 13, 0, false,
        { false, 0.0f, 0.0f, 0.0f, false, false, "" },
        56, 0
    },
    // assets/prefabs/npc/patrol helicopter/rocket_heli_napalm.prefab
    {
        "rocket_heli_napalm", "assets/prefabs/npc/patrol helicopter/rocket_heli_napalm.prefab", 200672762U, "FlameExplosive", 68, 3,
        8.0f, 10.0f, 2.0f, 6.0f,
        false, false, false, false,
        false, false, 2.5f, 4.0f,
        "Local", { 0.0f, 0.0f, 0.0f }, false, false, false, false, false,
        { "assets/prefabs/npc/patrol helicopter/effects/rocket_explosion.prefab", 1741616969U, true },
        { "assets/content/effects/explosions/underwater/explosion_underwater_large.prefab", 2593130125U, true },
        { "assets/prefabs/tools/c4/effects/c4_stick.prefab", 2722086713U, true },
        { "", 0U, false },
        { "assets/content/effects/explosions/underwater/explosion_underwater_surface_large.prefab", 2588596879U, true },
        1.0f, { 0.5f, 10.0f }, false, false, 1,
        53, 1, 13, 0, false,
        { false, 0.0f, 0.0f, 0.0f, false, false, "" },
        56, 9
    },
    // assets/prefabs/npc/sam_site_turret/rocket_sam.prefab
    {
        "rocket_sam", "assets/prefabs/npc/sam_site_turret/rocket_sam.prefab", 2160908677U, "TimedExplosive", 71, 2,
        8.0f, 10.0f, 3.0f, 5.0f,
        false, false, false, false,
        false, false, 2.5f, 4.0f,
        "Local", { 0.0f, 0.0f, 0.0f }, false, false, false, false, false,
        { "assets/prefabs/npc/sam_site_turret/effects/rocket_sam_explosion.prefab", 3591459072U, true },
        { "", 0U, false },
        { "", 0U, false },
        { "", 0U, false },
        { "", 0U, false },
        1.0f, { 0.5f, 10.0f }, false, false, 1,
        54, 2, 13, 0, false,
        { false, 0.0f, 0.0f, 0.0f, false, false, "" },
        65, 0
    },
    // assets/prefabs/npc/sam_site_turret/sam_ammo.prefab
    {
        "sam_ammo", "assets/prefabs/npc/sam_site_turret/sam_ammo.prefab", 3414321847U, "TimedExplosive", 73, 2,
        8.0f, 10.0f, 5.0f, 5.0f,
        false, false, false, false,
        false, false, 2.5f, 4.0f,
        "Local", { 0.0f, 0.0f, 0.0f }, false, false, false, false, false,
        { "assets/prefabs/weapons/beancan grenade/effects/beancan_grenade_explosion.prefab", 701725454U, true },
        { "", 0U, false },
        { "assets/prefabs/tools/c4/effects/c4_stick.prefab", 2722086713U, true },
        { "", 0U, false },
        { "", 0U, false },
        1.0f, { 0.5f, 10.0f }, false, false, 1,
        56, 1, 13, 0, false,
        { false, 0.0f, 0.0f, 0.0f, false, false, "" },
        65, 0
    },
    // assets/prefabs/tools/c4/explosive.timed.deployed.prefab
    {
        "explosive_timed_deployed", "assets/prefabs/tools/c4/explosive.timed.deployed.prefab", 3898309212U, "RFTimedExplosive", 75, 3,
        10.0f, 10.0f, 0.0f, 4.0f,
        false, true, false, true,
        false, false, 2.5f, 4.0f,
        "Local", { 0.0f, 0.0f, 0.3475f }, false, true, true, false, false,
        { "assets/prefabs/tools/c4/effects/c4_explosion.prefab", 857997843U, true },
        { "assets/content/effects/explosions/underwater/explosion_underwater_large.prefab", 2593130125U, true },
        { "assets/prefabs/tools/c4/effects/c4_stick.prefab", 2722086713U, true },
        { "", 0U, false },
        { "assets/content/effects/explosions/underwater/explosion_underwater_surface_large.prefab", 2588596879U, true },
        1.0f, { 0.5f, 20.0f }, false, false, 3,
        57, 1, 13, 0, true,
        { true, 0.2f, 0.0f, 0.05f, true, false, "ContinuousDynamic" },
        65, 3
    },
    // assets/prefabs/tools/flareold/flare.deployed.prefab
    {
        "flare_deployed", "assets/prefabs/tools/flareold/flare.deployed.prefab", 1693887801U, "RoadFlare", 78, 3,
        110.0f, 120.0f, 0.0f, 1.0f,
        false, false, false, false,
        false, false, 2.5f, 4.0f,
        "Local", { 0.0f, 0.0f, 0.0f }, false, false, false, false, false,
        { "", 0U, false },
        { "", 0U, false },
        { "", 0U, false },
        { "", 0U, false },
        { "", 0U, false },
        1.0f, { 0.5f, 10.0f }, true, false, 3,
        58, 0, 13, 0, false,
        { true, 0.2f, 0.01f, 0.05f, true, false, "ContinuousDynamic" },
        68, 1
    },
    // assets/prefabs/tools/smoke grenade/grenade.smoke.deployed.prefab
    {
        "grenade_smoke_deployed", "assets/prefabs/tools/smoke grenade/grenade.smoke.deployed.prefab", 1464001967U, "SmokeGrenade", 81, 3,
        1.0f, 1.0f, 1.5f, 4.5f,
        false, false, false, false,
        false, false, 2.5f, 4.0f,
        "Local", { 0.0f, 0.0f, 0.0f }, false, false, false, false, false,
        { "", 0U, false },
        { "", 0U, false },
        { "", 0U, false },
        { "assets/prefabs/weapons/f1 grenade/effects/bounce.prefab", 977761430U, true },
        { "", 0U, false },
        1.0f, { 0.5f, 10.0f }, false, false, 3,
        58, 0, 13, 0, false,
        { true, 0.2f, 0.0f, 0.05f, true, false, "ContinuousDynamic" },
        69, 6
    },
    // assets/prefabs/tools/supply signal/grenade.supplysignal.deployed.prefab
    {
        "grenade_supplysignal_deployed", "assets/prefabs/tools/supply signal/grenade.supplysignal.deployed.prefab", 3350651790U, "SupplySignal", 84, 3,
        3.5f, 3.5f, 1.5f, 4.5f,
        false, false, false, false,
        false, false, 2.5f, 4.0f,
        "Local", { 0.0f, 0.0f, 0.0f }, false, false, false, false, false,
        { "", 0U, false },
        { "", 0U, false },
        { "", 0U, false },
        { "assets/prefabs/weapons/f1 grenade/effects/bounce.prefab", 977761430U, true },
        { "", 0U, false },
        1.0f, { 0.5f, 10.0f }, false, false, 3,
        58, 0, 13, 0, false,
        { true, 0.1f, 0.0f, 0.05f, true, false, "ContinuousDynamic" },
        75, 2
    },
    // assets/prefabs/tools/surveycharge/survey_charge.deployed.prefab
    {
        "survey_charge_deployed", "assets/prefabs/tools/surveycharge/survey_charge.deployed.prefab", 2141863453U, "SurveyCharge", 87, 3,
        5.0f, 5.0f, 1.0f, 5.0f,
        false, false, false, false,
        false, false, 2.5f, 4.0f,
        "Local", { 0.0f, 0.0f, 0.0f }, false, false, false, false, false,
        { "assets/bundled/prefabs/fx/survey_explosion.prefab", 135533567U, true },
        { "", 0U, false },
        { "assets/prefabs/tools/c4/effects/c4_stick.prefab", 2722086713U, true },
        { "assets/bundled/prefabs/fx/weapons/survey_charge/survey_charge_stick.prefab", 3381208271U, true },
        { "", 0U, false },
        1.0f, { 0.5f, 10.0f }, false, false, 0,
        58, 2, 13, 0, false,
        { true, 0.1f, 0.0f, 0.05f, true, false, "ContinuousDynamic" },
        77, 2
    },
    // assets/prefabs/weapons/beancan grenade/grenade.beancan.deployed.prefab
    {
        "grenade_beancan_deployed", "assets/prefabs/weapons/beancan grenade/grenade.beancan.deployed.prefab", 2144399804U, "DudTimedExplosive", 90, 3,
        3.5f, 4.0f, 1.5f, 4.5f,
        false, false, true, false,
        false, false, 2.5f, 4.0f,
        "World", { 0.0f, 0.0f, 0.0f }, false, false, false, false, false,
        { "assets/prefabs/weapons/beancan grenade/effects/beancan_grenade_explosion.prefab", 701725454U, true },
        { "assets/content/effects/explosions/underwater/explosion_underwater_small.prefab", 2189740440U, true },
        { "assets/prefabs/tools/c4/effects/c4_stick.prefab", 2722086713U, true },
        { "assets/prefabs/weapons/beancan grenade/effects/bounce.prefab", 3052882219U, true },
        { "assets/content/effects/explosions/underwater/explosion_underwater_surface_small.prefab", 286309678U, true },
        1.0f, { 0.5f, 10.0f }, false, true, 1,
        60, 3, 13, 1, false,
        { true, 0.2f, 0.0f, 0.05f, true, false, "ContinuousDynamic" },
        79, 6
    },
    // assets/prefabs/weapons/bee grenade/grenade.bee.deployed.prefab
    {
        "grenade_bee_deployed", "assets/prefabs/weapons/bee grenade/grenade.bee.deployed.prefab", 4036845226U, "BeeGrenade", 93, 3,
        10.0f, 10.0f, 2.0f, 4.0f,
        true, false, false, false,
        false, true, 3.0f, 5.0f,
        "Local", { 0.0f, 0.0f, 0.0f }, false, false, false, true, false,
        { "assets/prefabs/weapons/bee grenade/effects/bee-grenade-explode.prefab", 3152512321U, true },
        { "", 0U, false },
        { "assets/prefabs/tools/c4/effects/c4_stick.prefab", 2722086713U, true },
        { "assets/prefabs/weapons/bee grenade/effects/bounce.prefab", 1822198831U, true },
        { "", 0U, false },
        1.0f, { 0.5f, 10.0f }, false, false, 0,
        63, 2, 14, 0, false,
        { true, 0.2f, 0.0f, 0.05f, true, false, "ContinuousDynamic" },
        85, 3
    },
    // assets/prefabs/weapons/f1 grenade/grenade.f1.deployed.prefab
    {
        "grenade_f1_deployed", "assets/prefabs/weapons/f1 grenade/grenade.f1.deployed.prefab", 1128089209U, "TimedExplosive", 96, 2,
        2.5f, 2.5f, 2.0f, 6.0f,
        false, false, true, false,
        false, false, 2.5f, 4.0f,
        "Local", { 0.0f, 0.0f, 0.0f }, false, false, false, false, false,
        { "assets/prefabs/weapons/f1 grenade/effects/f1grenade_explosion.prefab", 4089790239U, true },
        { "assets/content/effects/explosions/underwater/explosion_underwater_medium.prefab", 3262650776U, true },
        { "assets/prefabs/tools/c4/effects/c4_stick.prefab", 2722086713U, true },
        { "assets/prefabs/weapons/f1 grenade/effects/bounce.prefab", 977761430U, true },
        { "assets/content/effects/explosions/underwater/explosion_underwater_surface_medium.prefab", 4032387435U, true },
        1.0f, { 0.5f, 15.0f }, false, false, 1,
        65, 3, 14, 1, false,
        { true, 0.2f, 0.0f, 0.05f, true, false, "ContinuousDynamic" },
        88, 0
    },
    // assets/prefabs/weapons/flashbang/grenade.flashbang.deployed.prefab
    {
        "grenade_flashbang_deployed", "assets/prefabs/weapons/flashbang/grenade.flashbang.deployed.prefab", 1436152685U, "Flashbang", 98, 3,
        1.25f, 1.25f, 3.0f, 6.0f,
        false, false, false, false,
        false, true, 3.0f, 5.0f,
        "World", { 0.0f, 0.1f, 0.0f }, false, false, false, false, false,
        { "assets/prefabs/weapons/flashbang/effects/fx-flashbang-boom.prefab", 1872825961U, true },
        { "assets/content/effects/explosions/underwater/explosion_underwater_small.prefab", 2189740440U, true },
        { "assets/prefabs/tools/c4/effects/c4_stick.prefab", 2722086713U, true },
        { "assets/prefabs/weapons/f1 grenade/effects/bounce.prefab", 977761430U, true },
        { "assets/content/effects/explosions/underwater/explosion_underwater_surface_small.prefab", 286309678U, true },
        1.0f, { 0.5f, 10.0f }, false, false, 0,
        68, 1, 15, 1, false,
        { true, 0.2f, 0.0f, 0.05f, true, false, "ContinuousDynamic" },
        88, 5
    },
    // assets/prefabs/weapons/molotov cocktail/grenade.molotov.deployed.prefab
    {
        "grenade_molotov_deployed", "assets/prefabs/weapons/molotov cocktail/grenade.molotov.deployed.prefab", 2144253630U, "FlameExplosive", 101, 3,
        8.0f, 10.0f, 1.0f, 3.0f,
        true, false, false, false,
        false, false, 2.5f, 4.0f,
        "Local", { 0.0f, 0.0f, 0.0f }, true, false, false, false, false,
        { "assets/prefabs/weapons/molotov cocktail/effects/molotovexplode.prefab", 3731256754U, true },
        { "assets/prefabs/weapons/molotov cocktail/effects/molotovexplodeunderwater.prefab", 815882363U, true },
        { "assets/prefabs/tools/c4/effects/c4_stick.prefab", 2722086713U, true },
        { "assets/prefabs/weapons/f1 grenade/effects/bounce.prefab", 977761430U, true },
        { "", 0U, false },
        1.0f, { 0.5f, 10.0f }, false, false, 0,
        69, 1, 16, 0, false,
        { true, 0.2f, 0.0f, 0.05f, true, false, "ContinuousDynamic" },
        93, 9
    },
    // assets/prefabs/weapons/satchelcharge/explosive.satchel.deployed.prefab
    {
        "explosive_satchel_deployed", "assets/prefabs/weapons/satchelcharge/explosive.satchel.deployed.prefab", 2742759844U, "DudTimedExplosive", 104, 3,
        6.0f, 12.0f, 0.0f, 4.0f,
        false, true, false, true,
        false, false, 2.5f, 4.0f,
        "Local", { 0.0f, 0.0f, 0.3475f }, false, false, true, false, false,
        { "assets/prefabs/weapons/satchelcharge/effects/satchel-charge-explosion.prefab", 1289728008U, true },
        { "assets/content/effects/explosions/underwater/explosion_underwater_large.prefab", 2593130125U, true },
        { "assets/prefabs/tools/c4/effects/c4_stick.prefab", 2722086713U, true },
        { "", 0U, false },
        { "assets/content/effects/explosions/underwater/explosion_underwater_surface_large.prefab", 2588596879U, true },
        1.0f, { 0.5f, 20.0f }, false, false, 2,
        70, 3, 16, 1, true,
        { true, 0.2f, 0.0f, 0.05f, true, false, "ContinuousDynamic" },
        102, 6
    },
    // assets/rust.ai/agents/npcplayer/humannpc/scientist/gen2/scientist2.grenade.f1.deployed.prefab
    {
        "scientist2_grenade_f1_deployed", "assets/rust.ai/agents/npcplayer/humannpc/scientist/gen2/scientist2.grenade.f1.deployed.prefab", 3292751488U, "TimedExplosive", 107, 2,
        0.0f, 0.0f, 2.0f, 6.0f,
        false, false, false, false,
        false, false, 2.5f, 4.0f,
        "Local", { 0.0f, 0.0f, 0.0f }, false, false, false, false, false,
        { "assets/prefabs/weapons/f1 grenade/effects/f1grenade_explosion.prefab", 4089790239U, true },
        { "assets/content/effects/explosions/underwater/explosion_underwater_medium.prefab", 3262650776U, true },
        { "assets/prefabs/tools/c4/effects/c4_stick.prefab", 2722086713U, true },
        { "assets/prefabs/weapons/f1 grenade/effects/bounce.prefab", 977761430U, true },
        { "assets/content/effects/explosions/underwater/explosion_underwater_surface_medium.prefab", 4032387435U, true },
        1.0f, { 0.5f, 15.0f }, false, false, 1,
        73, 3, 17, 1, false,
        { true, 0.2f, 0.0f, 0.05f, true, false, "ContinuousDynamic" },
        108, 0
    },
    // assets/rust.ai/agents/npcplayer/humannpc/scientist/gen2/scientist2.grenade.smoke.deployed.prefab
    {
        "scientist2_grenade_smoke_deployed", "assets/rust.ai/agents/npcplayer/humannpc/scientist/gen2/scientist2.grenade.smoke.deployed.prefab", 1013743524U, "SmokeGrenade", 109, 3,
        10.0f, 10.0f, 1.5f, 4.5f,
        true, false, false, false,
        false, false, 2.5f, 4.0f,
        "Local", { 0.0f, 0.0f, 0.0f }, false, false, false, false, false,
        { "", 0U, false },
        { "", 0U, false },
        { "", 0U, false },
        { "assets/prefabs/weapons/f1 grenade/effects/bounce.prefab", 977761430U, true },
        { "", 0U, false },
        1.0f, { 0.5f, 10.0f }, false, false, 3,
        76, 0, 18, 0, false,
        { true, 0.2f, 0.0f, 0.05f, true, false, "ContinuousDynamic" },
        108, 6
    }
};

inline const TimedExplosiveData* GetByHash(std::uint64_t hash) noexcept
{
    switch (hash)
    {
    case 1467029527ULL: return &kData[0]; // rocket_mlrs
    case 362061794ULL: return &kData[1]; // boulder
    case 2899117222ULL: return &kData[2]; // boulder_bee
    case 1913489021ULL: return &kData[3]; // boulder_explosive
    case 520730022ULL: return &kData[4]; // boulder_explosive_deployed
    case 3871024251ULL: return &kData[5]; // boulder_incendiary
    case 3051519634ULL: return &kData[6]; // boulder_incendiary_deployed
    case 4081160652ULL: return &kData[7]; // boulder_mid
    case 1034606242ULL: return &kData[8]; // boulder_small
    case 1859672190ULL: return &kData[9]; // _40mm_grenade_he
    case 1502533292ULL: return &kData[10]; // _40mm_grenade_smoke
    case 3046924118ULL: return &kData[11]; // rocket_basic
    case 3967322771ULL: return &kData[12]; // rocket_basic_rpg
    case 901927673ULL: return &kData[13]; // rocket_fire
    case 2649360180ULL: return &kData[14]; // rocket_fire_rpg
    case 288982380ULL: return &kData[15]; // rocket_heatseeker
    case 1217937936ULL: return &kData[16]; // rocket_hv
    case 2062533425ULL: return &kData[17]; // rocket_hv_rpg
    case 1790390506ULL: return &kData[18]; // rocket_smoke
    case 110435217ULL: return &kData[19]; // torpedostraight
    case 1199568476ULL: return &kData[20]; // cannonball
    case 3093831259ULL: return &kData[21]; // mortar_shell_basic
    case 799615933ULL: return &kData[22]; // mortar_shell_fragment
    case 3428971889ULL: return &kData[23]; // firecrackers_deployed
    case 3721260684ULL: return &kData[24]; // eastereggprojectile
    case 1465468950ULL: return &kData[25]; // candyprojectile
    case 3032863244ULL: return &kData[26]; // maincannonshell
    case 129320027ULL: return &kData[27]; // rocket_heli
    case 3253859536ULL: return &kData[28]; // rocket_heli_airburst
    case 200672762ULL: return &kData[29]; // rocket_heli_napalm
    case 2160908677ULL: return &kData[30]; // rocket_sam
    case 3414321847ULL: return &kData[31]; // sam_ammo
    case 3898309212ULL: return &kData[32]; // explosive_timed_deployed
    case 1693887801ULL: return &kData[33]; // flare_deployed
    case 1464001967ULL: return &kData[34]; // grenade_smoke_deployed
    case 3350651790ULL: return &kData[35]; // grenade_supplysignal_deployed
    case 2141863453ULL: return &kData[36]; // survey_charge_deployed
    case 2144399804ULL: return &kData[37]; // grenade_beancan_deployed
    case 4036845226ULL: return &kData[38]; // grenade_bee_deployed
    case 1128089209ULL: return &kData[39]; // grenade_f1_deployed
    case 1436152685ULL: return &kData[40]; // grenade_flashbang_deployed
    case 2144253630ULL: return &kData[41]; // grenade_molotov_deployed
    case 2742759844ULL: return &kData[42]; // explosive_satchel_deployed
    case 3292751488ULL: return &kData[43]; // scientist2_grenade_f1_deployed
    case 1013743524ULL: return &kData[44]; // scientist2_grenade_smoke_deployed
    default: return nullptr;
    }
}

inline const TimedExplosiveData* GetByPrefabPath(const char* path) noexcept
{
    if (!path) return nullptr;
    for (std::size_t i = 0; i < kCount; ++i)
        if (std::strcmp(kData[i].prefab_path, path) == 0) return &kData[i];
    return nullptr;
}
} // namespace TimedExplosives
} // namespace RustData

#endif // RUST_DATA_TIMED_EXPLOSIVE_DATA_HPP
