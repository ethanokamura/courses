/**
 * @file pathfinder.cpp
 * @brief Implementation of PathFinder class
 * @status: needs implementation
 */

// imports
#include "MazeSolver.h"

Logger logger(false);

/**
 * @brief Handles test failures by throwing an exception.
 * @param message The error message.
 * @note [[noreturn]] ensures function never returns.
 */
[[noreturn]] void handleFailure(const std::string& message) {
  logger.error(std::cerr, "Path Finder: ");
  throw std::invalid_argument(message);
}

// default constructor
PathFinder::PathFinder() : n(0), p(nullptr), d(nullptr), color(nullptr){};

// maze constructor
PathFinder::PathFinder(std::vector<std::vector<int>> maze, std::size_t size)
    : n(size), nodes(maze) {
  p = new int[k];
  d = new int[k];
  color = new int[k];
}

// default destructor
PathFinder::~PathFinder() {
  delete[] p;
  delete[] d;
  delete[] color;
  p = d = color = nullptr;
}

/**
 * @brief Public wrapper to find shortest path from (0,0) to (n-1,n-1)
 *
 * @return The path from the starting node to the finishing node
 */
std::vector<int> PathFinder::get_path() {
  return (n > 0) ? find_path(k - 1, 0) : std::vector<int>();
}

/**
 * @brief Perform breadth first search on node x
 * @param x The starting node
 */
void PathFinder::BFS(int x) {
  // create default values
  for (int i = 0; i < k; i++) {
    p[i] = -1;     // flag value
    d[i] = -1;     // flag value
    color[i] = 0;  // undiscovered
  }

  Queue<int> q;

  // initialization of the node we will search from (root)
  color[x] = 1;
  d[x] = 0;
  p[x] = -1;
  q.push(x);

  // main section O(E)
  while (!q.empty()) {
    int u = q.front();
    std::vector<int> adj = find_adj(u);
    for (const int& v : adj) {
      if (color[v] == 0) {  // non-discovered node
        color[v] = 1;
        d[v] = d[u] + 1;
        p[v] = u;
        q.push(v);
      }
    }
    // done with it
    q.pop();
    color[u] = 2;
  }
}

/**
 * @brief find the shortest path between nodes u and v
 * @param u The start node
 * @param v The end node
 *
 * @return The path from u to v
 */
std::vector<int> PathFinder::find_path(int u, int v) {
  BFS(u);
  std::vector<int> path;
  // no path exists
  if (d[v] == -1) return path;
  // back track to find the path!
  int cur = v;
  while (cur != u) {
    path.push_back(cur);
    cur = p[cur];
  }
  path.push_back(u);
  return path;
}

/**
 * @brief Find the adjacent nodes to u
 * @param v The center node
 *
 * @return A list of adjacent nodes
 */
std::vector<int> PathFinder::find_adj(int v) {
  std::vector<int> adj;
  int y{v / n};
  int x{v % n};
  int directions[8] = {0, 0, 1, -1, 1, -1, 0, 0};
  for (std::size_t i = 0; i < 4; i++) {
    int new_x{x + directions[i]};
    int new_y{y + directions[i + 4]};
    if (in_bounds(new_x, new_y) && is_connected(x, y, new_x, new_y)) {
      adj.push_back(new_y * n + new_x);
    }
  }
  return adj;
}

/**
 * @brief Determine if two adjacent nodes have a valid connection
 * @param x1 x coordinate of u
 * @param y1 y coordinate of u
 * @param x2 x coordinate of v
 * @param y2 y coordinate of v
 *
 * @return A bool determining if the two nodes are connected
 */
// check if there is a connection
bool PathFinder::is_connected(int x1, int y1, int x2, int y2) const {
  int u{nodes[x1][y1]};
  int v{nodes[x2][y2]};

  // no change in y
  if (y1 == y2) {
    return (x1 < x2)
               // check if bottom wall in cell 1 and top wall in cell 2 connect
               ? ((u & 2) == 0 || (v & 8) == 0)
               // check top wall in cell 1 and bottom wall in cell 2 connect
               : ((u & 8) == 0 || (v & 2) == 0);

    // no change in x
  } else {
    return (y1 < y2)
               // check if right wall in cell 1 and left wall in cell 2 connect
               ? ((u & 1) == 0 || (v & 4) == 0)
               // check if left wall in cell 1 and right wall in cell 2 connect
               : ((u & 4) == 0 || (v & 1) == 0);
  }
}

/**
 * @brief Determine if the node is inbounds
 * @param x the x coordinate of the next node
 * @param y the y coordinate of the next node
 *
 * @return A bool determining if the next node is in bounds
 */
constexpr bool PathFinder::in_bounds(const int x, const int y) {
  return x < n && x >= 0 && y < n && y >= 0;
}
