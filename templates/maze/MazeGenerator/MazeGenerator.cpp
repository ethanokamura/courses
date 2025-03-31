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
MazeGenerator::MazeGenerator(int n) {}

/// @brief Randomly generate a maze!
void MazeGenerator::generate() {
  // Create a random number engine
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(0, 3);
  // YOUR CODE HERE
}

/// @brief Remove walls between two cells using bitwise operations
/// @param row The row of the first cell
/// @param col The column of the first cell
/// @param new_row The row of the second cell
/// @param new_col The column of the second cell
void MazeGenerator::remove_walls(int row, int col, int new_row, int new_col) {}

/// @brief Ensure that the desired cell is within the bounds of the maze
/// @param x The x coordinate
/// @param y The y coordinate
/// @return True if the cell is in bounds or false otherwise.
constexpr bool MazeGenerator::in_bounds(int x, int y) const {}

/// @brief Output the converted maze to stdout
/// @param out A reference to an output stream
void MazeGenerator::output_maze(std::ostream& out) {}

/// @brief Convert integer value to hexidecimal
/// @param x An integer value to be converted
/// @return A character representation of a hex-value
constexpr char MazeGenerator::convert(int x) const {}
