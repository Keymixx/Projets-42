def validate_ingredients(ingredients: str) -> str:
    split_ingredient = ingredients.split()
    for ingredient in split_ingredient:
        if not ingredient.lower() in ["fire", "air", "earth", "water"]:
            return f"{ingredients} - INVALID"

    return f"{ingredients} - VALID"
