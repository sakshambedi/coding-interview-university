#include <iostream>
#include <random>

template <class T = int>
class sorting {
 public:
  template <size_t array_size>
  void insertion_sort(T (&array)[array_size]);

  template <size_t array_size>
  void selection_sort(T (&array)[array_size]);

  template <size_t array_size>
  void print(const T (&array)[array_size]);

  template <size_t array_size>
  bool __validate_sort(T (&array)[array_size]) const;

  template <size_t array_size>
  void quick_sort_lomuto(T (&array)[array_size]);

  template <size_t array_size>
  void quick_sort_hoare(T (&array)[array_size]);

 private:
  void __insertion_sort(T *array, const int size);
  void __selection_sort(T *array, const int size);
  void __quick_sort_lomuto(T *array, int low, int high);
  void __quick_sort_hoare(T *array, const int size);
  int __partition(T *array, int low, int high);
  void swap(T *i, T *j);
};
/**
 * @brief Insertion sort interface
 *
 * @tparam T Type of the array
 * @tparam array_size Size of the array`
 * @param (&array)
 *
 * @return void
 */
template <typename T>
template <size_t array_size>
void sorting<T>::insertion_sort(T (&array)[array_size]) {
  __insertion_sort(array, array_size);
}

/**
 * @brief Insertion sort algorithm
 * learn more: https://www.geeksforgeeks.org/insertion-sort/
 *
 * @tparam T
 * @param array
 * @param size
 */
template <typename T>
void sorting<T>::__insertion_sort(T *array, const int size) {
  for (int i = 1; i < size; i++) {
    T _key_value = array[i];

    int j = i - 1;
    for (; j >= 0 && array[j] > _key_value; j--) {
      array[j + 1] = array[j];
    }
    array[j + 1] = _key_value;
  }
  return;
}

/**
 * @brief selection sort interface
 *
 * @tparam T
 * @tparam array_size
 */
template <typename T>
template <size_t array_size>
void sorting<T>::selection_sort(T (&array)[array_size]) {
  __insertion_sort(array, array_size);
}

/**
 * @brief : Selection sort algorithm
 * learn more: https://www.geeksforgeeks.org/selection-sort/
 *
 * @tparam T
 * @param array
 * @param size
 */
template <typename T>
void sorting<T>::__selection_sort(T *array, const int size) {
  for (int i = 0; i < size; i++) {
    T min_value = i;

    for (int j = i + 1; j < size; j++) {
      if (array[min_value] > array[j]) swap(&array[min_value], &array[j]);
    }
  }
  return;
}

template <typename T>
template <size_t array_size>
void sorting<T>::quick_sort_lomuto(T (&array)[array_size]) {
  __quick_sort_lomuto(array, 0, (int)array_size - 1);
}

template <typename T>
void sorting<T>::__quick_sort_lomuto(T *array, int low, int high) {
  if (low < high) {
    // point of pivot
    int pivot = __partition(array, low, high);

    // Quick sort from low to left side and then right side recursively
    __quick_sort_lomuto(array, low, pivot - 1);
    __quick_sort_lomuto(array, pivot + 1, high);
  }
  return;
}

/**
 * @brief Parition the array in two parts base upon low and high indices.
 *
 * @tparam T
 * @param array
 * @param low
 * @param high
 * @return int
 */
template <typename T>
int sorting<T>::__partition(T *array, int low, int high) {
  int pivot = array[high];
  int i = low - 1;
  for (int j = low; j < high; j++) {
    if (array[j] < pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return i + 1;
}

/**
 * @brief Swap pointers to the values
 *
 * @tparam T
 * @param i
 * @param j
 */
template <typename T>
void sorting<T>::swap(T *i, T *j) {
  T *temp = i;
  i = j;
  j = temp;
}

/**
 * @brief Print the array
 *
 * @tparam T
 * @tparam array_size
 */
template <typename T>
template <size_t array_size>
void sorting<T>::print(const T (&array)[array_size]) {
  for (int i = 0; i < (int)array_size; i++) {
    std::cout << "|" << array[i];
  }
  std::cout << "|" << std::endl;
  return;
}

/**
 * @brief Validate of the array is sorted or not
 *
 * @tparam T data type
 * @tparam array_size size of the array
 * @return bool
 */
template <typename T>
template <size_t array_size>
bool sorting<T>::__validate_sort(T (&array)[array_size]) const {
  int min_value = array[0];
  for (int i = 1; i < (int)array_size; i++) {
    if (min_value > array[i]) return false;
    min_value = array[i];
  }
  return true;
}

int main(void) {
  int Foo[100000];
  int Bar[] = {1, 20, 40, 10, 4, 6, 5, 90, 56, 23, 89, 189, 1234};
  std::random_device rd;  // obtain a random number from the hardware
  std::mt19937 gen(
      rd());  // seed the generator mt19937 : A Mersenne Twister psuedo-random
              // genrator of 32 bit numbers with state size of 19937 bits
  std::uniform_int_distribution<> distr(0, 1000000);  // defining range

  for (int i = 0; i < 100000; i++) {
    Foo[i] = distr(gen);
  }
  sorting<int> sort;
  /* std::cout << "Before Insertion Sort :" << std::endl; */
  // sort.print(Bar);
  /* sort.insertion_sort(Foo); */
  // sort.selection_sort(Bar);
  // sort.selection_sort(Foo);
  sort.quick_sort_lomuto(Bar);
  // std::cout << "After Insertion Sort : " << std::endl;
  // sort.print(Foo);

  std::cout << "Bar is sorted : " << sort.__validate_sort(Bar) << std::endl;
  // std::cout << "Foo is sorted : " << sort.__validate_sort(Foo) << std::endl;
  return 1;
}
