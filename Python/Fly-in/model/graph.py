from model import Zone, ZoneType
from heapq import heapify, heappop, heappush

class Graph:
    def __init__(self, map_info: dict):
        self.zones = map_info["zones"]
        self.connections = map_info["connections"]
        self.nb_drones = map_info["nb_drones"]
        self.graph = {}

    def add_edge(self, zone1: Zone, zone2: Zone):
        if zone1 not in self.graph:
            self.graph[zone1] = {}
        if zone1.type == ZoneType.BLOCKED or zone2.type == ZoneType.BLOCKED:
            self.graph[zone1][zone2] = float("inf")
        else:
            self.graph[zone1][zone2] = 1

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
                tentative_distance = current_distance + weight
                if tentative_distance < distances[neighbor]:
                    distances[neighbor] = tentative_distance
                    heappush(pq, (tentative_distance, neighbor))
        
        predecessors = {node: None for node in self.graph}

        for zone, distance in distances.items():
           for neighbor, weight in self.graph[zone].items():
               if distances[neighbor] == distance + weight + zone.type.value:
                   predecessors[neighbor] = zone

        return distances, predecessors
    
    def shortest_path(self, start: Zone, target: Zone):
        
        # Generate the predecessors dict
        _, predecessors = self.shortest_distances(start)
        
        path = []
        current_node = target
        
        # Backtrack from the target node using predecessors
        while current_node:
            path.append(current_node)
            current_node = predecessors[current_node]
        
        # Reverse the path and return it
        path.reverse()
        
        return path
