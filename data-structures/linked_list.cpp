/**
 * @file linkedList.cpp
 * @author Saksham Bedi (@sakshambedi)
 * @brief
 * @version 0.1
 * @date 2021-06-15
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "./linked_list.h"

#include <math.h>

#include <iostream>
using namespace saksy_datastructure;

template <typename T>
class node;

namespace saksy_datastructure {

template <typename T>
linkedList<T>::linkedList()
    : __head(NULL), __tail(NULL), __linked_list_size(0){};

template <typename T>
node<T> *linkedList<T>::get_head() {
  if (__linked_list_size == 0) return NULL;
  return __head;
}

/**
 * @brief Push value at the end of the Linked List
 *
 * @param _input_T_data
 */
template <typename T>
void linkedList<T>::push_back(const T &_input_T_data) {
  node<T> *_temp_node = new node<T>(_input_T_data);

  if (__head == NULL) {
    __head = _temp_node;
    __tail = __head;
  } else {
    __tail->set_next_node(_temp_node);
    __tail = __tail->next_node_pntr();
  }
  ++__linked_list_size;
}

/**
 * @brief Return the size of the Linked List
 *
 * @return int
 */
template <typename T>
int linkedList<T>::ll_size() const {
  return __linked_list_size;
}

/**
 * @brief Returns if the Linked List is empty or contains elements
 *
 * @return true
 * @return false
 */
template <typename T>
bool linkedList<T>::empty() {
  return __linked_list_size == 0;
}

/**
 * @brief Returns the value stored at the param index
 *
 * @param _value_at_index
 * @exception Index out of bounds
 * @return T
 */
template <typename T>
T linkedList<T>::value_at(const int &_value_at_index) {
  if (_value_at_index >= __linked_list_size)
    throw std::invalid_argument(
        "Index out of bounds for value at the parameter! No value exist at "
        "that index.");

  node<T> *_temp_node = __head;
  for (int i = 0; i < _value_at_index; i++)
    _temp_node = _temp_node->next_node_pntr();

  return _temp_node->get_data();
}

/**
 * @brief Push the value to the front of the linked list
 *
 * @param _push_front_value
 */
template <typename T>
void linkedList<T>::push_front(const T &_push_front_value) {
  if (empty()) {
    __head = new node<T>(_push_front_value);
    __tail = __head;
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
template <typename T>
node<T> *linkedList<T>::pop_front() {
  if (__linked_list_size == 0)
    throw std::length_error(
        "Linked List of size 0. Can not remove any elements");

  node<T> *_node_for_return = __head;
  __linked_list_size == 1 ? __head = NULL : __head = __head->next_node_pntr();
  --__linked_list_size;
  return _node_for_return;
}

/**
 * @brief
 *
 * @tparam T
 * @return node<T>*
 */
template <typename T>
node<T> *linkedList<T>::pop_back() {
  if (__linked_list_size == 0)
    throw std::length_error(
        "Linked List of size 0. Can not remove any elements");

  node<T> *_node_for_return;
  if (__linked_list_size == 1) {
    _node_for_return = __head;
    __head = NULL;
  }

  else {
    node<T> *_temp_node = __head;
    while (_temp_node->next_node_pntr()->next_node_pntr() != NULL) {
      _temp_node = _temp_node->next_node_pntr();
    }

    _node_for_return = _temp_node->next_node_pntr();
    __tail = _temp_node;
    _temp_node->set_next_node(NULL);
  }
  // finally decrement the size of the linked list
  --__linked_list_size;

  return _node_for_return;
}

/**
 * @brief Return the data at the front of the linked list
 *
 * @throws Exception if size of the linked list is 0
 * @return T
 */
template <typename T>
T linkedList<T>::front() {
  return __linked_list_size == 0
             ? throw std::length_error(
                   "Linked list of size 0 Exception! No front value exists.")
             : __head->get_data();
}

/**
 * @brief Returns the data at the end of the end of the linked list
 *
 * @throws Exception if size of the linked list is 0
 * @return T
 */
template <typename T>
T linkedList<T>::back() {
  return __linked_list_size == 0
             ? throw std::length_error(
                   "Linked list of size 0 Exception! No back value exists.")
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
template <typename T>
void linkedList<T>::insert(const int &_index, const T _input_T_data) {
  if (_index > __linked_list_size || _index < 0)
    throw std::invalid_argument(
        "Input value for index out of range for the linked list.");

  node<T> *_temp_node = __head;
  node<T> *_insert_node = new node<T>(_input_T_data);

  if (_index == __linked_list_size) {
    __tail->set_next_node(_insert_node);
    __tail = __tail->next_node_pntr();
  } else if (_index == 0) {
    __head = _insert_node;
    __head->set_next_node(_temp_node);

  } else {
    for (int i = 0; i < _index - 1; i++) {
      _temp_node = _temp_node->next_node_pntr();
    }
    _insert_node->set_next_node(_temp_node->next_node_pntr());
    _temp_node->set_next_node(_insert_node);
  }
  ++__linked_list_size;
}

/**
 * @brief Returns the Nth value stored in the linked list from the back.
 *        Value of N {1 - size of the linked list}
 *
 *
 * @throws Value of the Nth term is illegal
 *
 * @param _value_from_n_index Nth value from the end of the list from where n
 * > 0
 * @return T
 */
template <typename T>
T linkedList<T>::value_n_from_end(const int &_value_from_n_index) {
  if (_value_from_n_index > __linked_list_size)
    throw std::invalid_argument(
        "Value of Nth term from the back does not exist!");

  int _index = __linked_list_size - _value_from_n_index, _curr_index = 1;
  node<T> *_temp_node;
  for (_temp_node = __head; _curr_index <= _index; _curr_index++) {
    _temp_node = _temp_node->next_node_pntr();
  }
  return _temp_node->get_data();
}

/**
 * @brief Remove a value from the linked list
 *
 * @param _remove_this_value
 * @throws std::length_error
 * @return bool
 */
template <typename T>
bool linkedList<T>::remove_value(const T &_remove_this_value) {
  if (__linked_list_size == 0)
    throw std::length_error(
        "Linked List of size 0. Can not remove any elements");

  if (__head->get_data() == _remove_this_value) {
    pop_front();
    return true;
  } else if (__tail->get_data() == _remove_this_value) {
    pop_back();
    return true;
  } else {
    for (node<T> *_temp_node = __head;
         _temp_node->next_node_pntr()->next_node_pntr() != NULL;
         _temp_node = _temp_node->next_node_pntr()) {
      if (_temp_node->next_node_pntr()->get_data() == _remove_this_value) {
        _temp_node->set_next_node(
            _temp_node->next_node_pntr()->next_node_pntr());
        return true;
      }
    }
  }
  return false;
}

/**
 * @brief Reverse the linked list
 *
 * @throw std::length_error
 * @return void
 */
template <typename T>
void linkedList<T>::reverse_linked_list() {
  if (__linked_list_size == 0)
    throw std::length_error(
        "Linked list of size 0! Reverse can not be performed!");

  node<T> *__new_head = NULL, *__transverse_node = NULL;
  __new_head = pop_back();
  __transverse_node = __new_head;

  for (; __head != NULL;) {
    __transverse_node->set_next_node(pop_back());
    __transverse_node = __transverse_node->next_node_pntr();
  }

  __head = __new_head;
  __tail = __transverse_node;
}

/**
 * @brief Print the linked list
 *
 */
template <typename T>
void linkedList<T>::print() {
  node<T> *_temp_node = __head;

  std::cout << "head";
  while (_temp_node != NULL) {
    std::cout << " -> " << _temp_node->get_data();
    _temp_node = _temp_node->next_node_pntr();
  }
  std::cout << " -> NULL" << std::endl;
}  // namespace saksy_datastructure

template <typename T>
Node<T>::Node(const T &_input_data) {
  __node_data = _input_data;
  __next_node = NULL;
}

/**
 * @brief Set the next node<T> object
 *
 * @param _next_node_pointer
 */
template <typename T>
void node<T>::set_next_node(node *_next_node_pointer) {
  __next_node = _next_node_pointer;
}

/**
 * @brief Returns the pointer to the next node<T>
 *
 * @return node*
 */
template <typename T>

Node<T>::node *Node<T>::next_node_pntr() {
  return __next_node;
}

/**
 * @brief Get the data stored in node<T> object
 *
 * @return T
 */
template <typename T>
T Node<T>::get_data() {
  return __node_data;
};
/**
 * @brief Two sum algorithm implementation for the linked list
 *
 * @tparam T
 * @param first_list first input linked list
 * @param second_list second input linked list
 * @throw length_error if size of both lists do not match
 * @return linked_list<T>
 */
template <typename T>
linked_list<T>::sumTwo(linked_list<T> &first_list,
                       linked_list<T> &second_list) {
  // checking for an edge case of the size of the linked lists is same
  if (first_list.ll_size() != second_list.ll_size())
    throw new std::length_error("error");

  linked_list<T> result;
  int count = 0, num_one = 0, num_two = 0;
  node<T> *temp_one = first_list.get_head(), *temp_two = second_list.get_head();

  // complex looking for loop but its just is iterating over the linked
  // list using for loop and calculate the number stored in each list.
  // I am checking for temp_one == NULL and temp_two ==NUll just to avoid an
  // edge or silly case
  for (; temp_one != NULL || temp_two != NULL;
       temp_one = temp_one->next_node_pntr(),
       temp_two = temp_two->next_node_pntr()) {
    num_one += std::pow(10, count) * temp_one->get_data();
    num_two += std::pow(10, count) * temp_two->get_data();
    ++count;
  }

  // adding numbers to get the result sum
  int final_num = num_one + num_two;
  std::cout << "num_one is : " << num_one << " & num_two is : " << num_two
            << "  so : " << num_one << " + " << num_two << " = " << final_num
            << "\n";

  // very simple logic here is rmnder is the number store when
  // final_num is divided with 10. By doing so i get digit at the ones place.
  // I divide the final_sum with 10 until final sum==0
  int rmndr = 0;
  while (final_num != 0) {
    rmndr = final_num % 10;
    final_num /= 10;
    result.push_front(rmndr);
  }
  return result;
}

int main() {
  saksy_datastructure::linkedList<int> first_list;
  saksy_datastructure::linkedList<int> second_list;

  first_list.push_back(7);
  first_list.push_back(1);
  first_list.push_back(6);
  first_list.print();

  second_list.push_back(5);
  second_list.push_back(9);
  second_list.push_back(2);
  second_list.print();

  saksy_datastructure::linkedList<int> temp;
  temp = sumTwo(first_list, second_list);

  temp.print();
  return 0;
}