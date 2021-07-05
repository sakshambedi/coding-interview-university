#include <iostream>

template <class T>
class sorting {
 public:
  void insertion_sort(const T array[]) const;

 private:
  void __insertion_sort(const T* __input_array[], const int& __size) const;
};

template <typename T>
void sorting<T>::insertion_sort(const T array[]) const {
  this->__insertion_sort(array, std::ssize(array));
}

template <typename T>
void sorting<T>::__insertion_sort(const T* __input_array[],
                                  const int& __size) const {
  std::cout << __size << std::endl;
}

int main(void) {
  int Foo[] = {10, 3, 4, 6, 1, 7, 9, 4, 12};
  sorting<int> sort;
  sort.insertion_sort(Foo);
  return 1;
}