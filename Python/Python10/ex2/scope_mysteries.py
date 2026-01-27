def mage_counter() -> callable:
    count = 0

    def counter() -> int:
        nonlocal count
        count += 1
        return count
    return counter


def spell_accumulator(initial_power: int) -> callable:
    power = initial_power

    def accumulator(power_add: int):
        nonlocal power
        power += power_add
        return power
    return accumulator


def enchantment_factory(enchantment_type: str) -> callable:
    enchantment = enchantment_type

    def apply_enchant(item: str) -> str:
        return f"{enchantment} {item}"
    return apply_enchant


def memory_vault() -> dict[str, callable]:
    memory = {}

    def store(key: str, value: any) -> None:
        memory[key] = value

    def recall(key: str) -> any:
        if key not in memory:
            return "Memory not found"
        else:
            return memory[key]
    return {
        "store": store,
        "recall": recall
    }


def main():
    counter = mage_counter()
    print(counter())

    accumulator = spell_accumulator(5)
    print(accumulator(5))

    frozen_factory = enchantment_factory("Frozen")
    print(frozen_factory("Sword"))
    print(frozen_factory("Ring"))

    vault = memory_vault()
    vault["store"]("name", "Carl")
    vault["store"]("age", "24")
    print(vault["recall"]("name"))
    print(vault["recall"]("weight"))


if __name__ == "__main__":
    try:
        main()
    except Exception as e:
        print(e)
