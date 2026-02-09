import os
import random
import time
from colorama import Fore, Style
from typing import List, Optional


def white() -> str:
    """Provide the ANSI escape sequence for a white background block.

    Returns:
        str: A string containing the ANSI escape codes for a white block
            used to render the '42' pattern.
    """

    return "\033[48;5;15m \033[0m\033[48;5;15m \033[0m"


def red() -> str:
    """Provide the ANSI escape sequence for a red background block.

    Returns:
        str: A string containing the ANSI escape codes for a red block
            used to highlight the maze frontiers or exit.
    """
    return "\033[48;2;255;0;0m \033[0m\033[48;2;255;0;0m \033[0m"


class Cell:
    """Represents a single node in the maze grid.

    Attributes:
        wall (dict): Directions (N, E, S, W) mapping to boolean wall status.
        is_42 (bool): True if the cell belongs to the '42' logo pattern.
        y (int): Vertical coordinate in the grid.
        x (int): Horizontal coordinate in the grid.
        neighbours (set): Set of reachable adjacent Cell objects.
        unvisited (bool): Generation flag to track algorithm progress.
    """

    def __init__(self, y: int, x: int) -> None:
        """Initialize a cell with its grid coordinates.

        Args:
            y (int): The row index.
            x (int): The column index.
        """

        self.wall = {
            "N": False,
            "E": False,
            "S": False,
            "W": False
        }

        self.is_42: bool = False
        self.is_path: bool = False
        self.y = y
        self.x = x

        self.neighbours: set[Cell] = set()
        self.unvisited = True


class MazeGenerator:
    """Handles maze grid generation, logo placement, and terminal rendering.

    Provides algorithms like Prim's and Binary Tree to create varied mazes
    while protecting specific patterns like the '42' logo.
    """

    def __init__(self, width: int, height: int,
                 seed: Optional[int] = None) -> None:
        """Initialize dimensions and configuration for the maze generator.

        Args:
            width (int): Requested width of the maze.
            height (int): Requested height of the maze.

        Raises:
            ValueError: If dimensions are smaller than the 6x8 minimum.
        """
        if width < 1 or width > 65:
            raise ValueError("Width must be between 2 and 65")
        if height < 1 or height > 25:
            raise ValueError("Height must be between 2 and 25")

        self.width = width + 1
        self.height = height + 1

        self.grid: List[List[Cell]] = []
        self.visited: set[Cell] = set()
        self.frontiers: set[Cell] = set()
        self.number: set[int] = set()

        self.colors = [
            Style.RESET_ALL,
            Fore.RED,
            Fore.BLUE,
            Fore.GREEN,
            Fore.YELLOW
        ]
        self.ic: int = 0

        self.mazes = [
            self.prim_generator,
            self.binary_tree_generator
        ]
        self.index_maze = 0
        self.maze_name = [
            "Prim's Algorithm",
            "Binary Tree Algorithm"
        ]
        self.index_name: int = 0

        self.seed: Optional[int] = seed

    def maze_init(self) -> List[List[Cell]]:
        """Create the 2D grid of Cell objects and initialize the 42."""

        self.visited = set()
        self.frontiers = set()
        self.number = set()
        col = []
        for y in range(self.height):
            row = []
            for x in range(self.width):
                row.append(Cell(y, x))
            col.append(row)
        self.grid = col
        if self.height > 6 and self.width > 8:
            self.init_42()

        return self.grid

    def init_42(self) -> None:
        """Static layout definition for the '42' logo in the grid center."""

        x: int = self.width // 2
        y: int = self.height // 2

        self.grid[y][x - 1].is_42 = True
        self.grid[y + 1][x - 1].is_42 = True
        self.grid[y + 2][x - 1].is_42 = True
        self.grid[y][x - 2].is_42 = True
        self.grid[y][x - 3].is_42 = True
        self.grid[y - 1][x - 3].is_42 = True
        self.grid[y - 2][x - 3].is_42 = True
        self.grid[y][x + 1].is_42 = True
        self.grid[y + 1][x + 1].is_42 = True
        self.grid[y + 2][x + 1].is_42 = True
        self.grid[y - 2][x + 1].is_42 = True
        self.grid[y][x + 2].is_42 = True
        self.grid[y + 2][x + 2].is_42 = True
        self.grid[y - 2][x + 2].is_42 = True
        self.grid[y - 2][x + 3].is_42 = True
        self.grid[y - 1][x + 3].is_42 = True
        self.grid[y][x + 3].is_42 = True
        self.grid[y + 2][x + 3].is_42 = True

    def print_line(self, y: int) -> None:
        """Render a horizontal line of walls for a specific row.

        Args:
            y (int): The row index to print.
        """

        for x in range(self.width):
            cell: Cell = self.grid[y][x]
            if x == 0:
                print(self.colors[self.ic] + "╟", end="")
            if not cell.wall["N"]:
                if x == self.width - 1:
                    print(self.colors[self.ic] + "──╢", end="")
                else:
                    print(self.colors[self.ic] + "──┼", end="")
            else:
                if x == self.width - 1:
                    print(self.colors[self.ic] + "  ╢", end="")
                else:
                    print(self.colors[self.ic] + "  ┼", end="")

    def print_col(self, y: int) -> None:
        """Render the vertical walls and cell contents for a specific row.

        Args:
            y (int): The row index to print.
        """

        for x in range(self.width):
            cell: Cell = self.grid[y][x]
            if cell.is_42:
                print(self.colors[self.ic] + f"│{white()}", end="")
            elif x == 0:
                if cell in self.frontiers:
                    print(f"{self.colors[self.ic] + '║'}{red()}", end="")
                else:
                    print(self.colors[self.ic] + "║  ", end="")
            elif not cell.wall["W"]:
                if cell in self.frontiers:
                    print(f"{self.colors[self.ic] + '│'}{red()}", end="")
                else:
                    print(self.colors[self.ic] + "│  ", end="")
            elif cell.wall["W"]:
                print("   ", end="")
            if x == self.width - 1:
                print(self.colors[self.ic] + "║", end="")

    def print_maze(self, color_index: int) -> None:
        """Render the entire maze to the terminal with specified wall color.

        Args:
            color_i (int): Index for the desired wall color in self.colors.
        """

        for y in range(self.height):
            if y == 0:
                print(self.colors[color_index] +
                      f"╔{'══╤' * (self.width - 1)}══╗", end="")
            else:
                self.print_line(y)
            print()
            self.print_col(y)
            print()
        print(f"╚{'══╧' * (self.width - 1)}══╝" + self.colors[0])

    def add_neighbours(self, cell: Cell) -> None:
        """Find and link valid adjacent cells that are not part of the logo.

        Args:
            cell (Cell): The cell to analyze for neighbors.
        """

        y = cell.y
        x = cell.x

        if x > 0 and not self.grid[y][x - 1].is_42:
            cell.neighbours.add(self.grid[y][x - 1])

        if x < self.width - 1 and not self.grid[y][x + 1].is_42:
            cell.neighbours.add(self.grid[y][x + 1])

        if y > 0 and not self.grid[y - 1][x].is_42:
            cell.neighbours.add(self.grid[y - 1][x])

        if y < self.height - 1 and not self.grid[y + 1][x].is_42:
            cell.neighbours.add(self.grid[y + 1][x])

    def is_valid(self, cell: Cell) -> bool:
        """Validate if a cell can be included in the current generation path.

        Args:
            cell (Cell): The candidate cell to check.

        Returns:
            bool: True if the cell is within bounds, unvisited, and not logo.
        """

        if cell.y < 0 or cell.x < 0:
            return False
        if cell.x > self.width - 1 or cell.y > self.height - 1:
            return False
        if cell.is_42:
            return False
        if cell in self.visited:
            return False
        else:
            return True

    def add_frontier(self, cell: Cell) -> None:
        """Add all valid neighbors of a cell to the generation frontier set.

        Args:
            cell (Cell): The reference cell.
        """

        for n in cell.neighbours:
            if self.is_valid(n):
                self.frontiers.add(n)

    def break_frontier(self, cell: Cell) -> None:
        """Connect a frontier cell to the maze by removing a shared wall.

        Args:
            cell (Cell): The frontier cell to connect.
        """

        frontier = random.choice(sorted(self.visited & cell.neighbours,
                                        key=lambda c: (c.y, c.x)))

        if frontier.x != cell.x:
            if frontier.x > cell.x:  # if frontier = x + 1
                cell.wall["E"] = True
                frontier.wall["W"] = True

            elif frontier.x < cell.x:  # if frontier = x - 1
                cell.wall["W"] = True
                frontier.wall["E"] = True

        elif frontier.y != cell.y:
            if frontier.y > cell.y:  # if frontier = y + 1
                cell.wall["S"] = True
                frontier.wall["N"] = True

            elif frontier.y < cell.y:  # if frontier = y - 1
                cell.wall["N"] = True
                frontier.wall["S"] = True

    def prim_generator(self) -> List[List[Cell]]:
        """Generate a maze using the randomized Prim's algorithm.

        Returns:
            List[List[Cell]]: The generated maze grid.
        """
        if self.seed:
            random.seed(self.seed)

        x_start: int = random.randint(0, self.width - 1)
        y_start: int = random.randint(0, self.height - 1)

        while self.grid[y_start][x_start].is_42:
            x_start = random.randint(0, self.width - 1)
            y_start = random.randint(0, self.height - 1)

        cell = self.grid[y_start][x_start]

        cell.unvisited = False
        self.visited.add(cell)
        self.add_neighbours(cell)
        self.add_frontier(cell)

        while self.frontiers:
            cell = random.choice(sorted(self.frontiers,
                                        key=lambda c: (c.y, c.x)))
            self.frontiers.remove(cell)
            self.visited.add(cell)
            self.add_neighbours(cell)
            self.add_frontier(cell)
            self.break_frontier(cell)
            os.system("clear")
            self.print_maze(self.ic)
            time.sleep(0.005)

        return self.grid

    def binary_tree_generator(self) -> List[List[Cell]]:
        """Generate a maze using the Binary Tree algorithm logic.

        Returns:
            List[List[Cell]]: The generated maze grid.
        """
        if self.seed:
            random.seed(self.seed)
        for y in range(self.height):
            for x in range(self.width):
                cell = self.grid[y][x]
                if cell.is_42:
                    continue
                self.add_neighbours(cell)
                self.frontiers.add(cell)
                move = []
                if y > 0 and not self.grid[y - 1][x].is_42:
                    move.append("N")
                if x < self.width - 1 and not self.grid[y][x + 1].is_42:
                    move.append("E")
                if move:
                    direction = random.choice(move)
                    if direction == "N":
                        cell.wall["N"] = True
                        self.grid[y - 1][x].wall["S"] = True
                    if direction == "E":
                        cell.wall["E"] = True
                        self.grid[y][x + 1].wall["W"] = True
                os.system("clear")
                self.print_maze(self.ic)
                time.sleep(0.005)
                self.frontiers.remove(cell)
        return self.grid

    def unperfect(self, maze: List[List[Cell]]) -> List[List[Cell]]:
        """Introduce cycles by randomly removing walls across the maze.

        Args:
            maze (List[List[Cell]]): A perfect maze grid.

        Returns:
            List[List[Cell]]: The modified maze with multiple possible paths.
        """
        if self.seed:
            random.seed(self.seed)

        width = len(maze[0])
        height = len(maze)
        for row in maze:
            for c in row:
                random_num = random.randint(1, 100)
                if random_num < 30:
                    if c.is_42:
                        continue
                    if 0 < c.y < height - 1 and 0 < c.x < width - 1:
                        dir = random.choice(["S", "W", "E", "N"])
                        print(dir)
                        print(f"coord =   y:{c.y}   x:{c.x}")
                        if dir == "S" and not maze[c.y + 1][c.x].is_42:
                            c.wall["S"] = True
                            maze[c.y + 1][c.x].wall["N"] = True
                            neighbor = maze[c.y + 1][c.x]
                            c.neighbours.add(neighbor)
                            neighbor.neighbours.add(c)

                        elif dir == "N" and not maze[c.y - 1][c.x].is_42:
                            c.wall["N"] = True
                            maze[c.y - 1][c.x].wall["S"] = True
                            neighbor = maze[c.y - 1][c.x]
                            c.neighbours.add(neighbor)
                            neighbor.neighbours.add(c)

                        elif dir == "E" and not maze[c.y][c.x + 1].is_42:
                            c.wall["E"] = True
                            maze[c.y][c.x + 1].wall["W"] = True
                            neighbor = maze[c.y][c.x + 1]
                            c.neighbours.add(neighbor)
                            neighbor.neighbours.add(c)

                        elif dir == "W" and not maze[c.y][c.x - 1].is_42:
                            c.wall["W"] = True
                            maze[c.y][c.x - 1].wall["E"] = True
                            neighbor = maze[c.y][c.x - 1]
                            c.neighbours.add(neighbor)
                            neighbor.neighbours.add(c)
        return maze
