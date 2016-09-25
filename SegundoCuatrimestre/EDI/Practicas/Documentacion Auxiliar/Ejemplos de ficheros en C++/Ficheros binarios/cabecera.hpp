/***** ARCHIVO cabecera.h *****/

//Ejemplo completo de ficheros binarios

#ifndef _CABECERA_HPP_
#define _CABECERA_HPP_

#include <string>

using namespace std;

/* Definicion del tipo DatosPersonales */

struct DatosPersonales
{
  //Aqui no se pueden declarar strings, ya que dan problemas en las funciones
  // probablemente debido al tamaño indefinido de string
  char nombre[10];
  char apellido[10];
  int dni;
};

/* prototipos de funciones */
int menu();

bool existeFichero(string fichero);

void altaRegistro(string fichero);
void verRegistros(string fichero);

void buscarDNI(string fichero);
void borrarRegistrosNombre(string fichero);

void numeroRegistros(string fichero);

void registroNumeroI(string fichero);

void actualizarRegistro(string fichero);
int calcularNumeroRegistros(string fichero);
void verFichero(string fichero);

DatosPersonales introducirDatosPersonales(int dni);
DatosPersonales introducirNuevosDatosPersonales();
void escribirDatosPersonales(DatosPersonales aux);


void insertarRegistro(string fichero, DatosPersonales aux);
void modificarRegistro(string fichero, DatosPersonales datos, int dni);

bool buscarporDni(string fichero, int dni, DatosPersonales &persona);
bool borrarporNombre(string fichero, char *auxNombre);

DatosPersonales verRegistroNumeroI(string fichero, int i);


#endif

