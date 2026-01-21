from ex3.GameStrategy import GameStrategy
from ex3.CardFactory import CardFactory


class GameEngine:

    def configure_engine(self, factory: CardFactory,
                         strategy: GameStrategy) -> None:

        self.factory = factory
        self.strategy = strategy

        hand_deck = self.factory.create_themed_deck(3)
        battle_deck = self.factory.create_themed_deck(5)

        self.hand = hand_deck["deck"]
        self.battlefield = battle_deck["deck"]
        self.cards_created = len(self.hand) + len(self.battlefield)

        self.total_damage = 0
        self.turn_count = 0

    def simulate_turn(self) -> dict:

        turn = self.strategy.execute_turn(self.hand, self.battlefield)
        self.turn_count += 1
        self.total_damage += turn["damage_dealt"]

        return turn

    def get_engine_status(self) -> dict:
        return {
            "turn_simulated": self.turn_count,
            "strategy_used": self.strategy.get_strategy_name(),
            "total_damage": self.total_damage,
            "card_created": self.cards_created
        }
