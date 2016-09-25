#include <vector>
#include <iostream>
#include <cassert>

#include  "edge.hpp"
#include  "vertex.hpp"
#include "graph_matrix.hpp"

#include <cstdlib>
#include <limits>




//BORRAR
#include <cstdlib>
#include <cstdio>



/*!
\brief Espacio de nombres para la asignatura Estructura de datos.

*/
//Vector of vertexes
//Adjacency matrix of weights
//Is directed
//cursor of vertexes
//cursor of edges
//number of vertexes
//number of edges
//Capacity of graph (maximum value of _numVertexes. _capacity >= _numVertexes)

edi::GraphMatrix::GraphMatrix (const unsigned int & capacity, const bool & isDirected){
	capacity_=capacity;
	isDirected_=isDirected;
	matrix_= (double**)malloc(capacity*sizeof(double*));
	for (unsigned int i = 0; i < capacity; i++)
		matrix_[i]=(double*)malloc(capacity*sizeof(double));
	for (unsigned int i = 0; i < capacity; i++)
	{
		for (unsigned int j = 0; j < capacity; j++)
		{
			if (i==j)
				matrix_[i][j]=0;
			else matrix_[i][j]=std::numeric_limits<float>::infinity();
		}
	}
	currentVertex_=NULL;
	currentEdge_=NULL;
	nVertexes_=0;
	nEdges_=0;
}


//Observers
const unsigned int &edi::GraphMatrix::numVertexes()const{return nVertexes_;}

const unsigned int &edi::GraphMatrix::numEdges()const{return nEdges_;}

const unsigned int &edi::GraphMatrix::capacity()const{return capacity_;}

bool edi::GraphMatrix::isEmpty() const{
	if(numVertexes()==0)
		return true;
	else return false;
}

const bool & edi::GraphMatrix::isDirected() const{ return isDirected_;}

//Devuelve el elemento de la matriz de adyacencia (INFINITO si no hay lado)
const float edi::GraphMatrix::adjacent(const Vertex & u, const Vertex & v) const{
	return matrix_[u.getLabel()][v.getLabel()];
}

//Está el cursor de vértices posición válida
bool edi::GraphMatrix::hasCurrVertex() const{
	return currentVertex_ != NULL;
} 

//Pre: hasCurrVertex() is true.
//Devuelve el vértice referenciado por cursor de vértices
const edi::Vertex &edi::GraphMatrix::currVertex() const{
	assert (hasCurrVertex());
	return *currentVertex_;
}

//Está el cursor de lados posición válida
bool edi::GraphMatrix::hasCurrEdge() const{
	if (currentEdge_!=NULL)
		return true;
	else return false;
}

//Pre: hasCurrEdge() is true
//Devuelve el lado referenciado por cursor de lados
const edi::Edge edi::GraphMatrix::currEdge(){
	assert (hasCurrEdge());
	return *currentEdge_;
}

//Modifiers

//Crea un grafo dirigido
void edi::GraphMatrix::makeDirected(){isDirected_=true;}

//Crea un grafo no dirigido
void edi::GraphMatrix::makeUndirected(){isDirected_=false;}

//Prec: numVertexes() < capacity()
//Añade un vertice al grafo a partir del data
void edi::GraphMatrix::addVertex(const std::string & data){
	assert(numVertexes()<capacity());
	Vertex v;
	v.setData(data);
	v.setLabel(nVertexes_);
	vertex_.push_back(v);
	nVertexes_++;
}

//Prec: u y v pertenecen al grafo
//Añade un lado al grafo a partir de sus dos vértices y su peso. Esto se reflejará sólo en la matriz de adyacencia
void edi::GraphMatrix::addEdge(const double & data, const Vertex & u, const Vertex & v){
	matrix_[u.getLabel()][v.getLabel()] = data;
	if (!isDirected()){
		matrix_[v.getLabel()][u.getLabel()] = data;
	}
	nEdges_++;
}
		
//Busca un vertice a partir de su data, colocando el cursor en dicho vértice
void edi::GraphMatrix::searchVertex(const std::string &data){
	bool found = false;
	for (unsigned int i = 0 ; !found &&  i < nVertexes_ ; i++){
		if (vertex_[i].getData() == data){
			found = true;
			currentVertex_=&vertex_[i];
		}
	}
	if (!found){
		currentVertex_=NULL;
	}	
}

//Prec: u pertenece al grafo
//Lleva el cursor a un vertice a partir de dicho vertice
void edi::GraphMatrix::goTo(const Vertex & u){
	//assert(pertain());
	int i = 0;
	while (vertex_[i].getData()!=u.getData()&&vertex_[i].getLabel()!=u.getLabel()){
		i++;
	}
	currentVertex_=&vertex_[i];
}

//Prec: 0 <= idx < numVertexes()
//lleva el cursor a un vértice a partir de la posicion de dicho vertice
void edi::GraphMatrix::goTo(const int &idx){
	assert(0<=idx&& (unsigned int)idx<numVertexes());
	currentVertex_=&vertex_[idx];

}

//Prec: u y v pertenecen al grafo
//Lleva el cursor a un lado a partir de sus vertices
void edi::GraphMatrix::searchEdge(const Vertex & u, const Vertex & v){
	edi::Edge *e = new edi::Edge;
	e->setData(matrix_[u.getLabel()][v.getLabel()]); 
	e->setFirst(u);
	e->setSecond(v);
	currentEdge_ = e;
}


//Vertex cursor
//Lleva el cursor al primer vertice
void edi::GraphMatrix::beginVertex(){
	currentVertex_=&vertex_[0];
}

//Avanza el cursor al siguiente vertice
void edi::GraphMatrix::nextVertex(){
	currentVertex_=currentVertex_+1;
}

//Comprueba si el cursor ha sobrepasado su última posicion válida
bool edi::GraphMatrix::afterEndVertex() const{
	return  currentVertex_==&vertex_[nVertexes_];
}

//Edge cursor
//Lleva el cursor al primer lado que sale del vertice u
void edi::GraphMatrix::beginEdge(const Vertex & u){
	//currentEdge_= &vertex_[u.getLabel()];
	edi::Edge *aux = new edi::Edge;

	for (unsigned int i = 0; i < capacity_; i++){
		if (matrix_[u.getLabel()][i]>0 && matrix_[u.getLabel()][i]<std::numeric_limits<float>::infinity()){
			aux->setData(matrix_[u.getLabel()][i]);
			aux->setFirst(u);
			aux->setSecond(vertex_[i]);
			currentEdge_=aux;
			i = capacity_;
		}
	}
}

//Avanza el cursor al siguiente lado que sale de currEdge().first()
void edi::GraphMatrix::nextEdge(){
	bool found = false;
	edi::Edge *e = new edi::Edge;
	for (unsigned int i=currentEdge_->second().getLabel()+1 ; i < capacity_ ; i ++){
		if (matrix_[currentEdge_->first().getLabel()][i]>0 && matrix_[currentEdge_->first().getLabel()][i]<std::numeric_limits<float>::infinity()){
			e->setData(matrix_[currentEdge_->first().getLabel()][i]);
			e->setFirst(currentEdge_->first());
			e->setSecond(vertex_[i]);
			i=capacity_;
			found=true;
		}
	}
	if (found){
		currentEdge_=e;
	}
	else{
		currentEdge_=NULL;
	}
}

//Comprueba si el cursor ha sobrepasado su última posicion válida para los lados que salen de currEdge().first()
bool edi::GraphMatrix::afterEndEdge(){
	return currentEdge_==NULL;
}

bool edi::GraphMatrix::pertain (const Vertex & u){
	for (unsigned int i = 0 ; i < nVertexes_ ; i++){
		if (vertex_[i].getData() == u.getData() && vertex_[i].getLabel() == u.getLabel()){
			return true;
		}
	}
	return true;
}