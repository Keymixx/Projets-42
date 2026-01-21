from ex4.TournamentCard import TournamentCard


class TournamentPlatform:

    def __init__(self):
        self.leaderboard = []

    def register_card(self, card: TournamentCard) -> str:
        self.leaderboard.append(card)
        interfaces = card.interfaces
        registration = f"{card.name} (ID: {card.id})"
        registration += f"- Interfaces: {interfaces}\n"
        registration += f"- Rating: {card.rating}\n"
        registration += f"- Record: {card.record}\n"

        return registration

    def create_match(self, card1_id: str, card2_id: str) -> dict:
        card2 = None
        card1 = None

        for card in self.leaderboard:
            if card.id == card1_id:
                card1 = card

            elif card.id == card2_id:
                card2 = card

        cardcard1.defend(.)


    def get_leaderboard(self) -> list:
        pass

    def generate_tournament_report(self) -> dict:
        pass