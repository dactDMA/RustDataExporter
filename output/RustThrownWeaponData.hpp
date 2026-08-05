//
// Auto-generated Rust ThrownWeapon Data
// Generated: 2026-08-05 19:24:38 UTC
// Target: Protocol 2631.286.1 / Changeset 158240
// Total entries: 13
// Generator: RustDataExporter
//
// This file is generated from server-side Rust prefabs/components.
// Do not edit by hand.
//

#pragma once
#ifndef RUST_DATA_THROWN_WEAPON_DATA_HPP
#define RUST_DATA_THROWN_WEAPON_DATA_HPP

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <limits>

namespace RustData
{
namespace ThrownWeapons
{

struct Vec3 { float x; float y; float z; };
struct ResourceRefData { const char* path; std::uint32_t id; bool is_valid; };
struct ExtraFieldData { const char* name; const char* declaring_type; const char* value_type; const char* value; };
struct AttackData { float deploy_delay; float repeat_delay; float animation_delay; };
struct NpcData
{
    float effective_range; float damage_scale;
    float attack_length_min; float attack_length_max; float attack_spacing;
    float aim_sway_offset; float aim_cone; bool only_in_range;
    float close_range_addition; float medium_range_addition; float long_range_addition;
    bool can_use_at_medium_range; bool can_use_at_long_range;
};
struct HeldData
{
    bool can_use_with_shield; bool is_building_tool; float hostility_score;
    Vec3 first_person_arm_offset; Vec3 first_person_arm_rotation;
    float first_person_rotation_strength;
};

struct ThrownWeaponData
{
    const char* name;
    const char* prefab_path;
    std::uint32_t hash;
    const char* concrete_type;
    std::size_t first_type;
    std::size_t type_count;
    std::size_t first_item_shortname;
    std::size_t item_shortname_count;
    ResourceRefData prefab_to_throw;
    bool throws_timed_explosive;
    const char* thrown_explosive_type;
    float max_throw_velocity;
    float tumble_velocity;
    Vec3 override_angle;
    bool can_stick;
    bool can_throw_underwater;
    bool can_throw_from_helicopter;
    const char* throw_object_root_name;
    AttackData attack;
    NpcData npc;
    HeldData held;
    std::size_t first_extra_field;
    std::size_t extra_field_count;
};

inline constexpr std::size_t kTypeNamesCount = 50;
inline constexpr const char* kTypeNames[kTypeNamesCount == 0 ? 1 : kTypeNamesCount] =
{
    "ThrownWeapon",
    "AttackEntity",
    "HeldEntity",
    "ThrownWeapon",
    "AttackEntity",
    "HeldEntity",
    "GrenadeWeapon",
    "ThrownWeapon",
    "AttackEntity",
    "HeldEntity",
    "RecorderTool",
    "ThrownWeapon",
    "AttackEntity",
    "HeldEntity",
    "GrenadeWeapon",
    "ThrownWeapon",
    "AttackEntity",
    "HeldEntity",
    "GrenadeWeapon",
    "ThrownWeapon",
    "AttackEntity",
    "HeldEntity",
    "GrenadeWeapon",
    "ThrownWeapon",
    "AttackEntity",
    "HeldEntity",
    "GrenadeWeapon",
    "ThrownWeapon",
    "AttackEntity",
    "HeldEntity",
    "MolotovCocktail",
    "GrenadeWeapon",
    "ThrownWeapon",
    "AttackEntity",
    "HeldEntity",
    "GrenadeWeapon",
    "ThrownWeapon",
    "AttackEntity",
    "HeldEntity",
    "GrenadeWeapon",
    "ThrownWeapon",
    "AttackEntity",
    "HeldEntity",
    "GrenadeWeapon",
    "ThrownWeapon",
    "AttackEntity",
    "HeldEntity",
    "ThrownWeapon",
    "AttackEntity",
    "HeldEntity",
};

inline constexpr std::size_t kItemShortnamesCount = 13;
inline constexpr const char* kItemShortnames[kItemShortnamesCount == 0 ? 1 : kItemShortnamesCount] =
{
    "explosive.satchel",
    "explosive.timed",
    "flare",
    "fun.casetterecorder",
    "grenade.beancan",
    "grenade.bee",
    "grenade.f1",
    "grenade.flashbang",
    "grenade.molotov",
    "grenade.smoke",
    "lunar.firecrackers",
    "supply.signal",
    "surveycharge",
};

inline constexpr std::size_t kExtraFieldsCount = 7;
inline constexpr ExtraFieldData kExtraFields[kExtraFieldsCount == 0 ? 1 : kExtraFieldsCount] =
{
    { "PlayTapeSfx", "RecorderTool", "SoundDefinition", "cassette-recorder-start (SoundDefinition)" },
    { "RecordFinishedSfx", "RecorderTool", "SoundDefinition", "cassette-recorder-recording-stop (SoundDefinition)" },
    { "RecordStartSfx", "RecorderTool", "SoundDefinition", "cassette-recorder-recording-start (SoundDefinition)" },
    { "RecorderAudioSource", "RecorderTool", "UnityEngine.AudioSource", "" },
    { "RewindSfx", "RecorderTool", "SoundDefinition", "cassette-recorder-rewind (SoundDefinition)" },
    { "StopTapeSfx", "RecorderTool", "SoundDefinition", "cassette-recorder-stop (SoundDefinition)" },
    { "ThrowScale", "RecorderTool", "System.Single", "3" },
};

inline constexpr std::size_t kCount = 13;
inline constexpr ThrownWeaponData kData[kCount == 0 ? 1 : kCount] =
{
    // assets/prefabs/weapons/satchelcharge/explosive.satchel.entity.prefab
    {
        "explosive.satchel", "assets/prefabs/weapons/satchelcharge/explosive.satchel.entity.prefab", 2671523489U, "ThrownWeapon", 0, 3, 0, 1,
        { "assets/prefabs/weapons/satchelcharge/explosive.satchel.deployed.prefab", 2742759844U, true }, true, "DudTimedExplosive",
        10.0f, 0.0f, { 0.0f, 0.0f, 0.0f }, true, true, true, "",
        { 0.75f, 1.5f, 0.0f },
        { 1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 9.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f },
        0, 0
    },
    // assets/prefabs/tools/c4/explosive.timed.entity.prefab
    {
        "explosive.timed", "assets/prefabs/tools/c4/explosive.timed.entity.prefab", 1915331115U, "ThrownWeapon", 3, 3, 1, 1,
        { "assets/prefabs/tools/c4/explosive.timed.deployed.prefab", 3898309212U, true }, true, "RFTimedExplosive",
        10.0f, 0.0f, { 0.0f, 0.0f, 0.0f }, true, true, true, "",
        { 0.75f, 1.5f, 0.0f },
        { 1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 10.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f },
        0, 0
    },
    // assets/prefabs/tools/flareold/flare.weapon.prefab
    {
        "flare", "assets/prefabs/tools/flareold/flare.weapon.prefab", 2661658442U, "GrenadeWeapon", 6, 4, 2, 1,
        { "assets/prefabs/tools/flareold/flare.deployed.prefab", 1693887801U, true }, true, "RoadFlare",
        13.0f, 40.0f, { 0.0f, 0.0f, 0.0f }, true, true, true, "",
        { 1.0f, 0.5f, 0.0f },
        { 1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 0.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f },
        0, 0
    },
    // assets/prefabs/voiceaudio/cassetterecorder/cassetterecorder.weapon.prefab
    {
        "fun.casetterecorder", "assets/prefabs/voiceaudio/cassetterecorder/cassetterecorder.weapon.prefab", 705457609U, "RecorderTool", 10, 4, 3, 1,
        { "assets/prefabs/voiceaudio/cassetterecorder/cassetterecorder.deployed.prefab", 760079751U, true }, false, "",
        10.0f, 0.0f, { 0.0f, 0.0f, 0.0f }, true, true, true, "",
        { 1.0f, 0.5f, 0.0f },
        { 1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 0.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f },
        0, 7
    },
    // assets/prefabs/weapons/beancan grenade/grenade.beancan.entity.prefab
    {
        "grenade.beancan", "assets/prefabs/weapons/beancan grenade/grenade.beancan.entity.prefab", 3654150932U, "GrenadeWeapon", 14, 4, 4, 1,
        { "assets/prefabs/weapons/beancan grenade/grenade.beancan.deployed.prefab", 2144399804U, true }, true, "DudTimedExplosive",
        13.0f, 40.0f, { 0.0f, 0.0f, 0.0f }, true, false, true, "VisualRoot",
        { 0.5f, 0.5f, 0.0f },
        { 1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 5.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f },
        7, 0
    },
    // assets/prefabs/weapons/bee grenade/grenade.bee.entity.prefab
    {
        "grenade.bee", "assets/prefabs/weapons/bee grenade/grenade.bee.entity.prefab", 3444797639U, "GrenadeWeapon", 18, 4, 5, 1,
        { "assets/prefabs/weapons/bee grenade/grenade.bee.deployed.prefab", 4036845226U, true }, true, "BeeGrenade",
        13.0f, 40.0f, { 0.0f, 0.0f, 0.0f }, false, true, true, "w_Bee_Grenade",
        { 0.5f, 0.5f, 0.0f },
        { 15.0f, 0.2f, -1.0f, -1.0f, 10.0f, 0.0f, 0.0f, false, 0.0f, 0.0f, 0.0f, true, false },
        { false, false, 7.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f },
        7, 0
    },
    // assets/prefabs/weapons/f1 grenade/grenade.f1.entity.prefab
    {
        "grenade.f1", "assets/prefabs/weapons/f1 grenade/grenade.f1.entity.prefab", 45697420U, "GrenadeWeapon", 22, 4, 6, 1,
        { "assets/prefabs/weapons/f1 grenade/grenade.f1.deployed.prefab", 1128089209U, true }, true, "TimedExplosive",
        13.0f, 40.0f, { 0.0f, 0.0f, 0.0f }, true, true, true, "",
        { 0.5f, 0.5f, 0.0f },
        { 15.0f, 0.2f, -1.0f, -1.0f, 10.0f, 0.0f, 0.0f, false, 0.0f, 0.0f, 0.0f, true, false },
        { false, false, 7.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f },
        7, 0
    },
    // assets/prefabs/weapons/flashbang/grenade.flashbang.entity.prefab
    {
        "grenade.flashbang", "assets/prefabs/weapons/flashbang/grenade.flashbang.entity.prefab", 758326244U, "GrenadeWeapon", 26, 4, 7, 1,
        { "assets/prefabs/weapons/flashbang/grenade.flashbang.deployed.prefab", 1436152685U, true }, true, "Flashbang",
        13.0f, 40.0f, { 0.0f, 0.0f, 0.0f }, true, true, true, "",
        { 0.5f, 0.5f, 0.0f },
        { 15.0f, 0.2f, -1.0f, -1.0f, 10.0f, 0.0f, 0.0f, false, 0.0f, 0.0f, 0.0f, true, false },
        { false, false, 7.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f },
        7, 0
    },
    // assets/prefabs/weapons/molotov cocktail/grenade.molotov.entity.prefab
    {
        "grenade.molotov", "assets/prefabs/weapons/molotov cocktail/grenade.molotov.entity.prefab", 4104126979U, "MolotovCocktail", 30, 5, 8, 1,
        { "assets/prefabs/weapons/molotov cocktail/grenade.molotov.deployed.prefab", 2144253630U, true }, true, "FlameExplosive",
        13.0f, 40.0f, { 0.0f, 0.0f, 0.0f }, false, false, true, "",
        { 0.5f, 0.5f, 0.0f },
        { 15.0f, 0.2f, -1.0f, -1.0f, 10.0f, 0.0f, 0.0f, false, 0.0f, 0.0f, 0.0f, true, false },
        { false, false, 7.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f },
        7, 0
    },
    // assets/prefabs/tools/smoke grenade/smoke_grenade.weapon.prefab
    {
        "grenade.smoke", "assets/prefabs/tools/smoke grenade/smoke_grenade.weapon.prefab", 3642747736U, "GrenadeWeapon", 35, 4, 9, 1,
        { "assets/prefabs/tools/smoke grenade/grenade.smoke.deployed.prefab", 1464001967U, true }, true, "SmokeGrenade",
        10.0f, 40.0f, { 0.0f, 0.0f, 0.0f }, true, false, true, "",
        { 1.0f, 0.5f, 0.0f },
        { 1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 8.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f },
        7, 0
    },
    // assets/prefabs/misc/chinesenewyear/throwablefirecrackers/firecrackers.entity.prefab
    {
        "lunar.firecrackers", "assets/prefabs/misc/chinesenewyear/throwablefirecrackers/firecrackers.entity.prefab", 628064879U, "GrenadeWeapon", 39, 4, 10, 1,
        { "assets/prefabs/misc/chinesenewyear/throwablefirecrackers/firecrackers.deployed.prefab", 3428971889U, true }, true, "StringFirecracker",
        3.0f, 0.0f, { 0.0f, 0.0f, 0.0f }, true, true, true, "",
        { 1.0f, 0.5f, 0.0f },
        { 1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 0.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f },
        7, 0
    },
    // assets/prefabs/tools/supply signal/supplysignal.weapon.prefab
    {
        "supply.signal", "assets/prefabs/tools/supply signal/supplysignal.weapon.prefab", 775476535U, "GrenadeWeapon", 43, 4, 11, 1,
        { "assets/prefabs/tools/supply signal/grenade.supplysignal.deployed.prefab", 3350651790U, true }, true, "SupplySignal",
        10.0f, 40.0f, { 0.0f, 0.0f, 0.0f }, true, true, true, "",
        { 1.0f, 0.5f, 0.0f },
        { 1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 8.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f },
        7, 0
    },
    // assets/prefabs/tools/surveycharge/survey_charge.prefab
    {
        "surveycharge", "assets/prefabs/tools/surveycharge/survey_charge.prefab", 2698594377U, "ThrownWeapon", 47, 3, 12, 1,
        { "assets/prefabs/tools/surveycharge/survey_charge.deployed.prefab", 2141863453U, true }, true, "SurveyCharge",
        4.0f, 0.0f, { 0.0f, 0.0f, 1.0f }, true, true, true, "",
        { 0.5f, 0.75f, 0.0f },
        { 1.0f, 1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, false, 0.0f, 0.0f, 0.0f, true, true },
        { false, false, 5.0f, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1.0f },
        7, 0
    }
};

inline const ThrownWeaponData* GetByHash(std::uint64_t hash) noexcept
{
    switch (hash)
    {
    case 2671523489ULL: return &kData[0]; // explosive.satchel
    case 1915331115ULL: return &kData[1]; // explosive.timed
    case 2661658442ULL: return &kData[2]; // flare
    case 705457609ULL: return &kData[3]; // fun.casetterecorder
    case 3654150932ULL: return &kData[4]; // grenade.beancan
    case 3444797639ULL: return &kData[5]; // grenade.bee
    case 45697420ULL: return &kData[6]; // grenade.f1
    case 758326244ULL: return &kData[7]; // grenade.flashbang
    case 4104126979ULL: return &kData[8]; // grenade.molotov
    case 3642747736ULL: return &kData[9]; // grenade.smoke
    case 628064879ULL: return &kData[10]; // lunar.firecrackers
    case 775476535ULL: return &kData[11]; // supply.signal
    case 2698594377ULL: return &kData[12]; // surveycharge
    default: return nullptr;
    }
}

inline const ThrownWeaponData* GetByPrefabPath(const char* path) noexcept
{
    if (!path) return nullptr;
    for (std::size_t i = 0; i < kCount; ++i)
        if (std::strcmp(kData[i].prefab_path, path) == 0) return &kData[i];
    return nullptr;
}

inline bool HasItemShortname(const ThrownWeaponData* weapon, const char* shortname) noexcept
{
    if (!weapon || !shortname) return false;
    for (std::size_t i = 0; i < weapon->item_shortname_count; ++i)
        if (std::strcmp(kItemShortnames[weapon->first_item_shortname + i], shortname) == 0) return true;
    return false;
}
} // namespace ThrownWeapons
} // namespace RustData

#endif // RUST_DATA_THROWN_WEAPON_DATA_HPP
