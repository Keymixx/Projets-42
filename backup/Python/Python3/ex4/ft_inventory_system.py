def print_inventory(inventory: dict)-> None:
    
    total_categorie = {
        "weapon": 0,
        "armor": 0,
        "consumable": 0
    }

    total_item = 0
    total_value = 0
    print("=== Carl's Inventory ===")
    for item in inventory:
        
        
        categorie = inventory[item].get("categorie")
        rarity = inventory[item].get("rarity")
        quantities = inventory[item].get("quantities")
        value = inventory[item].get("value")
        
        total_categorie[categorie] += quantities
        total_item += quantities
        total_value += quantities * value

        print(f"{item} ({categorie}, {rarity}): {quantities}x @\
{value} gold each = {quantities * value} gold")

    weapon = total_categorie["weapon"]
    armor = total_categorie["armor"]
    consumable = total_categorie["consumable"]

    print(f"\nInventory value: {total_value} gold")
    print(f"Item count: {total_item} items")
    print(f"Categories: weapon({weapon}), consumable({consumable}), armor({armor})")




def transaction(giver, receiver, quantities, item)-> None:
    
    if item not in giver.keys():
        print(f"Missing ({item}) in inventory")
        return

    actual_quantities = giver[item]["quantities"]
    if actual_quantities < quantities:
        print(f"Not enough ({item}) in inventory.... you have {actual_quantities} {item}")
        return

    giver[item]["quantities"] -= quantities
    
    if item not in receiver.keys():
        receiver.update({item: giver[item]})
        receiver[item]["quantities"] = quantities
    else:
        receiver[item]["quantities"] += quantities
    
    print("Transaction successful!")

def most_valuable_player(all_players)-> None:

    most_valuable = None
    best_value = 0
    for player, inventory in all_players.items():
        player_value = 0
        for item in inventory:
            quantities = inventory[item].get("quantities")
            value = inventory[item].get("value")
            player_value += quantities * value
            if best_value < player_value:
                most_valuable = player
                best_value = player_value

    print(f"Most valuable player: {most_valuable} ({best_value} gold)")
    

def most_item_player(all_player)-> None:

    most_item_player = None
    most_item = 0
    for player, inventory in all_players.items():
        player_item = 0
        for item in inventory:
            quantities = inventory[item].get("quantities")
            player_item += quantities
            if most_item < player_item:
                most_item_player = player
                most_item = player_item

    print(f"Most items: {most_item_player} ({most_item} items)")

def rarest_item(all_player)-> None:

    rare_items = []
    for inventory in all_players.values():
        player_item = 0
        for item in inventory:
            if inventory[item]["rarity"] == "rare":
                rare_items.append(item)

    print(f"Rarest items: {rare_items}")

# =====ITEMS=====
sword = {
    "categorie": "weapon",
    "value": 600,
    "quantities": 1,
    "weight": 8,
    "rarity": "uncommon"
}

shield = {
    "categorie": "armor",
    "value": 200,
    "quantities": 1,
    "weight": 14,
    "rarity": "common"
}

potions = {
    "categorie": "consumable",
    "value": 50,
    "quantities": 4,
    "weight": 1,
    "rarity": "common"
}

elytra = {
    "categorie": "armor",
    "value": 1000,
    "quantities": 1,
    "weight": 6,
    "rarity": "rare"
}

# =====INVENTORY=====
carl = {
    "sword": sword,
    "shield": shield,
    "potions": potions,
    "elytra": elytra
}
yannis = {}

all_players = {
    "Carl": carl,
    "Yannis": yannis
}

print_inventory(carl)

print("\n== Transaction: Carl gives Yannis 2 potions ===")
transaction(carl, yannis, 2, "potions")

print("\n=== Updated Inventories ===")
print(f"Carl potions: {carl['potions']['quantities']}")
print(f"Yannis potions: {yannis['potions']['quantities']}")

print("\n=== Inventory Analytics ===")
most_valuable_player(all_players)
most_item_player(all_players)
rarest_item(all_players)
