#ifndef __ALGORITMOS_HPP__
#define __ALGORITMOS_HPP__

#include <vector>
#include <iostream>

#include "graph_matrix.hpp"
#include "vertex.hpp"

  void depthFirstSearch(edi::GraphMatrix& g, const edi::Vertex& v);

  void FloydAlgorithm(edi::GraphMatrix& g, float** ditance, int** intermediate);

  void shortestPath(edi::GraphMatrix& g, const float** distance, const int** intermediate, const edi::Vertex& from, const edi::Vertex& to);

#endif
