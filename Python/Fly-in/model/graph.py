from model import Zone, ZoneType


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
