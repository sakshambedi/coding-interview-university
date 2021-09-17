#include <iostream>
#include <memory>

#include "graphs.h"

namespace Graph {

template <class T, std::size_t list_size>
Graph::weighted_graph_list<T, list_size>::weighted_graph_list() {
  for (int i = 0; i < list_size; i++) {
    wg_array[i] = nullptr;
  }
}

template <class T, std::size_t list_size>
void Graph::weighted_graph_list<T, list_size>::insert_node(int source,
                                                           int target,
                                                           T input_weight) {
  // auto &temp = wg_array[source];
  if (wg_array[source] == nullptr)
    std::cout << "nullptr";
  else
    std::cout << "not  NULL ";
  return;
}

template <class T, std::size_t list_size>
void Graph::weighted_graph_list<T, list_size>::print() {
  for (auto &elem : wg_array) {
    // for (std::shared_ptr<graph_node> temp = *elem; temp.next_node != nullptr;
    //      temp = temp->next_node) {
    //   std::cout << temp->weight_node << " ";
    // }
    std::cout << "\n";
  }
}

template <class T, std::size_t list_size>
size_t Graph::weighted_graph_list<T, list_size>::size() const {
  return list_size;
}
};  // namespace Graph

int main(void) {
  Graph::weighted_graph_list<int, 10> wgn;
  std::cout << "size of the list : " << wgn.size() << "\n";
  wgn.insert_node(0, 1, 3);
  wgn.print();
  return 1;
}