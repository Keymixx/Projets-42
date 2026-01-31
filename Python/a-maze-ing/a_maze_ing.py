import random


class Cell:
    def __init__(self, y: int, x: int):
        self.wall = {
            "N": False,
            "E": False,
            "S": False,
            "W": False
        }
        self.is_42 = False

        self.y = y
        self.x = x

        self.neighbours = set()
        self.unvisited = True


class MazePrimGenerator:
    def __init__(self, lenght: int, height: int):
        self.lenght = lenght + 1
        self.height = height + 1

        self.grid = list[list[Cell]]
        self.visited = set()
        self.frontiers = set()

    def maze_init(self) -> None:
        col = []
        for y in range(self.height):
            row = []
            for x in range(self.lenght):
                row.append(Cell(y, x))
            col.append(row)
        self.grid = col
        self.init_42()

    def init_42(self) -> None:
        x: int = self.lenght // 2
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
        for x in range(self.lenght):
            cell: Cell = self.grid[y][x]
            if x == 0:
                print("+", end="")
            if not cell.wall["N"]:
                print("--+", end="")
            else:
                print("  +", end="")

    def print_col(self, y: int) -> None:
        for x in range(self.lenght):
            cell: Cell = self.grid[y][x]
            if x == 0:
                print("|  ", end="")
            elif not cell.wall["W"]:
                print("|  ", end="")
            elif cell.wall["W"]:
                print("   ", end="")
            if x == self.lenght - 1:
                print("|", end="")

    def print_maze(self) -> None:
        for y in range(self.height):
            if y == 0:
                print(f"+{'--+' * self.lenght}", end="")
            else:
                self.print_line(y)
            print()
            self.print_col(y)
            print()
        print(f"+{'--+' * self.lenght}")

    def add_neighbours(self, cell: Cell):
        y = cell.y
        x = cell.x

        if x > 0 and not self.grid[y][x - 1].is_42:
            cell.neighbours.add(self.grid[y][x - 1])
        if x < self.lenght - 1 and not self.grid[y][x + 1].is_42:
            cell.neighbours.add(self.grid[y][x + 1])
        if y > 0 and not self.grid[y - 1][x].is_42:
            cell.neighbours.add(self.grid[y - 1][x])
        if y < self.height - 1 and not self.grid[y + 1][x].is_42:
            cell.neighbours.add(self.grid[y + 1][x])

    def is_valid_frontier(self, cell: Cell):
        if cell.unvisited and not cell.is_42:
            return True
        else:
            return False

    def add_frontiers(self, cell: Cell):
        y = cell.y
        x = cell.x

        if x > 0 and self.is_valid_frontier(self.grid[y][x - 1]):
            self.frontiers.add(self.grid[y][x - 1])

        if x < self.lenght - 1 and self.is_valid_frontier(self.grid[y][x + 1]):
            self.frontiers.add(self.grid[y][x + 1])

        if y > 0 and self.is_valid_frontier(self.grid[y - 1][x]):
            self.frontiers.add(self.grid[y - 1][x])

        if y < self.height - 1 and self.is_valid_frontier(self.grid[y + 1][x]):
            self.frontiers.add(self.grid[y + 1][x])

    def break_frontier(self, cell: Cell):
        frontier = random.choice(list(self.visited & cell.neighbours))
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

    def prim_generator(self):
        x_start: int = random.randint(0, self.lenght - 1)
        y_start: int = random.randint(0, self.height - 1)

        cell = self.grid[y_start][x_start]
        print(f"y = {y_start}   x = {x_start}")
        cell.unvisited = False
        self.visited.add(cell)
        self.add_neighbours(cell)
        self.add_frontiers(cell)

        while self.frontiers:
            cell: Cell = random.choice(list(self.frontiers))
            self.frontiers.remove(cell)
            cell.unvisited = False
            self.visited.add(cell)
            self.add_neighbours(cell)
            self.add_frontiers(cell)
            self.break_frontier(cell)
