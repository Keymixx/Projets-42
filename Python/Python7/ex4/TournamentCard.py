from ex0.Card import Card, Rarity
from ex2.Combatable import Combatable
from ex4.Rankable import Rankable


class TournamentCard(Card, Combatable, Rankable):

    def __init__(self, name: str, id: str, cost: int, rarity: Rarity,
                 attack_point: int, health: int,
                 defense_point: int, rating: int):
        super().__init__(name, cost, rarity)

        self.attack_point = attack_point
        self.health = health
        self.defense_point = defense_point
        self.still_alive = True
        self.id = id

        self.interfaces = [base.__name__ for base in self.__class__.__bases__]
        self.wins = 0
        self.losses = 0
        self.rating = rating
        self.record = f"{self.wins}-{self.losses}"

    def play(self, game_state: dict) -> dict:
        game_state["battlefield"].append(self)
        game_state["mana"] -= self.cost
        return {
            "card_played": self.name,
            "mana_used": self.cost,
        }

    def attack(self, target) -> dict:
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

    def calculate_rating(self) -> int:
        for base in self.__class__.__bases__:
            print(base.__name__)

    def get_tournament_stats(self) -> dict:
        pass

    def update_wins(self, wins: int) -> None:
        self.wins += wins

    def update_losses(self, losses: int) -> None:
        self.losses += losses

    def get_rank_info(self) -> dict:
        return {
            "rating": self.rating,
            "record": f"{self.wins}-{self.losses}"
        }

    def get_combat_stats(self) -> dict:
        pass

