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
        self.metadata = metadata
        self.link = []
