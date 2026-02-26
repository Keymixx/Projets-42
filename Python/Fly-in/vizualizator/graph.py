from pyvis.network import Network


def graph_maker(map_info: dict) -> None:
    list_zones = map_info["zones"]
    list_connections = map_info["connections"]

    net = Network(notebook=True,
                  cdn_resources="remote",
                  height="1080px",
                  width="1920px")
    for zone in list_zones:
        x = zone.x * 150
        y = zone.y * 150
        net.add_node(zone.name,
                     label=zone.name,
                     x=x,
                     y=y,
                     fixed=True,
                     color='\033[39m')

    for connect in list_connections:
        net.add_edge(connect.zone1.name,
                     connect.zone2.name,
                     value=connect.capacity,
                     label=str(connect.capacity),
                     color="lightgray")
    net.show("map.html")
