## Maze Generator/Solver
In this project, we will create two programs:  
1. **Maze Generator**  
2. **Maze Solver**  

If at any point you get stuck, check out my [full course](https://www.perfectline.io/courses/maze/) with detailed explainations and walkthroughs

---

## Project Setup  
To follow along with this course, clone this [GitHub Repository](). This repository includes all the essential template files, helpful README files, and testing scripts.  

Your directory structure should look like this:  
```sh
MazeCourse/
  ├── Data/           # Contains user data
  ├── Examples/       # Contains control data (for testing)
  ├── Logger/         # Logger object to flag important information
  ├── MazeGenerator/  # Contains the maze generation logic
  ├── MazeSolver/     # Contains the maze solving logic
  ├── README.md       # Overview of the project
  └── test_solver.sh  # Testing script to ensure valid paths
```

For this project, you will only need to write code inside the `MazeGenerator/` and `MazeSolver/` directories. The `Tests/`, `Logger/`, and `Examples/` directories are already completed and **will not** be covered in this course.  

---

## Maze Generator  
To generate the maze, we will use a data structure called a **disjoint set**. This structure is defined in `DisjointSet.h` and implemented in `DisjointSet.cpp`. It will be used in `MazeGenerator.cpp` to construct the maze.  

The disjoint set will consist of an $n \times n$ grid of cells. Each cell will initially have four walls (left, right, top, and bottom), represented by an integer. The maze generation algorithm will systematically remove walls until the entire grid forms a single connected component (meaning all cells are accessible in some way).  

`MazeGenerator.cpp` takes an integer value `n` as input and outputs a maze of $n \times n$ cells. The cells will be represented using hexadecimal values.  

Example of a **valid output** for a $5 \times 5$ maze:  
```sh
01234
56789
abcde
f0123
45678
```
This may seem confusing at first, but we will cover the details later in the course. For now, just understand that you will be building a **hexadecimal-based maze representation**.  

### Required Files:  
```sh
MazeGenerator/
  ├── DisjointSet.cpp    # Implements the DisjointSet ADT
  ├── DisjointSet.h      # Defines the DisjointSet ADT and related methods
  ├── Generate.h         # Main program logic that generates a maze
  ├── Makefile           # Compiles a single executable
  ├── MazeGenerator.cpp  # Implements the MazeGenerator using the DisjoinSet
  ├── MazeGenerator.h    # Defines the MazeGenerator using the DisjoinSet
  └── README.md          # Description of the program and given directory
```

### Testing:
To test our maze generation, it is not as straight forward as you might think. Unfortunately, the best way to test it is to complete the `Solver`. However, you can visually check your maze via [this page](https://www.perfectline.io/maze-solver/) on PerfectLine.io

Here, you can input the hex maze directly into the input. Later on, when you need to test the paths, you can input your path as well. The main thing to check for is that all cells are reachable and there exists a path from start (top left) to finish (bottom right).

One important note is that the mazes are much harder to follow and visualize as they grow in size. I recommend staying with a 10x10 maze.

---

## Maze Solver  
In `MazeSolver.cpp`, you will implement the **Breadth-First Search (BFS)** algorithm to find the shortest path from the maze's starting position $(0,\;0)$ to the end position $(n-1,\;n-1)$.  

`MazeSolver` includes several important helper functions that will be covered later in the course. These include:  
- **Adjacency lists** for tracking valid movements.  
- The **pathfinding function**, which finds the shortest route.  
- A **validity checker** to ensure that each move stays within bounds and connects to an open path.  

### Required Files:  
```sh
MazeSolver/
  ├── FindPath.cpp    # Finds an outputs the shortest path to solve the maze
  ├── LinkedList.h    # Defines and implements a singly LinkedList
  ├── Makefile        # Compiles a single executable
  ├── MazeSolver.cpp  # Implements the MazeSolver
  ├── MazeSolver.h    # Defines the MazeSolver and related methods
  ├── Queue.h         # Defines and implements a Queue ADT (using a linked list)
  └── README.md       # Description of the program and directory
```

Your program should take the output from `MazeGenerator` as input and compute the shortest path using the BFS algorithm.  

Example of a **valid output**:  
```sh
(0,0)  # start
(0,1)
(1,1)
(2,1)
...
(4,4)  # finish
```

This output represents the shortest path from the starting cell to the ending cell.  

### Testing:
To ensure that your path finder is correct, there are a series of control files inside the `Examples/` subdirectory. To test and compare the output from your `Solver` program, run the following commands in your terminal:

```sh
chmod +x test_solver.sh  # create executable
./test_solver.sh         # run script
```

The output should look something like this:
```sh
#############################
Running data/Examples/Mazes/10.txt
Comparing output of Data/Paths/10.txt with Examples/Paths/10.txt
✅ Test passed: Found Correct Path
#############################
Running data/Examples/Mazes/50.txt
Comparing output of Data/Paths/50.txt with Examples/Paths/50.txt
✅ Test passed: Found Correct Path
#############################
Running data/Examples/Mazes/100.txt
Comparing output of Data/Paths/100.txt with Examples/Paths/100.txt
✅ Test passed: Found Correct Path
#############################
Running data/Examples/Mazes/500.txt
Comparing output of Data/Paths/500.txt with Examples/Paths/500.txt
✅ Test passed: Found Correct Path
#############################
Running data/Examples/Mazes/1000.txt
Comparing output of Data/Paths/1000.txt with Examples/Paths/1000.txt
✅ Test passed: Found Correct Path
#############################
Running data/Examples/Mazes/5000.txt
Comparing output of Data/Paths/5000.txt with Examples/Paths/5000.txt
✅ Test passed: Found Correct Path
#############################
```

