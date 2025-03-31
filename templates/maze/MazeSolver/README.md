# Breadth First Search Maze Solver

## Overview
This program implements a **Breadth-First Search (BFS) algorithm** to find the shortest path between two points in an **n x n hexadecimal maze**. The maze is represented using **hexadecimal characters**, where each character encodes the presence of walls in a grid cell. The program reads the maze from an input file, computes the shortest path, and writes the result to an output file.

## Maze Representation
Each cell in the maze is represented by a hexadecimal digit (0-F), where the bits indicate the presence of walls:

| Bit | Value | Wall Position |
|----|----|-----------------|
| 1  | 1  | Right Wall      |
| 2  | 2  | Bottom Wall     |
| 4  | 4  | Left Wall       |
| 8  | 8  | Top Wall        |

For example:
- A cell with no walls is `0`.
- A cell with all four walls is `F` (binary `1111`).
- A cell with right and bottom walls is `3` (binary `0011`).

### Connection Rules
Two cells are **connected** if they share a missing adjacent wall. For example:
- The pair `E` (1110) and `B` (1011) have a valid connection between their **left and right walls**.
- The pair `E` (1110) and `7` (0111) **are not connected**, because there is a solid wall between them.

## Input Format
The program reads a file containing an **NxN** grid of hexadecimal characters representing the maze.

### Example Input (5x5 Maze):
```sh
01234
56789
abcde
f0123
45678
```

## Output Format
The program outputs the shortest path from the **start** to the **goal** in a file. The output format consists of coordinates `(row, col)` representing the path from the start to the goal.

### Example Output:
```sh
(0,0)
(0,1)
(1,1)
(2,1)
...
(4,4)
```

## Performance Requirement
The program must compute the shortest path in a **5000x5000 maze** and write the result in **under 17 seconds**.

## Usage
### Compilation & Execution
Ensure you have a compatible runtime environment, then execute:
```sh
python maze_solver.py input.txt output.txt
```
- `input.txt` - File containing the NxN maze
- `output.txt` - File where the shortest path will be written

### Example Run
```sh
python maze_solver.py maze_5000x5000.txt path_output.txt
```

## Algorithm
1. **Read the input file** and parse the hexadecimal maze into a **2D grid**.
2. **Determine valid connections** between adjacent cells based on missing walls.
3. **Perform BFS** to find the shortest path from the **start position** to the **goal position**.
4. **Write the shortest path** to the output file.

## Running the Program:
This program uses make. To run the code type the following commands:

```sh
make
./PathFinder
```