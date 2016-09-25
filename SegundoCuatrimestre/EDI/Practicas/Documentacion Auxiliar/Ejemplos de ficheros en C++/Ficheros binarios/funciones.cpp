//////////////////////////////////////////
///
/// ARCHIVO funciones.cpp
///
//////////////////////////////////////

//Ejemplo completo de ficheros binarios

/// 
#include <iostream>
#include <fstream>

// Para usar strcmp
#include <string.h>

// Para usar system ("clear")
#include <stdlib.h>

#include "cabecera.hpp"

using namespace std;

int menu()
{
  int opcion; 

  system("clear");

  cout << "********************************************************\n";  
  cout << "* 1.  Insertar registros en el fichero.               *\n";
  cout << "* 2.  Ver todos los registros del fichero.            *\n";
  cout << "* 3.  Buscar un registro dado su dni.                 *\n";
  cout << "* 4.  Borrar registros por el nombre.                 *\n";
  cout << "* 5.  Calcular numero de registros del archivo.       *\n";
  cout << "* 6.  Ver registro que ocupa la posicion i-esima.     *\n";
  cout << "* 7.  Modificar registro dado su dni.                 *\n";
  cout << "*                                                     *\n";
  cout << "* 8.  Cambiar el fichero de registros                 *\n";
  cout << "*                                                     *\n";
  cout << "* 9.  Mostrar el nombre del fichero actual            *\n";
  cout << "*                                                     *\n";
  cout << "* 0.  Salir del programa.                             *\n";
  cout << "********************************************************\n";
  cout << " \n Introduzca una opcion: ";

  cin >> opcion;
  getchar();

  system("clear");

  return opcion;
}

struct DatosPersonales introducirDatosPersonales(int dni)
{
  struct DatosPersonales aux;
  cout << "Entrada de datos de la persona de DNI = " << dni << endl;
  cout << "==================================================\n";
  aux.dni = dni; 
  cout << "Nombre : ";
  cin >> aux.nombre;
  cout << "Apellido :";
  cin >> aux.apellido;

  getchar();

  return aux;
}

struct DatosPersonales introducirNuevosDatosPersonales()
{
  struct DatosPersonales aux;
  cout << "DNI: ";
  cin >> aux.dni; 
  cout << "Nombre : ";
  cin >> aux.nombre;
  cout << "Apellido :";
  cin >> aux.apellido;

  getchar();

  return aux;
}

void escribirDatosPersonales(struct DatosPersonales aux)
{
 cout << "\t Nombre: " << aux.nombre 
      << "\n\t Apellido: " << aux.apellido 
      << "\n\t DNI: " << aux.dni
      << endl << endl; 
}

void altaRegistro(string fichero)
{
  int auxdni; /*variable auxiliar para buscar por dni*/
  int existe; /* variable auxiliar para si existe un fichero */
  bool encontrado;
  struct DatosPersonales persona1;

  cout << "Introduzca DNI de la persona a dar de alta: ";
  cin >> auxdni;

  getchar();

  //si el fichero no existe se anade el registro.
  existe = existeFichero(fichero); // comprueba si existe el fichero.
  if (!existe) /* el fichero no existe*/
  {
    persona1 = introducirDatosPersonales(auxdni);
    escribirDatosPersonales(persona1);
    insertarRegistro(fichero, persona1);
    cout << " Registro anadido. \n Pulse intro para continuar \n";
  }
  else // el fichero existe.
  {
    //Comprueba si esa persona ha sido introducida antes.
    //para no duplicar sus datos.
    encontrado = buscarporDni(fichero, auxdni, persona1); 
    if (encontrado) /* ya existe el registro y no se anade */
    {
      cout << " Registro ya existente. \n Pulse intro para continuar \n";
    }
    else /* no existe el registro y se puede insertar */
    {
      persona1 = introducirDatosPersonales(auxdni);
      insertarRegistro(fichero, persona1);
      cout << " Registro anadido. \n Pulse intro para continuar \n";
    }
  }
}

bool existeFichero(string fichero)
{
  //Declaracion flujo de entrada.
  ifstream flujoEntrada; 

  //Se abre el fichero para leer.
  flujoEntrada.open(fichero.c_str(), ios::in); 

  if (flujoEntrada)
    return true;
  else
    return false;
}

void insertarRegistro(string fichero, struct DatosPersonales persona)
{
  //Se declara el flujo de salida.
  ofstream flujoSalida; 

  //Se abre el fichero para insertar.
  flujoSalida.open(fichero.c_str(), ios::app); 

  //Guarda el registro. 
  flujoSalida.write((char *) (&persona), sizeof(DatosPersonales)); 

  // Cierra el fichero o flujo de salida
  flujoSalida.close();
}

void verRegistros(string fichero)
{
  bool existe;

  
  /* comprueba si existe el fichero */
  existe = existeFichero(fichero); 

  /* el fichero existe */
  if (existe) 
  {
    /* muestra los registros del fichero */
    verFichero(fichero); 

    cout << " Datos leidos. \n Pulse Intro para continuar \n";
  }
  /* el fichero no existe */
  else 
  {
    cout << " El fichero no existe. \n Pulse intro para continuar \n";
  }
}

void verFichero(string fichero)
{ 
  struct DatosPersonales persona;

  //Declaracion flujo de entrada.
  ifstream flujoEntrada; 

  //Se abre el fichero para leer.
  flujoEntrada.open(fichero.c_str(), ios::in); 

  //Se lee el primero.
  flujoEntrada.read((char *) (&persona), sizeof(DatosPersonales));
  
  cout << " Se van a mostrar los  registros del fichero " << fichero << endl ;
  cout << " ============================================================== " << endl;

  while(flujoEntrada /*&& !flujoEntrada.eof()*/) 
  /* Comprueba que no ha llegado al final del fichero */
  {
   /* Muestra el registro por pantalla */
    escribirDatosPersonales(persona); 

    //se lee el registro.
    flujoEntrada.read((char *) (&persona), sizeof(DatosPersonales)); 
  }

  // Cierra el flujo de entrada (fichero)
  flujoEntrada.close();
}
    
void buscarDNI(string fichero)
{
  bool existe, encontrado;
  int auxdni;
  DatosPersonales persona1;

  existe = existeFichero(fichero); 

  /* el fichero existe */
  if (existe) 
  {
    cout << " Introduzca dni a buscar: ";
    cin >> auxdni;
    getchar();

    encontrado = buscarporDni(fichero, auxdni, persona1);

    /* se ha encontrado el registro */
    if (encontrado)
    {  
      /* se escriben los datos de la persona */
      escribirDatosPersonales(persona1); 
      cout << " Registro Encontrado. \n Pulse Intro para continuar  \n";
    }
    /* no se ha encontrado el registro */
    else 
    {
      cout << "Registro no encontrado. \n Pulse Intro para continuar  \n";
    }
  }
  else
  {
    cout << " El fichero no existe. \n Pulse intro para continuar \n";
  }
}

bool buscarporDni(string fichero, int dni, struct DatosPersonales &persona)
{
  int salir = 0;

  /* variables auxiliares para la busqueda */
  bool encontrado = false; 
  struct DatosPersonales auxiliar;

  //Declaracion flujo de entrada.
  ifstream flujoEntrada; 

  //Se abre el fichero para leer.
  flujoEntrada.open(fichero.c_str(), ios::in);

  //Se lee el primero. 
  flujoEntrada.read((char *) (&auxiliar), sizeof(DatosPersonales)); 

  while (flujoEntrada && salir == 0)
  {
    if (auxiliar.dni == dni) 
    /* ha encontrado el registro ya que está */
    {
      encontrado = true;
      salir = 1;

      /* almacena en persona el registro encontrado */
      persona = auxiliar; 
    }
    else
      flujoEntrada.read((char *) (&auxiliar), sizeof(DatosPersonales));
  }

  /* se cierra el fichero */
  flujoEntrada.close(); 

  return encontrado;
}

void borrarRegistrosNombre(string fichero)
{
  bool existe, borrado;
  char auxNombre[10];
  
  existe = existeFichero(fichero);

  /* el fichero existe */
  if (existe)
  {
    cout << " Introduzca nombre de los registros a borrar: ";
    cin >> auxNombre;
    getchar();

    borrado = borrarporNombre(fichero, auxNombre);

    /* se ha borrado al menos un registro*/
    if (borrado) 
      cout << "  Registros borrados. \n Pulse intro \n";
    /* no existe el registro */
    else
      cout << " No existen registros con ese nombre. \n Pulse intro \n";
   }
    /* el fichero no existe */
    else 
     cout << "  El fichero no existe. \n Pulse intro para continuar \n";
}

bool borrarporNombre(string fichero, char *auxNombre)
{
  //Se declara el flujo de salida.
  ofstream flujoSalida; 

  //Declaracion flujo de entrada.
  ifstream flujoEntrada; 

  struct DatosPersonales auxiliar;
  bool borrado = false;

  //Se abre el fichero para leer.
  flujoEntrada.open(fichero.c_str(), ios::in); 

  //Se abre el temporal para insertar.
  flujoSalida.open("_temporal.dat", ios::app); 

  //Se lee el primero.
  flujoEntrada.read((char *) (&auxiliar), sizeof(DatosPersonales));
 
  //Los registros que no borramos se vuelcan al temporal.
  while(flujoEntrada && !flujoEntrada.eof()) 
  /* Comprueba que no ha llegado al final del fichero */
  {
     //Se guarda registro en el temporal
    if (strcmp(auxiliar.nombre, auxNombre) != 0)
      flujoSalida.write((char *) (&auxiliar), sizeof(DatosPersonales));
    else
      borrado = true;

     //se lee el registro.
    flujoEntrada.read((char *) (&auxiliar), sizeof(DatosPersonales));
  }

  flujoEntrada.close();
  flujoSalida.close();

  //Borramos fichero antiguo.
  remove(fichero.c_str()); 

  // Renombramos el fichero temporal para que sea el fichero original
  rename("_temporal.dat", fichero.c_str());  

  return borrado;
}

void numeroRegistros(string fichero)
{
  bool existe;
  int numero;
  existe = existeFichero(fichero); 

  /* el fichero existe */
  if (existe)
  {
    numero = calcularNumeroRegistros(fichero);
    cout << " Numero de registros = " << numero << endl;
  }
  /* el fichero no existe */
  else
    cout << "  El fichero no existe. \n Pulse intro para continuar \n";
}

int calcularNumeroRegistros(string fichero)
{
  int numeroRegistros;

  //Declaracion flujo de entrada.
  ifstream flujoEntrada; 

  //Se abre el fichero para leer.
  flujoEntrada.open(fichero.c_str(), ios::in); 

  // Nos situamos al final del mismo.
  flujoEntrada.seekg(0, ios::end); 

  // tellg devuelve el numero de bytes desde el principio del fichero
  // hasta la posicion actual que es el final del fichero
  numeroRegistros = flujoEntrada.tellg() / sizeof(DatosPersonales);

  // Se cierra el fichero
  flujoEntrada.close();

  return numeroRegistros;
}

void registroNumeroI(string fichero)
{
  bool existe;
  int posicion;
  int numero;
  DatosPersonales persona1;

  existe = existeFichero(fichero); 

  /* el fichero existe */
  if (existe == 1) 
  {
    cout << " Introduzca la posición a buscar: ";
    cin >> posicion;
    getchar();

    /* hay que comprobar que posicion no supera al número de 
       registros del fichero */
    numero = calcularNumeroRegistros(fichero); 	    

   /* no sobrepasa el limite*/
    if (posicion <= numero) 
    {  
      persona1 = verRegistroNumeroI(fichero, posicion);
      escribirDatosPersonales(persona1); 
      cout << " Registro Encontrado. \n Pulse Intro para continuar  \n";
    }
    /* se sobrepasa el limite */
    else 
    {
       cout << "Se sale del fichero. \n Pulse Intro para continuar  \n";
    }
  }
  else 
  {
    cout << " El fichero no existe. \n Pulse intro para continuar \n";
  }
}

struct DatosPersonales verRegistroNumeroI(string fichero, int i)
{
  struct DatosPersonales auxiliar;

  //Declaracion flujo de entrada.
  ifstream flujoEntrada;

  //Se abre el fichero para leer. 
  flujoEntrada.open(fichero.c_str(), ios::in);

  // Nos desplazamos al final del registro i-1, desde el principio
  // del fichero con la funcion seekg.
  flujoEntrada.seekg((i - 1) * sizeof(DatosPersonales), ios::beg);

  //se lee el registro.
  flujoEntrada.read((char *) &(auxiliar), sizeof(DatosPersonales)); 
  flujoEntrada.close();

  // devuelve el registro leido.
  return auxiliar;
} 

void actualizarRegistro(string fichero)
{
  bool existe, encontrado;
  DatosPersonales persona1, auxiliar;
  int auxdni;
  
  existe = existeFichero(fichero); 

  // el fichero existe 
  if (existe) 
  {
    cout << " Introduzca dni a buscar: ";
    cin >> auxdni;
    getchar();

    encontrado = buscarporDni(fichero, auxdni, persona1);

    // se ha encontrado el registro.
    if (encontrado) 
    {  
      // se escriben los datos de la persona.
      escribirDatosPersonales(persona1); 
      cout <<" Registro Encontrado. Introduzca Datosnuevos  \n";

      auxiliar = introducirNuevosDatosPersonales();

      if (auxiliar.dni != persona1.dni)
      {
	encontrado = buscarporDni(fichero, auxiliar.dni, persona1);

	if (encontrado)
          cout << "El nuevo DNI ya existe y no se puede modificar el registro \n";
	else
	{
          modificarRegistro(fichero, auxiliar, auxdni);
          cout << "Registro modificado \n";
        }
      }
      else
      {     
        modificarRegistro(fichero, auxiliar, auxdni);
        cout << "Registro modificado \n";
      }
    }
    // no se ha encontrado el registro
    else
      cout << "Registro no encontrado. \n Pulse Intro para continuar  \n";
  }
  else
    cout << " El fichero no existe. \n Pulse intro para continuar \n";
} 
  
void modificarRegistro(string fichero, struct DatosPersonales datos, int dni)
{
  struct DatosPersonales auxiliar;
  int encontrado = 0;
  int contador = 0;

  // Declaracion flujo entrada/salida.
  fstream f;
   
  // Se abre para lectura y escritura el fichero.
  f.open(fichero.c_str(), ios::in | ios::out);

  //Se lee el primero.
  f.read((char *) (&auxiliar), sizeof(DatosPersonales)); 


  while(f)
  {
    contador++;

    //Hemos encontrado el registro a modificar.
    if (dni == auxiliar.dni) 
    {
      encontrado = 1;     

      // Situamos al puntero de escritura al principio del registro encontrado.
      f.seekp( (contador - 1) * sizeof(DatosPersonales), ios::beg);

      // Se reescribe el registro.
      f.write((char *) (&datos), sizeof(DatosPersonales));
    }

    f.read((char *) (&auxiliar), sizeof(DatosPersonales));    
  }
  // Se cierra el fichero 
  f.close();
}

