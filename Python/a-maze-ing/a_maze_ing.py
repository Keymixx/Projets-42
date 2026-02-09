from mazegen import MazeGenerator
from solver import Solver
from output_maze import output_maze
from config_parse import config
import os
import sys


def print_instructions(map: MazeGenerator) -> None:
    """Display the interactive menu and current algorithm status.

    Args:
        map (MazeGenerator): The current maze generator instance to
            access the algorithm name and color settings.
    """

    if map.width - 1 < 8 or map.height - 1 < 6:
        print("Labyrinth too small for display 42")
    print(f"\n=== {map.maze_name[map.index_name]} ===")
    print("\n=== A-Maze-ing ===")
    print("1. Re-generate a new maze")
    print("2. Show/Hide path from entry to exit")
    print("3. Rotate maze colors")
    print("4. Switch maze algo")
    print("5. Quit")


def main() -> None:
    """Execute the main program loop for the maze generator and solver.

    This function handles the configuration loading, initializes the maze
    objects, and manages the interactive user input for re-generation,
    solving, and visualization.

    Raises:
        ValueError: If arguments are invalid, config file is missing,
            or user input is out of range.
    """
    try:

        if len(sys.argv) != 2:
            raise ValueError("Number of arguments must be equal at 2!")
        if not sys.argv[1] == "config.txt":
            raise ValueError(f"{sys.argv[1]}, Not equal at config.txt!")
        maze_infos = config(sys.argv[1])
        if not maze_infos:
            raise ValueError("Missing maze_infos!")

        width = maze_infos["WIDTH"]
        height = maze_infos["HEIGHT"]
        entry_y, entry_x = maze_infos["ENTRY"]
        exit_y, exit_x = maze_infos["EXIT"]
        maze_txt = maze_infos["OUTPUT_FILE"]
        is_perfect = maze_infos["PERFECT"]
        if "SEED" in maze_infos:
            seed = maze_infos["SEED"]
        else:
            seed = None

        map = MazeGenerator(width, height, seed)
        init_map = map.maze_init()
        if init_map[entry_y][entry_x].is_42:
            raise ValueError("Entry is a 42 cell")
        if init_map[exit_y][exit_x].is_42:
            raise ValueError("Exit is a 42 cell")

        maze = map.mazes[map.index_maze]()

        if not is_perfect:
            maze = map.unperfect(maze)
        solver = Solver()

        running, show_hide_path, solving = True, False, False
        access = True

        while running:
            start = maze[entry_y][entry_x]
            exit = maze[exit_y][exit_x]
            os.system("clear")
            if not show_hide_path:
                map.print_maze(map.ic)
            else:
                solver.print_maze(solver.ic)
            if not access:
                print("The output was not generated.")
                print("File permissions are denied.")
            print_instructions(map)
            choice = input("Choice? (1-5): ")

            if choice == "1":
                map.maze_init()
                maze = map.mazes[map.index_maze]()
                if not is_perfect:
                    maze = map.unperfect(maze)
                solver.ic = map.ic
                solving = False
                show_hide_path = False

            elif choice == "2":
                if not show_hide_path:
                    if not solving:
                        path = solver.solving(maze, start, exit)
                        access = output_maze(maze_txt, maze, start, exit, path)
                        solving = True
                    show_hide_path = True
                else:
                    show_hide_path = False

            elif choice == "3":
                map.ic = (map.ic + 1) % len(map.colors)
                solver.ic = map.ic

            elif choice == "4":
                map.index_maze = (map.index_maze + 1) % len(map.mazes)
                map.index_name = (map.index_name + 1) % len(map.maze_name)
                map.maze_init()
                maze = map.mazes[map.index_maze]()
                solver.ic = map.ic
                if not is_perfect:
                    maze = map.unperfect(maze)
                solving, show_hide_path = False, False

            elif choice == "5":
                running = False

            else:
                print("Invalid choice. Please try again with: (1-5)")
                continue
    except FileNotFoundError:
        print("Error: The configuration file 'config.txt' was not found.")
    except KeyError as e:
        print(f"Error: Missing key {e} in the configuration file.")
    except ValueError as e:
        print(f"Value Error: {e}")
    except KeyboardInterrupt:
        print("\nProgram interrupted by user.")
        sys.exit(0)
    except Exception as e:
        print(f"An unexpected error occurred: {e}")


if __name__ == "__main__":
    main()
