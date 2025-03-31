/**
 * @author Ethan Okamura
 * @file disjoint_set.cpp
 * @brief implimenting member functions for my disjoint set
 */

#include "DisjointSet.h"

Logger logger(false);

/**
 * @brief Handles test failures by throwing an exception.
 * @param message The error message.
 * @note [[noreturn]] ensures function never returns.
 */
[[noreturn]] void handleFailure(const std::string& message) {
  logger.error(std::cerr, "Disjoint Set");
  throw std::invalid_argument(message);
}

/**
 * @brief Handles test failures by throwing an exception.
 * @param message The error message.
 * @note [[noreturn]] ensures function never returns.
 */
[[noreturn]] void handleDomainFailure(const std::string& message) {
  logger.error(std::cerr, "Disjoint Set");
  throw std::domain_error(message);
}

/// @brief Default constructor
DisjointSet::DisjointSet() : p(nullptr), r(nullptr), n(0){};

/// @brief Builds a DisjointSet of size n
/// @pre n >= 3
DisjointSet::DisjointSet(int n) {}

/// @brief Default destructor
/// @note Must free heap allocated memory
DisjointSet::~DisjointSet() {}

/// @brief union by rank
///        - unites set that includes x and y by rank
///        - determined representative element
///        - combine by rank to try to avoid worst-case
/// @pre (x, y) < number of elements
/// @param x The first element
/// @param x The second element
void DisjointSet::union_by_rank(int x, int y) {}

/// @brief Links two components together
/// @param x the first representative
/// @param y the second representative
void DisjointSet::link(int x, int y) {}

/// @brief find representative using path compression
///        - flatten structure
///        - fix parents at the same time
///        - do not change rank
/// @param x The value to find
/// @pre x < number of elements
/// @return representative of value
int DisjointSet::find(int x) {}

/// @brief Public getter for the size of the DisjointSet
/// @return The size
int DisjointSet::size() const {}

/// @brief Public getter for the number of sets inside the DisjointSet
/// @return The count
int DisjointSet::get_num_sets() const {}

/// @brief Checks if two elements are part of the same component
/// @param x The first element
/// @param y The second element
/// @return True if they are connected
bool DisjointSet::same_component(int x, int y) {}
