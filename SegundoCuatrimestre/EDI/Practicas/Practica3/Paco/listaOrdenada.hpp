/*!\file asignatura.hpp
   \brief
   \author Francisco José Rodríguez Ramírez
   \date 12-03-2015*/

#ifndef __LISTAORDENADA_HPP__
#define __LISTAORDENADA_HPP__

#include "persona.hpp"
#include "generarpersona.hpp"
#include "nodo.hpp"
#include <fstream>
/*!\namespace edi
   \brief Namespace para la asignatura Estructuras de Datos y de la Información.*/
namespace edi{
  /*!\class ListaOrdenada
     \brief clase abstracta template para el TAD ListaOrdenada.*/
  template <class T>
  class ListaOrdenada{
    /*!\name Atributos privados de la clase ListaOrdenada.*/
    private:
      // No hay

    /*!\name métodos públicos de la clase ListaOrdenada*/
    public:
      /*@}*/
      /*!\name Observadores:@{*/
      /*!\fn virtual bool esUltimo(const int &position) = 0
         \brief ¿Es la posición la última de la lista?
         \arg[in] pos es la posición a evaluar.
         \pre None.
         \post None.
         \return true si la posición dada es la última de la lista*/
      virtual bool esUltimo (const int &pos) = 0;

      /*!\fn virtual bool esValida (const int &pos) = 0
         \brief ¿Es la posición una posición válida?
         \arg[in] pos es la posición a evaluar.
         \pre None.
         \post None.
         \return true si la posición dada es una posición válida.*/
      virtual bool esValida (const int &pos) = 0;

      /*!\fn virtual Nodo <T> const *getNodo (int const &pos) = 0
         \brief Devuelve el nodo de cierta posición
         \arg[in] pos es la posición de la lista.
         \pre esValida(pos)
         \post None.
         \return referencia constante del Nodo.*/
      virtual Nodo <T> const *getNodo (int const &pos) = 0;

      /*!\fn virtual int buscaItem (const T &item, const int &from) = 0
         \brief Busca la posición de un determinado item a partir de una posición dada.
         \arg[in] item es el dato a encontrar.
         \arg[in] from es la posición por la cual se empieza a buscar.
         \pre esValida(from)
         \post returnValue>=0 implica esValida(returnValue)
         \return return -1 si no se ha encontrado la posición del item.*/
      virtual int buscaItem (const T &item, const int &from) = 0;

      /*@}*/
      /*!\name Modificadores:@{*/
      /*!\fn virtual void inserta(const T &item) = 0
         \brief Inserta un item ordenado ascendentemente
         \arg[in] item es el item a insertar.
         \pre None.
      */
      virtual void inserta(const T &item) = 0;

      /*!\fn virtual bool borraPosicion(const int &pos) = 0
         \brief Borra una posición dada.
         \arg[in] pos es la posición que se quiere borrar.
         \pre not vacia()
      */
      virtual bool borraPosicion(const int &pos) = 0;
      /*@}*/
    }; /*!class ListaOrdenada*/
} /*!namespace edi*/

#endif /*!__LISTAORDENADA_HPP__*/
