# ==================EXERCICE FUNCTION====================
def spell_combiner(spell1: callable, spell2: callable) -> callable:
    if not callable(spell1) or not callable(spell2):
        raise ValueError("spell1 and spell2 must be callable")

    def combined_spell(target: str) -> tuple:
        result1 = spell1(target)
        result2 = spell2(target)
        return (result1, result2)
    return combined_spell


def power_amplifier(base_spell: callable, multiplier: int) -> callable:
    if not callable(base_spell):
        raise ValueError("base_spell must be callable")

    def amplification() -> int:
        return base_spell() * multiplier
    return amplification


def conditional_caster(condition: callable, spell: callable) -> callable:
    if not callable(condition) or not callable(spell):
        raise ValueError("condition and spell must be callable")

    def caster(target: str) -> str:
        if condition(target):
            return spell(target)
        else:
            return "Spell fizzled"
    return caster


def spell_sequence(spells: list[callable]) -> callable:
    for spell in spells:
        if not callable(spell):
            raise ValueError("All spells must be callable")

    def sequence(target: str) -> list:
        all_spells = []
        for spell in spells:
            all_spells.append(spell(target))
        return all_spells
    return sequence


# ==================EXEMPLE FUNCTION====================
def heal(target: str) -> str:
    return f"Heals {target}"


def fireball(target: str) -> str:
    return f"Fireball hits {target}"


def waterfall(target: str) -> str:
    return f"Waterfall hits {target}"


def death_touch(target: str) -> str:
    return f"Death touch kill {target}"


def ice_spike() -> int:
    return 5


def is_target(target: str) -> bool:
    if target in ['Dragon', 'Goblin', 'Wizard', 'Knight']:
        return True
    else:
        return False


def main():

    print("\nTesting spell combiner...")
    combined = spell_combiner(heal, fireball)
    result = combined("dragon")
    print(f"combined spell = {result}")

    print("\nTesting power amplifier...")
    print(f"Original Ice Spike : {ice_spike()} damages")
    mega_ice_pike = power_amplifier(ice_spike, 5)
    print(f'Mega Ice Spike (x5 multiplier): {mega_ice_pike()} damages')

    print("\nTesting conditional caster...")
    maybe_spell = conditional_caster(is_target, fireball)
    print("Target avaible: 'Dragon', 'Goblin', 'Wizard', 'Knight'")
    print(f"Testing with 'Gobin': {maybe_spell('Goblin')}")
    print(f"Testing with 'Felix': {maybe_spell('Felix')}")

    print("\nTesting spell sequence...")
    spells = [
        heal,
        fireball,
        waterfall,
        death_touch,
    ]
    call_spell_list = spell_sequence(spells)
    all_spells = call_spell_list("Knight")
    for spell in all_spells:
        print(f"- {spell}")


if __name__ == "__main__":
    try:
        main()
    except Exception as e:
        print(e)
