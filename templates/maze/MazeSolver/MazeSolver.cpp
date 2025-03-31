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
PathFinder::PathFinder() {};

// maze constructor
PathFinder::PathFinder(std::vector<std::vector<int>> maze, std::size_t size) {}

// default destructor
PathFinder::~PathFinder() {}

/**
 * @brief Public wrapper to find shortest path from (0,0) to (n-1,n-1)
 *
 * @return The path from the starting node to the finishing node
 */
std::vector<int> PathFinder::get_path() {}

/**
 * @brief Perform breadth first search on node x
 * @param x The starting node
 */
void PathFinder::BFS(int x) {}

/**
 * @brief find the shortest path between nodes u and v
 * @param u The start node
 * @param v The end node
 *
 * @return The path from u to v
 */
std::vector<int> PathFinder::find_path(int u, int v) {}

/**
 * @brief Find the adjacent nodes to u
 * @param v The center node
 *
 * @return A list of adjacent nodes
 */
std::vector<int> PathFinder::find_adj(int v) {}

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
bool PathFinder::is_connected(int x1, int y1, int x2, int y2) const {}

/**
 * @brief Determine if the node is inbounds
 * @param x the x coordinate of the next node
 * @param y the y coordinate of the next node
 *
 * @return A bool determining if the next node is in bounds
 */
constexpr bool PathFinder::in_bounds(const int x, const int y) {}
