from functools import reduce, partial, lru_cache, singledispatch
from operator import add, mul
from time import time


def spell_reducer(spells: list[int], operation: str) -> int:
    if operation == "add":
        return reduce(add, spells)

    elif operation == "multiply":
        return reduce(mul, spells)

    elif operation == "max":
        return max(spells)

    elif operation == "min":
        return min(spells)

    else:
        raise ValueError(f"Operation '{operation}' not found")


def partial_enchanter(base_enchantment: callable) -> dict[str, callable]:
    return {
        "fire_enchant": partial(base_enchantment, 50, "Fire"),
        "ice_enchant": partial(base_enchantment, 50, "Ice"),
        "lightning_enchant": partial(base_enchantment, 50, "Light")
    }


@lru_cache(maxsize=128)
def memoized_fibonacci(n: int) -> int:
    if n < 2:
        return n
    return memoized_fibonacci(n - 1) + memoized_fibonacci(n - 2)


def fibonacci(n: int) -> int:
    if n < 2:
        return n
    return fibonacci(n - 1) + fibonacci(n - 2)


def spell_dispatcher() -> callable:

    @singledispatch
    def dispatcher(type):
        return f"Enchantement: {type}"

    @dispatcher.register(int)
    def damage_spell(type):
        return f"Damage: {type}"

    @dispatcher.register(list)
    def spell_cast(type):
        all_spell = ""
        for spell in type:
            all_spell += f"- Cast {spell}\n"
        return all_spell

    return dispatcher


def enchantement(power: int, element: str, target: str):
    return f"{element} enchantment ({power} power) applied to {target}"


def main():
    spell_powers = [30, 33, 39, 49, 20, 25]

    print("\nTesting spell reducer...")
    print(f'Sum: {spell_reducer(spell_powers, "add")}')
    print(f'Product: {spell_reducer(spell_powers, "multiply")}')
    print(f'Max: {spell_reducer(spell_powers, "max")}')
    print(f'Min: {spell_reducer(spell_powers, "min")}')

    print("\n\nTesting partial enchanter...")
    enchantement_table = partial_enchanter(enchantement)
    print(f'Fire enchant sword: {enchantement_table["fire_enchant"]("Sword")}')

    print("\n\nTesting memoized fibonacci...")
    begin = time()
    print(f"Fibonnaci(30): {memoized_fibonacci(30)}")
    end = time()
    print(f"With lru_cache: {end - begin:.5f}")

    begin = time()
    print(f"\nFibonnaci(30): {fibonacci(30)}")
    end = time()
    print(f"Without lru_cache: {end - begin:.5f}")

    print("\n\nTesting spell_dispatcher..")
    distpatcher = spell_dispatcher()
    print("Test with List:")
    print(distpatcher(spell_powers))

    print("Test with Int:")
    print(distpatcher(45))

    print("\nTest with String:")
    print(distpatcher("Fire"))


if __name__ == "__main__":
    try:
        main()
    except Exception as e:
        print(e)
