from typing import Optional
from enum import Enum


class ZoneType(Enum):
    START = "start_hub"
    END = "end_hub"
    NORMAL = "normal"
    BLOCKED = "blocked"
    RESTRICTED = "restricted"
    PRIORITY = "priority"


class Zone:
    def __init__(self, name: str, x: int, y: int, metadata: Optional[dict]):
        self.name = name
        self.x = x
        self.y = y
        self.zone_type = metadata["zone"]
        self.max_drones = metadata["max_drones"]
        self.color = metadata["color"]
        self.link = []
        self.start = False
        self.end = False
    
    def __str__(self) -> str:
        return f"{self.name} x: {self.x} y: {self.y}  type: {self.zone_type}  max: {self.max_drones}  color: {self.color}"