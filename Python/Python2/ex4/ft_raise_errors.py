def check_plant_health(plant_name, water_level, sun_hours):

    if plant_name == "":
        raise ValueError("Plant name cannot be empty!")
    elif water_level < 1:
        raise ValueError(f"Water level {water_level} is too low (min 1)")
    elif water_level > 10:
        raise ValueError(f"Water level {water_level} is too high (max 10)")
    elif sun_hours < 2:
        raise ValueError(f"Sunlight hours {sun_hours} is too low (min 2)")
    elif sun_hours > 12:
        raise ValueError(f"Sunlight hours {sun_hours} is too high (min 12)")
    else:
        print(f"Plant '{plant_name}' is healthy!")


def test_plant_checks():

    print("=== Garden Plant Health Checker ===\n")

    print("Testing good values...")
    check_plant_health("tomato", 4, 8)

    print("\nTesting empty plant name...")
    try:
        check_plant_health("", 5, 7)
    except ValueError as error:
        print(f"Error: {error}")

    print("\nTesting bad water level...")
    try:
        check_plant_health("lettuce", 0, 7)
    except ValueError as error:
        print(f"Error: {error}")

    print("\nTesting bad sunlight hours...")
    try:
        check_plant_health("carrot", 9, 15)
    except ValueError as error:
        print(f"Error: {error}")

    print("\nAll error raising tests completed!")


test_plant_checks()
