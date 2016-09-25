#include "graph_matrix.hpp"

edi::GraphMatrix::GraphMatrix(const unsigned int& capacity, const bool& isDirected) {
  _capacity = capacity;
  _isDirected = isDirected;
  _currVertex = NULL;
  _currEdge = NULL;
  _numVertexes = 0;
  _numEdges = 0;
  _weights = (float**) malloc(_capacity * sizeof(float*));
  for (size_t i = 0; i < _capacity; i++) {
    _weights[i] = (float*) malloc(_capacity * sizeof(float));
  }
  for(size_t r = 0; r < _capacity; r++) {
    for(size_t c = 0; c < _capacity; c++) {
      if(r == c) {
        _weights[r][c] = 0;
      } else {
        _weights[r][c] = std::numeric_limits<float>::infinity();
      }
    }
  }
}

/*edi::GraphMatrix::~GraphMatrix() {
  for(size_t i = 0; i < _numVertexes; i++) {
    delete _weights[i];
  }
  delete _weights;
}*/

const unsigned int& edi::GraphMatrix::numVertexes() const {
  return(_numVertexes);
}

const unsigned int& edi::GraphMatrix::numEdges() const {
  return(_numEdges);
}

const unsigned int& edi::GraphMatrix::capacity() const {
  return(_capacity);
}

bool edi::GraphMatrix::isEmpty() const {
  return(_vertexes.empty());
}

bool edi::GraphMatrix::isDirected() const {
  return(_isDirected);
}

const float& edi::GraphMatrix::adjacent(const edi::Vertex& u, const edi::Vertex& v) const {
  return((const float&) _weights[u.getLabel()][v.getLabel()]);
}

bool edi::GraphMatrix::hasCurrVertex() const {
  return(_currVertex != NULL);
}

const edi::Vertex & edi::GraphMatrix::currVertex() const {
  assert(hasCurrVertex());
  return(* _currVertex);
}

bool edi::GraphMatrix::hasCurrEdge() const {
  return(_currEdge != NULL);
}

const edi::Edge edi::GraphMatrix::currEdge() {
  assert(hasCurrEdge());
  return(* _currEdge);
}

void edi::GraphMatrix::makeDirected() {
  _isDirected = true;
}

void edi::GraphMatrix::makeUndirected() {
  _isDirected = false;
}

void edi::GraphMatrix::addVertex(const std::string& data) {
  assert(_numVertexes < _capacity);
  Vertex v;
  v.setData(data);
  v.setLabel(_numVertexes);
  _vertexes.push_back(v);
  _numVertexes++;
}

void edi::GraphMatrix::addEdge(const float& data, const edi::Vertex& u, const edi::Vertex& v) {
  #ifndef NDEBUG
    Vertex* savedCurr = _currVertex;
    goTo(u);
    goTo(v);
    _currVertex = savedCurr;
  #endif
  _weights[u.getLabel()][v.getLabel()] = data;
  if(!isDirected()) {
    _weights[v.getLabel()][u.getLabel()] = data;
  }
  _numEdges++;
}

void edi::GraphMatrix::searchVertex(const std::string& data) {
  bool found = false;
  for(size_t i = 0; i < _numVertexes and not found; i++) {
    if(data == _vertexes[i].getData()) {
      found = true;
      _currVertex = & _vertexes[i];
    }
  }
  if(!found) {
    _currVertex = NULL;
  }
}

void edi::GraphMatrix::goTo(const edi::Vertex& u) {
  #ifndef NDEBUG
    Vertex* savedCurr = _currVertex;
    searchVertex(u.getData());
    assert(hasCurrVertex());
    assert(_currVertex->getLabel() == u.getLabel());
    _currVertex = savedCurr;
  #endif
  for(size_t i = 0; i < _numVertexes; i++) {
    if(u == _vertexes[i]) {
      _currVertex = & _vertexes[i];
    }
  }
}

void edi::GraphMatrix::goTo(const unsigned int& idx) {
  assert(idx < _numVertexes);
  _currVertex = & _vertexes[idx];
}

void edi::GraphMatrix::searchEdge(const edi::Vertex& u, const edi::Vertex& v) {
  #ifndef NDEBUG
    Vertex* savedCurr = _currVertex;
    goTo(u);
    goTo(v);
    _currVertex = savedCurr;
  #endif
  Edge* e = new Edge;
  e->setData(_weights[u.getLabel()][v.getLabel()]);
  e->setFirst(u);
  e->setSecond(v);
  _currEdge = e;
}

void edi::GraphMatrix::beginVertex() {
  _currVertex = & _vertexes[0];
}

void edi::GraphMatrix::nextVertex() {
  _currVertex = & _vertexes[_currVertex->getLabel()+1];
}

bool edi::GraphMatrix::afterEndVertex() const {
  return(_currVertex == &_vertexes[_numVertexes]);
}

void edi::GraphMatrix::beginEdge(const edi::Vertex& u) {
  bool found = false;
  Edge* e = new Edge;
  for(size_t i = 0; i < _numVertexes and not found; i++) {
    if(i != u.getLabel() and _weights[u.getLabel()][i] != std::numeric_limits<float>::infinity()) {
      found = true;
      e->setData(_weights[u.getLabel()][i]);
      e->setFirst(u);
      e->setSecond(_vertexes[i]);
    }
  }
  if(found) {
    _currEdge = e;
  } else {
    _currEdge = NULL;
  }
}

void edi::GraphMatrix::nextEdge() {
  bool found = false;
  Edge* e = new Edge;
  for(size_t i = _currEdge->second().getLabel()+1; i < _numVertexes; i++) {
    if(i != _currEdge->first().getLabel() and _weights[_currEdge->first().getLabel()][i] != std::numeric_limits<float>::infinity() and not found) {
      found = true;
      e->setData(_weights[_currEdge->first().getLabel()][i]);
      e->setFirst(_currEdge->first());
      e->setSecond(_vertexes[i]);
    }
  }
  if(found) {
    _currEdge = e;
  } else {
    _currEdge = NULL;
  }
}

bool edi::GraphMatrix::afterEndEdge() {
  return(_currEdge == NULL);
}
