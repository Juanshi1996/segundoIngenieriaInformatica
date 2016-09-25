/***** ARCHIVO principal_binario.cpp *****/


//Ejemplo simple de ficheros binarios

#include <iostream>

//Para los flujos de entrada/salida en ficheros.
#include <fstream>  

#include <string>
#include <stdio.h>

//Para usar system("clear");
#include <stdlib.h> 

#include "cabecera.hpp"

using namespace std;

/////////////////////////////////////////////

int main()
{
  string nombreFichero;

  /* variable para opciones del menu */
  int opcion; 

  system("clear");

  /* Introduccion del nombre del fichero para trabajar */
  cout << "Nombre del fichero de datos: ";
  cin >> nombreFichero;
  getchar();

  /* Menu de opciones del programa  */
  do
   {
     opcion = menu();
    
     switch (opcion)
     {

      case 0: /*  Fin del programa */
        {
          cout << "\n Fin del programa " << endl;
       
	  break;
	 }
        case 1: /* insertar registros en el fichero o crearlo si no existe*/
        {
          altaRegistro(nombreFichero);
       
	  break;
	 }
	case 2: /* Visualizar el contenido del fichero completo */
	{
          verRegistros(nombreFichero);
           
	  break;
	}	 
	case 3: /* comprobar si existe un registro con dni dado */
	{
          buscarDNI(nombreFichero);
               
	  break;	  
	}

	case 4: /* borrar registros por el nombre*/
	{
          borrarRegistrosNombre(nombreFichero);
                   
	  break;	  
	}
	case 5: /* calcula numero de registros*/
	{	  
          numeroRegistros(nombreFichero);
                
	  break;	  
	} 
	case 6: /* Buscar registro n-ésimo */
	{
          registroNumeroI(nombreFichero);

	  break;	  
	}
	case 7: /* modificar un registro con dni dado */
	{
          actualizarRegistro(nombreFichero);
     
	  break;	  
	}	
	case 8: /* cambiar de fichero */
	{
          /* Introduccion del nombre del nuevo fichero para trabajar */
          cout << "Nombre del nuevo fichero de datos: ";
          cin >> nombreFichero;
            
	  break;	  
	}
	case 9: /* se muestra el nombre del fichero actual */
	{
          cout << "El nombre del nuevo fichero actual es: " << nombreFichero << endl;
          cout << "\n Pulse intro para continuar \n";
                
	  break;	  
	}
	default: /* Opcion incorrecta */
	{   
          cout << "\n La opcion " << opcion << " es incorrecta " << endl;
	}		 	 	 	  
      }  
   
    // Se pulsa intro para continuar
    getchar();

   } while (opcion != 0);

  // Salida normal del programa
 return 0;
}

