# Rust Data Exporter

Oxide.Rust plugin that exports server-side Rust prefab and item data to C++17
headers. JSON copies are optional.

## Command

```text
rustdata.dump [all|prefabs|items|weapons|projectiles|held|explosives] [json]
```

Examples:

```text
rustdata.dump explosives
rustdata.dump explosives json
rustdata.dump prefabs json
rustdata.dump all json
```

The permission is `rustdataexporter.use`. The server console can run the command
without the permission.

Output directory:

```text
[server directory]\oxide\data\RustDataExporter
```

The `explosives` target generates:

- `RustTimedExplosiveData.hpp`
- `RustThrownWeaponData.hpp`
- `RustTimedExplosiveData.json` when `json` is requested
- `RustThrownWeaponData.json` when `json` is requested

The `prefabs` target generates `RustPrefabData.hpp` and optionally
`RustPrefabData.json`. It contains loaded manifest prefabs that have a
`BaseNetworkable` component, including prefab path, ID, concrete type, and
inheritance chain.
It also exports Rigidbody, NavMeshAgent, CharacterController and Unity static
signals. The generated `mobility` value is `dynamic` when movement is detected by
Rigidbody, navigation, controller, type, or path signals. Other `BaseNetworkable`
prefabs are classified as `static`. Generated entries use the `Uncategorized`
category.

`RustTimedExplosiveData` contains fuse, radius, damage, AI, water, effects,
sticking, orientation, Rigidbody mass/drag, prefab type and prefab hash data. `RustThrownWeaponData`
contains the thrown prefab link, throw parameters, item shortnames, and relevant
`AttackEntity` and `HeldEntity` configuration.

`RustHeldItemTypeMap` includes the held entity `prefab_id` and provides
`GetByPrefabId`, `GetPrefabId`, and `HasTypeByPrefabId` helpers.

Serialized fields declared by subclasses of `TimedExplosive` or `ThrownWeapon`
are emitted in `extra_fields`. This preserves class-specific prefab settings such
as fields on `DudTimedExplosive` without hardcoding every derived class. Runtime
state and fields marked `NonSerialized` are intentionally excluded.

The formatting and original idea are based on lolz5465az's work.

AI was used to make this.
