from model import Zone


class Drone:
    def __init__(self, id: str, start: Zone, end: Zone):
        self.current_zone: Zone = start
        self.end_zone: Zone = end
        self.distance = 0
        self.id = id
        self.restricted_turn = False

    def do_turn(self, dest: Zone) -> str:
        if self.current_zone.type.value == 2 and not self.restricted_turn:
            self.restricted_turn = True
            self.stay()
        
        elif self in dest.queue or self.current_zone.end:
            if dest.check_capacity():
                dest.queue.remove(self)
                self.move(dest)
                self.restricted_turn = False
            else:
                self.stay()

        elif dest.check_capacity() or dest.end or self in dest.actual_drones:
            self.move(dest)
            self.restricted_turn = False
        
        else:
            dest.add_drone(self)
        
        print(f"{self.id}-{self.current_zone}")

    def move(self, dest: Zone):
        self.current_zone.remove_drone(self)
        dest.add_drone(self)
        self.current_zone = dest

    def stay(self):
        pass
    
    def __str__(self) -> str:
        return f"{self.id}"