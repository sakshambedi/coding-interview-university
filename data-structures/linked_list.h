/**
 * @file linkedList.cpp
 * @author Saksham Bedi (@sakshambedi)
 * @brief
 * @version 0.1
 * @date 2021-06-15
 *
 * @copyright Copyright (c) 2021
 *
 * empty() - bool returns true if empty
 * value_at(index) - returns the value of the nth item (starting at 0 for first)
 * push_front(value) - adds an item to the front of the list
 * pop_front() - remove front item and return its value
 * push_back(value) - add// std::vector<int> nums = {1, 2, 3, 1};
  // std::cout << "Test Case 1 :" << sol.constainsDuplicate(nums) << std::endl;

  // nums = {1, 2, 3, 4};
  // sol.constainsDuplicate(nums);
  // std::cout << "Test Case 1 :" << sol.constainsDuplicate(nums) << std::endl;

  // nums = {1, 1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
  // sol.constainsDuplicate(nums);
  // std::cout << "Test Case 1 :" << sol.constainsDuplicate(nums) << std::endl;

s an item at the end
 * pop_back() - removes end item and returns its value
 * front() - get value of front item
 * back() - get value of end item
 * insert(index, value) - insert value at index, so current item at that index
 * is pointed to by new item at index erase(index) - removes node at given index
 * value_n_from_end(n) - returns the value of the node at nth position from the
 * end of the list reverse() - reverses the list
 * remove_value(value) - removes the first item in the list with this value */
#include <cstddef>

namespace saksy_datastructure {
template <class T>
class Node {
 private:
  T __node_data;
  Node *__next_node;

 public:
  Node(const T &node_data);
  void set_next_node(Node *_next_node_pointer);
  Node next_node_pntr();
  T get_data();
};

template <typename T>
class linkedList {
 private:
  int __linked_list_size;
  Node<T> *__head;
  Node<T> *__tail;

 public:
  linkedList();
  Node<T> *get_head();
  void push_back(const T &_input_T_data);
  int ll_size() const;
  bool empty();
  T value_at(const int &_value_at_index);
  void push_front(const T &_push_front_value);
  Node<T> *pop_front();
  Node<T> *pop_back();
  T front();
  T back();
  void insert(const int &_index, const T _input_T_data);
  T value_n_from_end(const int &_value_from_n_index);
  bool remove_value(const T &_remove_this_value);
  void reverse_linked_list();
  void print();
};

}  // namespace saksy_datastructure