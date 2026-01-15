from ex0 import CreatureCard, Rarity

def main():

    racoon_warrior = CreatureCard("Racoon Warrior", 4, Rarity.COMMON, 3, 2)
    doggo_enchanter = CreatureCard("Doggo Enchanter", 3, Rarity.RARE, 5, 1)


    player1 = {
        "mana": 6,
        "card_in": [],
        "player_health": 40
    }

    player2 = {
        "mana": 6,
        "card_in": [],
        "player_health": 40
    }

    print("\n=== DataDeck Card Foundation ===")
    print("\nTesting Abstract Base Class Design:")

    print("\nCreatureCard Info:")
    print(racoon_warrior.get_card_info())

    print("\nPlaying Racoon Warrior with 6 mana available:")
    print(f"Playable: {racoon_warrior.is_playable(player1["mana"])}")
    print(f"Play result: {racoon_warrior.play(player1)}")

    print("\nRacoon Warrior attacks Doggo Enchanter:")
    print(f"Attack result: {racoon_warrior.attack_target(doggo_enchanter)}")

    print(f"\nTesting insufficient mana ({player1["mana"]} available):")
    print(f"Playable: {racoon_warrior.is_playable(player1["mana"])}")

    print("\nAbstract pattern successfully demonstrated!")   


if __name__ == "__main__":

    try:
        main()
    except Exception as e:
        print(f"ERROR: {e}")