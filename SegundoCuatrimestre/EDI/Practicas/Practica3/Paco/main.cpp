/*!
  \file   main.cpp
  \brief  Programa que prueba la clase Persona
  \author Name
  \date   16/03/2015
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <string>
#include <cstdio> // getline

#include "persona.hpp"
#include "generarpersona.hpp"
#include "asignatura.hpp"
#include "listaOrdenada.hpp"
#include "listaOrdenadaDoblementeEnlazada.hpp"
#include "nodo.hpp"
#include "persistenciaFichero.hpp"
#include "clave.hpp"
#include "edi_LinkedOrderedBinaryTree.hpp"
#include "edi_LinkedBinaryTree.hpp"
#include "creaArbolClaves.hpp"
#include "interfaz.hpp"


/*!
	\fn     int main()
	\brief  Progra princial
	\return Valor de control
*/
int main(){
	int opc = -1; // Opción para elegir en el menú
	int nAlumnos = 0;	// Número de alumnos para crear la asignatura (opc == 1)
	bool asignaturaCreada = false;
	std::string ficheroGuardaAsignatura;
	std::string ficheroCargaAsignatura;

	int dni;
	int numero = -1;

	std::string Buffer;

	edi::Persona persona;
	edi::Asignatura asignatura;
	edi::ListaOrdenadaDoblementeEnlazada <edi::Persona> lista;
	edi::LinkedOrderedBinaryTree <edi::Clave> arbol;


	while (opc != 0){
    opc = menu ();
		if (!asignaturaCreada){
      if (opc == 1){ // Crear una Asignatura
        while (nAlumnos<1||nAlumnos>100){
          system ("clear");
          std::cout << "Introduce un nº menor o igual de 100 y mayor de 0: ";
          std::cin  >> nAlumnos;
        }
				std::ofstream fichero("personas.txt");
				for(int i = 0; i < nAlumnos ; i++){
					persona = generarPersona();
					fichero << persona;
				}
				fichero.close();

        asignatura.crearAsignatura (nAlumnos);
				nAlumnos = -1;
				cargaFichero (&lista, (char*)"personas.txt");
				crearArbol (lista, &arbol);
        asignaturaCreada = true;
      }

			if (opc == 2){ // Cargar Asignatura
					system ("clear");
					std::cout << "Introduce el nombre del fichero del cual se cargará la asignatura\E[33m (sin extensión): \e[0m";
					std::cin >> ficheroCargaAsignatura;
					std::ifstream fichero((ficheroCargaAsignatura+".txt").c_str());

					edi::Persona aux;
					edi::ListaOrdenadaDoblementeEnlazada <edi::Persona> listaAuxiliar;

					// Carga listaAsignatura
					if (fichero.is_open()){
						while (!fichero.eof()){
							fichero >> aux;
							if (!fichero.eof ()){
								listaAuxiliar.inserta(aux);
							}
						}
						asignatura.setAsignatura(listaAuxiliar);
						fichero.close();

						// Carga árbol
						arbol.recogeFichero(&arbol, (char*)(ficheroCargaAsignatura+".idx").c_str());
						asignaturaCreada=true;
					}
					else{
						std::cout << "Ha habido un problema al abrir el fichero o el fichero no existe.";
						fflush(stdout);
						system ("sleep 2");
					}
      }
		}
		else{ // if (asignaturaCreada)
			if (opc == 1 || opc == 2){
				system ("clear");
				std::cout << "Ya has creado o cargado una asignatura.";
				fflush (stdout);
				system ("sleep 1");
			}
		}
		if (asignaturaCreada){
      if (opc == 3){ // Guardar Asignatura
				do {
					system ("clear");
					std::cout << "Introduce el nombre del fichero para guardar la asignatura \E[33m (sin extensión): \e[0m";
					std::cin >> ficheroGuardaAsignatura;
					if (ficheroGuardaAsignatura == "personas"){
						system ("clear");
	          std::cout << "'" << ficheroGuardaAsignatura << "'" <<  " no es un nombre de archivo válido.";
	          fflush (stdout);
	          system ("sleep 1");
					}
				}
				while (ficheroGuardaAsignatura == "personas");

				/*****************Guardar Asignatura*****************/

				//asignatura.crearAsignatura(ficheroGuardaAsignatura);
				std::ofstream fichero((ficheroGuardaAsignatura+".txt").c_str());
				fichero << asignatura;
				fichero.close();


				/*******************Guardar Árbol*******************/
				if (std::ifstream ((ficheroGuardaAsignatura+".idx").c_str()))	{
					remove ((ficheroGuardaAsignatura+(std::string)".idx").c_str()); // Borra el fichero .idx si existe
				}
				arbol.insertaFichero(&arbol, (char*)(ficheroGuardaAsignatura+".idx").c_str());
      }
      if (opc == 4){ // Buscar una persona en la Asignatura actual
				system ("clear");
				std::cout << "Introduce el dni de la persona a buscar en la asignatura\E[33m (sin letra): \e[0m";
				std::cin  >> dni;
				numero = arbol.searchDni(dni);
				if (numero==-1){
					std::cout << "El DNI introducido no coincide con ninguno del de la lista.";
					fflush(stdout);
					system ("sleep 2");
				}
				else{
					persona = asignatura.posicion(numero);
					std::cout << "La persona buscada es: \n" << persona << "\nPulse intro para continuar.";
					getchar();
					getchar();
				}
      }
      if (opc == 5){ // Mostrar Asignatura
				system ("clear");
				asignatura.mostrarListOrdenadoAsc();
				std::cout << "\nPulse intro para continuar.";
				getchar();
				getchar();
      }
		}
		else{
      if (opc != 1 && opc != 0 && opc != 2){
        system ("clear");
        std::cout << "Debes crear antes una asignatura.";
        fflush (stdout);
        system ("sleep 1");
	    }
		}
  }
	system ("clear");
  return 0;
}
