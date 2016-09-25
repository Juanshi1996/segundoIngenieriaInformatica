#include <vector>
#include <string>

#include "graph_matrix.hpp"
#include "vertex.hpp"

void depthFirstSearch (const edi::Vertex &vertex, edi::GraphMatrix g, std::vector <edi::Vertex> &vector);
void floydAlgorithm (edi::GraphMatrix &g, float **distance, int **intermediate);
void minimumDistance(edi::GraphMatrix &g, float **distance, int **intermediate,
					const edi::Vertex &origen, const edi::Vertex &destino);