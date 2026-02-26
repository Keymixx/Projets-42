from __future__ import annotations
from typing import Dict, Any, List, TYPE_CHECKING
from enum import Enum
if TYPE_CHECKING:
    from model.drone import Drone


class ZoneColor(Enum):
    purple = "\033[38;5;129m"
    red = "\033[31m"
    brown = "\033[38;5;130m"
    black = "\033[30m"
    orange = "\033[38;5;208m"
    gold = "\033[38;5;220m"
    darkred = "\033[38;5;88m"
    violet = "\033[38;5;135m"
    crimson = "\033[38;5;160m"
    blue = "\033[34m"
    cyan = "\033[36m"
    yellow = "\033[33m"
    green = "\033[32m"
    lime = "\033[38;5;154m"
    magenta = "\033[35m"
    maroon = "\033[38;5;88m"
    rainbow = 0
    reset = "\033[0m"


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

    def rainbow_zone(self, text: str) -> str:
        colors = list(ZoneColor)
        result = ""
        for i, char in enumerate(text):
            color = colors[i % len(colors)]
            result += color.value + char
        return result + ZoneColor.reset.value

    def __str__(self) -> Any:
        if self.color == "rainbow":
            return self.rainbow_zone(self.name)
        return ZoneColor[self.color].value + self.name + ZoneColor.reset.value

    def __lt__(self, other: Zone) -> Any:
        return self.type.value < other.type.value
