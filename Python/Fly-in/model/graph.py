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
            current_distance, current_zone = heappop(pq)

            if current_zone in visited:
                continue
            visited.add(current_zone)

            for neighbor, weight in self.graph[current_zone].items():
                tentative_distance = current_distance + weight + len(neighbor.queue)
                if tentative_distance < distances[neighbor]:
                    distances[neighbor] = tentative_distance
                    heappush(pq, (tentative_distance, neighbor))


        predecessors = {node: None for node in self.graph}
        
        for node, distance in distances.items():
           for neighbor, weight in self.graph[node].items():
               if distances[neighbor] == distance + weight + len(neighbor.queue):
                   predecessors[neighbor] = node
        
        return distances, predecessors

    def shortest_path(self, start: Zone, end: Zone):
       # Generate the predecessors dict
       _, predecessors = self.shortest_distances(start)
    
       path = []
       current_zone = end
    
       # Backtrack from the target node using predecessors
       while current_zone:
           path.append(current_zone)
           current_zone = predecessors[current_zone]
    
       # Reverse the path and return it
       path.reverse()
    
       return path
    
    def run(self, drones: List[Drone]):
        for drone in drones:
            dist, p = self.shortest_distances(drone.current_zone)
            drone.distance = dist[self.end_zone]
        
        sorted(drones, key=lambda x: x.distance)
        turn = 0
        while not all([drone.current_zone.end for drone in drones]):
        # for i in range(50):
            turn += 1
            for drone in drones:
                if drone.current_zone == self.end_zone:
                    continue
                drone_path = self.shortest_path(drone.current_zone, self.end_zone)
                drone.do_turn(drone_path[1])
            print()
        print(turn)