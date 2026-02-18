from ex0.Card import Card, Rarity, Type
from ex2.Magical import Magical
from ex2.Combatable import Combatable
from enum import Enum


class CombatType(Enum):
    MELEE = "Melee"
    RANGED = "Ranged"
    MAGICAL = "Magical"


class EliteCard(Card, Magical, Combatable):

    def __init__(self, name: str, cost: int, rarity: Rarity,
                 attack_point: int, combat_type: CombatType, health: int,
                 defense_point: int, spells: list):
        super().__init__(name, cost, rarity)

        self.attack_point = attack_point
        self.combat_type = combat_type
        self.health = health
        self.defense_point = defense_point
        self.spells = spells
        self.still_alive = True
        self.type = Type.ELITE

    def play(self, game_state: dict) -> dict:

        game_state["battlefield"].append(self)
        game_state["mana"] -= self.cost
        return {
            "card_played": self.name,
            "mana_used": self.cost,
            "effect": "Elite summoned to battlefield"
        }

    def attack(self, target: Card) -> dict:
        return {
            "attacker": self.name,
            "target": target.name,
            "damage": self.attack_point,
            "combat_type": self.combat_type.value
        }

    def defend(self, incoming_damage: int) -> dict:
        damage_blocked = min(self.defense_point, self.defense_point
                             - (self.defense_point - incoming_damage))
        damage_taken = max(0, (self.defense_point - incoming_damage) * -1)

        if (self.health - damage_taken) <= 0:
            self.still_alive = False

        return {
            "defender": self.name,
            "damage_taken": damage_taken,
            "damage_blocked": damage_blocked,
            "still_alive": self.still_alive
        }

    def get_combat_stats(self) -> dict:
        return {
            "name": self.name,
            "health": self.health,
            "attack": self.attack_point,
            "defense": self.defense_point,
            "combat_type": self.combat_type.value
        }

    def cast_spell(self, spell_name: str, targets: list) -> dict:
        find_spell = False
        for spell in self.spells:
            if spell.name == spell_name:
                find_spell = True
                actual_spell = spell

        if not find_spell:
            return {"error": "Spell not found"}

        actual_target = [target.name for target in targets]

        return {
            "caster": self.name,
            "spell": actual_spell.name,
            "targets": actual_target,
            "mana_used": actual_spell.cost
        }

    def channel_mana(self, amount: int) -> dict:
        return {
            "channeled": amount,
            "total_mana": 7
        }

    def get_magic_stats(self) -> dict:
        return {
            "name": self.name,
            "spells_list": self.spells,
        }

    def get_card_info(self) -> dict:
        card_info = super().get_card_info()

        card_info["attack_point"] = self.attack_point
        card_info["combat_type"] = self.combat_type
        card_info["health"] = self.health
        card_info["defense_point"] = self.defense_point
        card_info["spells"] = self.spells
        card_info["still_alive "] = self
        card_info["type"] = self.type

        return card_info
