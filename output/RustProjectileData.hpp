//
// Auto-generated Rust Projectile Data
// Generated: 2026-08-02 15:52:23 UTC
// Target: Protocol 2631.286.1 / Changeset 158240
// Total entries: 80
// Generator: RustDataExporter
//
// This file is generated from server-side Rust prefabs/components.
// Do not edit by hand.
//

#pragma once
#ifndef RUST_DATA_PROJECTILE_DATA_HPP
#define RUST_DATA_PROJECTILE_DATA_HPP

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <limits>

namespace RustData
{
struct ProjectileVec2 { float x; float y; };
struct ProjectileVec3 { float x; float y; float z; };
struct DamageTypeData { const char* type; float amount; };
inline constexpr std::size_t kProjectileMaxDamageTypes = 16;
struct ProjectileData
{
    const char* name;
    const char* prefab_path;
    std::uint64_t hash;
    ProjectileVec3 initial_velocity;
    float drag;
    float gravity_modifier;
    float thickness;
    float initial_distance;
    ProjectileVec3 initial_orientation;
    float penetration_power;
    float ricochet_chance;
    float stick_probability;
    float break_probability;
    float condition_loss;
    float water_integrity_loss;
    ProjectileVec2 damage_distances;
    ProjectileVec2 damage_multipliers;
    DamageTypeData damage_types[kProjectileMaxDamageTypes];
    std::uint8_t damage_type_count;
    bool remain_in_world;
    bool can_refract;
    bool penetrates_vehicles;
    bool create_decals;
};
} // namespace RustData

namespace RustData
{
namespace Projectiles
{

inline constexpr std::size_t kCount = 80;
inline constexpr ProjectileData kData[kCount == 0 ? 1 : kCount] =
{
    // assets/prefabs/ammo/arrow/bone/arrow_bone.prefab
    {
        "arrow_bone", "assets/prefabs/ammo/arrow/bone/arrow_bone.prefab", 1175273260ULL,
        { 0.0f, 0.0f, 0.0f }, 0.01f, 0.75f, 0.22f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 1.0f, 0.1f,
        0.0f, 0.1f,
        { 10.0f, 60.0f }, { 1.0f, 0.8f },
        {
            { "Arrow", 40.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/ammo/arrow/fire/arrow_fire.prefab
    {
        "arrow_fire", "assets/prefabs/ammo/arrow/fire/arrow_fire.prefab", 100479866ULL,
        { 0.0f, 0.0f, 0.0f }, 0.01f, 1.0f, 0.25f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 0.0f, 0.1f,
        0.0f, 0.1f,
        { 10.0f, 60.0f }, { 1.0f, 0.8f },
        {
            { "Arrow", 40.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, false, true, false, true
    },
    // assets/prefabs/ammo/arrow/arrow_hv.prefab
    {
        "arrow_hv", "assets/prefabs/ammo/arrow/arrow_hv.prefab", 4135687601ULL,
        { 0.0f, 0.0f, 0.0f }, 0.005f, 0.5f, 0.1f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 1.0f, 0.1f,
        0.0f, 0.1f,
        { 10.0f, 100.0f }, { 1.0f, 0.8f },
        {
            { "Arrow", 40.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/ammo/arrow/arrow_wooden.prefab
    {
        "arrow_wooden", "assets/prefabs/ammo/arrow/arrow_wooden.prefab", 70335961ULL,
        { 0.0f, 0.0f, 0.0f }, 0.005f, 0.75f, 0.1f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 1.0f, 0.1f,
        0.0f, 0.1f,
        { 10.0f, 60.0f }, { 1.0f, 0.8f },
        {
            { "Arrow", 50.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/weapons/salvaged_axe/axe_salvaged.projectile.prefab
    {
        "axe_salvaged_projectile", "assets/prefabs/weapons/salvaged_axe/axe_salvaged.projectile.prefab", 3381823385ULL,
        { 0.0f, 0.0f, 0.0f }, 0.5f, 1.0f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.1f, 0.0f, 0.7f, 0.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Slash", 25.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/content/vehicles/siegeweapons/ballista/ammo/projectiles/ballista.bolt.hammerhead.projectile.prefab
    {
        "ballista_bolt_hammerhead_projectile", "assets/content/vehicles/siegeweapons/ballista/ammo/projectiles/ballista.bolt.hammerhead.projectile.prefab", 3841293998ULL,
        { 0.0f, 0.0f, 0.0f }, 0.01f, 0.9f, 0.22f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 1.0f, 1.0f,
        0.0f, 0.1f,
        { 10.0f, 60.0f }, { 1.0f, 0.8f },
        {
            { "Arrow", 50.0f },
            { "AntiVehicle", 15.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        2, false, true, false, true
    },
    // assets/content/vehicles/siegeweapons/ballista/ammo/projectiles/ballista.bolt.incendiary.projectile.prefab
    {
        "ballista_bolt_incendiary_projectile", "assets/content/vehicles/siegeweapons/ballista/ammo/projectiles/ballista.bolt.incendiary.projectile.prefab", 2634460531ULL,
        { 0.0f, 0.0f, 0.0f }, 0.01f, 0.9f, 0.22f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 1.0f, 0.1f,
        0.0f, 0.1f,
        { 10.0f, 60.0f }, { 1.0f, 0.8f },
        {
            { "Arrow", 75.0f },
            { "AntiVehicle", 15.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        2, true, true, false, true
    },
    // assets/content/vehicles/siegeweapons/ballista/ammo/projectiles/ballista.bolt.piercer.projectile.prefab
    {
        "ballista_bolt_piercer_projectile", "assets/content/vehicles/siegeweapons/ballista/ammo/projectiles/ballista.bolt.piercer.projectile.prefab", 2301406582ULL,
        { 0.0f, 0.0f, 0.0f }, 0.005f, 0.75f, 0.22f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        2.0f, 0.0f, 1.0f, 0.1f,
        0.0f, 0.1f,
        { 10.0f, 100.0f }, { 1.0f, 0.6f },
        {
            { "Arrow", 80.0f },
            { "AntiVehicle", 60.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        2, false, false, true, true
    },
    // assets/content/vehicles/siegeweapons/ballista/ammo/projectiles/ballista.bolt.pitchfork.projectile.prefab
    {
        "ballista_bolt_pitchfork_projectile", "assets/content/vehicles/siegeweapons/ballista/ammo/projectiles/ballista.bolt.pitchfork.projectile.prefab", 3329430643ULL,
        { 0.0f, 0.0f, 0.0f }, 0.02f, 0.9f, 0.22f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 1.0f, 0.2f,
        0.0f, 0.1f,
        { 10.0f, 100.0f }, { 1.0f, 0.6f },
        {
            { "Arrow", 120.0f },
            { "AntiVehicle", 10.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        2, true, true, false, true
    },
    // assets/prefabs/weapons/bone knife/skins/obsidian knife/bone.knife.obsidian.projectile.prefab
    {
        "bone_knife_obsidian_projectile", "assets/prefabs/weapons/bone knife/skins/obsidian knife/bone.knife.obsidian.projectile.prefab", 916499682ULL,
        { 0.0f, 0.0f, 0.0f }, 0.5f, 1.0f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 0.0f, 0.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Slash", 10.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/weapons/bone club/boneclub.projectile.prefab
    {
        "boneclub_projectile", "assets/prefabs/weapons/bone club/boneclub.projectile.prefab", 1871533806ULL,
        { 0.0f, 0.0f, 0.0f }, 0.5f, 1.0f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 0.0f, 0.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Blunt", 12.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/weapons/bone knife/boneknife.projectile.prefab
    {
        "boneknife_projectile", "assets/prefabs/weapons/bone knife/boneknife.projectile.prefab", 1077356552ULL,
        { 0.0f, 0.0f, 0.0f }, 0.5f, 1.0f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 0.0f, 0.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Slash", 10.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/weapons/halloween/butcher knife/butcherknife.projectile.prefab
    {
        "butcherknife_projectile", "assets/prefabs/weapons/halloween/butcher knife/butcherknife.projectile.prefab", 1017853410ULL,
        { 0.0f, 0.0f, 0.0f }, 0.5f, 1.0f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 0.8f, 0.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Slash", 10.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/weapons/cake/cake.projectile.prefab
    {
        "cake_projectile", "assets/prefabs/weapons/cake/cake.projectile.prefab", 2714474319ULL,
        { 0.0f, 0.0f, 0.0f }, 0.8f, 1.0f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Blunt", 30.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/misc/xmas/candy cane club/candy_cane.projectile.prefab
    {
        "candy_cane_projectile", "assets/prefabs/misc/xmas/candy cane club/candy_cane.projectile.prefab", 1305651954ULL,
        { 0.0f, 0.0f, 0.0f }, 0.5f, 1.0f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 0.0f, 0.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Blunt", 12.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/weapons/cnyspear/cny_spear.projectile.prefab
    {
        "cny_spear_projectile", "assets/prefabs/weapons/cnyspear/cny_spear.projectile.prefab", 3091697167ULL,
        { 0.0f, 0.0f, 0.0f }, 0.1f, 2.0f, 0.2f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 1.0f, 0.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Arrow", 40.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/npc/m2bradley/coaxbullet.prefab
    {
        "coaxbullet", "assets/prefabs/npc/m2bradley/coaxbullet.prefab", 229321643ULL,
        { 0.0f, 0.0f, 0.0f }, 0.0f, 0.0f, 0.05f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.1f,
        { 10.0f, 100.0f }, { 1.0f, 0.8f },
        {
            { "Bullet", 45.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, false, true, false, true
    },
    // assets/prefabs/tools/lumberjack_tools/concrete_hatchet.projectile.prefab
    {
        "concrete_hatchet_projectile", "assets/prefabs/tools/lumberjack_tools/concrete_hatchet.projectile.prefab", 401287261ULL,
        { 0.0f, 0.0f, 0.0f }, 0.5f, 1.0f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 0.8f, 0.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Slash", 15.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/tools/lumberjack_tools/concrete_pickaxe.projectile.prefab
    {
        "concrete_pickaxe_projectile", "assets/prefabs/tools/lumberjack_tools/concrete_pickaxe.projectile.prefab", 2260704082ULL,
        { 0.0f, 0.0f, 0.0f }, 1.0f, 1.0f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 0.3f, 0.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Stab", 10.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/ammo/darts/incapacitate/dart_incapacitate.prefab
    {
        "dart_incapacitate", "assets/prefabs/ammo/darts/incapacitate/dart_incapacitate.prefab", 1399561535ULL,
        { 0.0f, 0.0f, 0.0f }, 0.005f, 0.75f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 1.0f, 0.1f,
        0.0f, 0.1f,
        { 10.0f, 60.0f }, { 1.0f, 0.8f },
        {
            { "Arrow", 15.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/ammo/darts/radiation/dart_radiation.prefab
    {
        "dart_radiation", "assets/prefabs/ammo/darts/radiation/dart_radiation.prefab", 2535553873ULL,
        { 0.0f, 0.0f, 0.0f }, 0.005f, 0.75f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 1.0f, 0.1f,
        0.0f, 0.1f,
        { 10.0f, 60.0f }, { 1.0f, 0.8f },
        {
            { "Arrow", 20.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/ammo/darts/scatter/dart_scatter.prefab
    {
        "dart_scatter", "assets/prefabs/ammo/darts/scatter/dart_scatter.prefab", 330613175ULL,
        { 0.0f, 0.0f, 0.0f }, 0.005f, 0.75f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        1.0f, 0.0f, 1.0f, 0.1f,
        0.0f, 0.1f,
        { 5.0f, 40.0f }, { 1.0f, 0.25f },
        {
            { "Arrow", 5.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, false, true, false, true
    },
    // assets/prefabs/ammo/darts/wood/dart_wood.prefab
    {
        "dart_wood", "assets/prefabs/ammo/darts/wood/dart_wood.prefab", 273669429ULL,
        { 0.0f, 0.0f, 0.0f }, 0.005f, 0.75f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 1.0f, 0.1f,
        0.0f, 0.1f,
        { 10.0f, 60.0f }, { 1.0f, 0.8f },
        {
            { "Arrow", 40.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/weapons/diverhatchet/diver_hatchet.projectile.prefab
    {
        "diver_hatchet_projectile", "assets/prefabs/weapons/diverhatchet/diver_hatchet.projectile.prefab", 1641313218ULL,
        { 0.0f, 0.0f, 0.0f }, 0.5f, 1.0f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 0.8f, 0.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Slash", 15.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/weapons/diverpickaxe/diver_pickaxe.projectile.prefab
    {
        "diver_pickaxe_projectile", "assets/prefabs/weapons/diverpickaxe/diver_pickaxe.projectile.prefab", 343429ULL,
        { 0.0f, 0.0f, 0.0f }, 0.5f, 1.0f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.1f, 0.0f, 0.8f, 0.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Stab", 20.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/food/pies/projectiles/food_pie_apple.projectile.prefab
    {
        "food_pie_apple_projectile", "assets/prefabs/food/pies/projectiles/food_pie_apple.projectile.prefab", 352441036ULL,
        { 0.0f, 0.0f, 0.0f }, 0.8f, 1.0f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 0.0f, 0.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Blunt", 10.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/food/pies/projectiles/food_pie_bear.projectile.prefab
    {
        "food_pie_bear_projectile", "assets/prefabs/food/pies/projectiles/food_pie_bear.projectile.prefab", 353782585ULL,
        { 0.0f, 0.0f, 0.0f }, 0.8f, 1.0f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 0.0f, 0.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Blunt", 10.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/food/pies/projectiles/food_pie_big_cat.projectile.prefab
    {
        "food_pie_big_cat_projectile", "assets/prefabs/food/pies/projectiles/food_pie_big_cat.projectile.prefab", 124739790ULL,
        { 0.0f, 0.0f, 0.0f }, 0.8f, 1.0f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 0.0f, 0.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Blunt", 10.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/food/pies/projectiles/food_pie_chicken.projectile.prefab
    {
        "food_pie_chicken_projectile", "assets/prefabs/food/pies/projectiles/food_pie_chicken.projectile.prefab", 3868670899ULL,
        { 0.0f, 0.0f, 0.0f }, 0.8f, 1.0f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 0.0f, 0.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Blunt", 10.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/food/pies/projectiles/food_pie_crocodile.projectile.prefab
    {
        "food_pie_crocodile_projectile", "assets/prefabs/food/pies/projectiles/food_pie_crocodile.projectile.prefab", 3109469561ULL,
        { 0.0f, 0.0f, 0.0f }, 0.8f, 1.0f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 0.0f, 0.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Blunt", 10.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/food/pies/projectiles/food_pie_fish.projectile.prefab
    {
        "food_pie_fish_projectile", "assets/prefabs/food/pies/projectiles/food_pie_fish.projectile.prefab", 3669067830ULL,
        { 0.0f, 0.0f, 0.0f }, 0.8f, 1.0f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 0.0f, 0.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Blunt", 10.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/food/pies/projectiles/food_pie_hunters.projectile.prefab
    {
        "food_pie_hunters_projectile", "assets/prefabs/food/pies/projectiles/food_pie_hunters.projectile.prefab", 704560237ULL,
        { 0.0f, 0.0f, 0.0f }, 0.8f, 1.0f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 0.0f, 0.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Blunt", 10.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/food/pies/projectiles/food_pie_pork.projectile.prefab
    {
        "food_pie_pork_projectile", "assets/prefabs/food/pies/projectiles/food_pie_pork.projectile.prefab", 1238910629ULL,
        { 0.0f, 0.0f, 0.0f }, 0.8f, 1.0f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 0.0f, 0.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Blunt", 10.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/food/pies/projectiles/food_pie_pumkin.projectile.prefab
    {
        "food_pie_pumkin_projectile", "assets/prefabs/food/pies/projectiles/food_pie_pumkin.projectile.prefab", 1357070519ULL,
        { 0.0f, 0.0f, 0.0f }, 0.8f, 1.0f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 0.0f, 0.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Blunt", 10.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/food/pies/projectiles/food_pie_survivors.projectile.prefab
    {
        "food_pie_survivors_projectile", "assets/prefabs/food/pies/projectiles/food_pie_survivors.projectile.prefab", 1526226691ULL,
        { 0.0f, 0.0f, 0.0f }, 0.8f, 1.0f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 0.0f, 0.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Blunt", 10.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/weapons/frontier hatchet/frontier_hatchet.projectile.prefab
    {
        "frontier_hatchet_projectile", "assets/prefabs/weapons/frontier hatchet/frontier_hatchet.projectile.prefab", 2365516520ULL,
        { 0.0f, 0.0f, 0.0f }, 0.5f, 1.0f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 0.8f, 0.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Slash", 15.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/weapons/salvaged_hammer/hammer_salvaged.projectile.prefab
    {
        "hammer_salvaged_projectile", "assets/prefabs/weapons/salvaged_hammer/hammer_salvaged.projectile.prefab", 1094174291ULL,
        { 0.0f, 0.0f, 0.0f }, 0.5f, 1.0f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.1f, 0.0f, 0.0f, 0.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Blunt", 20.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/ammo/handmade shell/handmade_shell.projectile.prefab
    {
        "handmade_shell_projectile", "assets/prefabs/ammo/handmade shell/handmade_shell.projectile.prefab", 3767492197ULL,
        { 0.0f, 0.0f, 0.0f }, 1.0f, 1.0f, 0.1f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        1.0f, 0.5f, 1.0f, 0.0f,
        0.0f, 0.1f,
        { 10.0f, 20.0f }, { 1.0f, 0.25f },
        {
            { "Bullet", 9.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, false, true, false, true
    },
    // assets/prefabs/weapons/hatchet/hatchet.projectile.prefab
    {
        "hatchet_projectile", "assets/prefabs/weapons/hatchet/hatchet.projectile.prefab", 49111812ULL,
        { 0.0f, 0.0f, 0.0f }, 0.5f, 1.0f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 0.8f, 0.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Slash", 15.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/weapons/stone hatchet/hatchet_stone.projectile.prefab
    {
        "hatchet_stone_projectile", "assets/prefabs/weapons/stone hatchet/hatchet_stone.projectile.prefab", 2075930968ULL,
        { 0.0f, 0.0f, 0.0f }, 0.5f, 1.0f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 0.8f, 0.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Slash", 10.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/npc/patrol helicopter/helibullet.prefab
    {
        "helibullet", "assets/prefabs/npc/patrol helicopter/helibullet.prefab", 1410987015ULL,
        { 0.0f, 0.0f, 0.0f }, 0.0f, 0.0f, 0.05f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.1f,
        { 10.0f, 100.0f }, { 1.0f, 0.8f },
        {
            { "Bullet", 45.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, false, true, false, true
    },
    // assets/prefabs/weapons/salvaged_icepick/icepick_salvaged.projectile.prefab
    {
        "icepick_salvaged_projectile", "assets/prefabs/weapons/salvaged_icepick/icepick_salvaged.projectile.prefab", 2329154564ULL,
        { 0.0f, 0.0f, 0.0f }, 0.5f, 1.0f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.1f, 0.0f, 0.8f, 0.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Stab", 15.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/weapons/knife/knife.combat.projectile.prefab
    {
        "knife_combat_projectile", "assets/prefabs/weapons/knife/knife.combat.projectile.prefab", 742765807ULL,
        { 0.0f, 0.0f, 0.0f }, 0.5f, 1.0f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 0.0f, 0.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Slash", 50.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/weapons/sword big/longsword.projectile.prefab
    {
        "longsword_projectile", "assets/prefabs/weapons/sword big/longsword.projectile.prefab", 151139324ULL,
        { 0.0f, 0.0f, 0.0f }, 0.5f, 1.0f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.1f, 0.0f, 1.0f, 0.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Slash", 30.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/tools/lumberjack_tools/lumberjack_axe.projectile.prefab
    {
        "lumberjack_axe_projectile", "assets/prefabs/tools/lumberjack_tools/lumberjack_axe.projectile.prefab", 623030135ULL,
        { 0.0f, 0.0f, 0.0f }, 0.5f, 1.0f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 0.8f, 0.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Slash", 15.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/tools/lumberjack_tools/lumberjack_pick.projectile.prefab
    {
        "lumberjack_pick_projectile", "assets/prefabs/tools/lumberjack_tools/lumberjack_pick.projectile.prefab", 3896353015ULL,
        { 0.0f, 0.0f, 0.0f }, 0.5f, 1.0f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 0.8f, 0.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Slash", 15.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/weapons/halloween/baseballbat/mace.baseballbat.projectile.prefab
    {
        "mace_baseballbat_projectile", "assets/prefabs/weapons/halloween/baseballbat/mace.baseballbat.projectile.prefab", 1500539487ULL,
        { 0.0f, 0.0f, 0.0f }, 0.5f, 1.0f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.1f, 0.0f, 0.0f, 0.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Blunt", 30.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/weapons/mace/mace.projectile.prefab
    {
        "mace_projectile", "assets/prefabs/weapons/mace/mace.projectile.prefab", 3224207227ULL,
        { 0.0f, 0.0f, 0.0f }, 0.5f, 1.0f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.1f, 0.0f, 0.0f, 0.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Blunt", 30.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/weapons/machete/machete.projectile.prefab
    {
        "machete_projectile", "assets/prefabs/weapons/machete/machete.projectile.prefab", 1013976023ULL,
        { 0.0f, 0.0f, 0.0f }, 0.5f, 1.0f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.1f, 0.0f, 0.8f, 0.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Slash", 20.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/ammo/nails/nail.prefab
    {
        "nail", "assets/prefabs/ammo/nails/nail.prefab", 2577479505ULL,
        { 0.0f, 0.0f, 0.0f }, 0.005f, 0.75f, 0.1f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 1.0f, 0.1f,
        0.0f, 0.1f,
        { 10.0f, 60.0f }, { 1.0f, 0.8f },
        {
            { "Arrow", 18.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/weapons/paddle/paddle.projectile.prefab
    {
        "paddle_projectile", "assets/prefabs/weapons/paddle/paddle.projectile.prefab", 4180286157ULL,
        { 0.0f, 0.0f, 0.0f }, 0.1f, 2.0f, 0.2f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 1.0f, 0.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Arrow", 40.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/ammo/paintball/paintballpellet.prefab
    {
        "paintballpellet", "assets/prefabs/ammo/paintball/paintballpellet.prefab", 362629199ULL,
        { 0.0f, 0.0f, 0.0f }, 0.7f, 1.0f, 0.05f,
        5.0f, { 0.0f, 0.0f, 0.0f },
        0.0f, 0.0f, 1.0f, 0.0f,
        0.2f, 1.0f,
        { 10.0f, 60.0f }, { 1.0f, 0.8f },
        {
            { "Paintball", 0.2f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, false, false, false, true
    },
    // assets/prefabs/weapons/pickaxe/pickaxe.projectile.prefab
    {
        "pickaxe_projectile", "assets/prefabs/weapons/pickaxe/pickaxe.projectile.prefab", 2826373220ULL,
        { 0.0f, 0.0f, 0.0f }, 0.5f, 1.0f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.1f, 0.0f, 0.8f, 0.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Stab", 20.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/ammo/pistol/pistolbullet.prefab
    {
        "pistolbullet", "assets/prefabs/ammo/pistol/pistolbullet.prefab", 2421548478ULL,
        { 0.0f, 0.0f, 0.0f }, 0.7f, 1.0f, 0.05f,
        15.0f, { 0.0f, 0.0f, 0.0f },
        1.0f, 0.4f, 1.0f, 0.0f,
        0.0f, 0.1f,
        { 10.0f, 60.0f }, { 1.0f, 0.8f },
        {
            { "Bullet", 50.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, false, true, false, true
    },
    // assets/prefabs/ammo/pistol/pistolbullet_fire.prefab
    {
        "pistolbullet_fire", "assets/prefabs/ammo/pistol/pistolbullet_fire.prefab", 3575118940ULL,
        { 0.0f, 0.0f, 0.0f }, 0.7f, 1.0f, 0.05f,
        15.0f, { 0.0f, 0.0f, 0.0f },
        1.0f, 0.6f, 1.0f, 0.0f,
        0.0f, 0.1f,
        { 10.0f, 60.0f }, { 1.0f, 0.8f },
        {
            { "Bullet", 50.0f },
            { "Heat", 6.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        2, false, true, false, true
    },
    // assets/prefabs/weapons/halloween/pitchfork/pitchfork.projectile.prefab
    {
        "pitchfork_projectile", "assets/prefabs/weapons/halloween/pitchfork/pitchfork.projectile.prefab", 294164989ULL,
        { 0.0f, 0.0f, 0.0f }, 0.1f, 2.0f, 0.2f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 1.0f, 0.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Arrow", 50.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/ammo/rifle/riflebullet.prefab
    {
        "riflebullet", "assets/prefabs/ammo/rifle/riflebullet.prefab", 1887514499ULL,
        { 0.0f, 0.0f, 0.0f }, 0.6f, 1.0f, 0.05f,
        15.0f, { 0.0f, 0.0f, 0.0f },
        2.0f, 0.4f, 1.0f, 0.0f,
        0.0f, 0.1f,
        { 20.0f, 100.0f }, { 1.0f, 0.8f },
        {
            { "Bullet", 50.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, false, true, false, true
    },
    // assets/prefabs/ammo/rifle/riflebullet_explosive.prefab
    {
        "riflebullet_explosive", "assets/prefabs/ammo/rifle/riflebullet_explosive.prefab", 1798302402ULL,
        { 0.0f, 0.0f, 0.0f }, 0.6f, 1.25f, 0.05f,
        15.0f, { 0.0f, 0.0f, 0.0f },
        1.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.1f,
        { 20.0f, 100.0f }, { 1.0f, 0.8f },
        {
            { "Bullet", 50.0f },
            { "Explosion", 0.01f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        2, false, true, false, true
    },
    // assets/prefabs/ammo/rifle/riflebullet_fire.prefab
    {
        "riflebullet_fire", "assets/prefabs/ammo/rifle/riflebullet_fire.prefab", 2828814118ULL,
        { 0.0f, 0.0f, 0.0f }, 0.6f, 1.0f, 0.05f,
        15.0f, { 0.0f, 0.0f, 0.0f },
        1.0f, 0.6f, 1.0f, 0.0f,
        0.0f, 0.1f,
        { 20.0f, 100.0f }, { 1.0f, 0.8f },
        {
            { "Bullet", 50.0f },
            { "Heat", 6.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        2, false, true, false, true
    },
    // assets/prefabs/weapons/rock/skins/rock_a_jungle/rock.a.jungle.projectile.prefab
    {
        "rock_a_jungle_projectile", "assets/prefabs/weapons/rock/skins/rock_a_jungle/rock.a.jungle.projectile.prefab", 1386261849ULL,
        { 0.0f, 0.0f, 0.0f }, 0.8f, 1.0f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 0.0f, 0.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Blunt", 10.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/weapons/rock/rock.projectile.prefab
    {
        "rock_projectile", "assets/prefabs/weapons/rock/rock.projectile.prefab", 3398080445ULL,
        { 0.0f, 0.0f, 0.0f }, 0.8f, 1.0f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 0.0f, 0.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Blunt", 10.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/weapons/cleaver big/salvaged_cleaver.projectile.prefab
    {
        "salvaged_cleaver_projectile", "assets/prefabs/weapons/cleaver big/salvaged_cleaver.projectile.prefab", 3761252112ULL,
        { 0.0f, 0.0f, 0.0f }, 0.5f, 1.0f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.1f, 0.0f, 1.0f, 0.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Slash", 30.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/weapons/sword/salvaged_sword.projectile.prefab
    {
        "salvaged_sword_projectile", "assets/prefabs/weapons/sword/salvaged_sword.projectile.prefab", 922652660ULL,
        { 0.0f, 0.0f, 0.0f }, 0.5f, 1.0f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.1f, 0.0f, 0.8f, 0.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Slash", 20.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/rust.ai/agents/npcplayer/humannpc/scientist/gen2/scientist2.clientricochet.prefab
    {
        "scientist2_clientricochet", "assets/rust.ai/agents/npcplayer/humannpc/scientist/gen2/scientist2.clientricochet.prefab", 3239136573ULL,
        { 0.0f, 0.0f, 0.0f }, 0.0f, 0.0f, 0.05f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.1f,
        { 10.0f, 100.0f }, { 1.0f, 0.8f },
        {
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        0, false, false, false, false
    },
    // assets/prefabs/ammo/shotgun/shotgunbullet.prefab
    {
        "shotgunbullet", "assets/prefabs/ammo/shotgun/shotgunbullet.prefab", 1991236224ULL,
        { 0.0f, 0.0f, 0.0f }, 1.0f, 1.0f, 0.1f,
        3.0f, { 0.0f, 0.0f, 0.0f },
        1.0f, 0.4f, 1.0f, 0.0f,
        0.0f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.25f },
        {
            { "Bullet", 15.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, false, true, false, true
    },
    // assets/prefabs/ammo/shotgun/shotgunbullet_fire.prefab
    {
        "shotgunbullet_fire", "assets/prefabs/ammo/shotgun/shotgunbullet_fire.prefab", 2206685111ULL,
        { 0.0f, 0.0f, 0.0f }, 1.0f, 1.0f, 0.2f,
        3.0f, { 0.0f, 0.0f, 0.0f },
        1.0f, 0.5f, 1.0f, 0.0f,
        0.0f, 0.1f,
        { 10.0f, 20.0f }, { 1.0f, 0.25f },
        {
            { "Bullet", 10.0f },
            { "Heat", 5.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        2, false, true, false, true
    },
    // assets/prefabs/ammo/shotgun/shotgunslug.prefab
    {
        "shotgunslug", "assets/prefabs/ammo/shotgun/shotgunslug.prefab", 648078183ULL,
        { 0.0f, 0.0f, 0.0f }, 0.6f, 1.0f, 0.1f,
        10.0f, { 0.0f, 0.0f, 0.0f },
        2.0f, 0.4f, 1.0f, 0.0f,
        0.0f, 0.1f,
        { 20.0f, 40.0f }, { 1.0f, 0.5f },
        {
            { "Bullet", 80.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, false, true, false, true
    },
    // assets/prefabs/tools/shovel/shovel.projectile.prefab
    {
        "shovel_projectile", "assets/prefabs/tools/shovel/shovel.projectile.prefab", 1418103607ULL,
        { 0.0f, 0.0f, 0.0f }, 0.5f, 1.0f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 1.0f, 0.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Slash", 10.0f },
            { "Stab", 10.0f },
            { "Generic", 0.1f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        3, true, true, false, true
    },
    // assets/prefabs/weapons/halloween/sickle/sickle.projectile.prefab
    {
        "sickle_projectile", "assets/prefabs/weapons/halloween/sickle/sickle.projectile.prefab", 1396162423ULL,
        { 0.0f, 0.0f, 0.0f }, 0.5f, 1.0f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 0.8f, 0.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Slash", 15.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/misc/decor_dlc/skinning knife/skinningknife.projectile.prefab
    {
        "skinningknife_projectile", "assets/prefabs/misc/decor_dlc/skinning knife/skinningknife.projectile.prefab", 2093157093ULL,
        { 0.0f, 0.0f, 0.0f }, 0.5f, 1.0f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 0.8f, 0.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Slash", 10.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/weapons/halloween/skull_halloween/skull.projectile.prefab
    {
        "skull_projectile", "assets/prefabs/weapons/halloween/skull_halloween/skull.projectile.prefab", 361494112ULL,
        { 0.0f, 0.0f, 0.0f }, 0.8f, 1.0f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 0.0f, 0.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Blunt", 10.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/misc/xmas/snowball/snowball.projectile.prefab
    {
        "snowball_projectile", "assets/prefabs/misc/xmas/snowball/snowball.projectile.prefab", 2931445184ULL,
        { 0.0f, 0.0f, 0.0f }, 0.8f, 1.0f, 0.2f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 0.0f, 1.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Blunt", 25.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, false
    },
    // assets/prefabs/misc/xmas/snowballgun/snowballgunbullet.prefab
    {
        "snowballgunbullet", "assets/prefabs/misc/xmas/snowballgun/snowballgunbullet.prefab", 2018030618ULL,
        { 0.0f, 0.0f, 0.0f }, 0.0f, 0.75f, 0.3f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        1.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.1f,
        { 20.0f, 100.0f }, { 1.0f, 0.8f },
        {
            { "Blunt", 8.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, false, true, false, true
    },
    // assets/prefabs/ammo/speargun/speargun_spear.prefab
    {
        "speargun_spear", "assets/prefabs/ammo/speargun/speargun_spear.prefab", 2551075186ULL,
        { 0.0f, 0.0f, 0.0f }, 0.05f, 0.3f, 0.2f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.0f, 0.0f, 1.0f, 0.1f,
        0.0f, 0.0f,
        { 10.0f, 60.0f }, { 1.0f, 0.8f },
        {
            { "Arrow", 50.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/weapons/stone pickaxe/stone_pickaxe.projectile.prefab
    {
        "stone_pickaxe_projectile", "assets/prefabs/weapons/stone pickaxe/stone_pickaxe.projectile.prefab", 3575089225ULL,
        { 0.0f, 0.0f, 0.0f }, 1.0f, 1.0f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 0.3f, 0.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Stab", 10.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/weapons/stone spear/stone_spear.projectile.prefab
    {
        "stone_spear_projectile", "assets/prefabs/weapons/stone spear/stone_spear.projectile.prefab", 1516542433ULL,
        { 0.0f, 0.0f, 0.0f }, 0.1f, 2.0f, 0.2f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 1.0f, 0.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Arrow", 50.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/weapons/knife/skins/sunkenknife/sunkenknife.projectile.prefab
    {
        "sunkenknife_projectile", "assets/prefabs/weapons/knife/skins/sunkenknife/sunkenknife.projectile.prefab", 465698672ULL,
        { 0.0f, 0.0f, 0.0f }, 0.5f, 1.0f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 0.0f, 0.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Blunt", 12.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    },
    // assets/prefabs/deployable/single shot trap/trapbullet.prefab
    {
        "trapbullet", "assets/prefabs/deployable/single shot trap/trapbullet.prefab", 2237911942ULL,
        { 0.0f, 0.0f, 0.0f }, 0.7f, 1.0f, 0.05f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        1.0f, 0.4f, 1.0f, 0.0f,
        0.0f, 0.1f,
        { 10.0f, 100.0f }, { 1.0f, 0.8f },
        {
            { "Bullet", 35.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, false, true, false, false
    },
    // assets/prefabs/weapons/halloween/vampirestake/vampirestake.projectile.prefab
    {
        "vampirestake_projectile", "assets/prefabs/weapons/halloween/vampirestake/vampirestake.projectile.prefab", 950430757ULL,
        { 0.0f, 0.0f, 0.0f }, 0.5f, 1.0f, 0.15f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 0.0f, 1.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Slash", 10.0f },
            { "Stab", 10.0f },
            { "Generic", 0.1f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        3, false, true, false, true
    },
    // assets/prefabs/weapons/wooden spear/wooden_spear.projectile.prefab
    {
        "wooden_spear_projectile", "assets/prefabs/weapons/wooden spear/wooden_spear.projectile.prefab", 3022308042ULL,
        { 0.0f, 0.0f, 0.0f }, 0.1f, 2.0f, 0.2f,
        0.0f, { 0.0f, 0.0f, 0.0f },
        0.5f, 0.0f, 1.0f, 0.0f,
        0.04f, 0.1f,
        { 10.0f, 40.0f }, { 1.0f, 0.8f },
        {
            { "Arrow", 40.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
            { "", 0.0f },
        },
        1, true, true, false, true
    }
};

inline const ProjectileData* GetByName(const char* name) noexcept
{
    if (!name) return nullptr;
    for (std::size_t i = 0; i < kCount; ++i)
        if (std::strcmp(kData[i].name, name) == 0) return &kData[i];
    return nullptr;
}

inline const ProjectileData* GetByHash(std::uint64_t hash) noexcept
{
    switch (hash)
    {
    case 1175273260ULL: return &kData[0]; // arrow_bone
    case 100479866ULL: return &kData[1]; // arrow_fire
    case 4135687601ULL: return &kData[2]; // arrow_hv
    case 70335961ULL: return &kData[3]; // arrow_wooden
    case 3381823385ULL: return &kData[4]; // axe_salvaged_projectile
    case 3841293998ULL: return &kData[5]; // ballista_bolt_hammerhead_projectile
    case 2634460531ULL: return &kData[6]; // ballista_bolt_incendiary_projectile
    case 2301406582ULL: return &kData[7]; // ballista_bolt_piercer_projectile
    case 3329430643ULL: return &kData[8]; // ballista_bolt_pitchfork_projectile
    case 916499682ULL: return &kData[9]; // bone_knife_obsidian_projectile
    case 1871533806ULL: return &kData[10]; // boneclub_projectile
    case 1077356552ULL: return &kData[11]; // boneknife_projectile
    case 1017853410ULL: return &kData[12]; // butcherknife_projectile
    case 2714474319ULL: return &kData[13]; // cake_projectile
    case 1305651954ULL: return &kData[14]; // candy_cane_projectile
    case 3091697167ULL: return &kData[15]; // cny_spear_projectile
    case 229321643ULL: return &kData[16]; // coaxbullet
    case 401287261ULL: return &kData[17]; // concrete_hatchet_projectile
    case 2260704082ULL: return &kData[18]; // concrete_pickaxe_projectile
    case 1399561535ULL: return &kData[19]; // dart_incapacitate
    case 2535553873ULL: return &kData[20]; // dart_radiation
    case 330613175ULL: return &kData[21]; // dart_scatter
    case 273669429ULL: return &kData[22]; // dart_wood
    case 1641313218ULL: return &kData[23]; // diver_hatchet_projectile
    case 343429ULL: return &kData[24]; // diver_pickaxe_projectile
    case 352441036ULL: return &kData[25]; // food_pie_apple_projectile
    case 353782585ULL: return &kData[26]; // food_pie_bear_projectile
    case 124739790ULL: return &kData[27]; // food_pie_big_cat_projectile
    case 3868670899ULL: return &kData[28]; // food_pie_chicken_projectile
    case 3109469561ULL: return &kData[29]; // food_pie_crocodile_projectile
    case 3669067830ULL: return &kData[30]; // food_pie_fish_projectile
    case 704560237ULL: return &kData[31]; // food_pie_hunters_projectile
    case 1238910629ULL: return &kData[32]; // food_pie_pork_projectile
    case 1357070519ULL: return &kData[33]; // food_pie_pumkin_projectile
    case 1526226691ULL: return &kData[34]; // food_pie_survivors_projectile
    case 2365516520ULL: return &kData[35]; // frontier_hatchet_projectile
    case 1094174291ULL: return &kData[36]; // hammer_salvaged_projectile
    case 3767492197ULL: return &kData[37]; // handmade_shell_projectile
    case 49111812ULL: return &kData[38]; // hatchet_projectile
    case 2075930968ULL: return &kData[39]; // hatchet_stone_projectile
    case 1410987015ULL: return &kData[40]; // helibullet
    case 2329154564ULL: return &kData[41]; // icepick_salvaged_projectile
    case 742765807ULL: return &kData[42]; // knife_combat_projectile
    case 151139324ULL: return &kData[43]; // longsword_projectile
    case 623030135ULL: return &kData[44]; // lumberjack_axe_projectile
    case 3896353015ULL: return &kData[45]; // lumberjack_pick_projectile
    case 1500539487ULL: return &kData[46]; // mace_baseballbat_projectile
    case 3224207227ULL: return &kData[47]; // mace_projectile
    case 1013976023ULL: return &kData[48]; // machete_projectile
    case 2577479505ULL: return &kData[49]; // nail
    case 4180286157ULL: return &kData[50]; // paddle_projectile
    case 362629199ULL: return &kData[51]; // paintballpellet
    case 2826373220ULL: return &kData[52]; // pickaxe_projectile
    case 2421548478ULL: return &kData[53]; // pistolbullet
    case 3575118940ULL: return &kData[54]; // pistolbullet_fire
    case 294164989ULL: return &kData[55]; // pitchfork_projectile
    case 1887514499ULL: return &kData[56]; // riflebullet
    case 1798302402ULL: return &kData[57]; // riflebullet_explosive
    case 2828814118ULL: return &kData[58]; // riflebullet_fire
    case 1386261849ULL: return &kData[59]; // rock_a_jungle_projectile
    case 3398080445ULL: return &kData[60]; // rock_projectile
    case 3761252112ULL: return &kData[61]; // salvaged_cleaver_projectile
    case 922652660ULL: return &kData[62]; // salvaged_sword_projectile
    case 3239136573ULL: return &kData[63]; // scientist2_clientricochet
    case 1991236224ULL: return &kData[64]; // shotgunbullet
    case 2206685111ULL: return &kData[65]; // shotgunbullet_fire
    case 648078183ULL: return &kData[66]; // shotgunslug
    case 1418103607ULL: return &kData[67]; // shovel_projectile
    case 1396162423ULL: return &kData[68]; // sickle_projectile
    case 2093157093ULL: return &kData[69]; // skinningknife_projectile
    case 361494112ULL: return &kData[70]; // skull_projectile
    case 2931445184ULL: return &kData[71]; // snowball_projectile
    case 2018030618ULL: return &kData[72]; // snowballgunbullet
    case 2551075186ULL: return &kData[73]; // speargun_spear
    case 3575089225ULL: return &kData[74]; // stone_pickaxe_projectile
    case 1516542433ULL: return &kData[75]; // stone_spear_projectile
    case 465698672ULL: return &kData[76]; // sunkenknife_projectile
    case 2237911942ULL: return &kData[77]; // trapbullet
    case 950430757ULL: return &kData[78]; // vampirestake_projectile
    case 3022308042ULL: return &kData[79]; // wooden_spear_projectile
    default: return nullptr;
    }
}
} // namespace Projectiles
} // namespace RustData

#endif // RUST_DATA_PROJECTILE_DATA_HPP
