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
    print("\nTesting mage counter...")
    counter = mage_counter()
    for i in range(5):
        print(f"Call {i + 1}: {counter()}")

    print("\nTesting spell accumulator...")
    initial_power = 5
    add_power = 10
    accumulator = spell_accumulator(initial_power)
    print(f"Initial power: {initial_power}")
    print(f"After {add_power} power accumulated: {accumulator(add_power)}")

    print("\nTesting enchantment factory...")
    element = "Frozen"
    item = "Sword"
    factory = enchantment_factory(element)
    print(f"Enchanted item: {factory(item)}")

    print("\nTesting memory vault...")
    vault = memory_vault()
    print('Store in vault:\n - "name": "Carl"\n - "age": "24"')
    vault["store"]("name", "Carl")
    vault["store"]("age", "24")
    print(f'\nRecall "name" from vault: {vault["recall"]("name")}')
    print(f'Recall "weight" from vault: {vault["recall"]("weight")}')


if __name__ == "__main__":
    try:
        main()

    except Exception as e:
        print(e)
