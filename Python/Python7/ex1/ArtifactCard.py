from ex0.Card import Card, Rarity, Type


class ArtifactCard(Card):
    def __init__(self, name: str, cost: int,
                 rarity: Rarity, durability: int, effect: str):
        super().__init__(name, cost, rarity)
        self.durability = durability
        self.effect = effect
        self.type = Type.ARTIFACT

    def play(self, game_state: dict) -> dict:
        pass

    def activate_ability(self) -> dict:
        pass
