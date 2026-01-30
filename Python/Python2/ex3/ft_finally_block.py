def water_plants(plant_list):
    """Waters all plants in the list and handles errors."""

    print("Opening watering system")
    try:
        for plant in plant_list:
            if plant == "":
                raise ("Cannot water None - invalid plant!")
            print(f"Watering {plant}")
    except Exception as error:  # Flake8
        print(f"Error: {error}")
    finally:
        print("Closing watering system (cleanup)")


def test_watering_system():
    """Tests the watering system with valid and invalid plant lists."""

    print("=== Garden Watering System ===\n")
    print("Testing normal watering...")
    good_list_plants = [
        "carrot",
        "tomato",
        "rose",
        "sunflower",
        "potato",
        "lettuce"
    ]
    water_plants(good_list_plants)
    print("Watering completed successfully!\n")

    print("Testing with error...")
    bad_list_plants = [
        "carrot",
        "",
        "rose",
        "sunflower",
        "",
        "lettuce"
    ]
    water_plants(bad_list_plants)
    print("\nCleanup always happens, even with errors!")


test_watering_system()
