/*!\file asignatura.hpp
   \brief
   \author Francisco José Rodríguez Ramírez
   \date 12-03-2015*/

#ifndef __ASIGNATURA_HPP__
#define __ASIGNATURA_HPP__

#include "persona.hpp"
#include "listaOrdenadaDoblementeEnlazada.hpp"
#include <vector>
#include <fstream>

/*!\namespace edi
   \brief Namespace para la asignatura Estructuras de Datos y de la Información.*/
namespace edi{
  /*!\class Asignatura
     \brief Implementa una asignatura como una ListaOrdenadaDoblementeEnlazada <Persona>.*/
  class Asignatura{
    /*!\name Atributos privados de la clase Asignatura.*/
    private:
      /*!\var ListaOrdenadaDoblementeEnlazada <Persona> estudiante_;
         \brief Lista ordenada doblemente enlazada de personas.*/
      ListaOrdenadaDoblementeEnlazada <Persona> estudiante_;
    /*!\name métodos públicos de la clase Asignatura*/
    public:

      friend std::ofstream &operator<<(std::ofstream &out, const edi::Asignatura &asignatura);


      ListaOrdenadaDoblementeEnlazada <Persona> getAsignatura()const{return estudiante_;}

      void setAsignatura(ListaOrdenadaDoblementeEnlazada<Persona> estudiante){estudiante_=estudiante;}

      edi::Persona posicion (const int &pos){
        estudiante_.setActual(estudiante_.getCabeza());
        int i;
        for (i = 0 ; estudiante_.getActual()!=NULL && i != pos ; i ++){
          estudiante_.setActual(estudiante_.getActual()->getSiguiente());
        }
        if (i == pos){
          return estudiante_.getActual()->getNodo();
        }
      }

      void crearAsignatura (const int &n){
        std::vector <Persona> vec;
        char fich[] = "personas.txt";
        vec = generarPersonas(fich, n);
        for (int i = 0 ; i < vec.size();i++){
          estudiante_.inserta(vec[i]);
        }
      }
    /*@}*/
    /*!\name Observadores:@{*/
    /*!\fn void mostrarListOrdenadoAsc ()
       \brief Muestra a los alumnos de la lista de manera ordenada ascendentemente
       \pre None.
       \post None.*/
    void mostrarListOrdenadoAsc (){
      Nodo <Persona> *actual = estudiante_.getCabeza();
      for (; actual!= NULL ;){
        std::cout << actual->getNodo();
        actual=actual->getSiguiente();
      }
    }
    /*!\fn void mostrarListOrdenadoDesc ()
       \brief Muestra a los alumnos de la lista de manera ordenada descendentemente
       \pre None.
       \post None.*/
    void mostrarListOrdenadoDesc (){
      Nodo <Persona> *actual = estudiante_.getCabeza();
      for (; actual->getSiguiente()!= NULL ;){
        actual=actual->getSiguiente();
      }
      for (;actual!=NULL;){
        std::cout << actual->getNodo();
        actual=actual->getAnterior();
      }
    }
    /*!\fn void mostrarAlumnosEntreOtrosDosOrdenadoAsc (const Persona &p1, const Persona &p2)
       \brief Muestra a los alumnos de la lista que se encuentran entre otros dos de manera ordenada ascendentemente.
       \arg[in] p1 es el primer estudiante.
       \arg[in] p2 es el segundo estudiante.
       \pre None.
       \post None.*/
    void mostrarAlumnosEntreOtrosDosOrdenadoAsc (const Persona &p1, const Persona &p2){
      if (p1 < p2){
         for(size_t i = estudiante_.buscaItem(p1, 1); i < estudiante_.buscaItem(p2, i-1)-1; i++) {
           std::cout << estudiante_.getNodo(i)->getNodo();
         }
       }
      else if (p1 > p2){
        for(size_t i = estudiante_.buscaItem(p2, 1); i < estudiante_.buscaItem(p1, i-1)-1; i++) {
          std::cout << estudiante_.getNodo(i)->getNodo();
        }
      }
    }
    /*!\fn void mostrarAlumnosEntreOtrosDosOrdenadoDesc (const Persona &p1, const Persona &p2)
       \brief Muestra a los alumnos de la lista que se encuentran entre otros dos de manera ordenada descendentemente.
       \arg[in] p1 es el primer estudiante.
       \arg[in] p2 es el segundo estudiante.
       \pre None.
       \post None.*/
    void mostrarAlumnosEntreOtrosDosOrdenadoDesc (const Persona &p1, const Persona &p2){
      if (p1 < p2){
        for(int i = estudiante_.buscaItem(p2, 1)-2; i > estudiante_.buscaItem(p1, 1)-1; i--) {
          std::cout << estudiante_.getNodo(i)->getNodo();
        }
      }
      else if (p1 > p2){
        for(size_t i = estudiante_.buscaItem(p1, 1)-2; i < estudiante_.buscaItem(p2, i)-1; i--) {
          std::cout << estudiante_.getNodo(i)->getNodo();
        }
      }
    }
    /*@}*/
    /*!\name modificadores:@{*/
    /*!\fn void modificarDatos (const Persona &p)
       \brief Modifica la información de un estudiante
       \arg[in] p es el estudiante que se va a modificar.
       \pre None.
       \post None.*/
    void modificarDatos (const Persona &p){
      int ex;
      if ((ex = (estudiante_.buscaItem (p, 1))) == -1){
        std::cout << "La persona no existe." << std::endl;
      }
      else{
        char n[30], ap[30];
        int dni;

        system ("clear");
        std::cout << "Introduzca los nuevos datos para " << p << std::endl;
        std::cout << "  Nombre: ";
        std::cin  >> n;
        std::cout << "  Apellido: ";
        std::cin  >> ap;
        std::cout << "  DNI \E[33m(Sin letra):\e[0m ";
        std::cin  >> dni;
        getchar();
        estudiante_.borraPosicion(ex-1);
        Persona q(n,ap,dni);
        estudiante_.inserta(q);
      }
    }
    /*!\name constructores:
    @{*/
    /*!\fn Asignatura ()
       \brief Construye una nueva asignatura.
       \pre None.
       \post None.*/
    Asignatura (){}

    /*@}*/
    /*!\name destructores:@{*/
    /*!\fn ~Asignatura()
       \brief Destruye una asignatura.
       \pre None.
       \post None.*/
      ~Asignatura() {}

  }; /*!\class Asignatura*/
} /*!namespace edi*/
#endif /*!__ASIGNATURA_HPP__*/
