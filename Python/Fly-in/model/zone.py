from __future__ import annotations
from typing import Dict, Any, List, TYPE_CHECKING
from enum import Enum
if TYPE_CHECKING:
    from model.drone import Drone


class ZoneType(Enum):
    NORMAL = 1
    BLOCKED = 999
    RESTRICTED = 2
    PRIORITY = 0.99


class Zone:
    def __init__(self, name: str, x: int, y: int, metadata: Dict[str, Any]):
        self.name: str = name
        self.x: int = x
        self.y: int = y
        self.type: ZoneType = metadata["zone"]
        self.max_drones: int = metadata["max_drones"]
        self.color: str = metadata["color"]
        self.start: bool = False
        self.end: bool = False
        self.actual_drones: List[Drone] = []
        self.incoming: List[Drone] = []

    def add_incoming(self, drone: Drone) -> None:
        self.incoming.append(drone)

    def add_to_zone(self, drone: Drone) -> None:
        if drone in self.incoming:
            self.incoming.remove(drone)
        self.actual_drones.append(drone)

    def remove_drone(self, drone: Drone) -> None:
        if drone in self.actual_drones:
            self.actual_drones.remove(drone)

    def not_full(self) -> bool:
        return (len(self.actual_drones) + len(self.incoming)) < self.max_drones

    def __str__(self) -> str:
        return f"{self.name}"

    def __lt__(self, other: Zone) -> Any:
        return self.type.value < other.type.value
