from typing import Optional, Dict
from model.zone import Zone


class Connection:
    def __init__(self, zone1: str, zone2: str, metadata: Optional[Dict]):
        self.name = f"{zone1}-{zone2}"
        self.zone1 = zone1
        self.zone2 = zone2
        
        if metadata:
            self.capacity = metadata["max_link_capacity"]
        else:
            self.capacity = 1

    def __str__(self):
        return f"connection: {self.name}   capacity: {self.capacity}"
