from abc import ABC, abstractmethod
from enum import Enum
from typing import Dict


class Type(Enum):
    CREATURE = "Creature"
    SPELL = "Spell"
    ARTIFACT = "Artifact"
    ELITE = "Elite"


class Rarity(Enum):
    COMMON = "Common"
    RARE = "Rare"
    LEGENDARY = "Legendary"


class Card(ABC):
    def __init__(self, name: str, cost: int, rarity: Rarity):
        self.name = name
        self.cost = cost
        self.rarity = rarity.value

    @abstractmethod
    def play(self, game_state: Dict) -> dict:
        return

    def get_card_info(self) -> dict:
        return {
            "name": self.name,
            "cost": self.cost,
            "rarity": self.rarity
        }

    def is_playable(self, available_mana: int) -> bool:
        if self.cost <= available_mana:
            return True
        else:
            return False
