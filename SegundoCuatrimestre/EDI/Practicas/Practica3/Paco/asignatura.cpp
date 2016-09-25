#include <iostream>
#include <fstream>

#include "listaOrdenadaDoblementeEnlazada.hpp"
#include "nodo.hpp"
#include "persona.hpp"
#include "asignatura.hpp"

namespace edi{
  std::ofstream &operator<<(std::ofstream &out, const edi::Asignatura &asignatura){
    edi::Nodo <edi::Persona> *personaActual;
    for (personaActual = asignatura.getAsignatura().getCabeza() ; personaActual!=NULL ; personaActual=personaActual->getSiguiente()){
      out << personaActual->getNodo().nombre() << " " << personaActual->getNodo().apellido() << " " << personaActual->getNodo().dni() << std::endl;
    }
  };

/*  std::ifstream &operator<<(std::ifstream &out, edi::Asignatura &asignatura){
    std::ofstream *out;
    //fichero.close();
    edi::Nodo <edi::Persona> *personaActual;
    for (personaActual = asignatura.getAsignatura().getCabeza() ; personaActual!=NULL ; personaActual=personaActual->getSiguiente()){
//out << personaActual->getNodo().nombre() << " " << personaActual->getNodo().apellido() << " " << personaActual->getNodo().dni() << std::endl;
    }
  };*/

}
