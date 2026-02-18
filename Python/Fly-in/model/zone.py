from typing import Optional
from enum import Enum


class ZoneType(Enum):
    NORMAL = 1
    BLOCKED = float("inf")
    RESTRICTED = 2
    PRIORITY = 0.8


class Zone:
    def __init__(self, name: str, x: int, y: int, metadata: Optional[dict]):
        self.name = name
        self.x = x
        self.y = y
        self.type = metadata["zone"]
        self.max_drones = metadata["max_drones"]
        self.color = metadata["color"]
        self.link = []
        self.start = False
        self.end = False
    
    def __str__(self) -> str:
        return f"{self.name}"