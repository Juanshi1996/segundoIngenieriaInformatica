/*!\file asignatura.hpp
   \brief
   \author Francisco José Rodríguez Ramírez
   \date 12-03-2015*/

#ifndef __LISTAORDENADADOBLEMENTEENLAZADA_HPP__
#define __LISTAORDENADADOBLEMENTEENLAZADA_HPP__

#include "listaOrdenada.hpp"
#include "nodo.hpp"
#include <cassert>
#include <cstdlib>
#include <cstdio>

/*!\namespace edi
   \brief Namespace para la asignatura Estructuras de Datos y de la Información.*/
namespace edi{
  /*!\class ListaOrdenadaDoblementeEnlazada
       \brief Implementa una ListaOrdenada<T> como una ListaOrdenadaDoblementeEnlazada.*/
  template <class T>
  class ListaOrdenadaDoblementeEnlazada : public ListaOrdenada <T>{
    /*!\name Private attributes of the class SortedDoublyLinkedList:*/
    private:
      /*!\var Nodo<T> *cabeza_
         \brief Puntero al primer elemento de la lista.*/
      Nodo <T> *cabeza_;

      /*!\var Nodo<T> *actual_
         \brief Puntero al elemento actual de la lista.*/
      Nodo <T> *actual_;

    /*!\name Public functions or class methods of SortedDoublyLinkedList:*/
    public:
      //Nodo<T> const *getCabeza() const {return(cabeza_);}
      Nodo<T> *getCabeza() const {return(cabeza_);}
      Nodo<T> *getCabeza() {return(cabeza_);}
      Nodo<T> const *getActual() const {return(actual_);}
      Nodo<T> *getActual() {return(actual_);}
      void setCabeza (Nodo <T> *cabeza) { cabeza_ = cabeza ;}
      void setActual (Nodo <T> *actual) { actual_ = actual ;}

      /*!\fn virtual bool esUltimo (const int &pos)
         \brief ¿Es la posición la última de la lista?
         \arg[in] pos es la posición a evaluar.
         \pre None.
         \post None.
         \return true si la posición dada es la última de la lista*/
      virtual bool esUltimo (const int &pos) {
        if (esValida (pos)){
          if (actual_->getSiguiente() == NULL) return true;
        }
        return false;
      }

      /*!\fn virtual bool esValida (const int &pos)
         \brief ¿Es la posición una posición válida?
         \arg[in] pos es la posición a evaluar.
         \pre None.
         \post None.
         \return true si la posición dada es una posición válida.*/
      virtual bool esValida (const int &pos) {
        posicion (pos);
        if (actual_ != NULL){
          return true;
        }
        else return false;
      }
      Nodo <T> item (const int &pos){
        //AQUÍ HACER LO DE NDEBUG
      }

      /*!\fn bool vacia() const
         \brief ¿Está vacía la lista?
         \pre None.
         \post None.
         \return true si la lista está vacía.*/
      virtual bool vacia () const {return cabeza_ == NULL;}

      /*!\fn virtual int buscaItem (const T &item, const int &from) = 0
         \brief Busca la posición de un determinado item a partir de una posición dada.
         \arg[in] item es el dato a encontrar.
         \arg[in] from es la posición por la cual se empieza a buscar.
         \pre esValida(from)
         \post returnValue>=0 implica esValida(returnValue)
         \return return -1 si no se ha encontrado la posición del item.*/
      virtual int buscaItem (const T &item, const int &from){
        assert (esValida(from));
        int i = from;
        bool encontrado = false;
        for (posicion(i) ; !encontrado ; i ++){
          if (actual_==NULL){
            return -1;
          }
          if (actual_->getNodo()==item){
            encontrado = true;
          }
          actual_ = actual_->getSiguiente();
        }
        return i;
      }

      /*!\fn virtual Nodo <T> const *getNodo (int const &pos)
         \brief Devuelve el nodo de cierta posición
         \arg[in] pos es la posición de la lista.
         \pre esValida(pos)
         \post None.
         \return referencia constante del Nodo.*/
      virtual Nodo <T> const *getNodo (int const &pos) {
        assert(esValida(pos));
        edi::Nodo<T> *actual = actual_;
        posicion (pos);
        actual_ = actual;
        return(actual_);
      }

      /*@}*/
      /*!\name Modificadores:@{*/
      /*!\fn virtual void inserta(const T &item) = 0
         \brief Inserta un item ordenado ascendentemente
         \arg[in] item es el item a insertar.
         \pre None.
      */
      virtual void inserta(const T &item){
        if (vacia()){
          cabeza_ = new Nodo<T>(NULL, item, NULL);
        }
        else{
          bool add = false;
          for (actual_ = cabeza_ ; actual_->getSiguiente()!=NULL ; actual_=actual_->getSiguiente()){
            if (cabeza_->getNodo()>item && add == false){
              cabeza_->setAnterior(new Nodo <T> (NULL, item, cabeza_));
              cabeza_ = cabeza_->getAnterior();
              add=true;
            }
            else if (item > actual_->getNodo() && actual_->getSiguiente()->getNodo() > item && add == false){
              Nodo <T> *newNodo = new Nodo <T> (actual_, item, actual_->getSiguiente());
              actual_->getSiguiente()->setAnterior(newNodo);
              actual_->setSiguiente(newNodo);
              add=true;
            }
          }
          if (add == false){
            actual_->setSiguiente(new Nodo <T> (actual_, item, NULL));
          }
        }
      }

      /*!\fn virtual bool borraPosicion(const int &pos) = 0
         \brief Borra una posición dada.
         \arg[in] pos es la posición que se quiere borrar.
         \pre not vacia()
      */
      virtual bool borraPosicion(const int &pos){
        if (vacia()==false && esValida(pos)==true){
          if (pos == 1){
            cabeza_=cabeza_->getSiguiente();
            cabeza_->setAnterior(NULL);
          }
          else{
            posicion(pos);
            if (actual_->getSiguiente()==NULL){
              actual_->getAnterior()->setSiguiente(NULL);
            }
            else{
              actual_->getSiguiente()->setAnterior(actual_->getAnterior());
              actual_->getAnterior()->setSiguiente((actual_->getSiguiente()));
            }
          }
          delete(actual_);
          actual_=cabeza_;
          return (true);
        }
        return (false);
      }

      /*!\fn bool posicion (const int &pos)
         \brief Va a la posición pos de la lista
         \pre None.
         \post None.*/
      bool posicion (const int &pos){
        actual_ = cabeza_;
        int i;
        for (i = 1 ; actual_!=NULL && i != pos ; i ++){
          actual_ = actual_->getSiguiente();
        }
        if (i == pos) return true;
        else return false;
      }

      /*@}*/

      /*!\name Constructores:@{*/
      /*!\fn ListaOrdenadaDoblementeEnlazada()
         \brief Crea una nueva ListaOrdenadaDoblementeEnlazada.
         \pre None.
      */
      ListaOrdenadaDoblementeEnlazada(){
        cabeza_=NULL;
        actual_=NULL;
      }
      /*@}*/

  }; /*!\class ListaOrdenadaDoblementeEnlazada*/

} /*!namespace edi*/

#endif /*!__LISTAORDENADADOBLEMENTEENLAZADA_HPP__*/
