/**
 * @file main.cpp
 * @brief Builds maze and finds shortest path from start to finish
 * @status: needs implementation
 */

#include <fstream>
#include <stdexcept>
#include <vector>

#include "../Logger/Logger.h"
#include "MazeSolver.h"

/**
 * @brief Generic function to handle failures.
 * @param message The error message to display.
 * @note [[noreturn]] throws instead of returning.
 */
[[noreturn]] void handleClientFailure(Logger &logger,
                                      const std::string &message) {
  logger.error(std::cout, message);
  throw std::runtime_error(message);
}

/**
 * @brief Inserts nodes into a maze and finds the shortest path.
 * @param argc The number of arguments.
 * @param argv The array of arguments (of type char*).
 * @return EXIT_SUCCESS or EXIT_FAILURE.
 */
int main(int argc, char **argv) {
  Logger logger(true);
  std::vector<std::vector<int>> maze;
  std::string line;
  try {
    if (argc != 3)
      handleClientFailure(logger, "Usage: Main <input_file> <output_file");
    // Open input file
    std::ifstream in(argv[1]);
    if (!in)
      handleClientFailure(logger, "Cannot read file: " + std::string(argv[1]));
    // Open output file
    std::ofstream out(argv[2]);
    if (!out)
      handleClientFailure(logger,
                          "Cannot write to file: " + std::string(argv[2]));

    // Read input
    while (in >> line) {
      std::vector<int> row;
      for (char c : line) {
        if (c >= 'a' && c <= 'z') {
          row.push_back(c - 87);
        } else if (c >= 'A' && c <= 'Z') {
          row.push_back(c - 55);
        } else if (c >= '0' && c <= '9') {
          row.push_back(c - 48);
        } else {
          handleClientFailure(logger, "Invalid hex code: " + c);
        }
      }
      maze.push_back(row);
    }

    // Output the path
    if (!maze.empty()) {
      std::size_t n = maze[0].size();
      PathFinder path_finder(maze, n);
      std::vector<int> path = path_finder.get_path();
      if (path.empty()) {
        handleClientFailure(logger, "No Valid Path!");
      }
      for (int v : path) {
        int x = v / n;
        int y = v % n;
        out << "(" << x << ", " << y << ")\n";
      }
    }

    // Exit on complete
    return EXIT_SUCCESS;
  } catch (const std::exception &e) {
    // Handle failure
    logger.error(std::cerr, "Main (" + std::string(e.what()) + ")");
    ;
    return EXIT_FAILURE;
  }
}
