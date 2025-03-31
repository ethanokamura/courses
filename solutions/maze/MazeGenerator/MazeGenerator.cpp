/**
 * @file maze_generation.cpp
 * @brief implimenting member functions for the MazeGenerator class
 *
 * Random number gen:
 * @cite
 * https://stackoverflow.com/questions/7560114/random-number-c-in-some-range
 */

#include "MazeGenerator.h"

/// @brief Constructs and nxn maze
/// @param n The dimensions of the maze
MazeGenerator::MazeGenerator(int n) : n(n), cells(n, std::vector<int>(n, 15)) {
  // Ensure the maze is larger than 2x2 cells
  if (n < 3) throw std::domain_error("invalid size");
  // Define starting cell
  cells[0][0] = 11;
  // Define ending cell
  cells[n - 1][n - 1] = 14;
}

/// @brief Randomly generate a maze!
void MazeGenerator::generate() {
  // Create a random number engine
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(0, 3);
  // Create disjoint set
  DisjointSet ds(n * n);
  // Create an array of x and y directions
  int directions[8]{0, 0, 1, -1, 1, -1, 0, 0};
  while (ds.get_num_sets() > 1) {
    // O(n)
    for (int row = 0; row < n; row++) {
      // O(n)
      for (int col = 0; col < n; col++) {
        int new_row{}, new_col{};
        // Find random direction
        do {
          int r{dist(gen)};
          new_row = row + directions[r];
          new_col = col + directions[r + 4];
        } while (!in_bounds(new_row, new_col));  // O(4)
        // Caclulate the 2 cells (current and new)
        int cell1{col * n + row};
        int cell2{new_col * n + new_row};
        // Ensure the cells are not already in the same set
        if (!ds.same_component(cell1, cell2)) {
          // O(1)
          remove_walls(row, col, new_row, new_col);
          // O(lg(n))
          ds.union_by_rank(cell1, cell2);
        }
      }
    }
  }
}

/// @brief Remove walls between two cells using bitwise operations
/// @param row The row of the first cell
/// @param col The column of the first cell
/// @param new_row The row of the second cell
/// @param new_col The column of the second cell
void MazeGenerator::remove_walls(int row, int col, int new_row, int new_col) {
  if (col == new_col) {  // no change in y
    if (row < new_row) {
      cells[row][col] &= ~2;          // remove bottom wall from cell 1
      cells[new_row][new_col] &= ~8;  // remove top wall from cell 2
    } else {
      cells[row][col] &= ~8;          // remove top wall from cell 1
      cells[new_row][new_col] &= ~2;  // remove bottom wall from cell 2
    }
  } else {  // no change in x
    if (col < new_col) {
      cells[row][col] &= ~1;          // remove right wall from cell 1
      cells[new_row][new_col] &= ~4;  // remove left wall from cell 2
    } else {
      cells[row][col] &= ~4;          // remove left wall from cell 1
      cells[new_row][new_col] &= ~1;  // remove right wall from cell 2
    }
  }
}

/// @brief Ensure that the desired cell is within the bounds of the maze
/// @param x The x coordinate
/// @param y The y coordinate
/// @return True if the cell is in bounds or false otherwise.
constexpr bool MazeGenerator::in_bounds(int x, int y) const {
  return x < n && x >= 0 && y < n && y >= 0;
}

/// @brief Output the converted maze to stdout
/// @param out A reference to an output stream
void MazeGenerator::output_maze(std::ostream& out) {
  std::string str;
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < n; col++) {
      if (cells[row][col] > 9)
        out << convert(cells[row][col]);
      else
        out << cells[row][col];
    }
    out << '\n';
  }
}

/// @brief Convert integer value to hexidecimal
/// @param x An integer value to be converted
/// @return A character representation of a hex-value
constexpr char MazeGenerator::convert(int x) const { return (x + 87); }
