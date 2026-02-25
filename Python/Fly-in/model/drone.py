from __future__ import annotations
from typing import Union, Optional
from model.zone import Zone
from model.connection import Connection


class Drone:
    def __init__(self, id: str, start: "Zone"):
        self.current: Union["Zone", Connection] = start
        self.last_location: "Zone" = start
        self.destination: Optional["Zone"] = None
        self.distance: float = 0
        self.id: str = id
        self.turn_left: int = 0
        self.in_transit: bool = False

    def move(self, dest: "Zone", connect: Connection) -> None:
        if isinstance(self.current, Zone):
            self.current.remove_drone(self)

        self.current = connect
        connect.add_drone(self)
        self.destination = dest

        if dest.type.value == 2:
            self.turn_left = 1
        else:
            self.turn_left = 0

        self.in_transit = True
        dest.add_incoming(self)

    def update_transit(self) -> None:
        if self.turn_left > 0:
            self.turn_left -= 1
        else:
            if self.destination is not None:
                from model.connection import Connection
                if isinstance(self.current, Connection):
                    self.current.remove_drone(self)
                self.destination.add_to_zone(self)
                self.current = self.destination
                self.last_location = self.destination
                self.destination = None
                self.in_transit = False

    def __str__(self) -> str:
        return f"{self.id}"
