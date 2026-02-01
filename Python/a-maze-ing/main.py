from PIL import Image
from a_maze_ing import MazePrimGenerator

map = MazePrimGenerator(20,20)
map.maze_init()
map.prim_generator()
img = Image.open("landscape_comp (1).jpeg")
img.show()
