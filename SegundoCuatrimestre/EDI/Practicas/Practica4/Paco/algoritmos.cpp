#include <vector>
#include <cstdlib>//borrar
#include <cstdio>//borrar
#include <string>

#include "graph_matrix.hpp"
#include "algoritmos.hpp"
#include "vertex.hpp"
#include <limits>
#include "colores.hpp"

int linea = 0;

bool searchVector (const edi::Vertex &vertex, std::vector <edi::Vertex> &vector){
	for (unsigned int i = 0 ; i < vector.size() ; i ++){
		if (vector[i]==vertex){
			return true;
		}
	}
	return false;
}

void depthFirstSearch (const edi::Vertex &vertex, edi::GraphMatrix g, std::vector <edi::Vertex> &vector){
	vector.push_back(vertex);
	g.beginEdge(vertex);

  if (linea==0){
    LUGAR(1, 10);
    INTENSIDAD;
    printf ("Búsqueda en amplitud.");
    APAGA;

  }


  LUGAR(linea+3,20);
      std::cout << vertex.getLabel() << " --> " << vertex.getData() << std::endl;

  if (linea%20==0 && linea!=0){
    LUGAR(linea+7,10);
    printf("pulse ");
    SUBRAYADO;
    printf("ENTER");
    APAGA;
    printf(" para ");
    INVERSO;
    printf(" continuar");
    APAGA;
    getchar();
    BORRAR;
    linea=-1;
  }
  linea++;
      
	while (!g.afterEndEdge()){
		if (!searchVector(g.currEdge().second(), vector)){
			depthFirstSearch(g.currEdge().second(), g, vector);
		}
		else g.nextEdge();
	}
}


void floydAlgorithm (edi::GraphMatrix &g, float **distance, int **intermediate){
  for(unsigned int i = 0 ; i < g.numVertexes() ; i ++){
    for(unsigned int j = 0 ; j < g.numVertexes() ; j ++){
      if (i==j)intermediate[i][j]=0;
      else intermediate [j][i]=i;
    }
  }

  for(unsigned int i = 0 ; i < g.numVertexes() ; i ++) {
    g.goTo(i);
    edi::Vertex vertexAux1 = g.currVertex();
    for(unsigned int j = 0 ; j < g.numVertexes() ; j ++){
      g.goTo(j);
      edi::Vertex vertexAux2 = g.currVertex();
      distance[i][j] = g.adjacent(vertexAux1, vertexAux2);
    }
  }

  for (unsigned int k = 0 ; k < g.numVertexes() ; k ++){
    for(unsigned int i = 0 ; i < g.numVertexes() ; i ++){
      for (unsigned int j = 0 ; j < g.numVertexes() ; j ++){
        if (distance[i][j]>distance[i][k]+distance[k][j]){
            distance[i][j]=distance[i][k]+distance[k][j];              
            intermediate[i][j]=intermediate[i][k];
        }
      }   
    }
  }
}

void minimumDistance(edi::GraphMatrix &g, float **distance, int **intermediate, const edi::Vertex &origin, const edi::Vertex &destination){
    int auxOrigin = origin.getLabel();
    std::cout << "\033[18;50H\E[33mLa mínima distancia entre " << origin.getData() << " y " << destination.getData() << " es \E[31m" << distance[origin.getLabel()][destination.getLabel()] << "\E[33m km.";
    std::cout << "\033[20;50H\E[36mEl camino más corta para llegar desde " << underline << origin.getData() << nunderline << " a " << underline << destination.getData() << nunderline <<" es:" << "\033[22;54H\E[32m";
    std::cout <<origin.getData() << " --> ";
    while (auxOrigin!=destination.getLabel()){
      auxOrigin = intermediate[auxOrigin][destination.getLabel()];
      g.goTo(auxOrigin);
      if (auxOrigin!=destination.getLabel())std::cout <<g.currVertex().getData() << " --> ";
    }
     std::cout << destination.getData();
     getchar();
}