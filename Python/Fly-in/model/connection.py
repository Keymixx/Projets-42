from typing import Optional, Dict
from model.zone import Zone


class Connection:
    def __init__(self, zone1: Zone, zone2: Zone, metadata: Optional[Dict]):
        self.name = f"{zone1.name}-{zone2.name}"
        self.zone1 = zone1
        self.zone2 = zone2
        self.capacity = metadata["max_link_capacity"]
        self.actual_drones = []

    def add_drone(self, drone):
        if self.check_capacity() or self.end:
            self.actual_drones.append(drone)
        else:
            self.queue.append(drone)

    def remove_drone(self, drone):
        if drone in self.actual_drones:
            self.actual_drones.remove(drone)

    def check_capacity(self) -> int:
        if len(self.actual_drones) < self.capacity:
            return self.capacity - len(self.actual_drones)
        else:
            return 0

    def __str__(self):
        return f"{self.name}"

