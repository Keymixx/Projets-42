from model import Drone
from model import Connection
from model import Zone, ZoneType
from heapq import heapify, heappop, heappush
from typing import List


class Graph:
    def __init__(self, map_info: dict, start, end):
        self.zones = map_info["zones"]
        self.connections = map_info["connections"]
        self.nb_drones = map_info["nb_drones"]
        self.graph = {}
        self.start_zone = start
        self.end_zone = end

    def add_edge(self, zone1: Zone, zone2: Zone):
        if zone1 not in self.graph:
            self.graph[zone1] = {}
        if zone1.type == ZoneType.BLOCKED or zone2.type == ZoneType.BLOCKED:
            pass
        else:
            self.graph[zone1][zone2] = zone2.type.value

    def graph_init(self):
        for zone in self.zones:
            for connection in self.connections:
                if zone == connection.zone1:
                    self.add_edge(zone, connection.zone2)
                if zone == connection.zone2:
                    self.add_edge(zone, connection.zone1)

    def print_graph(self):
        for a, b in self.graph.items():
            print(a, b)

    def shortest_distances(self, start: Zone):
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
                try_distance = curr_distance + weight + len(nghb.incoming_drones)
                if try_distance < distances[nghb]:
                    distances[nghb] = try_distance
                    heappush(pq, (try_distance, nghb))

        predecessors = {node: None for node in self.graph}

        for node, distance in distances.items():
            for nghb, weight in self.graph[node].items():
                if distances[nghb] == distance + weight + len(nghb.incoming_drones):
                    predecessors[nghb] = node

        return distances, predecessors

    def shortest_path(self, start: Zone, end: Zone):

        _, predecessors = self.shortest_distances(start)

        path = []
        curr_zone = end

        while curr_zone:
            path.append(curr_zone)
            curr_zone = predecessors[curr_zone]

        path.reverse()
        return path

    def find_connect(self, zone1: Zone, zone2: Zone):
        for c in self.connections:
            if c.zone1 == zone1 and c.zone2 == zone2:
                return c
            elif c.zone1 == zone2 and c.zone2 == zone1:
                return c
            else:
                continue

    def run(self, drones: List[Drone]):

        turn = 0
        while not all([drone.current_location == self.end_zone for drone in drones]):
            for drone in drones:
                dist, p = self.shortest_distances(drone.last_location)
                drone.distance = dist[self.end_zone]
            drones.sort(key=lambda x: x.distance)
            
            turn += 1
            for drone in drones:
                if drone.in_transit:
                    drone.update_transit()
                    if drone.in_transit:
                        print(f"D{drone.id}-{drone.current_location}", end=" ")
            
            not_transit_drone = [drone for drone in drones if not drone.in_transit]
            
            for drone in not_transit_drone:
                if drone.current_location == self.end_zone:
                    continue

                dest: Zone = self.shortest_path(drone.current_location, self.end_zone)[1]
                connect: Connection = self.find_connect(drone.current_location, dest)

                if dest.not_full() and connect.check_capacity():
                    drone.move(dest, connect)
                    print(f"D{drone.id}-{drone.destination}", end=" ")

            print()
        print(turn)
