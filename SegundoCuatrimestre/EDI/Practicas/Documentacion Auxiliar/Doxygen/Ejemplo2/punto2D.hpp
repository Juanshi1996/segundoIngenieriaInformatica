/*! 
  \file punto2D.hpp
  \brief Punto2D representa la clase punto del plano euclídeo definida mediante plantilla (template)
  \author Nombre y apellidos
  \date
*/

#ifndef _PUNTO2D_HPP_
#define _PUNTO2D_HPP_

// Facilita la entrada y salida 
#include <iostream>

using std::ostream;
using std::istream;


/*!
   \brief Espacio de nombres para la asignatura de Estructura de datos.

*/
namespace ed {

//!  Definición de la plantilla de la clase Punto2D
template < class T > 
class Punto2D 
{
  //! \name Atributos privados de la clase Punto2D
   private: 
      	T _x; //!< abscisa del Punto2D 
	T _y; //!< ordenada del Punto2D 


   //! \name Funciones o métodos públicos de la clase Punto2D
   public:

	//! \name Constructores de la clase Punto2D
	/*! 
		\brief Constructor que crea un Punto2D a partir de sus coordenadas x e y
		\attention Función sobrecargada        
	 	\note Los parámetros tienen valores por defecto
		\param x de tipo T, valor por defecto 0
		\param y de tipo T, valor por defecto 0
		\pre Ninguna
		\post Ninguna
		\sa setX(), setY()
	*/
	inline Punto2D(T x=0, T y=0)
	{
		// SE HA DE COMPLETAR EL CÓDIGO

	}

	/*! 
		\brief Constructor de "copia" que crea un Punto2D a partir de otro Punto2D
		\attention Función sobrecargada        
		\param q de tipo Punto2D pasado como referencia constante
		\pre El Punto2D q debe existir
		\post Ninguna
		\sa getX(), getY(), setX(), setY()
	*/
	inline Punto2D(Punto2D const &q)
	{
		// SE HA DE COMPLETAR EL CÓDIGO
	}

	//! \name Funciones de consulta de Punto2D

	/*! 
		\brief Devuelve la coordenadas "x" de un Punto2D
		\return componente "x" del Punto2D (tipo T)
		\pre El Punto2D debe existir
		\post Ninguna
		\sa getY()
	*/
	inline T getX()const
	{
		// SE HA DE COMPLETAR ESTE CÓDIGO
	}
	/*! 
		\brief Devuelve la coordenadas "y" de un Punto2D
		\return componente "y" del Punto2D (tipo T)
		\pre El Punto2D debe existir
		\post Ninguna
		\sa getX()
	*/
	inline T getY()const
	{
		// SE HA DE COMPLETAR EL CÓDIGO

	}


	//! \name Funciones de modificación de Punto2D

	/*! 
		\brief Asigna un valor "v" a la coordenada "x" de un Punto2D
		\param v de tipo T
		\pre El Punto2D debe existir
		\post Ninguna
		\sa setY()
	*/
	inline void setX(T v)
	{
		// SE HA DE COMPLETAR EL CÓDIGO
	}


	/*! 
		\brief Asigna un valor "v" a la coordenada "y" de un Punto2D
		\param v de tipo T
		\pre El Punto2D debe existir
		\post Ninguna
		\sa setX()
	*/
	inline void setY(T v)
	{
		// SE HA DE COMPLETAR EL CÓDIGO
	}


         //! \name Operadores
   
	/*! 
		\brief Operador que "copia" un Punto2D en otro Punto2D
		\attention Se sobrecarga el operador de asignación "="
		\param q de tipo Punto2D pasado como referencia constante
		\pre El Punto2D q debe existir
		\post Ninguna
		\sa getX(), getY(), setX(), setY()
	*/
	inline Punto2D & operator=(Punto2D const &q)
	{
		setX(q.getX());
		setY(q.getY());

		return *this;
	}

	//! \name Funciones lectura y escritura de la clase Punto2D

	/*! 
		\brief Asigna a un Punto2D las coordenadas "x" e "y" leídas desde el teclado
		\pre El Punto2D debe existir
		\post Ninguna
		\warning Se deben teclear números entero
		\sa setX(), setY()
	*/
	void leerPunto2D();


	/*! 
		\brief Escribe por pantalla las coordenadas de un Punto2D de la forma (x,y)
		\pre El Punto2D debe tener valores asignados a sus coordenadas
		\post Ninguna
		\sa getX(), getY()
	*/
	void escribirPunto2D();
  
}; // Fin de la definición de la clase Punto2D


} // \brief Fin de namespace ed

//////////////////////////////////////////////////////////////////////////////////////

// MODELO DE COMPILACION POR INCLUSION

#include "punto2D.cpp"

///////////////////////////////////////////////////////////////////////////////////////////


//  _PUNTO2D_HPP_
#endif 
