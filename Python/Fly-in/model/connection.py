from __future__ import annotations
from typing import Dict, List, TYPE_CHECKING

if TYPE_CHECKING:
    from model.zone import Zone
    from model.drone import Drone


class Connection:
    def __init__(self, zone1: "Zone", zone2: "Zone", metadata: Dict[str, int]):
        self.name = f"{zone1.name}-{zone2.name}"
        self.zone1 = zone1
        self.zone2 = zone2
        self.capacity = metadata["max_link_capacity"]
        self.actual_drones: List["Drone"] = []

    def add_drone(self, drone: "Drone") -> None:
        self.actual_drones.append(drone)

    def remove_drone(self, drone: "Drone") -> None:
        if drone in self.actual_drones:
            self.actual_drones.remove(drone)

    def check_capacity(self) -> int:
        if len(self.actual_drones) < self.capacity:
            return self.capacity - len(self.actual_drones)
        else:
            return 0

    def __str__(self) -> str:
        return f"{self.name}"
