from ex3.GameStrategy import GameStrategy
from ex0.Card import Type
from ex1 import Effect


class AgressiveStrategy(GameStrategy):

    def execute_turn(self, hand: list, battlefield: list) -> dict:

        available_mana = 10
        mana_used = 0
        cards_played = []
        damage_dealt = 0
        targets_attacked = self.prioritize_targets(battlefield)

        playable = [card for card in hand if card.cost <= available_mana]

        while available_mana > 0 and playable:
            card = min(playable, key=lambda c: c.cost)

            hand.remove(card)
            battlefield.append(card)

            available_mana -= card.cost
            mana_used += card.cost

            cards_played.append(card.name)

            if hasattr(card, "attack"):
                damage_dealt += card.attack

            if hasattr(card, "effect_type"):
                if card.effect_type == Effect.DAMAGE:
                    damage_dealt += 3

            playable = [card for card in hand if card.cost <= available_mana]

        return {
            "card_played": cards_played,
            "mana_used": mana_used,
            "targets_attacked": targets_attacked,
            "damage_dealt": damage_dealt
        }

    def get_strategy_name(self) -> str:
        return "AgressiveStrategy"

    def prioritize_targets(self, available_targets: list) -> list:

        prio_targets = []
        if available_targets:
            for target in available_targets:
                if isinstance(target, dict):
                    prio_targets.append(target.name)

                elif target.type == Type.CREATURE:
                    prio_targets.append(target.name)

        return prio_targets
