#include "algoritmos.hpp"

bool visited(const edi::Vertex& v, const std::vector<edi::Vertex>& visited){
  int i;
  for(i=0; i<visited.size(); i++){
    if(visited[i] == v){
      return true;
    }
  }

  return false;
}

void depthSearch(edi::GraphMatrix graph, const edi::Vertex& vertex, std::vector<edi::Vertex>& vexterVector){
  vexterVector.push_back(vertex); //METO EL VERTICE EN VISITADOS
  graph.beginEdge(vertex);
  std::cout << "Vertex " << vertex.getLabel() << " - " << vertex.getData() << std::endl;
  while(!graph.afterEndEdge()){ //RECORRO TODOS LOS VERTICES ADYACENTES
    if(!visited(graph.currEdge().second(), vexterVector)){ //SI NO ESTA VISITADO
      depthSearch(graph, graph.currEdge().second(), vexterVector); //LO VISITO
    }

    graph.nextEdge();
  }
}

void FloydAlgorithm(edi::GraphMatrix& graph, double** distanceMatrix, int** intermediateMatrix){
  int i,j,k, numVertexes;
  double distance;
  edi::Vertex u,v;
  //RELLENO MATRIZ ADYACENCIAS
  for(i=0, numVertexes = graph.numVertexes(); i< numVertexes; i++){
    graph.goTo(i);
    u = graph.currVertex();
    for(j=0; j< numVertexes; j++){
      graph.goTo(j);
      v = graph.currVertex();
      distanceMatrix[i][j] = graph.adjacent(u, v);
      intermediateMatrix[i][j] = j; //INICIALIZO MATRIZ INTERMEDIOS
    }
  }

  //APLICAMOS ALGORITMO
  for(k = 0; k < numVertexes; k++){
    for(i = 0; i < numVertexes; i++){
      for(j=0; j < numVertexes; j++){
        distance = distanceMatrix[i][k] + distanceMatrix[k][j];
        if(distance < distanceMatrix[i][j]){
          distanceMatrix[i][j] = distance;
          intermediateMatrix[i][j] = intermediateMatrix[i][k];
        }
      }
    }
  }
}

void goPath(edi::GraphMatrix& graph, const int** intermediateMatrix, int i, int j){
  int next = intermediateMatrix[i][j];
  graph.goTo(i);
  std::cout << graph.currVertex().getData();
  if(intermediateMatrix[i][j] != j){
    std::cout << " - ";
    goPath(graph, intermediateMatrix, next, j);
  }
  else{
    graph.goTo(j);
    std::cout << " - ";
    std::cout << graph.currVertex().getData() << std::endl;
  }
}

void shortestPath(edi::GraphMatrix& graph, const double** distanceMatrix,
                  const int** intermediateMatrix, const edi::Vertex& origin,
                  const edi::Vertex& destination){
  std::vector<int> travel;
  std::vector<int>::iterator it;
  //RECIBIMOS LA MATRIZ DE DISTANCIAS DEL ALGORITMO DE FLOYD
  std::cout << "The minimum distance between " << origin.getData() << " to " << destination.getData() << " is "
            << distanceMatrix[origin.getLabel()][destination.getLabel()] << std::endl;
  goPath(graph, intermediateMatrix, origin.getLabel(), destination.getLabel());
}
