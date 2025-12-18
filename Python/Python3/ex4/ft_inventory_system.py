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
    
    print(f"== Transaction: {giver["name"]} gives {receiver["name"]} {quantities} {item} ===")
    
    if item not in giver["inventory"].keys():
        print(f"Sorry {receiver["name"]}...")
        print(f"{giver["name"]} doesn't have anything called '{item}' inside is backpack.....'")
        return

    actual_quantities = giver["inventory"][item]["quantities"]
    if actual_quantities < quantities:
        print(f"Sorry {receiver["name"]}...")
        print(f"{giver["name"]} had only {actual_quantities} {item} but you want {quantities} {item}....")
        return

    giver["inventory"][item]["quantities"] -= quantities
    
    if item not in receiver["inventory"].keys():
        receiver["inventory"].update({item: quantities})
    
    else:
        receiver["inventory"][item]["quantities"] += quantities
    
    print(receiver["inventory"][item]["quantities"])
    print("Transaction successful!")
    print("=== Updated Inventories ===")
    print(f"{giver["name"]} potions: {giver["inventory"][item]["quantities"]}")
    # print(f"{receiver["name"]} {item}: {receiver["inventory"][item]["quantities"]}")

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
    "name": "Carl",
    "inventory": {
        "sword": sword,
        "shield": shield,
        "potions": potions,
        "elytra": elytra
    }
}

yannis = {
    "name": "Yannis",
    "inventory": {}
}

print_inventory(carl["inventory"])
transaction(carl, yannis, 2, "potions")