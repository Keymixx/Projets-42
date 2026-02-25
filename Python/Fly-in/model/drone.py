from model import Zone
from model import Connection
from typing import Union

class Drone:
    def __init__(self, id: str, start: Zone, end: Zone):
        self.current_location: Union[Zone, Connection] = start
        self.last_location: Zone = start
        self.destination: Zone = None
        self.distance: int = 0
        self.id: str = id
        self.turn_left: int = 0
        self.in_transit = False

    def move(self, dest: Zone, connect: Connection) -> str:
        if isinstance(self.current_location, Zone):
            self.current_location.remove_drone(self)

        self.last_location = self.current_location
        self.current_location = connect
        self.destination = dest

        if dest.type.value == 2:
            self.turn_left = 1
        else:
            self.turn_left = 0
        
        self.in_transit = True
        
        dest.add_incoming(self)

    def update_transit(self):
        if self.turn_left > 0:
            self.turn_left -= 1
        else:
            self.destination.add_to_zone(self)
            self.current_location = self.destination
            self.destination = None
            self.in_transit = False

    def __str__(self) -> str:
        return f"{self.id}"
