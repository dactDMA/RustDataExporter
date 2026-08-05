//
// Auto-generated Rust Weapon Data
// Generated: 2026-08-05 17:47:12 UTC
// Target: Protocol 2631.286.1 / Changeset 158240
// Total entries: 55
// Generator: RustDataExporter
//
// This file is generated from server-side Rust prefabs/components.
// Do not edit by hand.
//

#pragma once
#ifndef RUST_DATA_WEAPON_DATA_HPP
#define RUST_DATA_WEAPON_DATA_HPP

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <limits>

namespace RustData
{
struct Vec3 { float x; float y; float z; };

struct RecoilData
{
    float yaw_min;
    float yaw_max;
    float pitch_min;
    float pitch_max;
    float time_to_take_min;
    float time_to_take_max;
    float ads_scale;
    float movement_penalty;
    float clamp_pitch;
    int shots_until_max;
    bool use_curves;
    bool curves_as_scalar;
    float max_recoil_radius;
    bool override_aimcone_with_curve;
    float aimcone_curve_scale;
    float ammo_aimcone_scale_multi_projectile;
    float ammo_aimcone_scale_single_projectile;
};

struct AimConeData
{
    float aim_cone;
    float hip_aim_cone;
    float penalty_per_shot;
    float penalty_max;
    float penalty_recover_time;
    float penalty_recover_delay;
    float stance_penalty_scale;
};

struct ReloadData
{
    float time;
    float start_duration;
    float fraction_duration;
    float end_duration;
    bool fractional;
    bool can_unload_ammo;
};

struct BurstData { bool enabled; float recoil_scale; float fire_rate_scale; float aim_cone_scale; };
struct TurretData { bool usable; bool large_turret; float damage_scale; float reload_duration_override; };
struct AttackData { float deploy_delay; float repeat_delay; float animation_delay; };

struct NpcWeaponData
{
    float effective_range;
    float damage_scale;
    float attack_length_min;
    float attack_length_max;
    float attack_spacing;
    float aim_sway_offset;
    float aim_cone;
    bool only_in_range;
    float close_range_addition;
    float medium_range_addition;
    float long_range_addition;
    bool can_use_at_medium_range;
    bool can_use_at_long_range;
};

struct HeldData
{
    bool can_use_with_shield;
    bool is_building_tool;
    float hostility_score;
    Vec3 first_person_arm_offset;
    Vec3 first_person_arm_rotation;
    float first_person_rotation_strength;
};

struct WeaponData
{
    const char* name;
    const char* alias;
    const char* prefab_path;
    std::uint64_t hash;
    float damage_scale;
    float distance_scale;
    float projectile_velocity_scale;
    bool automatic;
    float noise_radius;
    float aim_sway;
    float aim_sway_speed;
    bool has_ads;
    bool can_change_fire_modes;
    bool default_on;
    bool manual_cycle;
    bool no_aiming_while_cycling;
    float reset_duration;
    int magazine_capacity;
    bool wants_recoil_comp;
    float recoil_comp_delay_override;
    bool no_headshots;
    RecoilData recoil;
    AimConeData aimcone;
    ReloadData reload;
    BurstData burst;
    TurretData turret;
    AttackData attack;
    NpcWeaponData npc;
    HeldData held;
};
} // namespace RustData

namespace RustData
{
namespace Weapons
{

inline constexpr std::size_t kCount = 55;
inline constexpr WeaponData kData[kCount == 0 ? 1 : kCount] =
{
    // assets/content/vehicles/boats/ptboat/turrets/50cal/entities/50cal.base.entity.prefab
    {
        "50cal.base", "_50cal_base", "assets/content/vehicles/boats/ptboat/turrets/50cal/entities/50cal.base.entity.prefab", 1234020621ULL,
        1.3f, 1.3f, 1.3f, true,
        100.0f, 2.0f, 2.0f,
        true, true, true, false, false,
        0.3f, 100, true, 0.0f, false,
        { 1.25f, 2.25f, -3.0f, -4.0f, 0.15f, 0.15f, 0.5f, 1.25f, -std::numeric_limits<float>::infinity(), 20, false, true, 20.0f, true, 2.5f, 1.0f, 1.0f },
        { 0.2f, 4.0f, 1.5f, 3.0f, 0.1f, 0.1f, 1.0f },
        { 7.5f, 0.0f, 0.0f, 0.0f, false, true },
        { false, 0.8f, 0.8f, 0.8f },
        { true, false, 0.35f, -1.0f },
        { 1.8f, 0.12f, 0.0f },
        { 150.0f, 0.2f, 2.5f, 3.0f, 1.0f, 1.0f, 3.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 20.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/content/vehicles/boats/ptboat/turrets/50cal/entities/50cal.single.entity.prefab
    {
        "50cal.mounted", "_50cal_mounted", "assets/content/vehicles/boats/ptboat/turrets/50cal/entities/50cal.single.entity.prefab", 3944162531ULL,
        1.0f, 1.0f, 1.0f, true,
        100.0f, 2.0f, 2.0f,
        true, true, true, false, false,
        0.3f, 100, true, 0.0f, false,
        { 1.25f, 2.25f, -3.0f, -4.0f, 0.15f, 0.15f, 0.5f, 1.25f, -std::numeric_limits<float>::infinity(), 20, false, true, 20.0f, true, 2.5f, 1.0f, 1.0f },
        { 0.2f, 4.0f, 1.5f, 3.0f, 0.1f, 0.1f, 1.0f },
        { 7.5f, 0.0f, 0.0f, 0.0f, false, true },
        { false, 0.8f, 0.8f, 0.8f },
        { true, false, 0.3f, -1.0f },
        { 1.8f, 0.12f, 0.0f },
        { 150.0f, 0.2f, 2.5f, 3.0f, 1.0f, 1.0f, 3.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 20.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/content/vehicles/boats/ptboat/turrets/50cal/entities/50cal.left.entity.prefab
    {
        "50cal.mounted.left", "_50cal_mounted_left", "assets/content/vehicles/boats/ptboat/turrets/50cal/entities/50cal.left.entity.prefab", 379001777ULL,
        1.0f, 1.0f, 1.0f, true,
        100.0f, 2.0f, 2.0f,
        true, true, true, false, false,
        0.3f, 100, true, 0.0f, false,
        { 1.25f, 2.25f, -3.0f, -4.0f, 0.15f, 0.15f, 0.5f, 1.25f, -std::numeric_limits<float>::infinity(), 20, false, true, 20.0f, true, 2.5f, 1.0f, 1.0f },
        { 0.2f, 4.0f, 1.5f, 3.0f, 0.1f, 0.1f, 1.0f },
        { 14.8f, 0.0f, 0.0f, 0.0f, false, true },
        { false, 0.8f, 0.8f, 0.8f },
        { true, false, 0.2f, -1.0f },
        { 1.8f, 0.12f, 0.0f },
        { 150.0f, 0.2f, 2.5f, 3.0f, 1.0f, 1.0f, 3.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 20.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/content/vehicles/boats/ptboat/turrets/50cal/entities/50cal.right.entity.prefab
    {
        "50cal.mounted.right", "_50cal_mounted_right", "assets/content/vehicles/boats/ptboat/turrets/50cal/entities/50cal.right.entity.prefab", 545211943ULL,
        1.0f, 1.0f, 1.0f, true,
        100.0f, 2.0f, 2.0f,
        true, true, true, false, false,
        0.3f, 100, true, 0.0f, false,
        { 1.25f, 2.25f, -3.0f, -4.0f, 0.15f, 0.15f, 0.5f, 1.25f, -std::numeric_limits<float>::infinity(), 20, false, true, 20.0f, true, 2.5f, 1.0f, 1.0f },
        { 0.2f, 4.0f, 1.5f, 3.0f, 0.1f, 0.1f, 1.0f },
        { 15.5f, 0.0f, 0.0f, 0.0f, false, true },
        { false, 0.8f, 0.8f, 0.8f },
        { true, false, 0.2f, -1.0f },
        { 1.8f, 0.12f, 0.0f },
        { 150.0f, 0.2f, 2.5f, 3.0f, 1.0f, 1.0f, 3.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 20.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/blowpipe/blowpipe.entity.prefab
    {
        "blowpipe", "blowpipe", "assets/prefabs/weapons/blowpipe/blowpipe.entity.prefab", 996318821ULL,
        1.0f, 1.0f, 1.0f, false,
        100.0f, 3.0f, 1.0f,
        true, false, true, false, false,
        0.3f, 1, false, 0.0f, false,
        { 0.0f, 0.0f, -1.0f, -3.0f, 0.1f, 0.3f, 0.6f, 0.0f, -std::numeric_limits<float>::infinity(), 30, false, false, 5.0f, false, 1.0f, 1.0f, 1.0f },
        { 0.0f, 1.0f, 0.0f, 0.0f, 0.1f, 0.1f, 1.0f },
        { 3.0f, 0.0f, 0.0f, 0.0f, false, true },
        { false, 0.8f, 0.8f, 0.8f },
        { true, false, 0.35f, 3.0f },
        { 1.0f, 1.6f, 0.0f },
        { 1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 6.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/blunderbuss/blunderbuss.entity.prefab
    {
        "blunderbuss", "blunderbuss", "assets/prefabs/weapons/blunderbuss/blunderbuss.entity.prefab", 2557812813ULL,
        1.0f, 1.0f, 1.0f, false,
        100.0f, 5.0f, 2.0f,
        true, true, true, false, false,
        0.3f, 2, false, 0.0f, false,
        { 8.0f, 15.0f, -10.0f, -15.0f, 0.1f, 0.2f, 1.0f, 0.0f, -std::numeric_limits<float>::infinity(), 30, false, false, 5.0f, false, 1.0f, 1.0f, 1.0f },
        { 0.5f, 2.0f, 0.0f, 0.0f, 0.1f, 0.1f, 1.0f },
        { 5.5f, 0.0f, 0.0f, 0.0f, false, true },
        { false, 0.8f, 0.8f, 0.8f },
        { true, false, 0.35f, -1.0f },
        { 1.75f, 0.5f, 0.0f },
        { 1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 2.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 8.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/compound bow/compound_bow.entity.prefab
    {
        "bow.compound", "bow_compound", "assets/prefabs/weapons/compound bow/compound_bow.entity.prefab", 1537401592ULL,
        1.0f, 1.0f, 1.0f, false,
        5.0f, 5.0f, 2.0f,
        true, true, true, false, false,
        0.3f, 1, false, 0.0f, false,
        { -3.0f, 3.0f, -3.0f, -6.0f, 0.1f, 0.2f, 0.6f, 0.0f, -std::numeric_limits<float>::infinity(), 30, false, false, 5.0f, false, 1.0f, 1.0f, 1.0f },
        { 0.2f, 0.2f, 0.0f, 0.0f, 0.1f, 0.1f, 0.0f },
        { 1.0f, 0.0f, 0.0f, 0.0f, false, true },
        { false, 0.8f, 0.8f, 0.8f },
        { true, true, 0.7f, 4.5f },
        { 1.0f, 1.25f, 0.6f },
        { 1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 5.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/bow/bow_hunting.entity.prefab
    {
        "bow.hunting", "bow_hunting", "assets/prefabs/weapons/bow/bow_hunting.entity.prefab", 2836331625ULL,
        1.0f, 1.0f, 1.0f, false,
        5.0f, 5.0f, 2.0f,
        true, true, true, false, false,
        0.3f, 1, false, 0.0f, false,
        { -3.0f, 3.0f, -3.0f, -6.0f, 0.1f, 0.2f, 0.6f, 0.0f, -std::numeric_limits<float>::infinity(), 30, false, false, 5.0f, false, 1.0f, 1.0f, 1.0f },
        { 1.0f, 1.0f, 0.0f, 0.0f, 0.1f, 0.1f, 0.0f },
        { 1.0f, 0.0f, 0.0f, 0.0f, false, true },
        { false, 0.8f, 0.8f, 0.8f },
        { true, true, 0.7f, 4.0f },
        { 1.0f, 1.25f, 0.6f },
        { 1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 5.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/crossbow/crossbow.entity.prefab
    {
        "crossbow", "crossbow", "assets/prefabs/weapons/crossbow/crossbow.entity.prefab", 2727391082ULL,
        1.2f, 1.5f, 1.5f, false,
        10.0f, 3.0f, 1.0f,
        true, true, true, false, false,
        0.3f, 1, false, 0.0f, false,
        { -3.0f, 3.0f, -3.0f, -6.0f, 0.1f, 0.2f, 0.6f, 0.0f, -std::numeric_limits<float>::infinity(), 30, false, false, 5.0f, false, 1.0f, 1.0f, 1.0f },
        { 1.0f, 1.8f, 0.0f, 0.0f, 0.1f, 0.1f, 0.0f },
        { 3.6f, 0.0f, 0.0f, 0.0f, false, true },
        { false, 0.8f, 0.8f, 0.8f },
        { true, false, 0.7f, 4.0f },
        { 1.6f, 1.0f, 0.0f },
        { 1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 6.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/crossbow/skins/bowless/crossbow_bowless.entity.prefab
    {
        "crossbowbowless", "crossbowbowless", "assets/prefabs/weapons/crossbow/skins/bowless/crossbow_bowless.entity.prefab", 777174364ULL,
        1.2f, 1.5f, 1.5f, false,
        10.0f, 3.0f, 1.0f,
        true, true, true, false, false,
        0.3f, 1, false, 0.0f, false,
        { -3.0f, 3.0f, -3.0f, -6.0f, 0.1f, 0.2f, 0.6f, 0.0f, -std::numeric_limits<float>::infinity(), 30, false, false, 5.0f, false, 1.0f, 1.0f, 1.0f },
        { 1.0f, 1.8f, 0.0f, 0.0f, 0.1f, 0.1f, 0.0f },
        { 3.6f, 0.0f, 0.0f, 0.0f, false, true },
        { false, 0.8f, 0.8f, 0.8f },
        { true, false, 0.7f, 4.0f },
        { 1.6f, 1.0f, 0.0f },
        { 1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 6.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/hmlmg/hmlmg.entity.prefab
    {
        "hmlmg", "hmlmg", "assets/prefabs/weapons/hmlmg/hmlmg.entity.prefab", 3459133190ULL,
        1.15f, 1.0f, 1.4f, true,
        100.0f, 2.0f, 2.0f,
        true, true, true, false, false,
        0.3f, 60, true, 0.0f, false,
        { -1.25f, -2.5f, -3.0f, -4.0f, 0.15f, 0.15f, 0.5f, 1.25f, -std::numeric_limits<float>::infinity(), 20, false, true, 20.0f, true, 4.25f, 1.0f, 1.0f },
        { 0.2f, 4.0f, 1.5f, 3.0f, 0.1f, 0.1f, 1.0f },
        { 6.5f, 0.0f, 0.0f, 0.0f, false, true },
        { false, 0.8f, 0.8f, 0.8f },
        { true, false, 0.35f, -1.0f },
        { 1.8f, 0.125f, 0.0f },
        { 150.0f, 0.2f, 2.5f, 3.0f, 1.0f, 1.0f, 3.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 20.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/homingmissilelauncher/homing_missile_launcher.entity.prefab
    {
        "homingmissile.launcher", "homingmissile_launcher", "assets/prefabs/weapons/homingmissilelauncher/homing_missile_launcher.entity.prefab", 542600037ULL,
        1.0f, 1.0f, 1.0f, false,
        100.0f, 2.0f, 2.0f,
        true, false, false, false, false,
        0.3f, 1, false, 0.0f, false,
        { 8.0f, 8.0f, -8.0f, -8.0f, 0.1f, 0.2f, 0.75f, 0.0f, -std::numeric_limits<float>::infinity(), 30, false, false, 5.0f, false, 1.0f, 1.0f, 1.0f },
        { 2.25f, 1.8f, 0.0f, 0.0f, 0.1f, 0.1f, 1.0f },
        { 5.92f, 0.0f, 0.0f, 0.0f, false, true },
        { false, 0.8f, 0.8f, 0.8f },
        { false, false, 0.35f, -1.0f },
        { 1.0f, 2.0f, 0.0f },
        { 1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 10.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 20.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/warhammer/krieg shotgun/krieg_shotgun.entity.prefab
    {
        "krieg.shotgun", "krieg_shotgun", "assets/prefabs/weapons/warhammer/krieg shotgun/krieg_shotgun.entity.prefab", 1896956209ULL,
        1.0f, 1.0f, 1.0f, false,
        100.0f, 5.0f, 2.0f,
        true, true, true, false, true,
        0.3f, 8, false, 0.0f, false,
        { 4.0f, 8.0f, -10.0f, -14.0f, 0.1f, 0.2f, 0.7f, 0.0f, -std::numeric_limits<float>::infinity(), 30, false, false, 5.0f, false, 1.0f, 1.0f, 1.0f },
        { 0.0f, 1.8f, 0.0f, 0.0f, 0.1f, 0.1f, 1.0f },
        { 5.5f, 0.9f, 0.578f, 0.8f, true, true },
        { false, 0.8f, 0.8f, 0.8f },
        { true, false, 0.35f, -1.0f },
        { 1.0f, 1.1f, 0.0f },
        { 15.0f, 0.25f, -1.0f, -1.0f, 0.0f, 8.0f, 1.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 8.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/legacy bow/legacybow.entity.prefab
    {
        "legacy bow", "legacy_bow", "assets/prefabs/weapons/legacy bow/legacybow.entity.prefab", 1400027705ULL,
        1.0f, 1.0f, 1.0f, false,
        5.0f, 5.0f, 2.0f,
        true, true, true, false, false,
        0.3f, 1, false, 0.0f, false,
        { -3.0f, 3.0f, -3.0f, -6.0f, 0.1f, 0.2f, 0.6f, 0.0f, -std::numeric_limits<float>::infinity(), 30, false, false, 5.0f, false, 1.0f, 1.0f, 1.0f },
        { 1.0f, 1.0f, 0.0f, 0.0f, 0.1f, 0.1f, 0.0f },
        { 1.0f, 0.0f, 0.0f, 0.0f, false, true },
        { false, 0.8f, 0.8f, 0.8f },
        { true, true, 0.7f, 4.0f },
        { 1.0f, 1.25f, 0.6f },
        { 1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 5.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/m249/m249.entity.prefab
    {
        "lmg.m249", "lmg_m249", "assets/prefabs/weapons/m249/m249.entity.prefab", 1440914039ULL,
        1.3f, 1.3f, 1.3f, true,
        100.0f, 2.0f, 2.0f,
        true, true, true, false, false,
        0.3f, 100, true, 0.0f, false,
        { 1.25f, 2.25f, -3.0f, -4.0f, 0.15f, 0.15f, 0.5f, 1.25f, -std::numeric_limits<float>::infinity(), 20, false, true, 20.0f, true, 2.5f, 1.0f, 1.0f },
        { 0.2f, 4.0f, 1.5f, 3.0f, 0.1f, 0.1f, 1.0f },
        { 7.5f, 0.0f, 0.0f, 0.0f, false, true },
        { false, 0.8f, 0.8f, 0.8f },
        { true, false, 0.35f, -1.0f },
        { 1.8f, 0.12f, 0.0f },
        { 150.0f, 0.2f, 2.5f, 3.0f, 1.0f, 1.0f, 3.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 20.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/m16a2/m16a2.entity.prefab
    {
        "m16a2", "m16a2", "assets/prefabs/weapons/m16a2/m16a2.entity.prefab", 4258809631ULL,
        0.7f, 1.4f, 1.4f, true,
        75.0f, 1.0f, 1.0f,
        true, false, true, false, false,
        0.2f, 30, true, 0.15f, false,
        { -0.5f, 0.5f, -2.0f, -3.0f, 0.1f, 0.1f, 0.75f, 0.2f, -std::numeric_limits<float>::infinity(), 15, false, true, 1.0f, true, 1.25f, 1.0f, 1.0f },
        { 0.25f, 3.5f, 0.1f, 1.0f, 0.12f, 0.12f, 1.0f },
        { 4.0f, 0.0f, 0.0f, 0.0f, false, true },
        { true, 0.55f, 0.5f, 1.0f },
        { true, false, 0.35f, -1.0f },
        { 1.5f, 0.1f, 0.0f },
        { 40.0f, 0.2f, 0.4f, 0.4f, 1.0f, 3.0f, 2.0f, false, 0.0f, 10.0f, 0.0f, true, true },
        { false, false, 11.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/mini crossbow/mini_crossbow.entity.prefab
    {
        "minicrossbow", "minicrossbow", "assets/prefabs/weapons/mini crossbow/mini_crossbow.entity.prefab", 4274044420ULL,
        1.0f, 0.8f, 1.1f, false,
        10.0f, 3.0f, 1.0f,
        true, true, true, false, false,
        0.3f, 4, false, 0.0f, false,
        { -3.0f, 3.0f, -3.0f, -6.0f, 0.1f, 0.2f, 0.6f, 0.0f, -std::numeric_limits<float>::infinity(), 30, false, false, 5.0f, false, 1.0f, 1.0f, 1.0f },
        { 1.0f, 1.8f, 0.0f, 0.0f, 0.1f, 0.1f, 0.0f },
        { 2.67f, 0.0f, 2.3f, 1.0f, true, true },
        { false, 0.8f, 0.8f, 0.8f },
        { true, false, 0.7f, 4.0f },
        { 1.6f, 1.0f, 0.0f },
        { 1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { true, false, 6.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/minigun/minigun.entity.prefab
    {
        "minigun", "minigun", "assets/prefabs/weapons/minigun/minigun.entity.prefab", 4007138847ULL,
        0.75f, 1.0f, 1.4f, true,
        100.0f, 2.0f, 2.0f,
        false, false, false, false, false,
        0.3f, 300, true, 0.0f, true,
        { 0.0f, 0.0f, -0.5f, -1.0f, 0.1f, 0.1f, 0.5f, 3.0f, -std::numeric_limits<float>::infinity(), 30, false, true, 0.75f, true, 1.5f, 1.0f, 1.0f },
        { 0.8f, 0.8f, 0.0f, 0.0f, 0.1f, 0.1f, 1.0f },
        { 3.5f, 0.0f, 0.0f, 0.0f, false, true },
        { false, 0.8f, 0.8f, 0.8f },
        { true, false, 0.4f, -1.0f },
        { 2.5f, 0.1f, 0.0f },
        { 150.0f, 0.25f, 2.5f, 5.0f, 1.0f, 1.5f, 2.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 20.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/grenade launcher/mgl.entity.prefab
    {
        "multiplegrenadelauncher", "multiplegrenadelauncher", "assets/prefabs/weapons/grenade launcher/mgl.entity.prefab", 1233562048ULL,
        1.0f, 1.0f, 1.0f, false,
        100.0f, 2.0f, 2.0f,
        true, true, true, false, false,
        0.3f, 6, false, 0.0f, false,
        { 5.0f, 10.0f, -15.0f, -20.0f, 0.1f, 0.2f, 0.75f, 0.0f, -std::numeric_limits<float>::infinity(), 30, false, false, 5.0f, false, 1.0f, 1.0f, 1.0f },
        { 2.25f, 1.8f, 0.0f, 0.0f, 0.1f, 0.1f, 1.0f },
        { 6.0f, 0.4f, 1.25f, 0.9f, true, true },
        { false, 0.8f, 0.8f, 0.8f },
        { false, false, 0.35f, -1.0f },
        { 1.0f, 0.4f, 0.0f },
        { 1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 10.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 20.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/paintball_gun/paintballgun.entity.prefab
    {
        "paintballgun", "paintballgun", "assets/prefabs/weapons/paintball_gun/paintballgun.entity.prefab", 3749252572ULL,
        0.75f, 1.0f, 0.9f, true,
        50.0f, 2.0f, 2.0f,
        true, true, false, false, false,
        0.3f, 30, true, 0.15f, false,
        { -1.0f, 1.0f, -1.0f, -3.0f, 0.1f, 0.1f, 0.5f, 0.2f, -std::numeric_limits<float>::infinity(), 10, false, true, 0.5f, true, 1.0f, 1.0f, 1.0f },
        { 0.5f, 3.0f, 0.1f, 1.0f, 0.3f, 0.3f, 1.0f },
        { 4.0f, 0.0f, 0.0f, 0.0f, false, true },
        { true, 0.5f, 0.7f, 0.5f },
        { true, false, 0.35f, -1.0f },
        { 1.6f, 0.1f, 0.0f },
        { 20.0f, 0.2f, 0.4f, 0.4f, 0.8f, 3.0f, 5.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 9.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/eoka pistol/pistol_eoka.entity.prefab
    {
        "pistol.eoka", "pistol_eoka", "assets/prefabs/weapons/eoka pistol/pistol_eoka.entity.prefab", 2176761593ULL,
        1.0f, 1.0f, 1.0f, true,
        100.0f, 3.0f, 1.0f,
        false, true, true, false, false,
        0.3f, 1, false, 0.0f, false,
        { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0, false, false, 0.0f, false, 0.0f, 0.0f, 0.0f },
        { 3.0f, 2.0f, 0.0f, 0.0f, 0.1f, 0.1f, 1.0f },
        { 2.0f, 0.0f, 0.0f, 0.0f, false, true },
        { false, 0.8f, 0.8f, 0.8f },
        { true, false, 0.35f, -1.0f },
        { 0.5f, 1.5f, 0.0f },
        { 1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 2.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 3.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/m92/m92.entity.prefab
    {
        "pistol.m92", "pistol_m92", "assets/prefabs/weapons/m92/m92.entity.prefab", 2293870814ULL,
        0.9f, 1.0f, 1.0f, false,
        50.0f, 2.0f, 1.0f,
        true, true, true, false, false,
        0.3f, 15, true, 0.2f, false,
        { -1.0f, 1.0f, -7.0f, -8.0f, 0.05f, 0.05f, 0.6f, 0.5f, -std::numeric_limits<float>::infinity(), 10, false, false, 5.0f, true, 1.25f, 1.0f, 1.0f },
        { 1.0f, 1.8f, 0.25f, 1.5f, 0.2f, 0.2f, 1.0f },
        { 2.39f, 0.0f, 0.0f, 0.0f, false, true },
        { false, 0.8f, 0.8f, 0.8f },
        { true, false, 0.35f, -1.0f },
        { 0.5f, 0.15f, 0.0f },
        { 15.0f, 0.25f, 0.0f, 0.46f, 0.8f, 3.0f, 2.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { true, false, 10.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/nailgun/nailgun.entity.prefab
    {
        "pistol.nailgun", "pistol_nailgun", "assets/prefabs/weapons/nailgun/nailgun.entity.prefab", 4279856314ULL,
        1.0f, 0.4f, 1.0f, false,
        50.0f, 2.0f, 1.0f,
        true, true, true, false, false,
        0.3f, 16, true, 0.2f, false,
        { -1.0f, 1.0f, -3.0f, -6.0f, 0.1f, 0.1f, 0.6f, 0.0f, -std::numeric_limits<float>::infinity(), 30, false, false, 5.0f, false, 1.0f, 1.0f, 1.0f },
        { 0.75f, 2.0f, 0.25f, 1.0f, 0.2f, 0.2f, 1.0f },
        { 3.1f, 0.0f, 0.0f, 0.0f, false, true },
        { false, 0.8f, 0.8f, 0.8f },
        { true, false, 0.35f, -1.0f },
        { 0.5f, 0.15f, 0.0f },
        { 1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 2.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { true, false, 5.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/glockskin/glock.entity.prefab
    {
        "pistol.prototype17", "pistol_prototype17", "assets/prefabs/weapons/glockskin/glock.entity.prefab", 636374895ULL,
        0.8f, 0.5f, 1.0f, false,
        50.0f, 2.0f, 1.0f,
        true, true, true, false, false,
        0.3f, 18, true, 0.15f, false,
        { -1.0f, 1.0f, -2.0f, -2.5f, 0.05f, 0.05f, 0.6f, 0.5f, -std::numeric_limits<float>::infinity(), 10, false, false, 5.0f, true, 2.0f, 1.0f, 1.0f },
        { 0.75f, 2.0f, 0.5f, 1.5f, 0.3f, 0.3f, 1.0f },
        { 2.9f, 0.0f, 0.0f, 0.0f, false, true },
        { true, 0.65f, 0.7f, 0.65f },
        { true, false, 0.35f, -1.0f },
        { 0.5f, 0.1125f, 0.0f },
        { 1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 2.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { true, false, 8.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/python/python.entity.prefab
    {
        "pistol.python", "pistol_python", "assets/prefabs/weapons/python/python.entity.prefab", 3305012504ULL,
        1.1f, 0.8f, 1.0f, false,
        100.0f, 2.0f, 1.0f,
        true, true, true, false, false,
        0.3f, 6, false, 0.0f, false,
        { -2.0f, 2.0f, -15.0f, -16.0f, 0.05f, 0.05f, 0.5f, 0.0f, -std::numeric_limits<float>::infinity(), 30, false, false, 5.0f, false, 1.0f, 1.0f, 1.0f },
        { 0.5f, 2.0f, 1.0f, 3.0f, 0.3f, 0.3f, 1.0f },
        { 3.75f, 0.0f, 0.0f, 0.0f, false, true },
        { false, 0.8f, 0.8f, 0.8f },
        { true, false, 0.35f, -1.0f },
        { 0.5f, 0.15f, 0.0f },
        { 1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 2.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { true, false, 7.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/revolver/pistol_revolver.entity.prefab
    {
        "pistol.revolver", "pistol_revolver", "assets/prefabs/weapons/revolver/pistol_revolver.entity.prefab", 2477536592ULL,
        0.7f, 0.4f, 1.0f, false,
        75.0f, 2.0f, 1.0f,
        true, true, true, false, false,
        0.3f, 8, false, 0.0f, false,
        { -1.0f, 1.0f, -3.0f, -6.0f, 0.1f, 0.1f, 0.6f, 0.0f, -std::numeric_limits<float>::infinity(), 30, false, false, 5.0f, false, 1.0f, 1.0f, 1.0f },
        { 0.75f, 2.0f, 1.0f, 2.5f, 0.2f, 0.2f, 1.0f },
        { 3.4f, 0.0f, 0.0f, 0.0f, false, true },
        { false, 0.8f, 0.8f, 0.8f },
        { true, false, 0.35f, -1.0f },
        { 0.5f, 0.175f, 0.0f },
        { 15.0f, 0.3f, 0.175f, 0.525f, 2.0f, 3.0f, 2.0f, true, 0.0f, 0.0f, 0.0f, true, true },
        { true, false, 5.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/semi auto pistol/pistol_semiauto.entity.prefab
    {
        "pistol.semiauto", "pistol_semiauto", "assets/prefabs/weapons/semi auto pistol/pistol_semiauto.entity.prefab", 563371667ULL,
        0.8f, 0.5f, 1.0f, false,
        50.0f, 2.0f, 1.0f,
        true, true, true, false, false,
        0.3f, 10, true, 0.15f, false,
        { -1.0f, 1.0f, -2.0f, -2.5f, 0.05f, 0.05f, 0.6f, 0.2f, -std::numeric_limits<float>::infinity(), 10, false, false, 5.0f, true, 2.0f, 1.0f, 1.0f },
        { 0.75f, 2.0f, 0.5f, 1.5f, 0.3f, 0.3f, 1.0f },
        { 2.9f, 0.0f, 0.0f, 0.0f, false, true },
        { false, 0.8f, 0.8f, 0.8f },
        { true, false, 0.35f, -1.0f },
        { 0.5f, 0.15f, 0.0f },
        { 1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 2.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { true, false, 8.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/semi auto pistol/skins/pistol_a_m15/pistol_semiauto.a.m15.entity.prefab
    {
        "pistol.semiauto.a.m15", "pistol_semiauto_a_m15", "assets/prefabs/weapons/semi auto pistol/skins/pistol_a_m15/pistol_semiauto.a.m15.entity.prefab", 2343718176ULL,
        0.8f, 0.5f, 1.0f, false,
        50.0f, 2.0f, 1.0f,
        true, true, true, false, false,
        0.3f, 10, true, 0.15f, false,
        { -1.0f, 1.0f, -2.0f, -2.5f, 0.05f, 0.05f, 0.6f, 0.2f, -std::numeric_limits<float>::infinity(), 10, false, false, 5.0f, true, 2.0f, 1.0f, 1.0f },
        { 0.75f, 2.0f, 0.5f, 1.5f, 0.3f, 0.3f, 1.0f },
        { 2.9f, 0.0f, 0.0f, 0.0f, false, true },
        { false, 0.8f, 0.8f, 0.8f },
        { true, false, 0.35f, -1.0f },
        { 0.5f, 0.15f, 0.0f },
        { 1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 2.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { true, false, 8.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/high caliber revolver/hc_revolver.entity.prefab
    {
        "revolver.hc", "revolver_hc", "assets/prefabs/weapons/high caliber revolver/hc_revolver.entity.prefab", 2154182718ULL,
        1.3f, 1.5f, 1.35f, false,
        100.0f, 1.0f, 1.0f,
        true, true, true, false, false,
        0.3f, 6, false, 0.0f, false,
        { -2.0f, 2.0f, -15.0f, -16.0f, 0.05f, 0.05f, 0.5f, 1.0f, -std::numeric_limits<float>::infinity(), 30, false, false, 5.0f, false, 1.0f, 1.0f, 1.0f },
        { 0.5f, 1.8f, 1.0f, 3.0f, 0.3f, 0.3f, 1.0f },
        { 3.5f, 0.0f, 0.0f, 0.0f, false, true },
        { false, 0.8f, 0.8f, 0.8f },
        { true, false, 0.5f, -1.0f },
        { 0.5f, 0.7f, 0.0f },
        { 1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 2.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { true, false, 7.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/ak47u/ak47u.entity.prefab
    {
        "rifle.ak", "rifle_ak", "assets/prefabs/weapons/ak47u/ak47u.entity.prefab", 1978739833ULL,
        1.0f, 1.0f, 1.0f, true,
        100.0f, 2.0f, 2.0f,
        true, true, true, false, false,
        0.3f, 30, true, 0.0f, false,
        { 1.5f, 2.5f, -2.5f, -3.5f, 0.1f, 0.1f, 0.75f, 0.2f, -std::numeric_limits<float>::infinity(), 10, false, true, 20.0f, true, 1.25f, 1.0f, 1.0f },
        { 0.2f, 2.5f, 0.1f, 1.0f, 0.3f, 0.3f, 1.0f },
        { 4.4f, 0.0f, 0.0f, 0.0f, false, true },
        { false, 0.8f, 0.8f, 0.8f },
        { true, false, 0.35f, -1.0f },
        { 1.0f, 0.1333f, 0.0f },
        { 30.0f, 0.2f, 0.2f, 0.4f, 1.0f, 3.0f, 2.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 10.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/ak47u/diver/ak47u_diver.entity.prefab
    {
        "rifle.ak.diver", "rifle_ak_diver", "assets/prefabs/weapons/ak47u/diver/ak47u_diver.entity.prefab", 4096772971ULL,
        1.0f, 1.0f, 1.0f, true,
        100.0f, 2.0f, 2.0f,
        true, true, true, false, false,
        0.3f, 30, true, 0.0f, false,
        { 1.5f, 2.5f, -2.5f, -3.5f, 0.1f, 0.1f, 0.75f, 0.2f, -std::numeric_limits<float>::infinity(), 10, false, true, 20.0f, true, 1.25f, 1.0f, 1.0f },
        { 0.2f, 2.5f, 0.1f, 1.0f, 0.3f, 0.3f, 1.0f },
        { 4.4f, 0.0f, 0.0f, 0.0f, false, true },
        { false, 0.8f, 0.8f, 0.8f },
        { true, false, 0.35f, -1.0f },
        { 1.0f, 0.1333f, 0.0f },
        { 30.0f, 0.2f, 0.2f, 0.4f, 1.0f, 3.0f, 2.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 10.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/ak47u/iceskin/ak47u_ice.entity.prefab
    {
        "rifle.ak.ice", "rifle_ak_ice", "assets/prefabs/weapons/ak47u/iceskin/ak47u_ice.entity.prefab", 1942738569ULL,
        1.0f, 1.0f, 1.0f, true,
        100.0f, 2.0f, 2.0f,
        true, true, true, false, false,
        0.3f, 30, true, 0.0f, false,
        { 1.5f, 2.5f, -2.5f, -3.5f, 0.1f, 0.1f, 0.75f, 0.2f, -std::numeric_limits<float>::infinity(), 10, false, true, 20.0f, true, 1.25f, 1.0f, 1.0f },
        { 0.2f, 2.5f, 0.1f, 1.0f, 0.3f, 0.3f, 1.0f },
        { 4.4f, 0.0f, 0.0f, 0.0f, false, true },
        { false, 0.8f, 0.8f, 0.8f },
        { true, false, 0.35f, -1.0f },
        { 1.0f, 0.1333f, 0.0f },
        { 30.0f, 0.2f, 0.2f, 0.4f, 1.0f, 3.0f, 2.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 10.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/ak47u/jungle skin/ak47u_jungle.entity.prefab
    {
        "rifle.ak.jungle", "rifle_ak_jungle", "assets/prefabs/weapons/ak47u/jungle skin/ak47u_jungle.entity.prefab", 1934468549ULL,
        1.0f, 1.0f, 1.0f, true,
        100.0f, 2.0f, 2.0f,
        true, true, true, false, false,
        0.3f, 30, true, 0.0f, false,
        { 1.5f, 2.5f, -2.5f, -3.5f, 0.1f, 0.1f, 0.75f, 0.2f, -std::numeric_limits<float>::infinity(), 10, false, true, 20.0f, true, 1.25f, 1.0f, 1.0f },
        { 0.2f, 2.5f, 0.1f, 1.0f, 0.3f, 0.3f, 1.0f },
        { 4.4f, 0.0f, 0.0f, 0.0f, false, true },
        { false, 0.8f, 0.8f, 0.8f },
        { true, false, 0.35f, -1.0f },
        { 1.0f, 0.1333f, 0.0f },
        { 30.0f, 0.2f, 0.2f, 0.4f, 1.0f, 3.0f, 2.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 10.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/ak47u/medieval skin/ak47u_med.entity.prefab
    {
        "rifle.ak.med", "rifle_ak_med", "assets/prefabs/weapons/ak47u/medieval skin/ak47u_med.entity.prefab", 3192146626ULL,
        1.0f, 1.0f, 1.0f, true,
        100.0f, 2.0f, 2.0f,
        true, true, true, false, false,
        0.3f, 30, true, 0.0f, false,
        { 1.5f, 2.5f, -2.5f, -3.5f, 0.1f, 0.1f, 0.75f, 0.2f, -std::numeric_limits<float>::infinity(), 10, false, true, 20.0f, true, 1.25f, 1.0f, 1.0f },
        { 0.2f, 2.5f, 0.1f, 1.0f, 0.3f, 0.3f, 1.0f },
        { 4.4f, 0.0f, 0.0f, 0.0f, false, true },
        { false, 0.8f, 0.8f, 0.8f },
        { true, false, 0.35f, -1.0f },
        { 1.0f, 0.1333f, 0.0f },
        { 30.0f, 0.2f, 0.2f, 0.4f, 1.0f, 3.0f, 2.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 10.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/bolt rifle/bolt_rifle.entity.prefab
    {
        "rifle.bolt", "rifle_bolt", "assets/prefabs/weapons/bolt rifle/bolt_rifle.entity.prefab", 1665481300ULL,
        1.6f, 1.75f, 1.75f, false,
        100.0f, 3.0f, 1.0f,
        true, true, true, true, true,
        0.3f, 4, false, 0.0f, false,
        { -4.0f, 4.0f, -2.0f, -3.0f, 0.1f, 0.1f, 0.8f, 0.5f, -std::numeric_limits<float>::infinity(), 30, false, false, 5.0f, false, 1.0f, 1.0f, 1.0f },
        { 0.0f, 1.8f, 0.0f, 0.0f, 0.1f, 0.1f, 1.0f },
        { 5.0f, 1.236f, 0.8664f, 1.4f, true, true },
        { false, 0.8f, 0.8f, 0.8f },
        { true, false, 0.8f, -1.0f },
        { 1.0f, 1.7f, 0.0f },
        { 1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 0.5f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 10.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/l96/l96.entity.prefab
    {
        "rifle.l96", "rifle_l96", "assets/prefabs/weapons/l96/l96.entity.prefab", 2620171289ULL,
        1.6f, 2.0f, 3.0f, false,
        100.0f, 2.0f, 1.0f,
        true, true, true, true, true,
        0.3f, 5, false, 0.0f, false,
        { -2.0f, 2.0f, -1.0f, -1.5f, 0.1f, 0.1f, 0.8f, 0.5f, -std::numeric_limits<float>::infinity(), 30, false, false, 5.0f, false, 1.0f, 1.0f, 1.0f },
        { 0.0f, 1.8f, 0.0f, 0.0f, 0.1f, 0.1f, 1.0f },
        { 3.0f, 0.0f, 0.0f, 0.0f, false, true },
        { false, 0.8f, 0.8f, 0.8f },
        { true, false, 0.8f, -1.0f },
        { 1.0f, 2.6f, 0.0f },
        { 1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 10.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/lr300/lr300.entity.prefab
    {
        "rifle.lr300", "rifle_lr300", "assets/prefabs/weapons/lr300/lr300.entity.prefab", 844375121ULL,
        0.8f, 1.5f, 1.5f, true,
        75.0f, 1.0f, 1.0f,
        true, true, false, false, false,
        0.25f, 30, true, 0.15f, false,
        { -0.5f, 0.5f, -2.0f, -3.0f, 0.1f, 0.1f, 0.75f, 0.2f, -std::numeric_limits<float>::infinity(), 15, false, true, 1.0f, true, 1.25f, 1.0f, 1.0f },
        { 0.2f, 3.0f, 0.1f, 1.0f, 0.14f, 0.14f, 1.0f },
        { 4.0f, 0.0f, 0.0f, 0.0f, false, true },
        { true, 0.65f, 0.7f, 0.5f },
        { true, false, 0.35f, -1.0f },
        { 1.5f, 0.12f, 0.0f },
        { 40.0f, 0.2f, 0.4f, 0.4f, 1.0f, 3.0f, 2.0f, false, 0.0f, 10.0f, 0.0f, true, true },
        { false, false, 11.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/lr300/skins/space/lr300_space.entity.prefab
    {
        "rifle.lr300.space", "rifle_lr300_space", "assets/prefabs/weapons/lr300/skins/space/lr300_space.entity.prefab", 1407888186ULL,
        0.8f, 1.5f, 1.5f, true,
        75.0f, 1.0f, 1.0f,
        true, true, false, false, false,
        0.25f, 30, true, 0.15f, false,
        { -0.5f, 0.5f, -2.0f, -3.0f, 0.1f, 0.1f, 0.75f, 0.2f, -std::numeric_limits<float>::infinity(), 15, false, true, 1.0f, true, 1.25f, 1.0f, 1.0f },
        { 0.2f, 3.0f, 0.1f, 1.0f, 0.14f, 0.14f, 1.0f },
        { 4.0f, 0.0f, 0.0f, 0.0f, false, true },
        { true, 0.65f, 0.7f, 0.5f },
        { true, false, 0.35f, -1.0f },
        { 1.5f, 0.12f, 0.0f },
        { 40.0f, 0.2f, 0.4f, 0.4f, 1.0f, 3.0f, 2.0f, false, 0.0f, 10.0f, 0.0f, true, true },
        { false, false, 11.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/m39 emr/m39.entity.prefab
    {
        "rifle.m39", "rifle_m39", "assets/prefabs/weapons/m39 emr/m39.entity.prefab", 1517089664ULL,
        1.0f, 1.5f, 1.25f, false,
        75.0f, 1.0f, 1.0f,
        true, true, true, false, false,
        0.3f, 20, false, 0.0f, false,
        { 1.5f, 2.5f, -3.0f, -4.0f, 0.1f, 0.1f, 0.6f, 0.5f, -std::numeric_limits<float>::infinity(), 4, false, false, 50.0f, true, 1.0f, 1.0f, 1.0f },
        { 0.1f, 3.0f, 0.2f, 1.0f, 0.14f, 0.14f, 1.0f },
        { 3.25f, 0.0f, 0.0f, 0.0f, false, true },
        { false, 0.8f, 0.8f, 0.8f },
        { true, false, 0.4f, -1.0f },
        { 1.0f, 0.175f, 0.0f },
        { 30.0f, 0.2f, 0.0f, 0.4f, 1.25f, 3.0f, 1.0f, false, 0.0f, 10.0f, 0.0f, true, true },
        { false, false, 11.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/semi auto rifle/semi_auto_rifle.entity.prefab
    {
        "rifle.semiauto", "rifle_semiauto", "assets/prefabs/weapons/semi auto rifle/semi_auto_rifle.entity.prefab", 4231282088ULL,
        0.8f, 1.0f, 1.0f, false,
        100.0f, 1.0f, 2.0f,
        true, true, true, false, false,
        0.3f, 16, true, 0.15f, false,
        { -0.5f, 0.5f, -2.0f, -3.0f, 0.1f, 0.1f, 0.6f, 0.5f, -std::numeric_limits<float>::infinity(), 3, false, false, 5.0f, true, 1.0f, 1.0f, 1.0f },
        { 0.25f, 1.8f, 0.4f, 1.5f, 0.3f, 0.3f, 1.0f },
        { 4.4f, 0.0f, 0.0f, 0.0f, false, true },
        { false, 0.8f, 0.8f, 0.8f },
        { true, false, 0.35f, -1.0f },
        { 1.15f, 0.175f, 0.0f },
        { 20.0f, 0.25f, 0.175f, 0.525f, 1.5f, 3.0f, 2.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 8.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/sks/sks.entity.prefab
    {
        "rifle.sks", "rifle_sks", "assets/prefabs/weapons/sks/sks.entity.prefab", 4228529517ULL,
        0.85f, 1.25f, 1.25f, false,
        100.0f, 1.0f, 2.0f,
        true, true, true, false, false,
        0.3f, 15, true, 0.15f, false,
        { -0.3f, 0.3f, -3.0f, -3.5f, 0.1f, 0.1f, 0.6f, 0.5f, -std::numeric_limits<float>::infinity(), 3, false, false, 5.0f, true, 1.0f, 1.0f, 1.0f },
        { 0.25f, 1.8f, 0.4f, 1.5f, 0.3f, 0.3f, 1.0f },
        { 4.4f, 0.0f, 0.0f, 0.0f, false, true },
        { false, 0.8f, 0.8f, 0.8f },
        { true, false, 0.35f, -1.0f },
        { 1.15f, 0.15f, 0.0f },
        { 20.0f, 0.25f, 0.175f, 0.525f, 1.5f, 3.0f, 2.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 8.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/rocketlauncher/rocket_launcher.entity.prefab
    {
        "rocket.launcher", "rocket_launcher", "assets/prefabs/weapons/rocketlauncher/rocket_launcher.entity.prefab", 601440135ULL,
        1.0f, 1.0f, 1.0f, false,
        100.0f, 2.0f, 2.0f,
        true, true, true, false, false,
        0.3f, 1, false, 0.0f, false,
        { 5.0f, 10.0f, -15.0f, -20.0f, 0.1f, 0.2f, 0.75f, 0.0f, -std::numeric_limits<float>::infinity(), 30, false, false, 5.0f, false, 1.0f, 1.0f, 1.0f },
        { 2.25f, 1.8f, 0.0f, 0.0f, 0.1f, 0.1f, 1.0f },
        { 6.162f, 0.0f, 0.0f, 0.0f, false, true },
        { false, 0.8f, 0.8f, 0.8f },
        { false, false, 0.35f, -1.0f },
        { 3.0f, 2.0f, 0.0f },
        { 1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 10.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 20.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/rocketlauncher/skins/cny_dragonlauncher/rocket_launcher_dragon.entity.prefab
    {
        "rocket.launcher.dragon", "rocket_launcher_dragon", "assets/prefabs/weapons/rocketlauncher/skins/cny_dragonlauncher/rocket_launcher_dragon.entity.prefab", 3704640358ULL,
        1.0f, 1.0f, 1.0f, false,
        100.0f, 2.0f, 2.0f,
        true, true, true, false, false,
        0.3f, 1, false, 0.0f, false,
        { 5.0f, 10.0f, -15.0f, -20.0f, 0.1f, 0.2f, 0.75f, 0.0f, -std::numeric_limits<float>::infinity(), 30, false, false, 5.0f, false, 1.0f, 1.0f, 1.0f },
        { 2.25f, 1.8f, 0.0f, 0.0f, 0.1f, 0.1f, 1.0f },
        { 6.162f, 0.0f, 0.0f, 0.0f, false, true },
        { false, 0.8f, 0.8f, 0.8f },
        { false, false, 0.35f, -1.0f },
        { 3.0f, 2.0f, 0.0f },
        { 1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 10.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 20.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/rocketlauncher/skins/rpg7/rpg7.entity.prefab
    {
        "rocket.launcher.rpg7", "rocket_launcher_rpg7", "assets/prefabs/weapons/rocketlauncher/skins/rpg7/rpg7.entity.prefab", 3445264346ULL,
        1.0f, 1.0f, 1.0f, false,
        100.0f, 2.0f, 2.0f,
        true, true, true, false, false,
        0.3f, 1, false, 0.0f, false,
        { 5.0f, 10.0f, -15.0f, -20.0f, 0.1f, 0.2f, 0.75f, 0.0f, -std::numeric_limits<float>::infinity(), 30, false, false, 5.0f, false, 1.0f, 1.0f, 1.0f },
        { 2.25f, 1.8f, 0.0f, 0.0f, 0.1f, 0.1f, 1.0f },
        { 6.162f, 0.0f, 0.0f, 0.0f, false, true },
        { false, 0.8f, 0.8f, 0.8f },
        { false, false, 0.35f, -1.0f },
        { 3.0f, 2.0f, 0.0f },
        { 1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 10.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 20.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/doubleshotgun/double_shotgun.entity.prefab
    {
        "shotgun.double", "shotgun_double", "assets/prefabs/weapons/doubleshotgun/double_shotgun.entity.prefab", 3474489095ULL,
        1.0f, 1.0f, 1.0f, false,
        100.0f, 5.0f, 2.0f,
        true, true, true, false, false,
        0.3f, 2, false, 0.0f, false,
        { 8.0f, 15.0f, -10.0f, -15.0f, 0.1f, 0.2f, 1.0f, 0.0f, -std::numeric_limits<float>::infinity(), 30, false, false, 5.0f, false, 1.0f, 1.0f, 1.0f },
        { 0.5f, 2.0f, 0.0f, 0.0f, 0.1f, 0.1f, 1.0f },
        { 5.5f, 0.0f, 0.0f, 0.0f, false, true },
        { false, 0.8f, 0.8f, 0.8f },
        { true, false, 0.35f, -1.0f },
        { 1.75f, 0.5f, 0.0f },
        { 1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 2.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 8.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/m4 shotgun/m4_shotgun.entity.prefab
    {
        "shotgun.m4", "shotgun_m4", "assets/prefabs/weapons/m4 shotgun/m4_shotgun.entity.prefab", 2416998201ULL,
        0.8f, 1.5f, 1.3f, false,
        100.0f, 3.0f, 1.5f,
        true, true, true, false, false,
        0.3f, 6, false, 0.0f, false,
        { 2.0f, 4.0f, -7.0f, -10.0f, 0.05f, 0.1f, 0.4f, 0.0f, -std::numeric_limits<float>::infinity(), 30, false, false, 5.0f, true, 1.0f, 0.1f, 1.0f },
        { 0.0f, 0.7f, 0.0f, 0.0f, 0.1f, 0.1f, 1.0f },
        { 5.8f, 1.03f, 0.488f, 1.09f, true, true },
        { false, 0.8f, 0.8f, 0.8f },
        { true, false, 0.35f, -1.0f },
        { 1.6f, 0.3f, 0.0f },
        { 15.0f, 0.2f, 0.3f, 1.0f, 2.0f, 8.0f, 3.0f, false, 2.0f, 5.0f, 0.0f, true, false },
        { false, false, 8.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/sawnoff_shotgun/shotgun_pump.entity.prefab
    {
        "shotgun.pump", "shotgun_pump", "assets/prefabs/weapons/sawnoff_shotgun/shotgun_pump.entity.prefab", 554582418ULL,
        1.0f, 1.0f, 1.0f, false,
        100.0f, 5.0f, 2.0f,
        true, true, true, false, true,
        0.3f, 8, false, 0.0f, false,
        { 4.0f, 8.0f, -10.0f, -14.0f, 0.1f, 0.2f, 0.7f, 0.0f, -std::numeric_limits<float>::infinity(), 30, false, false, 5.0f, false, 1.0f, 1.0f, 1.0f },
        { 0.0f, 1.8f, 0.0f, 0.0f, 0.1f, 0.1f, 1.0f },
        { 5.5f, 0.9f, 0.578f, 0.8f, true, true },
        { false, 0.8f, 0.8f, 0.8f },
        { true, false, 0.35f, -1.0f },
        { 1.0f, 1.1f, 0.0f },
        { 15.0f, 0.25f, -1.0f, -1.0f, 0.0f, 8.0f, 1.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 8.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/spas12/spas12.entity.prefab
    {
        "shotgun.spas12", "shotgun_spas12", "assets/prefabs/weapons/spas12/spas12.entity.prefab", 1877401463ULL,
        0.75f, 1.0f, 1.0f, false,
        100.0f, 4.0f, 2.0f,
        true, true, true, false, false,
        0.3f, 6, false, 0.0f, false,
        { 4.0f, 8.0f, -10.0f, -14.0f, 0.1f, 0.2f, 0.7f, 0.0f, -std::numeric_limits<float>::infinity(), 30, false, false, 5.0f, false, 1.0f, 1.0f, 1.0f },
        { 0.0f, 1.8f, 0.0f, 0.0f, 0.1f, 0.1f, 1.0f },
        { 5.8f, 1.03f, 0.488f, 1.09f, true, true },
        { false, 0.8f, 0.8f, 0.8f },
        { true, false, 0.35f, -1.0f },
        { 1.6f, 0.25f, 0.0f },
        { 15.0f, 0.2f, 0.3f, 1.0f, 2.0f, 8.0f, 3.0f, false, 2.0f, 5.0f, 0.0f, true, false },
        { false, false, 8.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/pipe shotgun/shotgun_waterpipe.entity.prefab
    {
        "shotgun.waterpipe", "shotgun_waterpipe", "assets/prefabs/weapons/pipe shotgun/shotgun_waterpipe.entity.prefab", 2696589892ULL,
        1.0f, 1.0f, 1.0f, false,
        100.0f, 5.0f, 2.0f,
        true, true, true, false, false,
        0.3f, 1, false, 0.0f, false,
        { 4.0f, 8.0f, -10.0f, -14.0f, 0.1f, 0.2f, 0.7f, 0.0f, -std::numeric_limits<float>::infinity(), 30, false, false, 5.0f, false, 1.0f, 1.0f, 1.0f },
        { 1.0f, 2.0f, 0.0f, 0.0f, 0.1f, 0.1f, 1.0f },
        { 4.5f, 0.0f, 0.0f, 0.0f, false, true },
        { false, 0.8f, 0.8f, 0.8f },
        { true, false, 0.35f, -1.0f },
        { 2.4f, 2.0f, 0.0f },
        { 1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 2.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 7.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/smg/smg.entity.prefab
    {
        "smg.2", "smg_2", "assets/prefabs/weapons/smg/smg.entity.prefab", 3759841439ULL,
        0.6f, 0.7f, 0.8f, true,
        75.0f, 3.0f, 1.0f,
        true, true, true, false, false,
        0.3f, 30, false, 0.0f, false,
        { -1.0f, 1.0f, -1.5f, -2.0f, 0.1f, 0.1f, 0.5f, 0.2f, -std::numeric_limits<float>::infinity(), 30, false, true, 0.75f, true, 1.5f, 1.0f, 1.0f },
        { 0.5f, 1.8f, 0.25f, 1.0f, 0.15f, 0.15f, 1.0f },
        { 4.0f, 0.0f, 0.0f, 0.0f, false, true },
        { false, 0.8f, 0.8f, 0.8f },
        { true, false, 0.35f, -1.0f },
        { 1.0f, 0.1f, 0.0f },
        { 1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 5.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 8.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/mp5/mp5.entity.prefab
    {
        "smg.mp5", "smg_mp5", "assets/prefabs/weapons/mp5/mp5.entity.prefab", 2545523575ULL,
        0.75f, 1.0f, 0.9f, true,
        50.0f, 2.0f, 2.0f,
        true, true, false, false, false,
        0.3f, 30, true, 0.15f, false,
        { -1.0f, 1.0f, -1.0f, -3.0f, 0.1f, 0.1f, 0.5f, 0.2f, -std::numeric_limits<float>::infinity(), 10, false, true, 0.5f, true, 1.0f, 1.0f, 1.0f },
        { 0.5f, 3.0f, 0.1f, 1.0f, 0.3f, 0.3f, 1.0f },
        { 4.0f, 0.0f, 0.0f, 0.0f, false, true },
        { true, 0.5f, 0.7f, 0.5f },
        { true, false, 0.35f, -1.0f },
        { 1.6f, 0.1f, 0.0f },
        { 20.0f, 0.2f, 0.4f, 0.4f, 0.8f, 3.0f, 5.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 9.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/thompson/thompson.entity.prefab
    {
        "smg.thompson", "smg_thompson", "assets/prefabs/weapons/thompson/thompson.entity.prefab", 3243900999ULL,
        0.75f, 1.0f, 1.0f, true,
        75.0f, 3.0f, 1.0f,
        true, true, true, false, false,
        0.3f, 20, false, 0.0f, false,
        { -1.0f, 1.0f, -1.5f, -2.0f, 0.1f, 0.1f, 0.5f, 0.2f, -std::numeric_limits<float>::infinity(), 30, false, true, 0.75f, true, 1.5f, 1.0f, 1.0f },
        { 0.5f, 1.8f, 0.25f, 1.0f, 0.15f, 0.15f, 1.0f },
        { 4.0f, 0.0f, 0.0f, 0.0f, false, true },
        { false, 0.8f, 0.8f, 0.8f },
        { true, false, 0.35f, -1.0f },
        { 1.0f, 0.13f, 0.0f },
        { 1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 4.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 8.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/misc/xmas/snowballgun/snowballgun.entity.prefab
    {
        "snowballgun", "snowballgun", "assets/prefabs/misc/xmas/snowballgun/snowballgun.entity.prefab", 3228215527ULL,
        1.0f, 1.0f, 0.5f, true,
        100.0f, 2.0f, 2.0f,
        true, true, true, false, false,
        0.3f, 50, false, 0.0f, false,
        { -0.5f, 0.5f, -2.0f, -3.0f, 0.1f, 0.1f, 0.75f, 0.2f, -std::numeric_limits<float>::infinity(), 15, false, true, 1.0f, true, 1.25f, 1.0f, 1.0f },
        { 2.25f, 1.8f, 0.0f, 0.0f, 0.1f, 0.1f, 1.0f },
        { 1.0f, 0.4f, 1.25f, 0.9f, false, false },
        { false, 0.8f, 0.8f, 0.8f },
        { false, false, 1.0f, -1.0f },
        { 1.0f, 0.15f, 0.0f },
        { 1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 10.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 20.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/speargun/speargun.entity.prefab
    {
        "speargun", "speargun", "assets/prefabs/weapons/speargun/speargun.entity.prefab", 4262383355ULL,
        1.0f, 1.0f, 1.0f, false,
        10.0f, 3.0f, 1.0f,
        true, true, true, false, false,
        0.3f, 1, false, 0.0f, false,
        { -3.0f, 3.0f, -3.0f, -6.0f, 0.1f, 0.2f, 0.6f, 0.0f, -std::numeric_limits<float>::infinity(), 30, false, false, 5.0f, false, 1.0f, 1.0f, 1.0f },
        { 1.0f, 1.8f, 0.0f, 0.0f, 0.1f, 0.1f, 0.0f },
        { 3.6f, 0.0f, 0.0f, 0.0f, false, true },
        { false, 0.8f, 0.8f, 0.8f },
        { false, false, 0.35f, -1.0f },
        { 1.6f, 1.0f, 0.0f },
        { 1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 6.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    },
    // assets/prefabs/weapons/t1 smg/t1_smg.entity.prefab
    {
        "t1_smg", "t1_smg", "assets/prefabs/weapons/t1 smg/t1_smg.entity.prefab", 4251501342ULL,
        0.4f, 0.5f, 0.5f, true,
        75.0f, 3.0f, 1.0f,
        true, true, true, false, false,
        0.3f, 18, false, 0.0f, false,
        { -1.0f, 1.0f, -2.0f, -2.5f, 0.1f, 0.1f, 0.5f, 0.2f, -std::numeric_limits<float>::infinity(), 30, false, true, 0.75f, true, 1.5f, 1.0f, 1.0f },
        { 0.5f, 3.0f, 0.25f, 1.0f, 0.15f, 0.15f, 1.0f },
        { 4.0f, 0.0f, 0.0f, 0.0f, false, true },
        { false, 0.8f, 0.8f, 0.8f },
        { true, false, 0.35f, -1.0f },
        { 1.0f, 0.14f, 0.0f },
        { 1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 5.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 8.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f }
    }
};

inline const WeaponData* GetByName(const char* name) noexcept
{
    if (!name) return nullptr;
    for (std::size_t i = 0; i < kCount; ++i)
    {
        if (std::strcmp(kData[i].name, name) == 0 || std::strcmp(kData[i].alias, name) == 0)
            return &kData[i];
    }
    return nullptr;
}

inline const WeaponData* GetByHash(std::uint64_t hash) noexcept
{
    switch (hash)
    {
    case 1234020621ULL: return &kData[0]; // 50cal.base
    case 3944162531ULL: return &kData[1]; // 50cal.mounted
    case 379001777ULL: return &kData[2]; // 50cal.mounted.left
    case 545211943ULL: return &kData[3]; // 50cal.mounted.right
    case 996318821ULL: return &kData[4]; // blowpipe
    case 2557812813ULL: return &kData[5]; // blunderbuss
    case 1537401592ULL: return &kData[6]; // bow.compound
    case 2836331625ULL: return &kData[7]; // bow.hunting
    case 2727391082ULL: return &kData[8]; // crossbow
    case 777174364ULL: return &kData[9]; // crossbowbowless
    case 3459133190ULL: return &kData[10]; // hmlmg
    case 542600037ULL: return &kData[11]; // homingmissile.launcher
    case 1896956209ULL: return &kData[12]; // krieg.shotgun
    case 1400027705ULL: return &kData[13]; // legacy bow
    case 1440914039ULL: return &kData[14]; // lmg.m249
    case 4258809631ULL: return &kData[15]; // m16a2
    case 4274044420ULL: return &kData[16]; // minicrossbow
    case 4007138847ULL: return &kData[17]; // minigun
    case 1233562048ULL: return &kData[18]; // multiplegrenadelauncher
    case 3749252572ULL: return &kData[19]; // paintballgun
    case 2176761593ULL: return &kData[20]; // pistol.eoka
    case 2293870814ULL: return &kData[21]; // pistol.m92
    case 4279856314ULL: return &kData[22]; // pistol.nailgun
    case 636374895ULL: return &kData[23]; // pistol.prototype17
    case 3305012504ULL: return &kData[24]; // pistol.python
    case 2477536592ULL: return &kData[25]; // pistol.revolver
    case 563371667ULL: return &kData[26]; // pistol.semiauto
    case 2343718176ULL: return &kData[27]; // pistol.semiauto.a.m15
    case 2154182718ULL: return &kData[28]; // revolver.hc
    case 1978739833ULL: return &kData[29]; // rifle.ak
    case 4096772971ULL: return &kData[30]; // rifle.ak.diver
    case 1942738569ULL: return &kData[31]; // rifle.ak.ice
    case 1934468549ULL: return &kData[32]; // rifle.ak.jungle
    case 3192146626ULL: return &kData[33]; // rifle.ak.med
    case 1665481300ULL: return &kData[34]; // rifle.bolt
    case 2620171289ULL: return &kData[35]; // rifle.l96
    case 844375121ULL: return &kData[36]; // rifle.lr300
    case 1407888186ULL: return &kData[37]; // rifle.lr300.space
    case 1517089664ULL: return &kData[38]; // rifle.m39
    case 4231282088ULL: return &kData[39]; // rifle.semiauto
    case 4228529517ULL: return &kData[40]; // rifle.sks
    case 601440135ULL: return &kData[41]; // rocket.launcher
    case 3704640358ULL: return &kData[42]; // rocket.launcher.dragon
    case 3445264346ULL: return &kData[43]; // rocket.launcher.rpg7
    case 3474489095ULL: return &kData[44]; // shotgun.double
    case 2416998201ULL: return &kData[45]; // shotgun.m4
    case 554582418ULL: return &kData[46]; // shotgun.pump
    case 1877401463ULL: return &kData[47]; // shotgun.spas12
    case 2696589892ULL: return &kData[48]; // shotgun.waterpipe
    case 3759841439ULL: return &kData[49]; // smg.2
    case 2545523575ULL: return &kData[50]; // smg.mp5
    case 3243900999ULL: return &kData[51]; // smg.thompson
    case 3228215527ULL: return &kData[52]; // snowballgun
    case 4262383355ULL: return &kData[53]; // speargun
    case 4251501342ULL: return &kData[54]; // t1_smg
    default: return nullptr;
    }
}
} // namespace Weapons
} // namespace RustData

#endif // RUST_DATA_WEAPON_DATA_HPP
