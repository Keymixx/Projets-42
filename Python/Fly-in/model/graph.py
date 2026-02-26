from model.drone import Drone
from model.connection import Connection
from model.zone import Zone, ZoneType
from heapq import heapify, heappop, heappush
from typing import List, Dict, Tuple, Any, Optional


class Graph:
    def __init__(self, map_info: Dict[str, Any], start: Zone, end: Zone):
        self.zones: List[Zone] = map_info["zones"]
        self.connections: List[Connection] = map_info["connections"]
        self.nb_drones: int = map_info["nb_drones"]
        self.graph: Dict[Zone, Dict[Zone, int]] = {}
        self.start_zone: Zone = start
        self.end_zone: Zone = end

    def add_edge(self, zone1: Zone, zone2: Zone) -> None:
        if zone1 not in self.graph:
            self.graph[zone1] = {}
        if zone1.type == ZoneType.BLOCKED or zone2.type == ZoneType.BLOCKED:
            pass
        else:
            self.graph[zone1][zone2] = zone2.type.value

    def graph_init(self) -> None:
        for zone in self.zones:
            for connection in self.connections:
                if zone == connection.zone1:
                    self.add_edge(zone, connection.zone2)
                if zone == connection.zone2:
                    self.add_edge(zone, connection.zone1)

    def shortest_distances(self, start: Zone) -> Tuple[Any, Any]:
        distances = {zone: float("inf") for zone in self.graph}
        distances[start] = 0

        pq = [(0, start)]
        heapify(pq)

        visited = set()

        while pq:
            curr_distance, curr_zone = heappop(pq)

            if curr_zone in visited:
                continue
            visited.add(curr_zone)

            for nghb, weight in self.graph[curr_zone].items():
                try_distance = curr_distance + weight + len(nghb.incoming)
                if try_distance < distances[nghb]:
                    distances[nghb] = try_distance
                    heappush(pq, (try_distance, nghb))

        prev: Dict[Zone, Optional[Zone]] = {zone: None for zone in self.graph}

        for zone, distance in distances.items():
            for nghb, weight in self.graph[zone].items():
                if distances[nghb] == distance + weight + len(nghb.incoming):
                    prev[nghb] = zone

        return distances, prev

    def shortest_path(self, start: Zone, end: Zone) -> List[Zone]:

        _, predecessors = self.shortest_distances(start)

        path = []
        curr_zone: Optional[Zone] = end

        while curr_zone:
            path.append(curr_zone)
            curr_zone = predecessors[curr_zone]

        path.reverse()
        return path

    def find_connect(self, zone1: Zone, zone2: Zone) -> Connection:
        for c in self.connections:
            if c.zone1 == zone1 and c.zone2 == zone2:
                return c
            elif c.zone1 == zone2 and c.zone2 == zone1:
                return c
        return self.connections[1]

    def run(self, drones: List[Drone]) -> None:

        turn = 0
        while not all([drone.current == self.end_zone for drone in drones]):
            for drone in drones:
                dist, p = self.shortest_distances(drone.last_location)
                drone.distance = dist[self.end_zone]
            drones.sort(key=lambda x: x.distance)

            turn += 1
            for drone in drones:
                if drone.in_transit:
                    if drone.turn_left == 1:
                        print(f"D{drone.id}-{drone.destination}", end=" ")
                    drone.update_transit()

            in_zone = [drone for drone in drones if not drone.in_transit]

            for drone in in_zone:
                if drone.current == self.end_zone:
                    continue
                dest: Zone = self.shortest_path(drone.last_location,
                                                self.end_zone)[1]

                connect: Connection = self.find_connect(drone.last_location,
                                                        dest)

                if dest.not_full() and connect.check_capacity():
                    drone.move(dest, connect)
                    if drone.destination.type.value <= 1:
                        print(f"D{drone.id}-{drone.destination}", end=" ")
                    else:
                        print(f"D{drone.id}-{connect}", end=" ")

            print()
            print()
        print(turn)
