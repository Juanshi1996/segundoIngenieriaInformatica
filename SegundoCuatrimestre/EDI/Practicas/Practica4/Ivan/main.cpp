#include <iostream>
#include <fstream>
#include "algoritmos.hpp"
#include "graph_matrix.hpp"
#include "entrada_salida.hpp"

int main(int argc, char const *argv[]) {
  int option = 0, i;
  double** distanceMatrix = NULL;
  int** intermediateMatrix = NULL;
  edi::GraphMatrix *g = 0;
  edi::Vertex origin, destination;
  bool loaded = false;
  std::string graphFileName, message;
  do{
    std::cout << std::endl << "----------- MENU -----------" << std::endl;
    std::cout << "1.- Load graph from file." << std::endl;
    std::cout << "2.- Show graph." << std::endl;
    std::cout << "3.- Depth search." << std::endl;
    std::cout << "4.- Floyd algorithm (show minimum distance/road of two vertex)." << std::endl;
    std::cout << "SELECT AN OPTION (-1 TO EXIT): " << std::endl;
    std::cin >> option;
    getchar();
    switch(option){
      case 1:
        std::cout << "Introduce graph file name: ";
        std::cin >> graphFileName;
        getchar();
        loaded = cargarGrafo(g, graphFileName);
        std::cout << (loaded ? "Graph loaded correctly!" : "Error loading graph") << std::endl;
        std::cout << "Press ENTER to continue." << std::endl;
        getchar();
      break;

      case 2:
        if(loaded)
          mostrarGrafo(*g);
        else
          std::cout << "No graph loaded!" << std::endl;
        std::cout << "Press ENTER to continue." << std::endl;
        getchar();
      break;

      case 3:
        if(loaded){
          std::cout << "Introduce initial vertex: ";
          std::cin >> message;
          getchar();
          g->searchVertex(message);
          if(!g->hasCurrVertex()){
            std::cout << "Vertex not found!" << std::endl;
          }
          else{
            std::vector<edi::Vertex> visited;
            depthSearch(*g, g->currVertex(), visited);
          }
        }
        else{
          std::cout << "No graph loaded!" << std::endl;
        }
        std::cout << "Press ENTER to continue." << std::endl;
        getchar();
      break;

      case 4:
        if(loaded){
          distanceMatrix = (double**) malloc(g->numVertexes()*sizeof(double*));
          intermediateMatrix = (int**) malloc(g->numVertexes()*sizeof(int*));
          for(i=0; i< g->numVertexes(); i++){
            distanceMatrix[i] = (double*) malloc(g->numVertexes()*sizeof(double));
            intermediateMatrix[i] = (int*) malloc(g->numVertexes()*sizeof(int));
          }
          FloydAlgorithm(*g, distanceMatrix, intermediateMatrix);
          std::cout << "Floyd Algorithm Executed." << std::endl;
          std::cout << "Introduce the initial vertex: ";
          std::cin >> message;
          getchar();
          g->searchVertex(message);
          if(!g->hasCurrVertex()){
            std::cout << "Initial vertex not found in the graph!" << std::endl;
          }
          else{
            origin = g->currVertex();
            std::cout << "Introduce the final vertex: ";
            std::cin >> message;
            getchar();
            g->searchVertex(message);
            if(!g->hasCurrVertex()){
              std::cout << "Final vertex not found in the graph!" << std::endl;
            }
            else{
              destination = g->currVertex();
              shortestPath(*g, (const double**) distanceMatrix, (const int**) intermediateMatrix, origin, destination);
            }
          }
        }
        else{
          std::cout << "No graph loaded!" << std::endl;
        }
        std::cout << "Press ENTER to continue.";
        getchar();
      break;
    }
  }while(option != -1);
  return 0;
}
