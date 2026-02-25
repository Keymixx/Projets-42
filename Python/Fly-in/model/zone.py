from typing import Optional
from enum import Enum


class ZoneType(Enum):
    NORMAL = 1
    BLOCKED = 999
    RESTRICTED = 2
    PRIORITY = 0.99


class Zone:
    def __init__(self, name: str, x: int, y: int, metadata: Optional[dict]):
        self.name = name
        self.x = x
        self.y = y
        self.type = metadata["zone"]
        self.max_drones = metadata["max_drones"]
        self.color = metadata["color"]
        self.start = False
        self.end = False
        self.actual_drones = []
        self.incoming_drones = []

    def add_incoming(self, drone):
        self.incoming_drones.append(drone)

    def add_to_zone(self, drone):
        self.incoming_drones.remove(drone)
        self.actual_drones.append(drone)

    def remove_drone(self, drone):
        if not self.start:
            self.actual_drones.remove(drone)

    def not_full(self) -> int:
        if len(self.actual_drones) + len(self.incoming_drones) < self.max_drones:
            return True
        else:
            return False

    def __str__(self) -> str:
        return f"{self.name}"

    def __lt__(self, other):
        return self.type.value < other.type.value
