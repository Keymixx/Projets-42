def garden_operations(error):
    """Triggers different types of errors based on the input parameter."""
    plants = {}
    if error == "ZeroDivisionError":
        return 10 / 0
    if error == "ValueError":
        return int("abc")
    if error == "FileNotFoundError":
        open("missing.txt", "r")
    if error == "KeyError":
        return plants["missing_plant"]


def test_error_types():
    """Tests handling of various Python error types in garden operations."""
    print("=== Garden Error Types Demo ===\n")

# ===================ValueError=========================
    print("Testing ValueError...")
    try:
        garden_operations("ValueError")
    except ValueError as error:
        print(f"Caught ValueError: {error}")
    print()
# ================ZeroDivisionError=====================
    print("Testing ZeroDivisionError...")
    try:
        garden_operations("ZeroDivisionError")
    except ZeroDivisionError as error:
        print(f"Caught ZeroDivisionError: {error}")
    print()
# =================FileNotFoundError=====================
    print("Testing FileNotFoundError...")
    try:
        garden_operations("FileNotFoundError")
    except FileNotFoundError as error:
        print(f"Caught FileNotFoundError: {error}")
    print()
# =====================KeyError=======================
    print("Testing KeyError...")
    try:
        garden_operations("KeyError")
    except KeyError as error:
        print(f"Caught KeyError: {error}")
    print()
# ====================MultipleTest=========================
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
