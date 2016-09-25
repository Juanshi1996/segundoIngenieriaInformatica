/*!
  \file   main.cpp
  \brief  Programa que prueba la clase Persona
  \author Name
  \date   16/03/2015
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

#include "interfaz.hpp"
#include "graph_matrix.hpp"
#include "entrada_salida.hpp"
#include "colores.hpp"
#include "algoritmos.hpp"

int main(){
	int opc = -1; // Opción para elegir en el menú
	bool grafoCreado = false;
	edi::GraphMatrix *g = 0;
	bool cargado;
	std::string nameFichero;
	std::string provinciaProfundidad;
	std::string ciudad1;
	std::string ciudad2;
	edi::Vertex vertexCiudad1;
	edi::Vertex vertexCiudad2;
	edi::Vertex vertexProfundidad;
	std::vector <edi::Vertex> vector;

	while (opc != 0){
    opc = menu ();
    	if (opc != 1 && opc != 0 && !grafoCreado){
    		system ("clear");
        	std::cout << "\E[31m\033[20;54HDebes cargar antes un grafo."<<tnormal;
        	fflush (stdout);
        	system ("sleep 1");
    	}
	    else if (opc == 1){ // Cargar un grafo desde un fichero
	    	system("clear");
	    	std::cout << "\033[20;30H\E[36mIntroduzca el nombre del fichero del cual quiere cargar el grafo: "<<tnormal;
	    	std::cin  >> nameFichero;
	    	system ("clear");
	    	cargado=cargarGrafo(g, nameFichero);
				if(cargado){
					grafoCreado = true;
					std::cout << "\E[32m\033[20;54HEl grafo se ha cargado correctamente.";
				}
				else
					std::cout << "\E[31m\033[20;54HEl grafo no se ha podido cargar";
				fflush(stdout);
				system ("sleep 2");
		}
		if (grafoCreado){
			if (opc == 2){ // Mostrar el grafo por pantalla
    		system ("clear");
    		mostrarGrafo(*g);
				getchar();
			}

      if (opc == 3){ // Realizar el recorrido en profundidad a partir de un nodo
      	system ("clear");
    		std::cout << "\033[20;30H\E[36mIntroduzca el nombre de una provincia por la que empezar el recorrido: "<<tnormal;
	    	std::cin  >> provinciaProfundidad;
				g->searchVertex(provinciaProfundidad);
				system("clear");
	  		getchar();
				depthFirstSearch (g->currVertex(), *g, vector);
				LUGAR(27,10);
		    printf("pulse ");
		    SUBRAYADO;
		    printf("ENTER");
		    APAGA;
		    printf(" para ");
		    INVERSO;
		    printf(" finalizar");
		    APAGA;
		    getchar();
		    BORRAR;
				vector.clear();

      }
      if (opc == 4){ // Mostrar distancia y camino mínimo entre dos ciudades
			system ("clear");

    		std::cout << "\033[18;50H\E[36mCiudad1: "<<tnormal;
	    	std::cin  >> ciudad1;
	    	g->searchVertex(ciudad1);
				vertexCiudad1=g->currVertex();
				std::cout << "\033[20;50H\E[36mCiudad2: "<<tnormal;
	    	std::cin  >> ciudad2;
	    	g->searchVertex(ciudad2);
				vertexCiudad2=g->currVertex();
				g->searchVertex(provinciaProfundidad);
				system("clear");
	  		getchar();

  			float **distance = (float**)malloc(g->numVertexes()*sizeof(float*));
			for (unsigned int i=0;i<g->numVertexes();i++){
				distance[i]=(float*)malloc(g->numVertexes()*sizeof(float));
			}
			int **intermediate = (int**)malloc(g->numVertexes()*sizeof(int*));
			for (unsigned int i=0;i<g->numVertexes();i++){
				intermediate[i]=(int*)malloc(g->numVertexes()*sizeof(int));
			}

			floydAlgorithm(*g, distance, intermediate);
			minimumDistance(*g, distance, intermediate, vertexCiudad1, vertexCiudad2);
      }
		}
  }
	system ("clear");
  return 0;
}
