/*!
  \file graph_matrix.hpp
  \brief Graph
  \author Iván Portillo Leal
*/
#ifndef __GRAPH_MATRIX_HPP__
#define __GRAPH_MATRIX_HPP__

#include <vector>
#include <iostream>
#include <cassert>
#include <vector>
#include <cstdlib>
#include <limits>

#include  "edge.hpp"
#include  "vertex.hpp"


/*!
	\brief Namespace to the Data Structures subject
*/
namespace edi
{
	/*!
		\class GraphMatrix
		\brief Class defining a Graph
	*/
	class GraphMatrix
	{
		/*!
			\name Private part of the GraphMatrix class
		*/
		private:
			/*!
				\var std::vector<Vertex> vertexes_
				\brief Vertexes vector
			*/
			std::vector<Vertex> vertexes_;
			/*!
				\var double** weightsMatrix_
				\brief Weights Matrix
			*/
			double** weightsMatrix_;
			/*!
				\var bool isDirected_
				\brief Indicates if the graph is directed
			*/
			bool isDirected_;
			/*!
				\var Vertex* vertexCursor_;
				\brief Cursor of vertexes
			*/
			Vertex* vertexCursor_;
			/*!
				\var Edge* edgeCursor_
				\brief Cursor of edges
			*/
			Edge* edgeCursor_;
			/*!
				\var unsigned int vertexesNum_
				\brief Number of vertexes
			*/
			unsigned int vertexesNum_;
			/*!
				\var unsigned int edgesNum_
				\brief Number of edges
			*/
			unsigned int edgesNum_;
			//(maximum value of _numVertexes. _capacity >= _numVertexes)
			/*!
				\var unsigned int capacity_
				\brief Capacity of graph
			*/
			unsigned int capacity_;
		/*!
			\name Public part of the GraphMatrix class
		*/
		public:
			/*!\name Makers:
				@{*/

			/*!
				\fn GraphMatrix (const unsigned int & capacity=0, const bool & isDirected = true)
				\brief Generates a graph
				\pre Nothing
				\post Nothing
			*/
			GraphMatrix (const unsigned int & capacity=0, const bool & isDirected = true);
			/*@}*/

			/*!\name Getters:
				@{*/
				/*!\fn const unsigned int &numVertexes()const
					\brief Return the number of vertexes
					\pre Nothing
					\post Nothing
					\return Number of vertexes of the graph
			*/
			const unsigned int &numVertexes()const;

			/*!\fn const unsigned int &numEdges()const
				\brief Return the number of edges
				\pre Nothing
				\post Nothing
				\return Number of edges of the graph
			*/
			const unsigned int &numEdges()const;

			/*!\fn const unsigned int &capacity()const
				\brief Return the capacity of the graph
				\pre Nothing
				\post Nothing
				\return Number of edges of the graph
			*/
			const unsigned int &capacity()const;

			/*!\fn bool isEmpty() const
				\brief Return if the graph is empty
				\pre Nothing
				\post Nothing
				\return True if graph is empty
			*/
			bool isEmpty() const;

			/*!\fn const bool & isDirected() const
				\brief Return if the graph is directed
				\pre Nothing
				\post Nothing
				\return True if graph is directed
			*/
			const bool & isDirected() const;

			/*!\fn const float adjacent(const Vertex & u, const Vertex & v) const
				\brief Return the element of the weights matrix
				\param u First vertex
				\param v Second vertex
				\pre Nothing
				\post Nothing
				\return element of the weights matrix
			*/
			//Devuelve el elemento de la matriz de adyacencia (INFINITO si no hay lado)
			const float adjacent(const Vertex & u, const Vertex & v) const;

			/*!\fn bool hasCurrVertex() const;
				\brief Return if the graph has a valid vertex
				\pre Nothing
				\post Nothing
				\return True if the current vertex is valid
			*/
			//Está el cursor de vértices posición válida
			bool hasCurrVertex() const;

			//Pre: hasCurrVertex() is true.
			//Devuelve el vértice referenciado por cursor de vértices
			/*!\fn const Vertex & currVertex() const;
				\brief Return current vertex
				\pre hasCurrVertex() == TRUE
				\post Nothing
				\return Current vertex
			*/
			const Vertex & currVertex() const;

			/*!\fn bool hasCurrEdge() const
				\brief Return if the graph has a valid edge
				\pre Nothing
				\post Nothing
				\return True if the current edge is valid
			*/
			//Está el cursor de lados posición válida
			bool hasCurrEdge() const;

			//Pre: hasCurrEdge() is true
			//Devuelve el lado referenciado por cursor de lados
			/*!\fn const Edge currEdge()
				\brief Return current edge
				\pre hasCurrEdge() == TRUE
				\post Nothing
				\return Current edge
			*/
			const Edge currEdge();

			/*@}*/
			/*!\name Getters:
				@{*/

			//Crea un grafo dirigido
			/*!\fn void makeDirected()
				\brief Create a directed graph
				\pre Nothing
				\post Nothing
			*/
			void makeDirected();

			//Crea un grafo no dirigido
			/*!\fn void makeUnDirected()
				\brief Create a undirected graph
				\pre Nothing
				\post Nothing
			*/
			void makeUndirected();

			//Prec: numVertexes() < capacity()
			//Añade un vertice al grafo a partir del data
			/*!\fn void addVertex(const std::string & data)
				\brief Add a vertex to the graph
				\param data Data of the vertex
				\pre numVertexes() < capacity()
				\post Nothing
			*/
			void addVertex(const std::string & data);

			//Prec: u y v pertenecen al grafo
			//Añade un lado al grafo a partir de sus dos vértices y su peso. Esto se reflejará sólo en la matriz de adyacencia
			/*!\fn void addEdge(const double & data, const Vertex & u, const Vertex & v)
				\brief Add a edge to the graph
				\param data Data of the vertex
				\pre u and v pertain to the graph
				\post Nothing
			*/
			void addEdge(const double & data, const Vertex & u, const Vertex & v);

			//Busca un vertice a partir de su data, colocando el cursor en dicho vértice
			/*!\fn void searchVertex(const std::string &data)
				\brief Search a vertex in the graph
				\param data Data of the vertex
				\pre Nothing
				\post Nothing
			*/
			void searchVertex(const std::string &data);

			//Prec: u pertenece al grafo
			//Lleva el cursor a un vertice a partir de dicho vertice
			/*!\fn void goTo(const Vertex & u)
				\brief Takes vertex cursor to the vertex
				\param u Vertex to search
				\pre u pertain to graph
				\post Nothing
			*/
			void goTo(const Vertex & u);

			//Prec: 0 <= idx < numVertexes()
			//lleva el cursor a un vértice a partir de la posicion de dicho vertice
			/*!\fn void goTo(const int &idx);
				\brief Takes vertex cursor to the vertex with id (idx)
				\param idx Vertex ID
				\pre 0 <= idx < numVertexes()
				\post Nothing
			*/
			void goTo(const int &idx);

			//Prec: u y v pertenecen al grafo
			//Lleva el cursor a un lado a partir de sus vertices
			/*!\fn void searchEdge(const Vertex & u, const Vertex & v)
				\brief Takes edge cursor to the edge
				\param u First vertex
				\param v Second vertex
				\pre u and v pertain to the graph
				\post Nothing
			*/
			void searchEdge(const Vertex & u, const Vertex & v);


			//Vertex cursor
			//Lleva el cursor al primer vertice
			/*!\fn void beginVertex()
				\brief Takes vertex cursor to the first vertex
				\pre Nothing
				\post Nothing
			*/
			void beginVertex();

			//Avanza el cursor al siguiente vertice
			/*!\fn void nextVertex()
				\brief Takes vertex cursor to the next vertex
				\pre Nothing
				\post Nothing
			*/
			void nextVertex();

			//Comprueba si el cursor ha sobrepasado su última posicion válida
			/*!\fn bool afterEndVertex() const
				\brief Check if cursor has exceeded the last valid position
				\pre Nothing
				\post Nothing
			*/
			bool afterEndVertex() const;

			//Edge cursor
			//Lleva el cursor al primer lado que sale del vertice u
			/*!\fn void beginEdge(const Vertex & u)
				\brief Takes edge cursor to the first edge from vertex u
				\param u Vertex
				\pre Nothing
				\post Nothing
			*/
			void beginEdge(const Vertex & u);

			//Avanza el cursor al siguiente lado que sale de currEdge().first()
			/*!\fn void nextEdge()
				\brief Takes edge cursor to the next edge
				\pre Nothing
				\post Nothing
			*/
			void nextEdge();

			//Comprueba si el cursor ha sobrepasado su última posicion válida para los lados que salen de currEdge().first()
			/*!\fn bool afterEndEdge()
				\brief Check if cursor has exceeded the last valid position
				\pre Nothing
				\post Nothing
			*/
			bool afterEndEdge();

			/*@}*/
	};
} //namespace ed

	#endif
