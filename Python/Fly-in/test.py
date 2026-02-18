from parsing import parser
from vizualizator import graph_maker
from model import Graph

try:
    info = parser("maps/challenger/01_the_impossible_dream.txt")
    # print(f"nb_drones: {info['nb_drones']}")
    # for zone in info["zones"]:
    #     print(str(zone))
    # for c in info["connections"]:
    #     print(str(c))
    g = Graph(info)
    g.graph_init()
    g.print_graph()
except Exception as e:
    print(e)


# graph_maker(info)