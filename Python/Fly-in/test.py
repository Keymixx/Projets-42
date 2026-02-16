from parsing import parser
try:
    info = parser("maps/test_maps/01_test_map.txt")
    print(f"nb_drones: {info["nb_drones"]}")
    for zone in info["zones"]:
        print(str(zone))
    for c in info["connections"]:
        print(str(c))
except Exception as e:
    print(e)
