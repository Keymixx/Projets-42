from ex0.Card import Card, Rarity, Type
from enum import Enum


class Effect(Enum):
    DAMAGE = "Deal 3 damage to target"
    HEAL = "Heal 3 hp to target"
    BUFF = "Increases the damage dealt by 3's attacks."
    DEBUFF = "Decreases attack damage by 3"


class SpellCard(Card):
    def __init__(self, name: str, cost: int, rarity: Rarity, effect_type: str):
        super().__init__(name, cost, rarity)
        self.effect_type = effect_type
        self.type = Type.SPELL

    def play(self, game_state: dict) -> dict:

        game_state["card_in"].append(self.get_card_info())
        game_state["mana"] -= self.cost
        return {
            "card_played": self.name,
            "mana_used": self.cost,
            "effect": self.effect_type
        }

    def resolve_effect(self, targets: list) -> dict:
        if self.type =