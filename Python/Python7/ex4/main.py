from ex4.TournamentPlatform import TournamentPlatform
from ex4.TournamentCard import TournamentCard
from ex0.Card import Rarity
from ex2.Combatable import CombatType

tournament = TournamentPlatform()
print("\n=== DataDeck Tournament Platform ===")

print("\nRegistering Tournament Cards...\n")

dragon_001 = TournamentCard("Fire Dragon", 5, Rarity.LEGENDARY, 6,
                            CombatType.MELEE, 10 , 4, "dragon_001",
                            1200)
print(tournament.register_card(dragon_001))


wizard_001 = TournamentCard("Ice Wizard", 4, Rarity.LEGENDARY, 5,
                            CombatType.MAGICAL, 6, 4, "wizard_001",
                            1200)
print(tournament.register_card(wizard_001))

print('Creating tournament match...')
print(tournament.create_match("dragon_001", "wizard_001"))

print("\nTournament Leaderboard:")
leaderboard = tournament.get_leaderboard()
for card in leaderboard:
    print(card)

print("\nPlatform Report:")
print(tournament.generate_tournament_report())

print("\n=== Tournament Platform Successfully Deployed! ===")
print("All abstract patterns working together harmoniously!")
