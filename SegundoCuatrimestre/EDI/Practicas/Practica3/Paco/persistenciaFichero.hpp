#ifndef __PERSISTENCIAFICHERO_HPP__
#define __PERSISTENCIAFICHERO_HPP_

#include <fstream>
#include "listaOrdenadaDoblementeEnlazada.hpp"
#include "listaOrdenada.hpp"
#include "nodo.hpp"
#include "persona.hpp"
#include "clave.hpp"

template <typename T> bool guardaFichero (const edi::ListaOrdenadaDoblementeEnlazada <T> *list, char *fichero){
  if (!list->vacia()){
    std::ofstream f;
    f.open (fichero, std::ofstream::out | std::ofstream::trunc);
    edi::Nodo <T> *actual = list->getCabeza();
    while (actual!=NULL){
      f<< actual->getNodo();
      actual=actual->getSiguiente();
    }
    f.close();
  }
  else{ std::cout << "La lista está vacía";}
}


template <class T> bool cargaFichero (edi::ListaOrdenadaDoblementeEnlazada <T> *list, char* fichero){
  std::ifstream f;
  f.open (fichero, std::ifstream::in);
  if (f.is_open()){
    T q;
    getchar();
    fflush(stdout);
    f >> q;
    while (!f.eof()){
      list->inserta(q);

      f >> q;
    }
  }
  else{
    std::cout << "cerrado";
  }
}

#endif
