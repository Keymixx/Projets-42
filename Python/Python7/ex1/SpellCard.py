from ex0.Card import Card, Rarity, Type
from enum import Enum


class Effect(Enum):
    DAMAGE = "Deal 3 damage to target"
    HEAL = "Heal 3 hp to target"
    BUFF = "Increases the damage dealt by 3's attacks."
    DEBUFF = "Decreases attack damage by 3"


class SpellCard(Card):
    def __init__(self, name: str, cost: int,
                 rarity: Rarity, effect_type: Effect):
        super().__init__(name, cost, rarity)
        self.effect_type = effect_type
        self.type = Type.SPELL

    def play(self, game_state: dict) -> dict:

        game_state["hand"].remove(self)
        game_state["mana"] -= self.cost
        return {
            "card_played": self.name,
            "mana_used": self.cost,
            "effect": self.effect_type
        }

    def resolve_effect(self, targets: list) -> dict:
        if self.type == Effect.DAMAGE:
            for target in targets:
                if target.type == Type.CREATURE:
                    target.health -= 3
                if target.type == Type.ARTIFACT:
                    target.durability -= 3

        elif self.type == Effect.HEAL:
            for target in targets:
                if target.type == Type.CREATURE:
                    target.health += 3
                if target.type == Type.ARTIFACT:
                    target.durability += 3

        elif self.type == Effect.DEBUFF:
            for target in targets:
                if target.type == Type.CREATURE:
                    target.attack -= 3

        elif self.type == Effect.BUFF:
            for target in targets:
                if target.type == Type.CREATURE:
                    target.attack -= 3

        return {"effect": self.type.value}

    def get_card_info(self) -> dict:
        card_info = super().get_card_info()

        card_info["type"] = self.type.value
        card_info["effect_type"] = self.effect_type

        return card_info
