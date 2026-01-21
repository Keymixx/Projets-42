from ex4.TournamentPlatform import TournamentPlatform
from ex4.TournamentCard import TournamentCard
from ex0.Card import Rarity

tournament = TournamentPlatform()
print("\n=== DataDeck Tournament Platform ===")

print("\nRegistering Tournament Cards...\n")

dragon_001 = TournamentCard("Fire Dragon", "dragon_001", 5,
                            Rarity.LEGENDARY, 6, 7, 3, 1200)
print(tournament.register_card(dragon_001))


wizard_001 = TournamentCard("Ice Wizard", "wizard_001", 4,
                            Rarity.LEGENDARY, 7, 2, 2, 1150)
print(tournament.register_card(wizard_001))

print('Creating tournament match...')
