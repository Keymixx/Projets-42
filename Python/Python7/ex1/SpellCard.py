from ex0.Card import Card, Rarity, Type


class SpellCard(Card):
    def __init__(self, name: str, cost: int, rarity: Rarity, effect_type: str):
        super().__init__(name, cost, rarity)
        self.effect_type = effect_type
        self.type = Type.SPELL

    def play(self, game_state: dict) -> dict:
        pass

    def resolve_effect(self, targets: list) -> dict:
        pass
