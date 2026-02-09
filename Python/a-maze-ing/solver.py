from typing import List, Dict, Optional
from mazegen import Cell
from time import sleep
import os
from colorama import Fore, Style


class Solver:
    """A class to solve mazes using a Breadth-First Search (BFS) algorithm.

    This class handles finding the shortest path between start and end cells,
    tracks the solution, and provides visual terminal rendering.
    """

    def __init__(self) -> None:
        """Initialize the Solver with empty state and default colors."""

        self.maze: List[List[Cell]] = []
        self.cell_start: Optional[Cell] = None
        self.cell_end: Optional[Cell] = None
        self.solution: List[Cell] = []

        self.colors = [
            Style.RESET_ALL,
            Fore.RED,
            Fore.BLUE,
            Fore.GREEN,
            Fore.YELLOW
        ]
        self.ic: int = 0

    def get_dir(self, new_cell: Cell, actual_cell: Cell) -> str:
        """Determine the cardinal direction between two adjacent cells.

        Args:
            new_cell (Cell): The parent cell in the search history.
            actual_cell (Cell): The current cell being evaluated.

        Returns:
            str: 'N', 'E', 'S', or 'W' indicating the move direction.
        """

        if new_cell.x + 1 == actual_cell.x:
            return "E"
        if new_cell.x - 1 == actual_cell.x:
            return "W"
        if new_cell.y + 1 == actual_cell.y:
            return "S"
        if new_cell.y - 1 == actual_cell.y:
            return "N"
        return ""

    def get_path(self, history: Dict[Cell, Cell]) -> str:
        """Backtrack through history to build the path string
            and solution list.

        Args:
            history (Dict[Cell, Cell]): A mapping of each cell to its parent.

        Returns:
            str: A string of directions (e.g., "NESW") from start to end.
        """

        if self.cell_end is None or self.cell_start is None:
            return ""

        cell_end = self.cell_end
        path: str = ""
        solution: List[Cell] = []
        actual_cell = history[cell_end]
        path += self.get_dir(actual_cell, cell_end)

        while not actual_cell == self.cell_start:  # retrace l'historique
            actual_cell.is_path = True
            solution.append(actual_cell)
            new_cell = history[actual_cell]
            path += self.get_dir(new_cell, actual_cell)
            actual_cell = new_cell
        solution.reverse()

        for s in solution:  # Lire la resolution du maze dans le bon sens
            self.solution.append(s)
            os.system("clear")
            self.print_maze(self.ic)
            sleep(0.05)
        return path[::-1]

    def solving(self, maze: List[List[Cell]],
                cell_start: Cell, cell_end: Cell) -> str:
        """Solve the maze using Breadth-First Search.

        Args:
            maze (List[List[Cell]]): The 2D grid representing the maze.
            cell_start (Cell): The entrance cell.
            cell_end (Cell): The exit cell.

        Returns:
            str: The shortest path string, or None if no solution exists.
        """

        self.solution.clear()
        self.cell_start = cell_start
        self.cell_end = cell_end
        self.maze = maze
        queue: List[Cell] = [cell_start]
        visited: List[Cell] = [cell_start]
        self.solution = []
        history: Dict[Cell, Cell] = {}

        while queue:
            actual_cell = queue.pop(0)

            if actual_cell == cell_end:
                return self.get_path(history)

            for n in actual_cell.neighbours:
                if n not in visited:
                    if actual_cell.wall["N"] and n.y + 1 == actual_cell.y:
                        visited.append(n)
                        history[n] = actual_cell
                        queue.append(n)

                    if actual_cell.wall["S"] and n.y - 1 == actual_cell.y:
                        visited.append(n)
                        history[n] = actual_cell
                        queue.append(n)

                    if actual_cell.wall["E"] and n.x - 1 == actual_cell.x:
                        visited.append(n)
                        history[n] = actual_cell
                        queue.append(n)

                    if actual_cell.wall["W"] and n.x + 1 == actual_cell.x:
                        visited.append(n)
                        history[n] = actual_cell
                        queue.append(n)
        return ""

    def color(self, cell: Cell) -> str:
        """Determine the background color for a cell based on its status.

        Args:
            cell (Cell): The cell to evaluate (start, end, path, or 42).

        Returns:
            str: ANSI escape sequence for the cell's background color.
        """

        if cell.is_42:
            return "\033[48;5;15m \033[0m\033[48;5;15m \033[0m"
        if cell in self.solution:
            return "\033[48;5;46m \033[0m\033[48;5;46m \033[0m"
        if cell is self.cell_start:
            return "\033[48;5;21m \033[0m\033[48;5;21m \033[0m"
        if cell is self.cell_end:
            return "\033[48;2;255;0;0m \033[0m\033[48;2;255;0;0m \033[0m"
        else:
            return "  "

    def print_line(self, y: int) -> None:
        """Render a horizontal line of walls for a specific row.

        Args:
            y (int): The row index to print.
        """

        len_maze = len(self.maze[0])
        for x in range(len_maze):
            cell: Cell = self.maze[y][x]
            if x == 0:
                print(self.colors[self.ic] + "╟", end="")
            if not cell.wall["N"]:
                if x == len_maze - 1:
                    print(self.colors[self.ic] + "──╢", end="")
                else:
                    print(self.colors[self.ic] + "──┼", end="")
            else:
                if x == len_maze - 1:
                    print(self.colors[self.ic] + "  ╢", end="")
                else:
                    print(self.colors[self.ic] + "  ┼", end="")

    def print_col(self, y: int) -> None:
        """Render the vertical walls and cell contents for a specific row.

        Args:
            y (int): The row index to print.
        """

        len_maze = len(self.maze[0])

        for x in range(len_maze):
            cell: Cell = self.maze[y][x]
            if cell.is_42:
                print(self.colors[self.ic] + f"│{self.color(cell)}", end="")

            elif x == 0:
                print(self.colors[self.ic] + f"║{self.color(cell)}", end="")

            elif not cell.wall["W"]:
                print(self.colors[self.ic] + f"│{self.color(cell)}", end="")

            elif cell.wall["W"]:
                print(self.colors[self.ic] + f" {self.color(cell)}", end="")

            if x == len_maze - 1:
                print(self.colors[self.ic] + "║", end="")

    def print_maze(self, color_i: int) -> None:
        """Render the entire maze to the terminal with specified wall color.

        Args:
            color_i (int): Index for the desired wall color in self.colors.
        """

        h_maze = len(self.maze)
        l_maze = len(self.maze[0]) - 1
        for y in range(h_maze):
            if y == 0:
                print(self.colors[color_i] + f"╔{'══╤' * l_maze}══╗", end="")
            else:
                self.print_line(y)
            print()
            self.print_col(y)
            print()
        print(f"╚{'══╧' * l_maze}══╝" + self.colors[0])
