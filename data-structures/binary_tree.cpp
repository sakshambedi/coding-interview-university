#include <iostream>

template <typename T>
class node;

template <class T>
class binary_tree {
 private:
  node<T> *__root;
  int __tree_size;

 public:
  binary_tree() : __root(NULL), __tree_size(0) {}

  void Insert(const T &_input_T_data) {
    this->insert(this->__root, _input_T_data);
  }

  /**
   * @brief
   *
   * @param _input_T_value
   * @return void*
   */
  void insert(node<T> *_node, const T &_input_T_value) {
    if (_node == NULL) _node = new node<T>(_input_T_value);
    (_input_T_value < _node->get_data())
        ? insert(_node->left_node_pntr(), _input_T_value)
        : insert(_node->right_node_pntr(), _input_T_value);
    return;
  }

  void print_post_order() {
    if (__root = NULL) return;

    node<T> *_temp_node = __root;
    // print_post_order(_temp_node->left_node_pntr());

    // print_post_order(_temp_node->right_node_pntr());
    std::cout << _temp_node->get_data() << " ";
  }

  ~binary_tree() { delete __root; }
};

template <typename T>
class node {
 private:
  T __node_data;
  node *__left_node;
  node *__right_node;

 public:
  node(const T &_input_data) {
    __node_data = _input_data;
    __right_node = NULL;
    __left_node = NULL;
  }

  /**
   * @brief Set the next node<T> object
   *
   * @param _next_node_pointer
   */
  void set_right_node(node *_next_pointer) { __right_node = _next_pointer; }

  /**
   * @brief Set the next node<T> object
   *
   * @param _next_node_pointer
   */
  void set_left_node(node *_next_pointer) { __left_node = _next_pointer; }

  /**
   * @brief Returns the pointer to the next node<T>
   *
   * @return node*
   */
  node *right_node_pntr() { return __right_node; }
  node *left_node_pntr() { return __right_node; }

  /**
   * @brief Get the data stored in node<T> object
   *
   * @return T
   */
  T get_data() { return __node_data; }
};

int main(void) {
  binary_tree<int> bt;
  bt.Insert(20);
  bt.Insert(10);
  bt.Insert(15);
  bt.Insert(16);
  bt.Insert(14);
  bt.Insert(30);
  bt.Insert(25);
  bt.Insert(40);
  bt.Insert(50);
  bt.Insert(9);
  bt.Insert(8);
  bt.Insert(7);
  bt.Insert(6);
  bt.Insert(5);
  // bt.print_post_order();
  return 1;
}