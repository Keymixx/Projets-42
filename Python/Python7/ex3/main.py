from ex3.AggressiveStrategy import AgressiveStrategy
from ex3.FantasyCardFactory import FantasyCardFactory
from ex3.GameEngine import GameEngine

if (__name__ == "__main__"):
    print("\n=== DataDeck Game Engine ===\n")

    game = GameEngine()
    print("Configuring Fantasy Card Game...")
    factory = FantasyCardFactory()
    strat = AgressiveStrategy()

    print(f"Factory: {factory.name}")
    print(f"Strategy: {strat.get_strategy_name()}")
    print(f"Available types: {factory.get_supported_types()}")

    game.configure_engine(factory, strat)

    print("\nSimulating aggressive turn...")
    hand = [card.name + f" ({str(card.cost)})" for card in game.hand]
    print(f"Hand: {hand}")

    print("\nTurn execution:")
    print(f"Strategy: {game.strategy.get_strategy_name()}")
    print(f"Actions: {game.simulate_turn()}")

    print("\nGame Report:")
    print(f"{game.get_engine_status()}\n")

    print("Abstract Factory + Strategy Pattern: Maximum flexibility achieved!")
