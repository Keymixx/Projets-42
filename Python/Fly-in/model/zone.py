from typing import Optional, List
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
        self.queue = []

    def add_drone(self, drone):
        if self.check_capacity() or self.end:
            self.actual_drones.append(drone)
        else:
            self.queue.append(drone)
    
    def remove_drone(self, drone):
        if not self.start:
            self.actual_drones.remove(drone)

    def check_capacity(self) -> int:
        if len(self.actual_drones) < self.max_drones:
            return self.max_drones - len(self.actual_drones)
        else:
            return 0


    def __str__(self) -> str:
        return f"{self.name}"
    
    def __lt__(self, other: Zone):
        return self.type.value < other.type.value
    