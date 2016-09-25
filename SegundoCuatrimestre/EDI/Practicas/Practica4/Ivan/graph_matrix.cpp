#include "graph_matrix.hpp"

using namespace edi;

GraphMatrix::GraphMatrix (const unsigned int & capacity, const bool & isDirected){
  int i, j;
  capacity_ = capacity;
  weightsMatrix_ = (double**) malloc(capacity_*sizeof(double*));
  for(i=0; i<capacity_; i++){
    weightsMatrix_[i] = (double*) malloc(capacity_*sizeof(double));
  }
  for(i=0; i<capacity_; i++){
    for(j=0; j<capacity_; j++){
      weightsMatrix_[i][j] = (i == j) ? 0 : std::numeric_limits<double>::infinity();
    }
  }
  isDirected_ = isDirected;
  vertexCursor_ = NULL;
  edgeCursor_ = NULL;
  vertexesNum_ = 0;
  edgesNum_ = 0;
}

const unsigned int& GraphMatrix::numVertexes()const{
  return (vertexesNum_);
}

const unsigned int& GraphMatrix::numEdges()const{
  return (edgesNum_);
}

const unsigned int& GraphMatrix::capacity()const{
  return (capacity_);
}

bool GraphMatrix::isEmpty() const{
  return vertexes_.empty();
}

const bool& GraphMatrix::isDirected() const{
  return isDirected_;
}

//Devuelve el elemento de la matriz de adyacencia (INFINITO si no hay lado)
const float GraphMatrix::adjacent(const Vertex & u, const Vertex & v) const{
  return (weightsMatrix_[u.getLabel()][v.getLabel()]);
}

//Está el cursor de vértices posición válida
bool GraphMatrix::hasCurrVertex() const{
  return (vertexCursor_ != NULL);
}

//Pre: hasCurrVertex() is true.
//Devuelve el vértice referenciado por cursor de vértices
const Vertex & GraphMatrix::currVertex() const{
  assert(hasCurrVertex());
  return (*vertexCursor_);
}

bool GraphMatrix::hasCurrEdge() const{
  return (edgeCursor_ != NULL);
}

//Pre: rEdge() is true
//Devuelve el lado referenciado por cursor de lados
const Edge GraphMatrix::currEdge(){
  assert(hasCurrEdge());
  return (*edgeCursor_);
}

//Modifiers

//Crea un grafo dirigido
void GraphMatrix::makeDirected(){
  isDirected_ = true;
}

			//Crea un grafo no dirigido
void GraphMatrix::makeUndirected(){
  isDirected_ = false;
}

//Prec: numVertexes() < capacity()
//Añade un vertice al grafo a partir del data
void GraphMatrix::addVertex(const std::string & data){
  assert(numVertexes() < capacity());
  Vertex vertexAux;
  vertexAux.setData(data);
  vertexAux.setLabel(vertexesNum_);
  vertexes_.push_back(vertexAux);
  vertexesNum_++;
}

//Prec: u y v pertenecen al grafo
//Añade un lado al grafo a partir de sus dos vértices y su peso. Esto se reflejará sólo en la matriz de adyacencia
void GraphMatrix::addEdge(const double & data, const Vertex & u, const Vertex & v){
  #ifndef NDEBUG
  goTo(u);
  goTo(v);
  #endif
  weightsMatrix_[u.getLabel()][v.getLabel()] = data;
  if(!(isDirected())){
    weightsMatrix_[v.getLabel()][u.getLabel()] = data;
  }
  edgesNum_++;
}

//Busca un vertice a partir de su data, colocando el cursor en dicho vértice
void GraphMatrix::searchVertex(const std::string &data){
  int i;
  bool found = false;
  for(i=0; i<vertexesNum_; i++){
    if(vertexes_[i].getData() == data){
      vertexCursor_ = &vertexes_[i];
      found = true;
    }
  }

  if(!found){
    vertexCursor_ = NULL;
  }
}

//Prec: u pertenece al grafo
//Lleva el cursor a un vertice a partir de dicho vertice
void GraphMatrix::goTo(const Vertex & u){
  #ifndef NDEBUG
  searchVertex(u.getData());
  assert(hasCurrVertex());
  #endif
  int i;
  for(i=0; i<vertexesNum_; i++){
    if(vertexes_[i] == u){
      vertexCursor_ = &vertexes_[i];
      break;
    }
  }
}

//Prec: 0 <= idx < numVertexes()
//lleva el cursor a un vértice a partir de la posicion de dicho vertice
void GraphMatrix::goTo(const int &idx){
  assert(0 <= idx < numVertexes());
  vertexCursor_ = &vertexes_[idx];
}

//Prec: u y v pertenecen al grafo
//Lleva el cursor a un lado a partir de sus vertices
void GraphMatrix::searchEdge(const Vertex & u, const Vertex & v){
  #ifndef DNDEBUG
  goTo(u);
  goTo(v);
  #endif

  Edge* edgeAux = new Edge;
  edgeAux->setFirst(u);
  edgeAux->setSecond(v);
  edgeAux->setData(weightsMatrix_[u.getLabel()][v.getLabel()]);

  edgeCursor_ = edgeAux;
}


//Vertex cursor
//Lleva el cursor al primer vertice
void GraphMatrix::beginVertex(){
  vertexCursor_ = &vertexes_[0];
}

//Avanza el cursor al siguiente vertice
void GraphMatrix::nextVertex(){
  vertexCursor_ = &vertexes_[vertexCursor_->getLabel()+1];
}

//Comprueba si el cursor ha sobrepasado su última posicion válida
bool GraphMatrix::afterEndVertex() const{
  return (vertexCursor_ == &vertexes_[vertexesNum_]);
}

//Edge cursor
//Lleva el cursor al primer lado que sale del vertice u
void GraphMatrix::beginEdge(const Vertex & u){
  int i;
  Vertex* vertexAux = vertexCursor_;
  bool found = false;
  Edge* edgeAux = new Edge;
  for(i=0; i<vertexesNum_ && !found; i++){
    if(weightsMatrix_[u.getLabel()][i] != std::numeric_limits<double>::infinity() && i != u.getLabel()){
      edgeAux->setFirst(u);
      goTo(i);
      edgeAux->setSecond(*vertexCursor_);
      edgeAux->setData(weightsMatrix_[u.getLabel()][i]);
      found = true;
    }
  }
  vertexCursor_ = vertexAux;
  edgeCursor_ = found ? edgeAux : NULL;
}

//Avanza el cursor al siguiente lado que sale de currEdge().first()
void GraphMatrix::nextEdge(){
  int i;
  bool found = false;
  Vertex* vertexAux = vertexCursor_;
  Edge* edgeAux = new Edge;
  for(i=currEdge().second().getLabel()+1; i<vertexesNum_ && !found; i++){
    if(weightsMatrix_[currEdge().first().getLabel()][i] != std::numeric_limits<double>::infinity()
       && i != currEdge().first().getLabel()){
      edgeAux->setFirst(currEdge().first());
      goTo(i);
      edgeAux->setSecond(*vertexCursor_);
      edgeAux->setData(weightsMatrix_[currEdge().first().getLabel()][i]);
      found = true;
    }
  }
  vertexCursor_ = vertexAux;
  edgeCursor_ = found ? edgeAux : NULL;
}

//Comprueba si el cursor ha sobrepasado su última posicion válida para los lados que salen de currEdge().first()
bool GraphMatrix::afterEndEdge(){
  return (edgeCursor_ == NULL);
}
