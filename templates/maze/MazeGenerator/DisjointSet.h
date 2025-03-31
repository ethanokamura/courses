#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H

/**
 * @file disjoint_set.h
 * @brief declaring the member functions and variables for the union find
 * structure
 */

#include <iostream>
#include <unordered_map>
#include <vector>

#include "../Logger/Logger.h"

/// @brief Delcares the DisjointSet ADT
class DisjointSet {
 public:
  // default constructor
  DisjointSet();
  // size constructor
  DisjointSet(int);
  // default destructor
  ~DisjointSet();
  // union by rank
  void union_by_rank(int, int);
  // find rep
  int find(int);
  // public getter for the size of the disjoint set
  int size() const;
  // public getter for the number of sets
  int get_num_sets() const;
  // checks if two elements are part of the same set
  bool same_component(int, int);

 private:
  int* p;  // parent
  int* r;  // rank (height of tree rep. the set)
  int n;
  int count;
  void link(int, int);
};

#endif  // DISJOINT_SET_H
