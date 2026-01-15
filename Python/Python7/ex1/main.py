from ex0.CreatureCard import CreatureCard
from ex0.Card import Rarity, Type
from ArtifactCard import ArtifactCard
from SpellCard import SpellCard
from Deck import Deck

print("\n=== DataDeck Deck Builder ===\n")

racoon_warrior = CreatureCard("Racoon Warrior", 4, Rarity.COMMON, 3, 2)
doggo_enchanter = CreatureCard("Doggo Enchanter", 3, Rarity.RARE, 5, 1)
bowl_of_kibble = ArtifactCard("Bowl of Kibble", 6, Rarity.LEGENDARY, 15, "Feed your pets")
magic_woof = SpellCard("Magic Woof", 4, Rarity.RARE, "WOOF WOOF !!!")

carl_deck = Deck()

carl_deck.add_card(racoon_warrior)
carl_deck.add_card(doggo_enchanter)
carl_deck.add_card(bowl_of_kibble)
carl_deck.add_card(magic_woof)

print(f"Deck stats: {carl_deck.get_deck_stats}")
