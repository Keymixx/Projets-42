def check_temperature(temp_str):
    try:
        temp = int(temp_str)
        if temp > 0 and temp < 40:
            print(f"Temperature {temp}°C is perfect for plants!")
            return temp
        elif temp > 40:
            print(f"Error: {temp}°C is too hot for plants (max 40°C)")
        else:
            print(f"Error: {temp}°C is too cold for plants (min 0°C)")
        return None
    except Exception:  # Flake8
        print(f"Error: '{temp_str}' is not a valid number")
        return None


def test_temperature_input():
    print("=== Garden Temperature Checker ===")

    print("\nTesting temperature: 25")
    check_temperature("25")

    print("\nTesting temperature: abc")
    check_temperature("abc")

    print("\nTesting temperature: 100")
    check_temperature("100")

    print("\nTesting temperature: -50")
    check_temperature("-50")

    print("\nAll tests completed - program didn't crash!")


test_temperature_input()
