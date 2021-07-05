#include <iostream>

template <class T>
class binary_tree {
 private:
  T *__bnry_array;
  int __tree_size;
  int __curr_size;

 public:
  binary_tree(const int &_input_tree_size) {
    __bnry_array = new (std::nothrow) T[_input_tree_size];
    __tree_size = _input_tree_size;
    __curr_size = 0;
  }

  void insert(const int &_input_T_value) { return; }
};

int main(void) { return 1; }