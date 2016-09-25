#include <cstdlib>
#include <iostream>

#include "graph_matrix.hpp"
#include "entrada_salida.hpp"
#include "algoritmos.hpp"

int main() {
  int option = 1;
  edi::GraphMatrix *g;
  bool isLoaded = false;
  while(option) {
    system("reset");
    std::cout << "\n(#)  ======================== Elija una opción del menú ==";
    std::cout << "=======================";
    std::cout << "\n(1)  Cargar grafo";
    std::cout << "\n(2)  Mostrar grafo";
    std::cout << "\n(3)  Recorrer el grafo en profundidad";
    std::cout << "\n(4)  Calcular camino mínimo y distancia entre dos vértices";
    std::cout << "\n(0)  Salir del programa.\n";
    std::cout << "(#)  =======================================================";
    std::cout << "=====================\n";
    do {
    std::cout << "\n     \e[93mIntroduzca un número entero comprendido entre el 0 y 4: \e[0m";
    std::cin >> option;
  } while(option < 0 or option > 4);
    switch(option) {
      case 0: {
        if(isLoaded) {
          delete g;
        }
        std::cout << "\n";
        exit(EXIT_SUCCESS);
      }
      case 1: {
        std::string fileGraph;
        std::cout << "\n     \e[94mIntroduzca el nombre del fichero: \e[0m";
        std::cin >> fileGraph;
        isLoaded = cargarGrafo(g, fileGraph);
        if(not isLoaded) {
      		std::cout << "\n     \e[91mEl grafo no se ha podido cargar.\n\e[0m";
        }
        break;
      }
      case 2: {
        if(isLoaded) {
          mostrarGrafo(*g);
        } else {
          std::cout << "\n     \e[91mPor favor, cargue antes un grafo.\n\e[0m";
        }
        break;
      }
      case 3: {
        if(isLoaded) {
          g->beginVertex();
          do
        	{
        		std::cout << "\n     " << g->currVertex().getData();
        		g->nextVertex();
        	}while(not g->afterEndVertex());
        	std::cout<< std::endl;
          std::string data;
          std::cout << "\n     \e[94mIntroduzca el vértice origen: \e[0m";
          std::cin >> data;
          g->searchVertex(data);
          while(not g->hasCurrVertex()) {
            std::cout << "\n     \e[93mEl vértice introducido no existe, por favor introduzca un vértice válido: \e[0m";
            std::cin >> data;
            g->searchVertex(data);
          }
          depthFirstSearch(*g, g->currVertex());
        } else {
          std::cout << "\n     \e[91mPor favor, cargue antes un grafo.\n\e[0m";
        }
        break;
      }
      case 4: {
        if(isLoaded) {
          float** distance = (float**) malloc(g->numVertexes() * sizeof(float*));
          for(size_t i = 0; i < g->numVertexes(); i++) {
            distance[i] = (float*) malloc(g->numVertexes() * sizeof(float));
          }
          int** intermediate = (int**) malloc(g->numVertexes() * sizeof(int*));
          for(size_t i = 0; i < g->numVertexes(); i++) {
            intermediate[i] = (int*) malloc(g->numVertexes() * sizeof(int));
          }
          std::string data;
          g->beginVertex();
          do
        	{
        		std::cout << "\n     " << g->currVertex().getData();
        		g->nextVertex();
        	}while(not g->afterEndVertex());
        	std::cout<< std::endl;
          std::cout << "\n     \e[94mIntroduzca el vértice de origen: \e[0m";
          std::cin >> data;
          g->searchVertex(data);
          while(not g->hasCurrVertex()) {
            std::cout << "\n     \e[93mEl vértice introducido no existe, por favor introduzca un vértice válido: \e[0m";
            std::cin >> data;
            g->searchVertex(data);
          }
          edi::Vertex from = g->currVertex();
          std::cout << "\n     \e[94mIntroduzca el vértice de destino: \e[0m";
          std::cin >> data;
          g->searchVertex(data);
          while(not g->hasCurrVertex()) {
            std::cout << "\n     \e[93mEl vértice introducido no existe, por favor introduzca un vértice válido: \e[0m";
            std::cin >> data;
            g->searchVertex(data);
          }
          edi::Vertex to = g->currVertex();
          FloydAlgorithm(*g, distance, intermediate);
          shortestPath(*g, (const float**) distance, (const int**) intermediate, from, to);
        } else {
          std::cout << "\n     \e[91mPor favor, cargue antes un grafo.\n\e[0m";
        }
        break;
      }
    }
    std::cout << "\n     \e[94mPulse la tecla ENTER para mostrar de nuevo el menú...\e[0m";
    getchar();
    getchar();
  }
}
