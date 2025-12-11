def water_plants(plant_list):
    print("Opening watering system")
    try:
        for plant in plant_list:
            if plant == "":
                1 / 0
            print(f"Watering {plant}")
    except ZeroDivisionError:  # Flake8
        print("Error: Cannot water None - invalid plant!")
    finally:
        print("Closing watering system (cleanup)")


def test_watering_system():

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
