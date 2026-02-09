# A-Maze-ing

*This project has been created as part of the 42 curriculum by psok-on and caaubert.*

## Description
This project is a random maze generator and solver based on Prim's and Binary Tree algorithms. It includes a solving engine using the Breadth-First Search (BFS) algorithm and a specific hexadecimal export system. The goal of this project is to handle complex data structures while ensuring code robustness through strict type hinting (Mypy strict).

## Instructions

### Installation and Cleanup
- Install dependencies: make install
- Clean project: make clean

### Execution and Debugging
- Run program: make run
- Debug mode: make debug

### Code Quality (Linting)
- Standard lint: make lint
- Strict lint: make lint-strict

### Standalone Module Creation
To build the reusable package as required by Chapter VI, run:
python3 -m build

## Resources
- Algorithms: Documentation on Minimum Spanning Trees and Prim's algorithm.
- Documentation: PEP 484 (Type Hints) and PEP 257 (Docstrings).
- AI Usage: Solved complex type issues for mypy strict mode, guided the setup of pyproject.toml, and helped refactor logic to meet Flake8 coding standards.

---

## Project Details

- Configuration File: One KEY=VALUE pair per line. Supports WIDTH, HEIGHT, ENTRY, EXIT, OUTPUT_FILE, and PERFECT.
- Algorithms: Prim's Algorithm was chosen for its ability to create natural, "perfect" mazes without the diagonal bias found in simpler algorithms like Binary Tree.
- Team Roles: 
    * psok-on: Config parsing, build system, and strict type implementation.
    * caaubert: Generation algorithms, seed management, and hexadecimal export logic.
- Project Management:
    * Roles: Distributed between algorithm logic and system architecture.
    * Evolution: Transitioned from a functional prototype to a fully typed and packaged module.
    * Tools: Git, Flake8, Mypy, and Colorama.
- Reusability: The core logic is isolated in the 'mazegen' package. After installation, it can be used via: from mazegen.maze_generator import MazeGenerator.


# MazeGen Module Documentation

## Installation
```bash
pip install mazegen-1.0.0-py3-none-any.whl
```

## Basic Usage
```python
from mazegen import MazeGenerator

# Instantiate generator
gen = MazeGenerator(width=20, height=15, seed=42)
gen.maze_init()

# Generate maze
maze = gen.prim_generator()

# Access structure
cell = maze[0][0]
print(cell.wall)  # {'N': bool, 'E': bool, 'S': bool, 'W': bool}
print(cell.neighbours)  # Set of accessible neighbor cells

# Get solution
solver = Solver()
path = solver.solving(maze, maze[0][0], maze[14][19])
print(path)  # "EESSWW..." (N/E/S/W directions)
```

## Parameters
- `width` (int): Maze width (1-65)
- `height` (int): Maze height (1-25)  
- `seed` (int, optional): Random seed for reproducibility