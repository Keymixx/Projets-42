class GardenError(Exception):
    """Base exception for all garden-related errors."""
    def __init__(self, message):
        super().__init__(message)


class PlantError(GardenError):
    """Exception raised when a plant is wilting or unhealthy."""
    def __init__(self, plant):
        self.plant = plant
        super().__init__(f"The {plant.name} plant is wilting!")


class WaterError(GardenError):
    """Exception raised when there is insufficient water in the tank."""
    def __init__(self, water, water_required):
        error = f"Not enough water in the tank! {water}/{water_required}L"
        super().__init__(error)


class Plant:
    """Represents a plant with a name and wilting status."""
    def __init__(self, name, is_wilting):
        self.name = name
        self.is_wilting = is_wilting


def test_custom_execption():
    """Tests all custom garden exception types."""

    print("=== Custom Garden Errors Demo ===")
    print("\nTesting PlantError...")

# =====PLANT ERROR TEST=====
    plants = [
        Plant("tomato", True),
        Plant("sunflower", False)
    ]
    try:
        for plant in plants:
            if plant.is_wilting:
                raise PlantError(plant)
    except PlantError as error:
        print(f"Caught PlantError: {error}")

    print("\nTesting WaterError...")

# =====WATER ERROR TEST=====
    water_tank = 10
    water_required = 50
    try:
        if water_tank < water_required:
            raise WaterError(water_tank, water_required)
    except WaterError as error:
        print(f"Caught WaterError: {error}")

    print("\nTesting catching all garden errors...")

# =====ALL GARDEN ERROR=====
    salad = Plant("salad", True)
    try:
        raise PlantError(salad)
    except GardenError as error:
        print(f"Caught GardenError: {error}")

    try:
        raise WaterError(water_tank, water_required)
    except GardenError as error:
        print(f"Caught GardenError: {error}")

    print("\nAll custom error types work correctly!")


test_custom_execption()
