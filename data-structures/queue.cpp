/**
Queue
Queue (video)
Circular buffer/FIFO
Implement using linked-list, with tail pointer:
enqueue(value) - adds value at position at tail
dequeue() - returns value and removes least recently added element (front)
empty()

Implement using fixed-sized array:
enqueue(value) - adds item at end of available storage
dequeue() - returns value and removes least recently added element
empty()
full()
 Cost:
a bad implementation using linked list where you enqueue at head and dequeue at
tail would be O(n) because you'd need the next to last element, causing a full
traversal each dequeue enqueue: O(1) (amortized, linked list and array
[probing]) dequeue: O(1) (linked list and array) empty: O(1) (linked list and
array)
*/

#include <iostream>
template <typename T>
class node;

template <class T>
class Queue_ll {
 private:
  int __queue_size;
  node<T> *__head;
  node<T> *__tail;

 public:
  Queue_ll() {
    __head = NULL;
    __tail = NULL;
    __queue_size = 0;
  }

  /**
   * @brief Returns true if the queue is empty
   *
   * @return bool
   */
  bool empty() { return __queue_size == 0; }

  /**
   * @brief push the data to the end of the queues
   *
   * @param _input_T_value
   */
  void push(const T &_input_T_value) {
    if (empty()) {
      __head = new node<T>(_input_T_value);
      __tail = __head;
    } else {
      __tail->set_next_node(new node<T>(_input_T_value));
      __tail = __tail->next_node_pntr();
    }
    ++__queue_size;
  }

  /**
   * @brief Queue data T to the queue
   *
   * @param _input_T_value
   */
  void enqueue(const T &_input_T_value) {
    if (empty()) {
      __head = new node<T>(_input_T_value);
      __tail = __head;
    } else {
      node<T> *_temp_node = new node<T>(_input_T_value);
      _temp_node->set_next_node(__head);
      __head = _temp_node;
    }

    ++__queue_size;
    return;
  }

  /**
   * @brief
   *
   */
  void dequeue() {
    if (__queue_size == 0)
      throw std::length_error("Queue of size 0. Can not dequeue any value!");
    __queue_size == 1 ? __head = NULL : __head = __head->next_node_pntr();
    --__queue_size;
  }

  T front() {
    if (__queue_size == 0)
      throw std::length_error("Queue of size 0. Can not dequeue any value!");
    return __head->get_data(); 
  }

  /**
   * @brief Return the size of the queue
   *
   * @return int
   */
  int size() { return __queue_size; }

  /**
   * @brief return the value at the back of the list
   *
   * @return T
   */
  T back() { return __tail->get_data(); }

  /**
   * @brief Return a new deep copy of the queue
   *
   * @param _other_queue
   * @return Queue_ll<T>&
   */
  Queue_ll<T> &operator=(const Queue_ll<T> &_other_queue) noexcept {
    if (__head == &_other_queue) return *__head;
    if (empty())
      throw std::runtime_error("Can not clone an empty queue to another queue");

    node<T> *_other_head = NULL, *_other_tail = NULL;

    for (node<T> *_temp_node = __head; _temp_node != NULL;
         _temp_node = _temp_node->next_node_pntr()) {
      if (_other_head == NULL) {
        _other_head = new node<T>(_temp_node->get_data());
        _other_tail = _other_head;
      } else {
        _other_tail->set_next_node(new node<T>(_temp_node->get_data()));
        _other_tail = _other_tail->next_node_pntr();
      }
    }
    return _other_head;
  }

  /**
   * @brief Destroy the Queue_ll object
   *
   */
  ~Queue_ll() {
    if (!empty()) {
      node<T> *curr = __head, *next = __head->next_node_pntr();
      while (curr != NULL) {
        next = curr->next_node_pntr();
        delete curr;
        curr = next;
      }
      __head = __tail = NULL;
    }
  }

  /**
   * @brief Print the queue
   *
   */
  void print() {
    node<T> *_temp_node = __head;

    std::cout << "head";
    while (_temp_node != NULL) {
      std::cout << " -> " << _temp_node->get_data();
      _temp_node = _temp_node->next_node_pntr();
    }
    std::cout << " -> NULL" << std::endl;
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
  node *next_node_pntr() { return __next_node; }

  /**
   * @brief Get the data stored in node<T> object
   *
   * @return T
   */
  T get_data() { return __node_data; }
};

// int main(void) {
//   Queue_ll<int> ql;
//   ql.enqueue(1);
//   ql.print();
//   std::cout << "Value at the end : " << ql.back() << std::endl;
//   std::cout << "Queue size :" << ql.size() << std::endl;
//   ql.enqueue(2);
//   ql.print();
//   std::cout << "Value at the end : " << ql.back() << std::endl;
//   std::cout << "Queue size :" << ql.size() << std::endl;
//   ql.enqueue(3);
//   ql.print();
//   std::cout << "Value at the end : " << ql.back() << std::endl;
//   std::cout << "Queue size :" << ql.size() << std::endl;
//   ql.enqueue(4);
//   ql.print();
//   std::cout << "Value at the end : " << ql.back() << std::endl;
//   std::cout << "Queue size :" << ql.size() << std::endl;
//   ql.enqueue(5);
//   ql.print();
//   std::cout << "Value at the end : " << ql.back() << std::endl;
//   std::cout << "Queue size :" << ql.size() << std::endl;

//   // ql.dequeue();
//   // ql.print();
//   // ql.dequeue();
//   // ql.print();
//   // ql.dequeue();
//   // ql.print();
//   // ql.dequeue();
//   // ql.print();
//   // ql.dequeue();
//   // ql.print();
//   // ql.dequeue();
//   // ql.print();

//   Queue_ll<int> other_ql = ql;
//   other_ql.enqueue(10);
//   other_ql.enqueue(20);
//   other_ql.enqueue(30);
//   other_ql.enqueue(40);
//   other_ql.enqueue(50);
//   other_ql.enqueue(60);
//   // other_ql.dequeue();
//   other_ql.print();
//   ql.print();
//   return 1;
// }
