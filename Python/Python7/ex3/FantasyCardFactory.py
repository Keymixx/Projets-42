from ex0.CreatureCard import CreatureCard
from ex1.ArtifactCard import ArtifactCard
from ex1.SpellCard import SpellCard, Effect
from ex0.Card import Card, Rarity
from ex3.CardFactory import CardFactory
from random import randint, choice


class FantasyCardFactory(CardFactory):

    def __init__(self):
        self.types = {
            'creatures': ['Dragon', 'Goblin', "Elve", "Dwarf", "Human"],
            'spells': ['Fireball', 'Lightnigh Bolt', 'Ice Arrow'],
            'artifacts': ['Mana Ring'],
        }
        self.name = "FantasyCardFactory"

    def create_creature(self, name_or_power: str | int
                        | None = None) -> Card:

        cost = randint(1, 10)
        health = randint(max(1, cost - 2), cost + 2)
        attack = randint(max(1, cost - 2), cost + 2)
        if isinstance(name_or_power, str):
            return CreatureCard(name_or_power, cost,
                                Rarity.COMMON, attack, health)

        elif isinstance(name_or_power, int):
            cost = name_or_power
            health = randint(max(1, cost - 2), cost + 2)
            attack = randint(max(1, cost - 2), cost + 2)
            return CreatureCard(choice(self.types["creatures"]), name_or_power,
                                Rarity.COMMON, attack, health)

        else:
            return CreatureCard(choice(self.types["creatures"]), cost,
                                Rarity.COMMON, attack, health)

    def create_spell(self, name_or_power: str | int
                     | None = None) -> Card:
        cost = randint(1, 10)
        choosen_effect = choice(list(Effect))
        if isinstance(name_or_power, str):
            return SpellCard(name_or_power, cost,
                             Rarity.COMMON, choosen_effect.value)

        elif isinstance(name_or_power, int):
            return SpellCard(choice(self.types["spells"]), name_or_power,
                             Rarity.COMMON, choosen_effect.value)

        if name_or_power is None:
            return SpellCard(choice(self.types["spells"]), cost,
                             Rarity.COMMON, choosen_effect.value)

    def create_artifact(self, name_or_power: str | int
                        | None = None) -> Card:

        cost = randint(1, 10)
        effect = ["Permanent: +1 mana per turn"]
        if isinstance(name_or_power, str):
            return ArtifactCard(name_or_power, cost,
                                Rarity.COMMON, cost, choice(effect))

        elif isinstance(name_or_power, int):
            return ArtifactCard("Mana Ring", name_or_power,
                                Rarity.COMMON, name_or_power, choice(effect))

        if name_or_power is None:
            return ArtifactCard("Mana Ring", cost,
                                Rarity.COMMON, cost, choice(effect))

    def create_themed_deck(self, size: int) -> dict:

        result = {"deck": []}

        nb_creatures = size // 2
        nb_artifacts = size // 4
        nb_spells = size - nb_creatures - nb_artifacts

        for _ in range(nb_creatures):
            result["deck"].append(self.create_creature())

        for _ in range(nb_artifacts):
            result["deck"].append(self.create_artifact())

        for _ in range(nb_spells):
            result["deck"].append(self.create_spell())

        return result

    def get_supported_types(self) -> dict:
        return self.types
