from functools import wraps
from typing import Any
from time import time, sleep


def spell_timer(func: callable) -> callable:

    @wraps(func)
    def wrapper(*args, **kwargs) -> Any:
        print(f"Casting: {func.__name__}...")
        start_time = time()
        result = func(*args, **kwargs)
        end_time = time()
        print(f"Spell completed in {end_time - start_time:.3f} seconds")
        return result

    return wrapper


def power_validator(min_power: int) -> callable:

    def factory(func: callable) -> callable:
        @wraps(func)
        def wrapper(*args, **kwargs) -> Any:
            if args[1] >= min_power:
                return func(*args, **kwargs)
            else:
                return "Insufficient power for this spell"
        return wrapper
    return factory


def retry_spell(max_attempts: int) -> callable:

    def retryer(func: callable) -> callable:
        @wraps(func)
        def wrapper(*args, **kwargs) -> Any:
            for i in range(max_attempts + 1):
                try:
                    return func(*args, **kwargs)
                except Exception:
                    if i == max_attempts:
                        return f"Spell casting failed after {max_attempts} try"
                    print("Spell failed, retrying... ", end="")
                    print(f"attempts {i + 1}/{max_attempts})")
        return wrapper
    return retryer


class MageGuild:
    @staticmethod
    def validate_mage_name(name: str) -> bool:
        return all(x.isalpha() or x.isspace() for x in name) and len(name) > 2

    @power_validator(10)
    def cast_spell(self, power: int, spell_name: str) -> str:
        return (f"Successfully cast {spell_name} with {power} power")


@spell_timer
def fireball() -> str:
    sleep(2)
    return "Fireball cast!"


@power_validator(70)
def cast_spell(spell: str, power: int) -> str:
    return f"{spell} of {power} power cast!"


@retry_spell(5)
def broken_spell() -> str:
    raise ValueError("ERROR")


def main():
    print("\nTesting spell timer...")
    print(f"Result: {fireball()}")

    print("\nTesting power validator...")
    print(f"Result: {cast_spell("Fireball", 50)}\n")

    print("\nTesting retry spell...")
    print(broken_spell())

    print("\nTesting mage guild...")
    guild = MageGuild()
    name = "Alex123"
    power = 5
    print(f"{name} validate ?: {guild.validate_mage_name(name)}")
    print(f"Try to cast with {power} of power: {guild.cast_spell(5, "fire")}")


if __name__ == "__main__":
    try:
        main()
    except Exception as e:
        print(e)
