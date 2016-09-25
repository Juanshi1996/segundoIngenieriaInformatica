// Adaptacion del ejemplo del Libro "Como programar en C++" de Deitel y Deitel
// Fig. 8.14: fig08_14.cpp
// Demostración de la clase vector de la biblioteca estándar.

//

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include <iomanip>

using std::setw;

#include <vector>

using std::vector;

void muestraVector( const vector< int > & );
void introduceVector( vector< int > & );

int main()
{
   vector< int > enteros1( 4 );   // vector de 4 elementos < int >
   vector< int > enteros2( 5 );  // vector de 5 elementos < int >
 
   // imprime el tamaño y el contenido de enteros1
   cout << "El tamanio del vector enteros1 es " 
        << enteros1.size()
        << "\nvector despues de la inicializacion:\n";
   muestraVector( enteros1 );

   // imprime el tamaño y el contenido de enteros2
   cout << "\nEl tamanio del vector enteros2 es " 
        << enteros2.size()
        << "\nvector despues de la inicializacion:\n";
   muestraVector( enteros2 );

   // introduce e imprime enteros1 y enteros2
   cout << "\nIntroduce 9 enteros:\n";
   introduceVector( enteros1 );
   introduceVector( enteros2 );

   cout << "\nDespues de la introduccion, los vectores contienen:\n"
        << "enteros1:\n";
   muestraVector( enteros1 );
   cout << "enteros2:\n";
   muestraVector( enteros2 );

   // utiliza el operador de desigualdad sobrecargado (!=)
   cout << "\nEvaluando: enteros1 != enteros2\n";

   if ( enteros1 != enteros2 )
      cout << "enteros1 y enteros2 no son iguales\n";

   // crea el vector enteros3 utilizando enteros1 como un
   // inicializador; imprime el tamaño y el contenido
   vector< int > enteros3( enteros1 );  // constructor de copia

   cout << "\nEl tamanio del vector enteros3 es "
        << enteros3.size()
        << "\nvector despues de la inicializacion:\n";
   muestraVector( enteros3 );


   // uso del operador de asignación (=) sobrecargado
   cout << "\nAsigna enteros2 a enteros1:\n";
   enteros1 = enteros2;

   cout << "enteros1:\n";
   muestraVector( enteros1 );
   cout << "enteros2:\n";
   muestraVector( enteros1 );

   // uso del operador sobrecargado de igualdad (==)
   cout << "\nEvaluando: enteros1 == enteros2\n";

   if ( enteros1 == enteros2 )
      cout << "enteros1 y enteros2 son iguales\n";

   // uso del operador de subíndices sobrecargado para crear un rvalue
   cout << "\nenteros1[5] es " << enteros1[ 5 ];

   // uso del operador de subíndices sobrecargado para crear un lvalue
   cout << "\n\nAsigna 1000 a enteros1[5]\n";
   enteros1[ 5 ] = 1000;
   cout << "enteros1:\n";
   muestraVector( enteros1 );

   // intento de uso de un subíndice fuera de rango
   cout << " ++++++++++++++++++++++++++++++++++++ " << endl << endl;
   cout << " AHORA SE VA A PRODUCIR UN ERROR " << endl << endl;
   cout << "\nIntenta asignar 1000 a enteros1.at( 15 )"
        << endl;

   // ERROR: fuera de rango
   enteros1.at( 15 ) = 1000;  

   return 0;

} // fin de main

// muestra el contenido del vector
void muestraVector( const vector< int > &arreglo )
{
 // La variable i se ha declarado fuera del "for" 
 // para que sea visible en el resto de la funcion
  int i;

   for ( i = 0; i < arreglo.size(); i++ ) {
      cout << setw( 12 ) << arreglo[ i ];

      if ( ( i + 1 ) % 4 == 0 ) // 4 números por fila de salida
         cout << endl;

   } // fin de for

   if ( i % 4 != 0 )
      cout << endl;

} // fin de la función muestraVector

// introduce el contenido de los vectores
void introduceVector( vector< int > &arreglo )
{
   for ( int i = 0; i < arreglo.size(); i++ )
      cin >> arreglo[ i ];

} // fin de la función introduceVector


