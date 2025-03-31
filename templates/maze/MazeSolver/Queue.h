#ifndef QUEUE_H
#define QUEUE_H

/**
 * @file queue.h
 * @brief Defines and implements a generic Queue ADT
 */

#include "LinkedList.h"

/// @brief Defines a generic Queue ADT that uses a LinkedList as its core data
/// strucutre
/// @param T The generic data type
template <typename T>
class Queue {
 public:
  /// @brief Default constructor for the Queue
  Queue() : _ll{} {}

  /// @brief List constructor
  /// @param init_list The list object needed to build the Queue
  Queue(std::initializer_list<T> init_list) { _ll = init_list; }

  /// @brief Destructor used to clean up heap allocated memory
  /// @note Not necessary because the LinkedList will automatically destruct
  ~Queue() {}

  /// @brief Pushes the value to the back of the Queue
  /// @param val The value to push
  void push(T val) { _ll.push_back(val); }

  /// @brief Pops off the front value of the Queue
  void pop() { _ll.pop_front(); }

  /// @brief Retrieves the front element of the LinkedList
  /// @return The data of the LinkedList's front element
  T &front() const { return _ll.front(); }

  /// @brief Checks to see if the queue is empty
  /// @return True if empty, false otherwise
  bool empty() const { return _ll.empty(); }

  /// @brief Prints out the elements in the Queue
  /// @param out The output stream (cout, file, etc)
  /// @param q A reference to a Queue object
  /// @return The stream object containing the output.
  friend std::ostream &operator<<(std::ostream &out, const Queue &q) {
    return out << q._ll << '\n';
  }

 private:
  LinkedList<T> _ll;
};

#endif  // QUEUE_H
