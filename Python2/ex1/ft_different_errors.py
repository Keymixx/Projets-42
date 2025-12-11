def garden_operations(error):
    plants = {}
    if error == "ZeroDivisionError":
        return 10 / 0  # Cause an ZeroDivisionError
    if error == "ValueError":
        return int("abc")  # Cause an ValueError
    if error == "FileNotFoundError":
        open("missing.txt", "r")  # Cause an FileNotFoundError
    if error == "KeyError":
        return plants["missing_plant"]  # Cause an KeyError


def test_error_types():  # Print and explain each error
    print("=== Garden Error Types Demo ===")
    print()
    print("Testing ValueError...")
    try:
        garden_operations("ValueError")  # Cause ValueError
    except ValueError as error:  # Catch ValueError
        print(f"Caught ValueError: {error}")  # Explains what went wrong
    print()
    print("Testing ZeroDivisionError...")
    try:
        garden_operations("ZeroDivisionError")
    except ZeroDivisionError as error:
        print(f"Caught ZeroDivisionError: {error}")
    print()
    print("Testing FileNotFoundError...")
    try:
        garden_operations("FileNotFoundError")
    except FileNotFoundError as error:
        print(f"Caught FileNotFoundError: {error}")
    print()
    print("Testing KeyError...")
    try:
        garden_operations("KeyError")
    except KeyError as error:
        print(f"Caught KeyError: {error}")
    print()
    print("Testing multiple errors together...")
    try:  # cause mutiple error
        garden_operations("KeyError")
        garden_operations("FileNotFoundError")
        garden_operations("ZeroDivisionError")
        garden_operations("ValueError")
    except (FileExistsError, KeyError, ValueError, ZeroDivisionError):
        print("Caught an error, but program continues!")
    print()
    print("All error types tested successfully")
    print("program didn't crash!")


test_error_types()
