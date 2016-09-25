#include "graph_matrix.hpp"
#include "vertex.hpp"

/*!
  \fn        bool visited(const edi::Vertex& v, const std::vector<edi::Vertex>& visited)
  \brief     Check if a vertex is visited
  \param v  Vertex to check
  \param visited Vector of visited vextex
  \return    True if the vertex is visited
*/
bool visited(const edi::Vertex& v, const std::vector<edi::Vertex>& visited);
/*!
  \fn        void depthSearch(edi::GraphMatrix graph, const edi::Vertex& vertex, std::vector<edi::Vertex>& vexterVector)
  \brief     Depth search algorithm
  \param graph  Graph
  \param vertex Initial vertex
  \param vexterVector Vexter vector
*/
void depthSearch(edi::GraphMatrix graph, const edi::Vertex& vertex, std::vector<edi::Vertex>& vexterVector);
/*!
  \fn        void FloydAlgorithm(edi::GraphMatrix& graph, double** distanceMatrix, int** intermediateMatrix)
  \brief     Floyd Algorithm
  \param graph  Graph
  \param distanceMatrix Distance matrix
  \param intermediateMatrix Intermediate matrix
*/
void FloydAlgorithm(edi::GraphMatrix& graph, double** distanceMatrix,
                    int** intermediateMatrix);
/*!
  \fn        void goPath(edi::GraphMatrix& graph, const int** intermediateMatrix, int i, int j)
  \brief     Shortest path
  \param graph  Graph
  \param intermediateMatrix Intermediate matrix
  \param i origin
  \param j destination
*/
void shortestPath(edi::GraphMatrix& graph, const double** distanceMatrix,
                  const int** intermediateMatrix, const edi::Vertex& origin,
                  const edi::Vertex& destination);
/*!
  \fn        void shortestPath(edi::GraphMatrix& graph, const double** distanceMatrix, const int** intermediateMatrix, const edi::Vertex& origin, const edi::Vertex& destination)
  \brief     Shortest path and minimum distance
  \param graph  Graph
  \param intermediateMatrix Intermediate matrix
  \param distanceMatrix Distance matrix
  \param origin Origin Vertex
  \param destination Destination Vertex
*/
void goPath(edi::GraphMatrix& graph, const int** intermediateMatrix, int i, int j);
