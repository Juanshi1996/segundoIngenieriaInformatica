/***** ARCHIVO principal_texto.cpp *****/

//Ejemplo simple de ficheros texto

#include <iostream>

//Para los flujos de entrada/salida en ficheros.
#include <fstream>  
#include <string>

//Para usar exit.
#include <stdlib.h> 

using namespace std;

int main()
{
  string nombre, apellido;
  int edad;
  string nombreFichero;

  cout << "Nombre del fichero de datos: ";
  cin >> nombreFichero;
   
  //Se declara el flujo de salida.
  ofstream ficheroSalida;

  //Se abre el fichero para escribir.
  ficheroSalida.open(nombreFichero.c_str(), ios::out); 

  if (!ficheroSalida)
  {
    cout << "Error al abrir el fichero\n";
    exit(1);
  }

  for(;;)
  {
    cout << "Edad (-1 para terminar): ";
    cin >> edad;
    
    if (edad == -1)
      break;
    
    cout << "Nombre: ";
    cin >> nombre;
    cout << "Apellido: ";
    cin >> apellido;
    
    ficheroSalida << nombre << " " << apellido << " " << edad << endl;
   }
   
   //Cerramos el fichero.
   ficheroSalida.close();

   //Declaracion flujo de entrada.
   ifstream ficheroEntrada; 

   //Se abre el fichero para leer.
   ficheroEntrada.open(nombreFichero.c_str(), ios::in); 

   if (!ficheroEntrada)
   {
    cout << "Error al abrir el fichero\n";
    exit(1);
   }

   cout << "El contenido del fichero creado es: \n";
   while(ficheroEntrada >> nombre >> apellido >> edad)
   {
     cout << "\n Nombre: " << nombre << "\n Apellido: " << apellido << "\n Edad: " << edad << endl;
   }

   //Cerramos el fichero.
   ficheroEntrada.close();

   // Salida normal del programa
   return 0;
}

