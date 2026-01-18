from ex0.CreatureCard import CreatureCard
from ex0.Card import Rarity, Type
from ex1 import ArtifactCard, SpellCard, Deck
from ex2 import EliteCard, CombatType

print("\n=== DataDeck Deck Builder ===\n")

racoon_warrior = CreatureCard("Racoon Warrior", 4, Rarity.COMMON, 3, 2)
bowl_of_kibble = ArtifactCard("Bowl of Kibble", 6, Rarity.LEGENDARY, 15, "Feed your pets (+1 health)")
magic_meow = SpellCard("Magic Meow", 4, Rarity.RARE, "MEOW MEOW !!")
doggo_enchanter = CreatureCard("Doggo Enchanter", 3, Rarity.RARE, 5, 1)
kitty_warrior = EliteCard ("Kitty Warrior", 6, Rarity.LEGENDARY, 6, CombatType.MELEE, 6, 2, [magic_meow])


carl = {
    "mana": 6,
    "card_in": [],
    "hand": [],
    "cemetery": [],
    "deck": Deck(),
    "player_health": 40
    }

carl["deck"].add_card(racoon_warrior)
carl["deck"].add_card(bowl_of_kibble)
carl["deck"].add_card(kitty_warrior)
carl["deck"].add_card(doggo_enchanter)

print("Building deck with different card types...")
print(f"Deck stats: {carl['deck'].get_deck_stats()}")

print("\nDrawing and playing cards:")

for _ in range(3):

        card_drew = carl["deck"].draw_card()
        print(f"\nDrew: {card_drew.name} ({card_drew.type.value})")
        print(f"Play result: {card_drew.play(carl)}")

print("\nPolymorphism in action: Same interface, different card behaviors!")