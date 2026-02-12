from typing import Optional, Dict
from zone import Zone


class Connection:
    def __init__(self, zone1: Zone, zone2: Zone, metadata: Optional[Dict]):
        self.name = f"{zone1.name}-{zone2.name}"
        self.zone1 = zone1
        self.zone2 = zone2
        self.capacity = 1
