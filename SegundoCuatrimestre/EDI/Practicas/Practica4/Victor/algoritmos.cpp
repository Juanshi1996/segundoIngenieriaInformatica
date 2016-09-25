#include "algoritmos.hpp"

bool isVisited(const edi::Vertex& v, const std::vector<edi::Vertex>& visited) {
  for(size_t i = 0; i < visited.size(); i++) {
    if(visited[i] == v) {
      return(true);
    }
  }
  return(false);
}

void depthFirstSearch(edi::GraphMatrix g, const edi::Vertex& v, std::vector<edi::Vertex>& visited) {
  visited.push_back(v);
  g.beginEdge(v);
  std::cout << "\n     Vértice: " << v.getLabel() << " -> " << v.getData();
  while(not g.afterEndEdge()) {
    if(not isVisited(g.currEdge().second(), visited)) {
      depthFirstSearch(g, g.currEdge().second(), visited);
    }
    g.nextEdge();
  }
}

void depthFirstSearch(edi::GraphMatrix& g, const edi::Vertex& v) {
  std::vector<edi::Vertex> visited;
  depthFirstSearch(g, v, visited);
  std::cout << std::endl;
}

void FloydAlgorithm(edi::GraphMatrix& g, float** distance, int** intermediate) {
  for(size_t i = 0; i < g.numVertexes(); i++) {
    g.goTo(i);
    edi::Vertex u = g.currVertex();
    for(size_t j = 0; j < g.numVertexes(); j++) {
      g.goTo(j);
      edi::Vertex v = g.currVertex();
      distance[i][j] = g.adjacent(u, v);
    }
  }
  for(size_t i = 0; i < g.numVertexes(); i++) {
    for(size_t j = 0; j < g.numVertexes(); j++) {
      intermediate[i][j] = j;
    }
  }
  for(size_t k = 0; k < g.numVertexes(); k++) {
    for(size_t i = 0; i < g.numVertexes(); i++) {
      for(size_t j = 0; j < g.numVertexes(); j++) {
        if(distance[i][k] + distance[k][j] < distance[i][j]) {
          distance[i][j] = distance[i][k] + distance[k][j];
          intermediate[i][j] = intermediate[i][k];
        }
      }
    }
  }
}

void shortestPath(edi::GraphMatrix& g, const float** distance, const int** intermediate, const edi::Vertex& from, const edi::Vertex& to) {
  std::cout << "\n     La distancia mínima entre " << from.getData() << " y " << to.getData() << " es \e[92m" << distance[from.getLabel()][to.getLabel()] << "\e[0m\n";
  std::cout << "\n     El camino más corto para llegar desde " << from.getData() << " hasta " << to.getData() << " es\n\n     ";
  std::cout << "\e[94m" << from.getData() << "\e[0m\t->\n     ";
  int currentLabel = from.getLabel();
  while(to.getLabel() != intermediate[currentLabel][to.getLabel()]) {
    g.goTo(intermediate[currentLabel][to.getLabel()]);
    std::cout << "\e[95m" << g.currVertex().getData() << "\e[0m\t->\n     ";
    currentLabel = intermediate[currentLabel][to.getLabel()];
  }
  std::cout << "\e[91m" << to.getData() << "\e[0m\t**" << std::endl;
}
