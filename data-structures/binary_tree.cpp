#ifndef __binary_tree_saks
#define __binary_tree_saks

#include <iostream>
#include <memory>
#include <vector>

namespace BinaryTree {

// template <class T>
// class binary_tree_node {
//  private:
//   struct node {
//     T data;
//     std::unique_ptr<node> left;
//     std::unique_ptr<node> right;

//     node(T input_data) : data(input_data), left(nullptr), right(nullptr){};
//   };
//   size_t tree_size;
//   std::unique_ptr<BinaryTree::binary_tree_node::node> root;

//  public:
//   // binary_tree_node() : root(nullptr), tree_size(0);
// };

/**
 * @brief
 *
 * @tparam T
 */
template <class T>
class binary_tree_array {
 public:
  binary_tree_array(int user_size);
  void insert(T insert_value, size_t pos);
  void print() const;

 private:
  std::vector<T> b_tree;
  size_t btree_size;
};
}  // namespace BinaryTree

template <typename T>
BinaryTree::binary_tree_array<T>::binary_tree_array(int user_size)
    : btree_size(size_t(user_size)) {
  b_tree.resize(user_size);
}

template <typename T>
void BinaryTree::binary_tree_array<T>::insert(T insert_value, size_t pos) {
  if (pos >= btree_size)
    throw new std::length_error("Insert position invalid!\n");

  b_tree.at(pos) = insert_value;
}

template <typename T>
void BinaryTree::binary_tree_array<T>::print() const {
  for (size_t i = 0; i < btree_size; i++) std::cout << b_tree[i] << "->";
  std::cout << std::endl;
}
#endif  //

int main(void) {
  BinaryTree::binary_tree_array<int> bt(10);
  bt.insert(10, 0);
  bt.insert(9, 1);
  bt.insert(8, 2);
  bt.insert(7, 3);
  bt.insert(6, 4);
  bt.insert(5, 5);
  bt.insert(4, 6);
  bt.insert(3, 7);
  bt.insert(2, 8);
  bt.insert(1, 9);

  return 1;
}