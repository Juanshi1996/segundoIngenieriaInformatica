/*!\file asignatura.hpp
   \brief
   \author Francisco José Rodríguez Ramírez
   \date 12-03-2015*/

#ifndef __NODO_HPP__
#define __NODO_HPP__

/*!\namespace edi
   \brief Namespace para la asignatura Estructuras de Datos y de la Información.*/
namespace edi{
  /*!\class Nodo
     \brief clase abstracta template para el TAD Nodo.*/
  template <class T>
  class Nodo{
    /*!\name Atributos privados de la clase Nodo.*/
    private:
     /*!\var T *anterior_
        \brief Puntero al nodo anterior*/
      Nodo<T> *anterior_;
      /*!\var T nodo_
         \brief Elemento a insertar en la lista*/
      T nodo_;
      /*!\var T *siguiente_
         \brief Puntero al nodo siguiente*/
      Nodo<T> *siguiente_;

      /*!\name Atributos públicos de la clase Nodo.*/
    public:
      /*!\name Observadores:@{*/
      /*!\fn virtual Nodo <T> *getAnterior (void) const
         \brief Devuelve el elemento anterior del nodo.
         \pre None.
         \post None.
         \return un puntero al elemento anterior*/
      virtual Nodo <T> *getAnterior (void) const {return anterior_;}

      /*!\fn T const &getNodo(void) const
         \brief Devuelve el nodo.
         \pre None.
         \post None.
         \return a una referencia constante al nodo.*/
      virtual T getNodo (void) const {return nodo_;}

      /*!\fn virtual Nodo <T> *getSiguiente (void) const
         \brief Devuelve el elemento siguiente del nodo.
         \pre None.
         \post None.
         \return un puntero al elemento siguiente*/
      virtual Nodo <T> *getSiguiente (void) const {return siguiente_;}
      /*@}*/

      /*!\name Modificadores:@{*/
      /*!\fn virtual void setAnterior (Nodo <T> *anterior)
         \brief Introduce un enlace al elemento anterior.
         \arg[in] anterior es una referencia al anterior nodo.
         \pre None.
         \post None.*/
      virtual void setAnterior (Nodo <T> *anterior) {anterior_ = anterior;}

      /*!\fn virtual void setNodo (const T &Nodo)
         \brief Introduce un nodo
         \arg[in] Nodo es el nodo que se va a guardar.
         \pre None.
         \post None.*/
      virtual void setNodo (const T &Nodo) {nodo_ = Nodo;}

      /*!\fn virtual void setSiguiente (Nodo <T> *siguiente)
         \brief Introduce un enlace al elemento siguiente.
         \arg[in] siguiente es una referencia al siguiente nodo.
         \pre None.
         \post None.*/
      virtual void setSiguiente (Nodo <T> *siguiente) {siguiente_ = siguiente;}

      /*!\name Constructores:@{*/
      /*!\fn Nodo(Nodo <T> *anterior, const T &nodo, Nodo <T> *siguiente)
         \brief Crea un nodo para introducirlo en la lista
         \arg[in] Puntero al nodo anterior.
         \arg[in] Elemento a insertar en la lista.
         \arg[in] Puntero al nodo siguiente.
         \pre None.
         \post None.*/
      Nodo(Nodo <T> *anterior, const T &nodo, Nodo <T> *siguiente){
        anterior_=anterior;
        nodo_=nodo;
        siguiente_=siguiente;
      }

      Nodo(){};

      /*@}*/
      /*!\name Destructores:@{*/
      /*!\fn ~Nodo()
         \brief Destruye un nodo.
         \pre None.
         \post None.*/
      virtual ~Nodo(){}
      /*@}*/
  };  /*!class Nodo*/
} /*!namespace edi*/


#endif  /*!__NODO_HPP__*/
