from parsing import parser
from model import Graph
# from vizualizator import graph_maker
from model import Drone

# try:
info = parser("maps/hard/02_capacity_hell.txt")
for zone in info["zones"]:
    if zone.start:
        start = zone
    if zone.end:
        end = zone
g = Graph(info, start, end)
g.graph_init()
distance, p = g.shortest_distances(start)
drones = []
for i in range(info["nb_drones"]):
    drones.append(Drone(f"{i+1}", start))
g.run(drones)

# except Exception as e:
#     print(e)


# graph_maker(info)
