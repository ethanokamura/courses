#ifndef MAZE_GENERATION_H
#define MAZE_GENERATION_H

/**
 * @file maze_generation.h
 * @brief declaring the member functions and variables for the maze generator
 * class
 */

#include <iostream>
#include <random>

#include "DisjointSet.h"

class MazeGenerator {
 public:
  MazeGenerator(int);
  void output_maze(std::ostream&);
  void generate();

 private:
  int n;
  std::vector<std::vector<int>> cells;
  void remove_walls(int, int, int, int);
  constexpr bool in_bounds(int, int) const;
  constexpr char convert(int) const;
};

#endif  // MAZE_GENERATION_H
