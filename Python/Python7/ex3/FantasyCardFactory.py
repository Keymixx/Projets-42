from ex0.CreatureCard import CreatureCard
from ex1.ArtifactCard import ArtifactCard
from ex1.SpellCard import SpellCard
from ex0.Card import Card, Type, Rarity
from ex3.CardFactory import CardFactory
from random import randint, choice

class FantasyCardFactory(CardFactory):

    def __init__(self):
        self.card = {
            "creatures": [],
            "spells": [],
            "artifacts": []
        }

    def add_card(self, card: Card) -> None:

        if card.type == Type.CREATURE:
            self.card["creatures"].append(card)

        elif card.type == Type.SPELL:
            self.card["spells"].append(card)

        elif card.type == Type.ARTIFACT:
            self.card["artifacts"].append(card)
        
        else:
            print("Invalid Type: Artifact, Creature or Spell")

    def create_creature(self, name_or_power: str | int
                        | None = None) -> Card:

        cost = randint(1, 4)
        health = randint(1, 4)
        attack = randint(1, 4)
        creature_names = ["Goblin", "Knight", "Archer", "Wizard"]

        if isinstance(name_or_power, str):
            for creature in self.creatures:
                if creature.name == name_or_power:
                    return creature
            return CreatureCard(name_or_power, cost,
                                Rarity.COMMON, attack, health)

        elif isinstance(name_or_power, int):
            return CreatureCard(choice(creature_names), name_or_power,
                                Rarity.COMMON, attack, health)

        elif not name_or_power:
            return CreatureCard(choice(creature_names), cost,
                                Rarity.COMMON, attack, health)

    def create_spell(self, name_or_power: str | int
                     | None = None) -> Card:
        cost = randint(1, 4)
        spell_names = ["Fireball", "Ice Spike", "Flash"]

        if isinstance(name_or_power, str):
            for spell in self.card["spells"]:
                if spell.name == name_or_power:
                    return spell
            return SpellCard(name_or_power, cost,
                             Rarity.COMMON, attack, health)

        elif isinstance(name_or_power, int):
            return CreatureCard(choice(creature_names), name_or_power,
                                Rarity.COMMON, attack, health)

        elif not name_or_power:
            return CreatureCard(choice(creature_names), cost,
                                Rarity.COMMON, attack, health)

    def create_artifact(self, name_or_power: str | int
                        | None = None) -> Card:
        pass

    def create_themed_deck(self, size: int) -> dict:
        pass

    def get_supported_types(self) -> dict:
        pass
