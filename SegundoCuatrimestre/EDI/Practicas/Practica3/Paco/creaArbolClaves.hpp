#ifndef __CREAARBOLCLAVES_HPP__
#define __CREAARBOLCLAVES_HPP__

#include "edi_LinkedBinaryTree.hpp"
#include "edi_OrderedBinaryTree.hpp"
#include "edi_BinaryTree.hpp"
#include "edi_LinkedOrderedBinaryTree.hpp"
#include "edi_OrderedBinaryTree.hpp"
#include "edi_exports.hpp"
#include "clave.hpp"
#include "nodo.hpp"
#include "listaOrdenadaDoblementeEnlazada.hpp"
#include <fstream>

void crearArbol (edi::ListaOrdenadaDoblementeEnlazada <edi::Persona> list,
                 edi::LinkedOrderedBinaryTree <edi::Clave> *arbol){
  edi::Nodo <edi::Persona> *personaActual;
  edi::Clave claveActual;
  int i=0;
  for (personaActual = list.getCabeza() ; personaActual!=NULL ; personaActual=personaActual->getSiguiente()){
    claveActual.numero(i);
    claveActual.dni(personaActual->getNodo().dni());
    arbol->insert(claveActual);
    //std::cout << claveActual.numero()<<std::endl;
    //std::cout << claveActual.dni()<<std::endl;
    i++;
  }
}


/*void crearArbol (edi::ListaOrdenadaDoblementeEnlazada <edi::Persona> list,
                 edi::BinaryTree <edi::Clave> *arbol){
  edi::Nodo <edi::Persona> *personaActual;
  edi::Clave claveActual;
  int i=0;
  for (personaActual = list.getCabeza() ; personaActual!=NULL ; personaActual=personaActual->getSiguiente()){
    claveActual.numero(i);
    claveActual.dni(personaActual->getNodo().dni());
    //arbol->insert(claveActual);
    i++;
  }
}*/

/*namespace edi{

   std::ofstream &operator<< (std::ofstream& out, const LinkedOrderedBinaryTree<Clave>* t)
   {
     out << t->item().numero() << " " << t->item().dni() << std::endl;
     return out;
  };
}*/


/*edi::LinkedOrderedBinaryTree <edi::Clave> crearArbol (edi::ListaOrdenadaDoblementeEnlazada <edi::Persona> list, edi::LinkedOrderedBinaryTree <edi::Clave> arbol){
      return (arbol);
}*/

#endif
