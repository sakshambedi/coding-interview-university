#include <iostream>
using namespace std;

/**
 * @brief Class for the dynamically storing primitive data types
 *
 * @tparam T : can be ints, floats , longs , doubles
 */
template <class T>
class dynamic_array {
 private:
  T *__dyn_array_int;
  int __array_size;
  int __current_array_index;

 public:
  dynamic_array(const int &array_size) {
    __dyn_array_int = new (nothrow) T[array_size];
    __array_size = array_size;
    __current_array_index = 0;

    for (int i = 0; i < array_size; i++) {
      __dyn_array_int[i] = 0;
    }
  }

  ~dynamic_array() { delete[] __dyn_array_int; }
  int index() { return __current_array_index; }
  int size() { return __array_size; }

  void pushback(const T &input_data) {
    if (__current_array_index == __array_size) {
      __array_size += 10;
      T *_new_T_array = new T[__array_size];

      // copying all the new values from the __dyn_array_list to the
      // _new_T_array
      for (int i = 0; i < __current_array_index; i++)
        _new_T_array[i] = __dyn_array_int[i];

      // set the value next the the last value
      _new_T_array[__current_array_index] = input_data;

      // setting all the of the other values to 0
      for (int j = __current_array_index + 1; j < __array_size; j++)
        _new_T_array[j] = 0;

      // delete the old array and then set the pointer of the old array to the
      // new array(_new_T_array)
      delete[] __dyn_array_int;
      __dyn_array_int = _new_T_array;

    } else {
      // let the value of of the input_data at the current index and then
      // increment __current_array_index
      __dyn_array_int[__current_array_index] = input_data;
      ++__current_array_index;
    }
  }

  /**
   * @brief Push data to the front of the linked list
   * 
   * @param input_data 
   */
  void pushfront(const T &input_data) {
    if (__current_array_index == __array_size) {
      __array_size += 10;
      T *_new_T_array = new T[__array_size];

      _new_T_array[0] = input_data;

      for (int i = 0; i < __current_array_index; i++)
        _new_T_array[i + 1] = __dyn_array_int[i];

      for (int j = __current_array_index + 2; j < __array_size; j++) {
        _new_T_array[j] = 0;
      }

      // did it later so that the loop conditons are easy to understand
      ++__current_array_index;
      delete[] __dyn_array_int;
      __dyn_array_int = _new_T_array;

    } else {
      for (int i = __array_size - 1; i >= 0; i--) {
        __dyn_array_int[i] = __dyn_array_int[i - 1];
      }
      __dyn_array_int[0] = input_data;
      __current_array_index++;
    }
  }

  void print() {
    for (int i = 0; i < __array_size; i++) {
      (i == __array_size - 1) ? std::cout << __dyn_array_int[i] << " ;" << endl
                              : std::cout << __dyn_array_int[i] << ", ";
    }
  }
};