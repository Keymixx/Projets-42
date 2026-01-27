def artifact_sorter(artifacts: list[dict]) -> list[dict]:
    return sorted(artifacts, key=lambda x: x['power'], reverse=True)


def power_filter(mages: list[dict], min_power: int) -> list[dict]:
    return list(filter(lambda x: x["power"] > min_power, mages))


def spell_transformer(spells: list[str]) -> list[str]:
    return list(map(lambda x: f"*{x}*", spells))


def mage_stats(mages: list[dict]) -> dict:
    most = max(mages, key=lambda x: x["power"])
    least = min(mages, key=lambda x: x["power"])
    avg = sum(map(lambda x: x["power"], mages)) / len(mages)
    return {
        "max_power": most,
        "min_power": least,
        "avg_power": avg
    }


artifacts = [
    {'name': 'Wind Cloak', 'power': 105, 'type': 'armor'},
    {'name': 'Storm Crown', 'power': 79, 'type': 'accessory'},
    {'name': 'Fire Staff', 'power': 91, 'type': 'weapon'},
    {'name': 'Lightning Rod', 'power': 68, 'type': 'focus'}
    ]

mages = [
    {'name': 'Ash', 'power': 61, 'element': 'fire'},
    {'name': 'Zara', 'power': 54, 'element': 'fire'},
    {'name': 'Alex', 'power': 86, 'element': 'light'},
    {'name': 'Morgan', 'power': 87, 'element': 'wind'},
    {'name': 'Sage', 'power': 93, 'element': 'light'}
    ]

spells = ['tsunami', 'darkness', 'freeze', 'earthquake']

print("\n========Artifacts Function========")
print("Artifacts list before function:")
for arctifact in artifacts:
    print(arctifact)

new_artifacts = artifact_sorter(artifacts)

print("\nArtifacts list after function:")
for arctifact in new_artifacts:
    print(arctifact)


print("\n\n========Mages Function========")
print("Mages list before function (80 power filter):")
for mage in mages:
    print(mage)

new_mages = power_filter(mages, 80)

print("\nMages list after function (80 power filter):")
for mage in new_mages:
    print(mage)

print("\nMage Stats:")
print(mage_stats(mages))


print("\n\n========Spells Function========")
print("Spells list before function :")
for spell in spells:
    print(spell)

new_spells = spell_transformer(spells)

print("\n\nSpells list after function :")
for spell in new_spells:
    print(spell)


