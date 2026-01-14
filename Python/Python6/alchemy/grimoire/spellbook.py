def record_spell(spell_name: str, ingredients: str) -> str:
    from .validator import validate_ingredients

    verified_ingredients = validate_ingredients(ingredients)
    if "- VALID" in verified_ingredients:
        return f"Spell recorded: {spell_name} ({verified_ingredients})"
    else:
        return f"Spell rejected: {spell_name} ({verified_ingredients})"
