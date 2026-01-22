from ex0.Card import Card, Rarity, Type


class ArtifactCard(Card):
    def __init__(self, name: str, cost: int,
                 rarity: Rarity, durability: int, effect: str):
        super().__init__(name, cost, rarity)
        self.durability = durability
        self.effect = effect
        self.type = Type.ARTIFACT

    def play(self, game_state: dict) -> dict:

        game_state["battlefield"].append(self)
        game_state["mana"] -= self.cost
        return {
            "card_played": self.name,
            "mana_used": self.cost,
            "effect": self.effect
        }

    def activate_ability(self) -> dict:
        return {"effect": self.effect}

    def get_card_info(self) -> dict:
        card_info = super().get_card_info()

        card_info["type"] = self.type.value
        card_info["durability"] = self.durability
        card_info["effect"] = self.effect

        return card_info
