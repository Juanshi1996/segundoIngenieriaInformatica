#include <iostream>
#include <fstream>
#include "graph_matrix.hpp"
#include "entrada_salida.hpp"
#include "colores.hpp"

bool cargarGrafo(edi::GraphMatrix * &g, std::string fileGraph)
{
	std::ifstream f(fileGraph.c_str()); //Se define el stream de lectura y se abre el fichero.
	if (not f)
		return false;
	
  //Se definen variables auxiliares para cargar el grafo.
  unsigned int vertexes;	
  int type;
	bool isDirected;
	std::string dataVertex;
	std::string dataEdgeFirst, dataEdgeSecond;
	edi::Vertex first, second;
	double weight;
	
  f >> vertexes; //Se lee el numero de nodos.
  f >> type; //Se lee el tipo.
  
  if (type == 0)
		isDirected = false;
	else
		isDirected = true;
	
	std::cout << "\E[32m\033[15;56Hcargados tipo y numero de nodos\n";

  g = new edi::GraphMatrix (vertexes, isDirected); //Se reserva espacio para el grafo y se invoca al constructor.
	
	//Lectura de los data de los nodos
	for(unsigned int i = 1; i <= vertexes; i++)
	{
		f >> dataVertex;
		g->addVertex(dataVertex);
	}
	
	std::cout << "\E[32m\033[16;65HCargados nodos\n";
	//Lectura de los lados.
	
	//Inicializamos todos los lados a infinito y después se sobreescriben

	while(f >> dataEdgeFirst >> dataEdgeSecond >> weight )
	{
		//Creamos los nodos que forman parte del lado
		//std::cout << "Cargo Lado\n";
		//Para localizar el indice del nodo
		
		g->searchVertex(dataEdgeFirst);
		first.setLabel((g->currVertex()).getLabel()); 

		first.setData(dataEdgeFirst);
		
		//Para localizar el indice del nodo
		g->searchVertex(dataEdgeSecond);

		second.setLabel((g->currVertex()).getLabel());
		
		second.setData(dataEdgeSecond);
		
		//std::cout << "Buscados nodos del lado \n";
		
		//Añade el lado(first, second) con peso weight;
		g->addEdge(weight, first, second);
		
		//std::cout << "Lado añadido \n";
	}
	f.close();
	
	std::cout << "\E[32m\033[17;65HCargados lados\n";
	
	return true;
}


void mostrarGrafo(edi::GraphMatrix & g)
{	
	int linea = 1;
	g.beginVertex();
	LUGAR(linea,10);
	INTENSIDAD;
	std::cout << "Nodos del grafo\n";
	getchar();
	APAGA;
	edi::Vertex v;
	
	do
	{
		v = g.currVertex();
		LUGAR(linea+2,10);
		std::cout << v.getData() << std::endl;
        linea++;
     	if (linea%30==0){
     		std::cout << std::endl;
     		LUGAR(linea+3,10);
            printf("pulse ");
	    	SUBRAYADO;
  	    	printf("ENTER");
	    	APAGA;
	    	printf(" para ");
	    	INVERSO;
	    	printf("continuar");
	    	APAGA;
            getchar();
            BORRAR;
            linea=1;
            LUGAR(linea,10);
	    	INTENSIDAD;
            printf("Nodos del grafo (continuación)");
	    	APAGA;
		}



		g.nextVertex();
	}while(not g.afterEndVertex());
	LUGAR(linea+3,10);
	printf("pulse ");
	SUBRAYADO;
  	printf("ENTER");
	APAGA;
	printf(" para ");
	INVERSO;
	printf("ver los lados del grafo");
	APAGA;
	getchar();
	BORRAR;
	linea=1;
	
	//Lados del grafo
	LUGAR(1 ,10);
	INTENSIDAD;
	printf ("Lados del grafo");//std::cout << "\nLados del grafo\n";
	LUGAR(1 ,45);
	INVERSO;
	std::cout << " Lados = " << fred << g.numEdges() << tnormal << std::endl;
	APAGA;

	edi::Vertex aux;
	g.beginVertex();

	while(not g.afterEndVertex()){
		aux = g.currVertex();
		
		g.beginEdge(aux); //Se posiciona en el primer lado que tiene a aux como nodo origen
		while (not g.afterEndEdge())
		{
			LUGAR(linea+2,10);
			//std::cout << "\nLados del grafo\n";

			std::cout << g.currEdge().first().getData() << ", " << g.currEdge().second().getData() << ", " << g.currEdge().getData() << std::endl;
			linea++;
     	if (linea%30==0){
     		LUGAR(linea+3,10);
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
            linea=1;
            LUGAR(linea,10);
	    	INTENSIDAD;
            printf("Lados del grafo (continuación)");
            LUGAR(1 ,45);
			INVERSO;
			std::cout << "Lados = " << fred << g.numEdges() << tnormal << std::endl;
	    	APAGA;
		}
			g.nextEdge();
		}
		g.nextVertex();
	}
}
	
