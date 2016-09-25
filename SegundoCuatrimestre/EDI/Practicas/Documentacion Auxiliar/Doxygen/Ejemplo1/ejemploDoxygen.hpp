/*!
  \file ejemploDoxygen.hpp
  \brief Se representa el TAD lista limitada de elementos genéricos
*/

#ifndef __LISTA_SIMPLE_LIMITADA_HPP__
#define __LISTA_SIMPLE_LIMITADA_HPP__


/*!
   \brief Espacio de nombres para la asignatura Estructura de datos.

*/
namespace ed 
{
  /*!
  \brief Clase para definir una lista limitada de elementos genéricos G.
  
  \brief Define una colección de elementos G organizados de manera secuencial. 
  \brief Cada elemento puede tener un anterior y un siguiente
  
  \brief estaVacia() implica not estaLlena()
  
  \brief estaVacia() implica numeroElementos() == 0
*/

//!  Definición de la plantilla de la clase ListaSimpleLimitada
template<class G>
class ListaSimpleLimitada
{
  public:

	//! \name Constructor

	/*!
		\brief Crea una lista simple limitada vacía 
		\note  Crea una lista vacía con capacidad c
		\param c Número entero que indica la capacidad máxima de la lista
	    	\pre c > 0
	        \post estaVacia()
	    	\post not estaLlena()
		\sa estaVacia, estaLlena
	 */
	
	ListaSimpleLimitada(int c);
	
	//! \name Observadores

	/*!
		\brief Comprueba si la lista está vacía.
	        \return true si la lista está vacía y false si no lo está.
		\sa estaLlena
	*/
	bool estaVacia() const;
	
	/*!
		\brief Comprueba si la lista está llena.
    		\return true si la lista está llena y false si no lo está.
		\post estaLlena() implica numeroItems() == capacidad()
		\post not estallena() implica numeroItems() < capacidad()
		\sa estaVacia
	*/
	bool estaLlena() const;
	
	/*!
		\brief Devuelve el primer item de la lista
		\return el primer item de la lista si no está vacía
		\pre not estaVacia()
	*/
	const G & primerItem() const;


	/*! 
		\brief  Devuelve la capacidad de la lista
		\return capacidad de la lista
		\sa capacidad
	*/

	int capacidad() const;


	/*! 
		\brief  Devuelve el número de items de la lista
		\return devuelve el número de items de la lista
		\post 0 <= retVal <= capacidad()
		\sa capacidad
	*/
	int numeroItems() const;
	
	
	//! \name Modificadores

	/*! 
		\brief Inserta un elemento en la lista.
		\note Inserta un elemento como primero de la lista   
	        \param item elemento a insertar   
		\pre not estaLlena()
		\post not estaVacia().
		\post primerItem() == item
		\post numeroElementos() == old.numeroElementos() + 1
		\sa borraPrimero
	*/
	void insertaPrimero(const G &item);
  

	/*! 
		\brief Borra primer elemento de la lista.
		\note Borra el primer elemento de la lista si no está vacía       
		\pre not estaVacia()
		\post numeroElementos() == old.numeroElementos() - 1
		\pre Ninguna
		\post Ninguna
		\sa insertaPrimero
	*/
	 void borraPrimero();  
	
     //! \name Atributos privados de la clase ListaSimpleLimitada
    private:

};


} //namespace ed

#endif //__LISTA_ORDENADA_HPP__

