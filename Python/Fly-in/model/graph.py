from model import Drone
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
                try_distance = curr_distance + weight + len(nghb.queue)
                if try_distance < distances[nghb]:
                    distances[nghb] = try_distance
                    heappush(pq, (try_distance, nghb))

        predecessors = {node: None for node in self.graph}

        for node, distance in distances.items():
            for nghb, weight in self.graph[node].items():
                if distances[nghb] == distance + weight + len(nghb.queue):
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

    def run(self, drones: List[Drone]):
        for drone in drones:
            dist, p = self.shortest_distances(drone.curr_zone)
            drone.distance = dist[self.end_zone]

        sorted(drones, key=lambda x: x.distance)
        turn = 0
        while not all([drone.curr_zone.end for drone in drones]):
            turn += 1
            for drone in drones:
                if drone.curr_zone == self.end_zone:
                    continue
                drone_path = self.shortest_path(drone.curr_zone, self.end_zone)
                drone.do_turn(drone_path[1])
            print()
        print(turn)
