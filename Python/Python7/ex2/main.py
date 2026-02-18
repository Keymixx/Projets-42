from ex0.CreatureCard import CreatureCard
from ex0.Card import Rarity
from ex1 import SpellCard, Deck
from ex2 import EliteCard, CombatType

print("\n=== DataDeck Ability System ===\n")

racoon_warrior = CreatureCard("Racoon Warrior", 4, Rarity.COMMON, 3, 2)
magic_meow = SpellCard("Magic Meow", 4, Rarity.RARE, "MEOW MEOW !!")
doggo_enchanter = CreatureCard("Doggo Enchanter", 3, Rarity.RARE, 5, 1)
kitty_warrior = EliteCard("Kitty Warrior", 6, Rarity.LEGENDARY, 6,
                          CombatType.MELEE, 6, 2, [magic_meow])

carl = {
    "mana": 6,
    "battlefield": [],
    "hand": [],
    "cemetery": [],
    "deck": Deck(),
    "player_health": 40
    }


print("EliteCard capabilities:")
print("- Card: ['play', 'get_card_info', 'is_playable']")
print("- Combatable: ['attack', 'defend', 'get_combat_stats']")
print("- Magical: ['cast_spell', 'channel_mana', 'get_magic_stats']")

print("\nPlaying Arcane Warrior (Elite Card):\n")

print("Combat phase:")
print(f"Attack result: {kitty_warrior.attack(racoon_warrior)}")
print(f"Defense result: {kitty_warrior.defend(7)}")

print("Magic phase:")
print(f"Spell cast: {kitty_warrior.cast_spell('Magic Meow',[racoon_warrior])}")
print(f"Mana Channel: {kitty_warrior.channel_mana(3)}")

print("\nMultiple interface implementation successful!")
