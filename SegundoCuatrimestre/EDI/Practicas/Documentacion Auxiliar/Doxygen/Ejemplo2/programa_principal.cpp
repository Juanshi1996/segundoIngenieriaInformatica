/*! 
  \file programa_principal.cpp
  \brief Programa para usar el tipo de dato Punto2D
*/

/*!
	\mainpage Plantillas de clases y funciones
	\author Profesor de prácticas de la asignatura de Estructuras de datos
	\date 16 de febrero de 2015
*/


// Ficheros de cabecera
#include <iostream>
#include <string>

#include "punto2D.hpp"
#include "distancias2D.hpp"


// Espacio de nombres para la entrada y salida de datos
using namespace std;

// ed Espacio de nombres de la asignatura de Programación Orientada a Objetos
using namespace ed;

//! Programa principial que muestra el uso de la clase Punto2D 
int main(void)
{
 // Variable para obtener el resultado de las distancias
 float d;

 cout << " Uso de la plantilla para declarar puntos de tipo int" << endl;

 // Definición de puntos de tipo int
 Punto2D<int> p1, p2;

 cout << "Valores por defecto de los puntos enteros " << endl;

 p1.escribirPunto2D();
 p2.escribirPunto2D();

 cout << "Lectura de las coordenadas de los puntos enteros" << endl << endl;
 p1.leerPunto2D();
 p2.leerPunto2D();

 cout << "Nuevos valores de los puntos enteros " << endl;

 p1.escribirPunto2D();
 p2.escribirPunto2D();
 cout << endl; 
 
 cout << endl; 

 // 

 d = calcularDistanciaEuclidea2D(p1.getX(),p1.getY(),p2.getX(),p2.getY()); 
 cout << "Distancia euclidea --> " << d << endl;

 d = calcularDistanciaManhattan2D(p1.getX(),p1.getY(),p2.getX(),p2.getY()); 
 cout << "Distancia de Manhattan --> " << d << endl;

 d = calcularDistanciaAjedrez2D(p1.getX(),p1.getY(),p2.getX(),p2.getY()); 
 cout << "Distancia de ajedrez --> " << d << endl;

 cout << endl;


///////////////////////////////////////////////////////////////////////////

  cout << " ****************************************************" << endl << endl;

  cout << " Uso de la plantilla para declarar puntos de tipo float" << endl;

  // Se indica que se muestre el punto decimal
  cout << fixed;
  // Se indica que se muestren 2 cifras decimales
  cout.precision(2);

 // Definición de puntos de tipo float 

 Punto2D<float> p3, p4;


 cout << "Valores por defecto de los puntos reales " << endl;

 p3.escribirPunto2D();
 p4.escribirPunto2D();
 cout << endl; 
 
 cout << "Lectura de las coordenadas de los puntos reales" << endl;
 p3.leerPunto2D();
 p4.leerPunto2D();

 cout << "Nuevos valores de los puntos reales " << endl;

 p3.escribirPunto2D();
 p4.escribirPunto2D();
 cout << endl; 
 
 d = calcularDistanciaEuclidea2D(p3.getX(),p3.getY(),p4.getX(),p4.getY()); 
 cout << "Distancia euclidea --> " << d << endl;

 d = calcularDistanciaManhattan2D(p3.getX(),p3.getY(),p4.getX(),p4.getY()); 
 cout << "Distancia de Manhattan --> " << d << endl;

 d = calcularDistanciaAjedrez2D(p3.getX(),p3.getY(),p4.getX(),p4.getY());  
 cout << "Distancia de ajedrez --> " << d << endl;

 cout << endl << endl;

// Fin del programa

 return 0;
}




