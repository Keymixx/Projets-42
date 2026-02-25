from typing import Dict, Union
from model import Connection, Zone, ZoneType
import re


def connection_parser(line: str) -> Dict:
    split_connect = line.split()
    metadata = {"max_link_capacity": 1}
    pattern_connect = r"^\w+-\w+$"
    pattern_metadata = r"^\[max_link_capacity=\d+\]$"

    if 2 > len(split_connect) > 3:
        raise ValueError("excepted connection: <name1>-<name2> [metadata]")

    if not re.match(pattern_connect, split_connect[1]):
        raise ValueError("excepted connection: 'zone1-zone2'")
    else:
        zones = sorted(split_connect[1].split("-"))
        if zones[0] == zones[1]:
            raise ValueError(f"name zone can't be similar: {split_connect[1]}")

    if len(split_connect) == 3:
        if not re.match(pattern_metadata, split_connect[2]):
            raise ValueError("excepted metadata:[max_link_capacity='integer']")
        else:
            parse_metadata = re.split(r"[\[\]=]", split_connect[2])
            metadata = {parse_metadata[1]: int(parse_metadata[2])}

    return {"zone1": zones[0], "zone2": zones[1], "metadata": metadata}


def hub_parser(line: str, start_finish: bool) -> Zone:
    zone_type = ZoneType.NORMAL
    max_drones = 1
    color = None

    valid_zones = [
        "normal",
        "restricted",
        "priority",
        "blocked"
    ]

    occ_metadata = re.findall(r'\[(.*?)\]', line)
    if occ_metadata:
        if len(occ_metadata) > 1:
            raise ValueError(f"Duplicate metadata detected : {occ_metadata}")
        raw_metadata = occ_metadata[0]
        line = line.replace(f"[{raw_metadata}]", "")
        split_metadata = raw_metadata.split()
        for data in split_metadata:
            if data.startswith("zone="):
                if start_finish:
                    raise ValueError("start or end zone type can't be modify")
                zone_type = data.strip("zone=")
                if zone_type not in valid_zones:
                    raise ValueError(f"Invalid zone: {data}")

                if zone_type == "normal":
                    zone_type = ZoneType.NORMAL
                if zone_type == "restricted":
                    zone_type = ZoneType.RESTRICTED
                if zone_type == "blocked":
                    zone_type = ZoneType.BLOCKED
                if zone_type == "priority":
                    zone_type = ZoneType.PRIORITY

            elif data.startswith("max_drones="):
                try:
                    max_drones = int(data.strip("max_drones="))
                    if max_drones < 1:
                        raise ValueError("max_drone must superior than 0")
                except Exception:
                    raise ValueError("max_drones must be a integer")

            elif data.startswith("color="):
                color = data.replace("color=", "")

            else:
                raise ValueError(f"Invalid metada : {data}")

    metadata = {
        "zone": zone_type,
        "max_drones": max_drones,
        "color": color
    }
    split_hub = line.split()

    if len(split_hub) != 4:
        raise ValueError("hub format line: hub: <name> <x> <y> [metadata]")

    if not split_hub[1].find("-") == -1:
        raise ValueError("Dash not allowed in zone name")

    try:
        split_hub[2] = int(split_hub[2])
    except ValueError:
        raise ValueError("<x> must be a integer")

    try:
        split_hub[3] = int(split_hub[3])
    except ValueError:
        raise ValueError("<y> must be a integer")

    return Zone(split_hub[1], split_hub[2], split_hub[3], metadata)


def nb_drones_parser(line: str) -> int:
    nb_drones = line.strip("nb_drones:")
    nb_drones = nb_drones.strip()

    try:
        nb_drones = int(nb_drones)
    except ValueError:
        raise ValueError("nb_drones must be a integer")

    if nb_drones < 1:
        raise ValueError("nb_drones must be a positive integer")

    return nb_drones


def check_mismatch(map_info: Dict, data: Union[Zone, Connection]):
    if isinstance(data, Connection):
        if any(data.name == c.name for c in map_info["connections"]):
            raise ValueError(f"duplicate connection: {data.name}")
        if not any(data.zone1.name == zone.name for zone in map_info["zones"]):
            raise ValueError(f"error connection ({data.name}):"
                             f"{data.zone1.name} not found")
        if not any(data.zone2.name == zone.name for zone in map_info["zones"]):
            raise ValueError(f"error connection ({data.name}):"
                             f"{data.zone2.name} not found")

    if isinstance(data, Zone):
        if any(data.name == z.name for z in map_info["zones"]):
            raise ValueError(f"duplicate zone name: {data.name}")
        if any((data.x, data.y) == (z.x, z.y) for z in map_info["zones"]):
            raise ValueError(f"duplicate coord: x: {data.x} y: {data.y}")


def parser(map: str) -> Dict:

    map_info = {
        "nb_drones": 0,
        "connections": [],
        "zones": []
    }

    valid_lines = [
        "hub:",
        "connection:",
        "start_hub:",
        "end_hub:",
        "nb_drones:"
        ]

    unique_line = [
        "start_hub:",
        "end_hub:",
        "nb_drones:"
    ]

    with open(map, "r") as f:
        first_line = True
        nb_line = 0
        for line in f:
            try:
                nb_line += 1
                line = line.strip()
                if not line or line.startswith("#"):
                    continue

                elif not any(line.startswith(x) for x in valid_lines):
                    if any(line.startswith(x) for x in unique_line):
                        raise ValueError(f"duplicate line detected: '{line}'")
                    raise ValueError(f"Invalid Line: {line}")

                elif first_line and line.startswith("nb_drones:"):
                    map_info["nb_drones"] = nb_drones_parser(line)
                    valid_lines.remove("nb_drones:")
                    first_line = False

                elif first_line and map_info["nb_drones"] == 0:
                    raise ValueError("first line must start with nb_drones")

                elif line.startswith("connection:"):
                    connect_dict = connection_parser(line)
                    for zone in map_info["zones"]:
                        if zone.name == connect_dict["zone1"]:
                            zone1 = zone
                        if zone.name == connect_dict["zone2"]:
                            zone2 = zone
                    metadata = connect_dict["metadata"]
                    connect = Connection(zone1, zone2, metadata)
                    check_mismatch(map_info, connect)
                    map_info["connections"].append(connect)

                elif line.startswith("hub:"):
                    zone = hub_parser(line, False)
                    check_mismatch(map_info, zone)
                    map_info["zones"].append(zone)

                elif line.startswith("start_hub:"):
                    start_zone = hub_parser(line, True)
                    check_mismatch(map_info, start_zone)
                    start_zone.start = True
                    map_info["zones"].append(start_zone)
                    valid_lines.remove("start_hub:")

                elif line.startswith("end_hub:"):
                    end_zone = hub_parser(line, True)
                    check_mismatch(map_info, end_zone)
                    end_zone.end = True
                    map_info["zones"].append(end_zone)
                    valid_lines.remove("end_hub:")

            except Exception as e:
                raise Exception(f"{e} <line {nb_line}>")

        return map_info
