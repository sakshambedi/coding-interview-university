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
 * push_back(value) - adds an item at the end
 * pop_back() - removes end item and returns its value
 * front() - get value of front item
 * back() - get value of end item
 * insert(index, value) - insert value at index, so current item at that index
 * is pointed to by new item at index erase(index) - removes node at given index
 * value_n_from_end(n) - returns the value of the node at nth position from the
 * end of the list reverse() - reverses the list
 * remove_value(value) - removes the first item in the list with this value */

#include <iostream>

template <typename T>
class node;

template <class T>
class linked_list {
 private:
  int __linked_list_size;
  node<T> *__head;
  node<T> *__tail;

 public:
  linked_list() {
    __head = NULL;
    __tail = NULL;
    __linked_list_size = 0;
  }

  /**
   * @brief Push value at the end of the Linked List
   *
   * @param _input_T_data
   */
  void push_back(const T &_input_T_data) {
    node<T> *_temp_node = new node<T>(_input_T_data);

    if (__head == NULL) {
      __head = _temp_node;
      __tail = __head;
    } else {
      __tail->set_next_node(_temp_node);
      __tail = __tail->pointer_to_next_node();
    }
    ++__linked_list_size;
  }

  /**
   * @brief Return the size of the Linked List
   *
   * @return int
   */
  int ll_size() { return __linked_list_size; }

  /**
   * @brief Returns if the Linked List is empty or contains elements
   *
   * @return true
   * @return false
   */
  bool empty() { return __linked_list_size == 0; }

  /**
   * @brief Returns the value stored at the param index
   *
   * @param _value_at_index
   * @exception Index out of bounds
   * @return T
   */
  T value_at(const int &_value_at_index) {
    if (_value_at_index >= __linked_list_size) throw "Index out of bounds";

    node<T> *_temp_node = __head;
    for (int i = 0; i < _value_at_index; i++)
      _temp_node = _temp_node->pointer_to_next_node();

    return _temp_node->get_data();
  }

  /**
   * @brief Push the value to the front of the linked list
   *
   * @param _push_front_value
   */
  void push_front(const T &_push_front_value) {
    if (__head == NULL) {
      __head = new node<T>(_push_front_value);
    } else {
      node<T> *_temp_node = __head;
      __head = new node<T>(_push_front_value);
      __head->set_next_node(_temp_node);
    }
    ++__linked_list_size;
  }

  /**
   * @brief Remove the node from the front of the linked list
   *
   * @throws Size of the list is 0
   */
  void pop_front() {
    if (__linked_list_size == 0)
      throw "Linked List of size 0. Can not remove any elements";

    node<T> *_temp_node = __head->pointer_to_next_node();
    __head = _temp_node;
  }

  /**
   * @brief Return the data at the front of the linked list
   *
   * @throws Exception if size of the linked list is 0
   * @return T
   */
  T front() {
    return __linked_list_size == 0 ? throw "Linked list of size 0 Exception."
                                   : __head->get_data();
  }

  /**
   * @brief Returns the data at the end of the end of the linked list
   *
   * @throws Exception if size of the linked list is 0
   * @return T
   */
  T back() {
    return __linked_list_size == 0 ? throw "Linked list of size 0 Exception."
                                   : __tail->get_data();
  }

  /**
   * @brief Insert the T data at the index
   *
   * @param _index index of insert {0, size of the linked list}
   * @param _input_T_data T type data to be added in the linked list
   *
   * @throws Index out of range Exception
   */
  void insert(const int &_index, const T _input_T_data) {
    if (_index > __linked_list_size || _index < 0)
      throw "Index out of range for the linked list.";

    node<T> *_temp_node = __head;
    node<T> *_insert_node = new node<T>(_input_T_data);

    if (_index == __linked_list_size) {
      __tail->set_next_node(_insert_node);
      __tail = __tail->pointer_to_next_node();
    } else if (_index == 0) {
      __head = _insert_node;
      __head->set_next_node(_temp_node);

    } else {
      for (int i = 0; i < _index - 1; i++) {
        _temp_node = _temp_node->pointer_to_next_node();
      }
      _insert_node->set_next_node(_temp_node->pointer_to_next_node());
      _temp_node->set_next_node(_insert_node);
    }
    ++__linked_list_size;
  }

  /**
   * @brief Print the linked list
   *
   */
  void print() {
    node<T> *_temp_node = __head;

    std::cout << "head -> ";
    while (_temp_node != NULL) {
      _temp_node->pointer_to_next_node() != NULL
          ? std::cout << _temp_node->get_data() << " -> "
          : std::cout << _temp_node->get_data() << " -> NULL " << std::endl;
      _temp_node = _temp_node->pointer_to_next_node();
    }
  }
};

template <class T>
class node {
 private:
  T __node_data;
  node *__next_node;

 public:
  node(const T &_input_data) {
    __node_data = _input_data;
    __next_node = NULL;
  }

  /**
   * @brief Set the next node<T> object
   *
   * @param _next_node_pointer
   */
  void set_next_node(node *_next_node_pointer) {
    __next_node = _next_node_pointer;
  }

  /**
   * @brief Returns the pointer to the next node<T>
   *
   * @return node*
   */
  node *pointer_to_next_node() { return __next_node; }

  /**
   * @brief Get the data stored in node<T> object
   *
   * @return T
   */
  T get_data() { return __node_data; }
};

int main() {
  linked_list<int> ll;
  ll.push_back(1);
  ll.push_back(2);
  ll.push_back(3);
  ll.push_back(4);

  ll.push_front(10);
  ll.push_front(20);
  ll.push_front(30);
  ll.push_front(40);
  ll.print();

  ll.pop_front();
  ll.pop_front();

  ll.print();

  // std::cout << ll.value_at(0) << std::endl;
  // std::cout << ll.value_at(1) << std::endl;
  // std::cout << ll.value_at(2) << std::endl;
  // std::cout << ll.value_at(3) << std::endl;

  try {
    // std::cout << ll.value_at(10) << std::endl;
    std::cout << "Element at the front : " << ll.front() << std::endl;
    std::cout << "Element at the back : " << ll.back() << std::endl;
    ll.insert(2, 100);
    ll.insert(0, 200);

    ll.print();

  } catch (const char *msg) {
    std::cout << msg << std::endl;
  }

  return 1;
}