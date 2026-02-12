def parser(map: str) -> dict:
    map_info = {
        "nb_drones": 0,
        "start_hub":
    }
    
    with open(map, "r") as f:
        for line in f:
            if not line or line.startswith("#"):
                continue
            
            if