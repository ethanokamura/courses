#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/**
 * @file linked_list.h
 * @brief Implements a linked list of type int
 */

#include <initializer_list>
#include <iostream>

/// @brief Defines a LinkedList ADT of generic type T
/// @param T The generic data type
template <typename T>
class LinkedList {
  // Forward declaration for our private Node object
  struct Node;

 public:
  /// @brief Default constructor for the LinkedList ADT
  LinkedList() : head(nullptr), tail(nullptr), _size(0) {}

  /// @brief List constructor
  /// @param init_list The list object needed to build the LinkedList
  LinkedList(std::initializer_list<T> init_list) {
    for (const T &val : init_list) push_back(val);
  }

  /// @brief Copy constructor
  /// @param another A reference to another LinkedList used to build
  ///        the current LinkedList
  LinkedList(const LinkedList<T> &another) {
    for (Node *current = another.head; current; current = current->next)
      push_back(current->data);
  }

  /// @brief Destructor used to clean up heap allocated memory
  ~LinkedList() {
    Node *current = head;
    while (current != nullptr) {
      Node *next = current->next;
      delete current;
      current = next;
    }
  }

  /// @brief Public getter to retrieve the head of the LinkedList
  /// @return The value of the head node
  T &front() const {
    if (head == nullptr) throw std::domain_error("empty list!");
    return head->data;
  }

  /// @brief Public getter to retrieve the size of the LinkedList
  /// @return The size of the list
  std::size_t size() const { return _size; }

  /// @brief Public getter to check if the list is empty
  /// @return True if empty, false if not
  bool empty() const { return !head; }

  /// @brief Adds a new element to the back of the list and reassigns the tail
  /// @param val The element to add
  void push_back(T val) {
    Node *new_node = new Node(val);
    if (empty()) {
      head = tail = new_node;
    } else {
      tail->next = new_node;
      tail = new_node;
    }
    _size++;
  }

  /// @brief Removes the current head from the list and reassigns it
  ///        to the next node in the sequence
  void pop_front() {
    if (empty()) throw std::domain_error("empty list!");
    Node *temp = head;
    head = head->next;
    delete temp;
    if (head == nullptr) tail = nullptr;
    _size--;
  }

  /// @brief Public method to clear the list
  /// @note The list is empty when both the head and tail are null
  void clear() {
    while (head) pop_front();
  }

  /// @brief Assignment operator to replace the values in the current
  ///         LinkedList with the values in a generic container.
  /// @param init_list The generic container of values
  /// @return A reference to the current LinkedList containing the new values
  LinkedList &operator=(std::initializer_list<T> init_list) {
    clear();
    for (const T &val : init_list) push_back(val);
    return *this;
  }

  /// @brief Assignment operator to replace the values in the current
  ///        LinkedList with the values in another list.
  /// @param another A reference to another LinkedList
  /// @return A reference to the current LinkedList containing the new values
  LinkedList &operator=(const LinkedList &another) {
    Node *current = another.head;
    clear();
    while (current) {
      push_back(current->data);
      current = current->next;
    }
    return *this;
  }

  /// @brief Checks equivalency between two LinkedLists
  /// @param another A reference to another LinkedList
  /// @return True if the lists are equal or false otherwise
  bool operator==(const LinkedList &another) {
    if (size() != another.size()) return false;
    Node *current = head;
    Node *other = another.head;
    while (current) {
      if (other->data != current->data) return false;
      current = current->next;
      other = other->next;
    }
    return true;
  }

  /// @brief Checks if two LinkedLists are different
  /// @param another A reference to another LinkedList
  /// @return True if the lists are not equal
  bool operator!=(const LinkedList &another) { return !(*this == another); }

  /// @brief Stream operator to output the list to an output stream
  /// @param out The output stream object
  /// @param list A reference to the list that needs to be output
  /// @return The output stream containing all the elements in the list
  /// @note The output should be in the form of "[1, 2, 3, 4]"
  friend std::ostream &operator<<(std::ostream &out, const LinkedList &list) {
    out << '[';
    Node *current = list.head;
    for (; current; current = current->next) {
      out << current->data;
      if (current->next) out << ", ";
    }
    out << ']';
    return out;
  }

 private:
  /// @brief Private Node object of type T
  struct Node {
    // The node's inner data
    T data;
    // A pointer to the next node in the squence
    Node *next = nullptr;
    /// @brief Constructs a new node containing a value
    /// @param value The value to copy
    /// @note The node's next pointer should remain null until assigned
    Node(T value) : data(value), next(nullptr) {}
  };
  // The head of the list (front)
  Node *head = nullptr;
  // The tail of the list (back)
  Node *tail = nullptr;
  // The size of the list
  std::size_t _size = 0;
};

#endif  // LINKED_LIST_H
