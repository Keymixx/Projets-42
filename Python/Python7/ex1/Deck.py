from ex0.Card import Card, Type
import random


class Deck:
    def __init__(self):
        self.cards = []

    def add_card(self, card: Card) -> None:
        try:
            self.cards.append(card)
        except TypeError as e:
            print(f"TypeError: {e}")

    def remove_card(self, card_name: str) -> bool:
        try:
            for card in self.cards:
                if card["name"] == card_name:
                    self.cards.remove(card)
                    return True
            return False

        except Exception as e:
            print(f"ERROR1 : {e}")

    def shuffle(self) -> None:
        random.shuffle(self.cards)

    def draw_card(self) -> Card:
        if not self.cards:
            raise IndexError("Deck empty")
        card = self.cards[0]
        self.cards.pop(0)
        return card

    def get_deck_stats(self) -> dict:
        deck_stats = {
            "total_cards": 0,
            "creatures": 0,
            "spells": 0,
            "artifacts": 0,
            "avg_cost": 0.0
        }

        total_cost = 0
        for card in self.cards:
            if card.type == Type.CREATURE:
                deck_stats["creatures"] += 1
            elif card.type == Type.ARTIFACT:
                deck_stats["artifacts"] += 1
            elif card.type == Type.SPELL:
                deck_stats["spells"] += 1

            deck_stats["total_cards"] += 1
            total_cost += card.cost

        deck_stats["avg_cost"] = total_cost / deck_stats["total_cards"]

        return deck_stats
