from abc import ABC, abstractmethod
from enum import Enum

class CombatType(Enum):
    MELEE = "Melee"
    RANGED = "Ranged"
    MAGICAL = "Magical"


class Combatable(ABC):

    def __init__(self,attack_point: int, combat_type: CombatType,
                 health: int, defense_point: int,):
        self.attack_point = attack_point
        self.combat_type = combat_type
        self.health = health
        self.defense_point = defense_point

    @abstractmethod
    def attack(self, target) -> dict:
        pass

    @abstractmethod
    def defend(self, incoming_damage: int) -> dict:
        pass

    @abstractmethod
    def get_combat_stats(self) -> dict:
        pass
