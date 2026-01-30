def is_even(x) -> bool:
    if x % 2 == 0:
        return True
    else:
        return False


class Cell:
    def __init__(self, y: int, x: int):
        self.wall = {
            "N": True,
            "E": True,
            "S": True,
            "W": True
        }
        self.y = y
        self.x = x


class Grid:
    def __init__(self, lenght: int, height: int):
        self.lenght = lenght
        self.height = height

        self.grid = list[list[Cell]]

    def grid_generator(self) -> None:
        col = []
        for y in range(self.height):
            row = []
            for x in range(self.lenght):
                row.append(Cell(y, x))
            col.append(row)
        self.grid = col

    def print_grid(self) -> None:
        for y in range(self.height):
            for x in range(self.lenght):
                if is_even(y):
                    cell: Cell = self.grid[y][x]
                    if y == 0 and x == 0:
                        print("+", end="")
                    elif cell.wall["N"]:
                        print("--+", end="")
                    else:
                        print("   ")
                else:
                    if y == 0 and cell.wall["E"]:
                        print("|", end="")
                    elif cell.wall["E"]:
                        print("|", end="")
            print("")
                    
                    




map = Grid(5, 5)
map.grid_generator()
map.print_grid()

