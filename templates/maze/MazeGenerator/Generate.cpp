/**
 * @file main.cpp
 * @brief Builds a valid hexidecimal maze using a disjoint set
 * @status: needs implementation
 */

#include <fstream>
#include <stdexcept>

#include "../Logger/Logger.h"
#include "MazeGenerator.h"

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
      handleClientFailure(logger, "Usage: Main <size> <output_file");
    // Get the size of the maze
    int n = std::stoi(argv[1]);
    // Open output file
    std::ofstream out(argv[2]);
    if (!out)
      handleClientFailure(logger,
                          "Cannot write to file: " + std::string(argv[2]));
    logger.info(std::cout, "validated files");
    // Init maze
    MazeGenerator maze(n);
    logger.info(std::cout, "constructed MazeGenerator");
    // Generate maze
    maze.generate();
    logger.info(std::cout, "generated maze");
    // Output the maze
    maze.output_maze(out);
    logger.info(std::cout, "output maze");

    logger.success(std::cout, "Maze Generation");
    // Exit on complete
    return EXIT_SUCCESS;
  } catch (const std::exception &e) {
    // Handle failure
    logger.error(std::cerr, "Generator (" + std::string(e.what()) + ")");
    ;
    return EXIT_FAILURE;
  }
}
