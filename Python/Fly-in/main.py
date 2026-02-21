from parsing import parser
from vizualizator import graph_maker
from model import Graph
from model import Drone

# try:
info = parser("maps/hard/03_ultimate_challenge.txt")
# print(f"nb_drones: {info['nb_drones']}")
# for zone in info["zones"]:
    # if zone.name == "conv_restricted7":
        # zone.queue.append(1)
# for c in info["connections"]:
#     print(str(c))
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
    drones.append(Drone(f"D{i+1}", start,end))

g.run(drones)

# except Exception as e:
#     print(e)


graph_maker(info)