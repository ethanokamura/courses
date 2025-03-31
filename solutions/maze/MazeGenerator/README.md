# Union-Find Maze Generator

## Overview
As defined in the intro, for this program, we will be generating an $n \times n$ maze consisting of cells represented by hexidecimal values.

---

## Using the Disjoint Set
To generate a valid maze, we will be using a Union-Find structure to connect $n^2$ cells (containing integer values).The cells will then be converted to hexidecimal values to help visualize and create a uniform output (each value will be represented by a single character).

---

## Methods:
To generate the mazes, the main logic will be within the `generate()` function. This being said, the generate function requires a few helper functions. These functions will remove walls and ensure that we are within the bounds of the 2D array.

---

## Generate
Generate requires a bit of randomness to help us decide which adjacent cells to inspect. From there we will determine if we should remove the walls between the cells.

---

## Running the program:
```sh
./MazeGenerator <integer_value> <output_file>
```

Example command:
```sh
./MazeGenerator 5 output.txt
```

Example `output.txt`:
```sh
# output.txt
01234
56789
abcde
f0123
45678
```