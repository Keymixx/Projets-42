import sys
import math


def calcul_distance(first_coord: tuple, second_coord: tuple) -> int:
    x1, y1, z1 = first_coord
    x2, y2, z2 = second_coord
    return math.sqrt((x2-x1)**2 + (y2-y1)**2 + (z2-z1)**2)


def one_arg():
    print('Invalid number of args. ')
    print('Usage: python3 ft_coordinate_system.py <x> <y> <z> or "x,y,z"...')
    quit()


def two_args(args: list) -> tuple:
    coord = args[1].split(",")
    i = 0
    len_coord = len(coord)
    if not len_coord == 3:
        print("Invalid number of args.")
        print('Usage: python3 ft_coordinate_system.py "x,y,z"...')
        quit()
    try:
        while i < len(coord):
            coord[i] = int(coord[i])
            i += 1
    except ValueError:
        print(f"Parsing invalid coordinates: {args}")
        print("Error parsing coordinates: invalid literal", end="")
        print(f"for int() with base 10: '{coord[i]}'")
        print("Error details - Type: ValueError, Args:", end="")
        print(f"('invalid literal for int() with base 10:' '{coord[i]}'")
        quit()

    coord = tuple(coord)
    return coord


def four_args(args: list) -> tuple:
    i = 1
    try:
        while i < len_args:
            args[i] = int(args[i])
            i += 1
    except TypeError:
        print(f"Parsing invalid coordinates: {args}")
        print("Error parsing coordinates: invalid literal", end="")
        print(f"for int() with base 10: '{sys.argv[i]}'")
        print("Error details - Type: ValueError, Args:", end="")
        print(f"('invalid literal for int() with base 10:' '{sys.argv[i]}'")
        quit()

    coord = tuple(sys.argv[1:])
    return coord


spawn = (0, 0, 0)
len_args = len(sys.argv)
if len_args == 1:
    one_arg()
elif len_args == 2:
    coord = two_args(sys.argv)
elif len_args == 4:
    coord = four_args(sys.argv)
else:
    print('Invalid number of args')
    print('Usage: python3 ft_coordinate_system.py <x> <y> <z> or "x,y,z"...')
    quit()

distance = calcul_distance(spawn, coord)
print("=== Game Coordinate System ===")
print(f"Position created: {coord}")
print(f"Distance between {spawn} and {coord}: {distance:.2f}")

print("\nUnpacking demonstration:")
x1, y1, z1 = spawn
print(f"Spawn at : x={x1} y={y1} z={z1}")
x2, y2, z2 = coord
print(f"Player at : x={x2} y={y2} z={z2}")
