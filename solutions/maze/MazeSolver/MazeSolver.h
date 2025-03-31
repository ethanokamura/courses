#ifndef PATHFIND_H
#define PATHFIND_H

/**
 * @author Ethan Okamura
 * @file pathfinder.h
 * @brief declaring the member functions and variables for
 *        the path finder class
 */

#include <iostream>
#include <vector>

#include "../Logger/Logger.h"
#include "Queue.h"

class PathFinder {
 public:
  // default constructor
  PathFinder();
  // maze constructor
  PathFinder(std::vector<std::vector<int>>, std::size_t);
  // default destructor
  ~PathFinder();
  // public wrapper to find shortest path from (0,0) to (n-1,n-1)
  std::vector<int> get_path();

 private:
  int n;               // size
  const int k{n * n};  // dimensions
  int* p;              // parent of each node
  int* d;              // distance from start
  int* color;          // color of each node
  std::vector<std::vector<int>> nodes;
  // perform breath first search on node x
  void BFS(int);
  // find the shortest path between nodes u and v
  std::vector<int> find_path(int, int);
  // find the adjacent nodes of u
  std::vector<int> find_adj(int);
  // determine if two adjacent nodes have a valid connection
  bool is_connected(int, int, int, int) const;
  // determine if the node is inbounds
  constexpr bool in_bounds(const int, const int);
};

#endif  // PATHFIND_H
