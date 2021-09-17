#include <limits.h>

#include <iostream>

#include "graphs.h"

namespace Graph {
template <class T, std::size_t rows, std::size_t cols>
weighted_graph_matrix<T, rows, cols>::weighted_graph_matrix() {
  for (size_t i = 0; i < rows; i++)
    for (size_t j = 0; j < cols; j++) gmatrix[i][j] = 0;
}

template <typename T, std::size_t rows, std::size_t cols>
void Graph::weighted_graph_matrix<T, rows, cols>::print() {
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols; j++) std::cout << gmatrix[i][j] << " ";
    std::cout << "\n";
  }
  return;
}

template <class T, std::size_t rows, std::size_t cols>
void Graph::weighted_graph_matrix<T, rows, cols>::insert(int source, int target,
                                                         T data) {
  if (source < 0 || target < 0)
    throw new std::length_error("Invalid argument ");
  gmatrix[source][target] = data;
}

template <class T, std::size_t rows, std::size_t cols>
size_t Graph::weighted_graph_matrix<T, rows, cols>::num_rows() const {
  return rows;
}

template <class T, std::size_t rows, std::size_t cols>
size_t Graph::weighted_graph_matrix<T, rows, cols>::num_cols() const {
  return cols;
}

template <class T, std::size_t rows, size_t cols>
int Graph::weighted_graph_matrix<T, rows, cols>::min_distance(int dist[],
                                                              bool sptSet[]) {
  int min = INT_MAX, min_index;

  for (std::size_t v = 0; v < cols; v++) {
    if (sptSet[v] == false && dist[v] <= min) min = dist[v], min_index = v;
  }
  return 1;
}

/**
 * @brief Find the shorted path using Dikstra algorithm
 *
 * @tparam T
 * @tparam rows
 * @tparam cols
 * @param source
 */
template <class T, std::size_t rows, std::size_t cols>
void Graph::weighted_graph_matrix<T, rows, cols>::shortest_path_dijkstra(
    int source) {
  int dist[cols];
  bool sptSet[cols];

  std::cout << "Int_Max Value : " << INT_MAX << "\n";
  for (std::size_t i = 0; i < cols; i++) dist[i] = INT_MAX, sptSet[i] = false;

  dist[source] = 0;

  for (std::size_t count = 0; count < rows - 1; count++) {
    int u = min_distance(dist, sptSet);
    sptSet[u] = true;
    for (std::size_t v = 0; v < cols; v++)

      // Update dist[v] only if is not in sptSet, there is an edge from
      // u to v, and total weight of path from src to  v through u is
      // smaller than current value of dist[v]
      if (!sptSet[v] && gmatrix[u][v] && dist[u] != INT_MAX &&
          dist[u] + gmatrix[u][v] < dist[v])
        dist[v] = dist[u] + gmatrix[u][v];
  }

  // print the constructed distance array
  printSolution(dist);
}

template <class T, std::size_t rows, std::size_t cols>
void Graph::weighted_graph_matrix<T, rows, cols>::printSolution(
    int dist[]) const {
  std::cout << "Vertex \t Distance from source " << std::endl;
  for (std::size_t i = 0; i < cols; i++)
    std::cout << i << "\t\t" << dist[i] << std::endl;
}
};  // namespace Graph

int main(void) {
  // Graph::weighted_graph_node<int> g(10);
  // std::cout << g.size() << "\n";
  // g.insert_value(0, 0, 5);
  Graph::weighted_graph_matrix<double, 5, 6> gm;
  gm.print();
  std::cout << "num of rows : " << gm.num_rows()
            << " and num of cols : " << gm.num_cols() << std::endl;

  std::cout << "Inserting values : \n";
  gm.insert(0, 0, 1);
  gm.insert(0, 1, 0);
  gm.insert(0, 2, 10);
  gm.insert(0, 3, 0);
  gm.insert(0, 4, 5);
  gm.insert(0, 5, 2);
  gm.insert(1, 0, 0);
  gm.insert(1, 1, 1);
  gm.insert(1, 2, 0);
  gm.insert(1, 3, 5);
  gm.insert(1, 4, 7);
  gm.insert(1, 5, 1);
  gm.insert(2, 0, 2);
  gm.insert(2, 1, 3);
  gm.insert(2, 2, 0);
  gm.insert(2, 3, 1);
  gm.insert(2, 4, 3);
  gm.insert(2, 5, 4);
  gm.insert(3, 0, 1);
  gm.insert(3, 1, 0);
  gm.insert(3, 2, 2);
  gm.insert(3, 3, 3);
  gm.insert(3, 4, 4);
  gm.insert(3, 5, 5);
  gm.insert(3, 5, 5);
  gm.insert(4, 0, 10);
  gm.insert(4, 1, 2);
  gm.insert(4, 2, 0);
  gm.insert(4, 3, 5);
  gm.insert(4, 4, 7);
  gm.insert(4, 5, 8);
  gm.print();

  gm.shortest_path_dijkstra(0);

  return 0;
}
