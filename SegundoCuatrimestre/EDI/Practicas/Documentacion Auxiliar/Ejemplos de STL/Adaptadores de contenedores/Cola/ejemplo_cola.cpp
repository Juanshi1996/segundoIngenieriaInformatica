///////////////////////////////
///
///  ejemplo_cola.cpp
///
////////////////////////////////


/// Ejemplo del libro de Deytel y Deytel 
/// C++ Cómo programar

// Fig. 21.24: fig21_24.cpp
// Programa de prueba para el adaptador queue de la Biblioteca estándar.
#include <iostream>

using std::cout;
using std::endl;

// definición del adaptador queue
#include <queue>  

int main()
{
   std::queue< double > valores;
   
   // meter elementos en la cola valores
   valores.push( 3.2 );
   valores.push( 9.8 );
   valores.push( 5.4 );

   cout << "Sacando de valores: ";
   
   while ( !valores.empty() )
     {
      // ver elemento inicial
      cout << valores.front() << ' ';  
      
      // eliminar elemento
      valores.pop();                    

   } // fin de instrucción while

   cout << endl;

   return 0;

} // fin de main

