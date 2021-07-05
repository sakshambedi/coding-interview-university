/** Implement using linked-list, with tail pointer:
 * enqueue(value) - adds value at position at tail
 * dequeue() - returns value and removes least recently added element (front)
 * empty()
 * destructor
 * Implement using fixed-sized array:
 * enqueue(value) - adds item at end of available storage
 * dequeue() - returns value and removes least recently added element
 * empty()
 * full() */

#include <iostream>

/**
 * @brief Stack array based implementation
 *
 * @tparam T
 */
template <class T>
class stack_array {
 private:
  int __stack_size;
  T *__stk_array;
  int __curr_index;

 public:
  // constructor
  stack_array(const int &__array_size_user) {
    __stack_size = __array_size_user;
    __curr_index = 0;
    __stk_array = new (std::nothrow) T[__array_size_user];
    for (int i = 0; i < __array_size_user; i++) {
      __stk_array[i] = 0;
    }
  }

  /**
   * @brief Check if the stack is empty
   *
   * @return bool
   */
  bool empty() { return __curr_index == 0; }

  /**
   * @brief Check if the stack is full
   *
   * @return bool
   */
  bool full() { return __stack_size == __curr_index; }

  /**
   * @brief
   *
   * @throws std::length_error if the stack is full
   * @param _input_T_data
   */
  void enqueue(const T &_input_T_data) {
    if (__curr_index >= __stack_size)
      throw std::length_error(
          "Stack is full. Can not add more values to the stack!");
    __stk_array[__curr_index++] = _input_T_data;
    return;
  }

  /**
   * @brief Remove values from the front of the array
   *
   * @throws std::length_error if the number od elements in the stack is 0
   * @return T
   */
  T dequeue() {
    if (empty())
      throw std::length_error("Stack size 0. Can not dequeue any value!");

    T _deque_value = __stk_array[0];
    for (int i = 0; i < __curr_index; i++) {
      __stk_array[i] = __stk_array[i + 1];
    }
    __stk_array[__curr_index] = 0;
    --__curr_index;
    return _deque_value;
  }

  /**
   * @brief Destroy the stack array object
   *
   */
  ~stack_array() { delete __stk_array; }

  /**
   * @brief Print the stack as an array
   *
   */
  void print() {
    for (int i = 0; i < __stack_size; i++) {
      std::cout << "|" << __stk_array[i];
    }
    std::cout << "|" << std::endl;
    return;
  }
};

// class forwarding for linked lists based stacks
template <typename T>
class node;

/**
 * @brief Stack template class based on linked list
 *
 * @tparam T Generic type
 */
template <class T>
class stack_ll {
 private:
  node<T> *__head;
  node<T> *__tail;
  int __stack_size;

 public:
  stack_ll() {
    __head = NULL;
    __tail = NULL;
    __stack_size = 0;
  }

  /**
   * @brief Add a new data T to the stack
   *
   * @param _input_T_data
   */
  void enqueue(const T &_input_T_data) {
    if (__head == NULL) {
      __head = new node<T>(_input_T_data);
      __tail = __head;
    } else {
      node<T> *_temp_node = new node<T>(_input_T_data);
      __tail->set_next_node(_temp_node);
      __tail = __tail->next_node_pntr();
    }
    ++__stack_size;
    return;
  }

  /**
   * @brief Remove the element from the top of the stack
   *
   * @throw length_error
   */
  node<T> *dequeue() {
    if (empty()) throw std::length_error("Stack of size 0. Can not dequeue!");

    node<T> *__return_node = __head;
    __stack_size == 1 ? __head = NULL : __head = __head->next_node_pntr();
    --__stack_size;

    return __return_node;
  }

  /**
   * @brief Return if the stack is empty or not
   *
   * @return bool
   */
  bool empty() { return __stack_size == 0; }

  ~stack_ll() noexcept {
    if (__stack_size > 0) {
      node<T> *curr = __head;
      node<T> *next = __head->next_node_pntr();
      while (curr != NULL) {
        next = curr->next_node_pntr();
        delete curr;
        curr = next;
      }
      __head = __tail = NULL;
    }
  }

  /**
   * @brief Prints the stack
   *
   */
  void print() {
    node<T> *_temp_node;
    std::cout << "HEAD";
    for (_temp_node = __head; _temp_node != NULL;
         _temp_node = _temp_node->next_node_pntr()) {
      std::cout << " -> " << _temp_node->get_data();
    }
    std::cout << " " << std::endl;
  }
};

/**
 * @brief Node template class for the linked list
 *
 * @tparam T
 */
template <class T>
class node {
 private:
  node *__pntr_next_node;
  T __data;

 public:
  // constructor
  node(const T &__input_data) {
    __data = __input_data;
    __pntr_next_node = NULL;
  }
  T get_data() { return __data; }
  node *next_node_pntr() { return __pntr_next_node; }
  void set_next_node(node *_next_node) { __pntr_next_node = _next_node; }
  ~node() { delete __pntr_next_node; }
};
