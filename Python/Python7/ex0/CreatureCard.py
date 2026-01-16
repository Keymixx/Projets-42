from ex0 import Card, Rarity, Type
from typing import Dict


class CreatureCard(Card):
    def __init__(self, name: str, cost: int,
                 rarity: Rarity, attack: int, health: int):
        super().__init__(name, cost, rarity)

        if not isinstance(health, int) or health <= 0:
            raise ValueError(f"Health of '{name}' must be positive integer")
        if not isinstance(attack, int) or attack <= 0:
            raise ValueError(f"Attack of '{name}' must be positive integer")
        self.attack = attack
        self.health = health
        self.type = Type.CREATURE

    def play(self, game_state: Dict) -> dict:

        game_state["card_in"].append(self.get_card_info())
        game_state["mana"] -= self.cost
        return {
            "card_played": self.name,
            "mana_used": self.cost,
            "effect": "Creature summoned to battlefield"
        }

    def attack_target(self, target: Card) -> dict:
        return {
            "attacker": self.name,
            "target": target.name,
            "damage_dealt": self.attack,
            "combat_resolved": True
        }

    def get_card_info(self) -> dict:
        card_info = super().get_card_info()

        card_info["type"] = self.type
        card_info["attack"] = self.attack
        card_info["health"] = self.health

        return card_info
