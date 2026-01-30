class GardenError(Exception):
    """Base exception for garden-related errors."""
    def __init__(self, message):
        super().__init__(message)


class PlantError(GardenError):
    """Exception for plant-specific errors."""
    def __init__(self, message):
        super().__init__(message)


class WaterError(GardenError):
    """Exception for plant-specific errors."""
    def __init__(self, water, water_required):
        error = f"Not enough water in the tank! {water}/{water_required}L"
        super().__init__(error)


class Plant:
    """Represents a plant with water and sun requirements."""
    def __init__(self, name: str, water: int, sun: int):
        self.name = name
        self.water = water
        self.sun = sun


class GardenManager:
    """Manages plants and water resources in the garden."""
    def __init__(self, water_tank):
        self.plants = []
        self.water_tank = water_tank
        self.water_required = 30
        self.water_max = 150

    def add_plants(self, plants):
        """Adds a list of plants to the garden."""
        try:
            for plant in plants:
                if plant.name == "":
                    raise PlantError("Plant name cannot be empty!")
                self.plants.append(plant)
                print(f"Added {plant.name} successfully")
        except PlantError as error:
            print(f"Error adding plant: {error}")

    def water_plants(self):
        """Waters all plants in the garden."""
        print("Opening watering system")
        try:
            for plant in self.plants:
                plant.water += 1
                print(f"Watering {plant.name} - success")
        except Exception:
            print("Something goes wrong")
        finally:
            print("Closing watering system (cleanup)")

    def check_plants_health(self):
        """Checks the health status of all plants."""
        for plant in self.plants:
            try:
                if plant.water < 1:
                    raise PlantError(f"Water {plant.water} too low (min 1)")
                elif plant.water > 10:
                    raise PlantError(f"Water {plant.water} too high (max 10)")
                elif plant.sun < 2:
                    raise PlantError(f"Sun {plant.sun} too low (min 2)")
                elif plant.sun > 12:
                    raise PlantError(f"Sun {plant.sun} too high (min 12)")
                else:
                    print(f"{plant.name}: is healthy! ", end="")
                    print(f"(water: {plant.water}, sun: {plant.sun})")
            except PlantError as error:
                print(f"Error checking: {error}")

    def check_water_tank(self):
        """Checks if the water tank has sufficient water."""
        try:
            if self.water_tank < self.water_required:
                raise WaterError(self.water_tank, self.water_required)
        except WaterError as error:
            print(f"Error checking water tank: {error}")

    def fill_water_tank(self, fill_water):
        """Fills the water tank with the specified amount."""
        try:
            water = fill_water + self.water_tank
            if water > self.water_max:
                raise GardenError("Too much water for the water tank")
            self.water_tank = water
            print(f"Water was added: {water}/{self.water_max}L")
        except GardenError as error:
            print(f"Error check: {error}")


print("=== Garden Management System ===")

plants = [
        Plant("tomato", 6, 8),
        Plant("sunflower", -1, 9),
        Plant("lettuce", 2, 3),
        Plant("carrot", 0, 9),
        Plant("cucumber", 5, 1),
    ]
garden = GardenManager(10)

print("\nAdding plants to garden...")
garden.add_plants(plants)

print("\nWatering plants...")
garden.water_plants()

print("\nChecking plant health...")
garden.check_plants_health()

print("\nTesting error recovery...")
garden.check_water_tank()
print("System recovered and continuing...")

print("\nFilling water tank...")
garden.fill_water_tank(50)

print("\nGarden management system test complete!")
