from ex4.TournamentCard import TournamentCard
import random


class TournamentPlatform:

    def __init__(self):
        self.leader = []
        self.matches_played = 0

    def register_card(self, card: TournamentCard) -> str:
        self.leader.append(card)
        interfaces = card.interfaces
        registration = f"{card.name} (ID: {card.id})"
        registration += f"- Interfaces: {interfaces}\n"
        registration += f"- Rating: {card.rating}\n"
        registration += f"- Record: {card.get_rank_info()["record"]}\n"

        return registration

    def create_match(self, card1_id: str, card2_id: str) -> dict:
        card2 = None
        card1 = None

        for card in self.leader:
            if card.id == card1_id:
                card1 = card

            elif card.id == card2_id:
                card2 = card

        candidate = [card1, card2]
        random.shuffle(candidate)
        winner = candidate[0]
        loser = candidate[1]

        winner.update_wins(1)
        loser.update_losses(1)

        self.matches_played += 1

        return {
            "winner": winner.id,
            "loser": loser.id,
            "winner_rating": winner.rating,
            "loser_rating": loser.rating
        }

    def get_leaderboard(self) -> list:

        leaderboard = []
        i = 1
        for card in sorted(self.leader, key=lambda x: x.rating, reverse=True):
            info = card.get_rank_info()
            record = info["record"]
            stat = f"{i}. {card.name} - Rating: {card.rating} ({record})"
            leaderboard.append(stat)
            i += 1
        return leaderboard

    def generate_tournament_report(self) -> dict:
        avg = sum(card.rating for card in self.leader) / len(self.leader)
        return {
            "total_cards": len(self.leader),
            "matches_played": self.matches_played,
            "avg_rating": avg,
            "platform_status": "active"
        }
