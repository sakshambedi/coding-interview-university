// #include "header/graphs.h"
#include <array>
#include <memory>
#include <vector>

namespace Graph {

/**
 * @brief
 *
 * @tparam T
 * @tparam list_size
 */
template <class T, std::size_t list_size>
class weighted_graph_list {
 private:
  struct graph_node {
    // member vars
    T weight_node;
    int point_value;
    std::unique_ptr<graph_node> next_node;

    // constructor
    graph_node() : next_node(nullptr){};
  };

  std::vector<std::unique_ptr<graph_node>> wg_array;

 public:
  weighted_graph_list();
  void insert_node(int index, int destination, T data);
  void print();
  size_t size() const;
};

/**
 * @brief Graph implementation using standard library array for the adjacency
 * matrix
 *
 * @tparam T Object type
 * @tparam rows Number of rows for the adjacency matrix
 * @tparam cols Number of cols for the adjacency matrix
 */
template <class T, std::size_t rows, std::size_t cols>
class weighted_graph_matrix {
 private:
  std::array<std::array<T, cols>, rows> gmatrix;
  int min_distance(int dist[], bool sptSet[]);
  void printSolution(int dist[]) const;

 public:
  weighted_graph_matrix();
  void print();
  void insert(int source, int target, T input_weight);
  size_t num_rows() const;
  size_t num_cols() const;
  void shortest_path_dijkstra(int source);
};
}  // namespace Graph
