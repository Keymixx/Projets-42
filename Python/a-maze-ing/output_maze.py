from typing import List
from mazegen import Cell


def convert_maze(maze: List[List[Cell]]) -> str:
    """Convert the maze into a hexadecimal string representation.

    Each cell is encoded as a hexadecimal digit based on its walls
    (North=bit 0, East=bit 1, South=bit 2, West=bit 3).

    Args:
        maze (List[List[Cell]]): The 2D grid of cells to convert.

    Returns:
        str: A string of hexadecimal digits representing the maze,
            with each row separated by a newline.
    """

    hexa_map = ""
    for row in maze:
        for cell in row:
            bstring = "WSEN"
            if cell.wall["N"]:
                bstring = bstring.replace("N", "0")
            else:
                bstring = bstring.replace("N", "1")
            if cell.wall["E"]:
                bstring = bstring.replace("E", "0")
            else:
                bstring = bstring.replace("E", "1")
            if cell.wall["S"]:
                bstring = bstring.replace("S", "0")
            else:
                bstring = bstring.replace("S", "1")
            if cell.wall["W"]:
                bstring = bstring.replace("W", "0")
            else:
                bstring = bstring.replace("W", "1")
            hexa_cell = hex(int(bstring, 2)).split("0x")[1].capitalize()
            hexa_map += hexa_cell
        hexa_map += "\n"
    return hexa_map


def output_maze(file: str, maze: List[List[Cell]],
                cell_start: Cell, cell_end: Cell, path: str) -> bool:
    """Write the maze data and its solution path to an output file.

    The file includes the hexadecimal map, the entry/exit coordinates,
    and the shortest path from start to end.

    Args:
        file (str): The name or path of the output file.
        maze (List[List[Cell]]): The generated maze structure.
        cell_start (Cell): The designated entry cell.
        cell_end (Cell): The designated exit cell.
        path (str): The solution path as a sequence of N, E, S, W.

    Returns:
        None: This function does not return a value.
    """
    try:
        with open(file, "w") as f:
            f.write(convert_maze(maze))
            f.write("\n")
            f.write(f"{cell_start.y}, {cell_start.x}\n")
            f.write(f"{cell_end.y}, {cell_end.x}\n")
            # if path:
            f.write(path)
            return True

    except PermissionError:
        return False
