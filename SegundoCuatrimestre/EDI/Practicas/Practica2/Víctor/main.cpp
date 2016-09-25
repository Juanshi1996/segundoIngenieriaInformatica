/*!\mainpage Program that show, list and modify the students of a subject.
   \author Víctor Monserrat Villatoro
   \date 07-03-2015
   \version 1.0*/

/*!\file main.cpp
   \brief Main file that uses the implemented class Subject.
   \author Víctor Monserrat Villatoro
   \date 07-03-2015*/

#include "dis_Subject.hpp"
#include <cstdlib>
#include <vector>
#include <iostream>
#include "generarpersona.hpp"
#include "persona.hpp"
#include <string>
#include <cstdio>

int main(int argc, char const *argv[]) {
  int option = 1;
  int n;
  char file[15];
  system("reset");
  std::cout << "\n     Introduzca el número de alumnos que tiene la ";
  std::cout << "asignatura: ";
  std::cin >> n;
  while(n > 100 || n < 0) {
    std::cout << "\n     El número de alumnos debe ser menor o igual ";
    std::cout << "que 100, por favor introduzca un número válido: ";
    std::cin >> n;
  }
  std::cout << "\n     Introduzca el nombre del fichero para generar ";
  std::cout << "los alumnos: ";
  std::cin >> file;
  std::vector<edi::Persona> students = generarPersonas(file, n);
  dis::Subject subject(students);
  while(option) {
    system("reset");
    std::cout << "\n(#)  ======================== Elija una opción del menú ==";
    std::cout << "=======================";
    std::cout << "\n(1)  Mostrar la lista de alumnos de la asignatura ";
    std::cout << "ascendentemente.";
    std::cout << "\n(2)  Mostrar la lista de alumnos de la asignatura ";
    std::cout << "descendentemente.";
    std::cout << "\n(3)  Mostrar ordenados ascendentemente los alumnos ";
    std::cout << "comprendidos entre otros dos.";
    std::cout << "\n(4)  Mostrar ordenados descendentemente los alumnos ";
    std::cout << "comprendidos entre otros dos.";
    std::cout << "\n(5)  Modificar los datos de un alumno.";
    std::cout << "\n(0)  Salir del programa.\n";
    std::cout << "(#)  =======================================================";
    std::cout << "=====================\n";
    do {
    std::cout << "\n     Introduzca un número entero comprendido entre el 0 y ";
    std::cout << "el 5: ";
    std::cin >> option;
  } while(option < 0 or option > 5);
    switch(option) {
      case 0: {
        std::cout << "\n";
        exit(EXIT_SUCCESS);
      }
      case 1: {
        subject.listUpwardlySorted();
        break;
      }
      case 2: {
        subject.listDescendentSorted();
        break;
      }
      case 3: {
        edi::Persona p, q;
        subject.listUpwardlySorted();
        std::cout << "\n     Introduzca los datos del primer alumno...\n";
        std::cin >> p;
        while(!subject.isStudent(p)) {
          std::cout << "\n     No se ha encontrado al alumno, por favor ";
          std::cout << "introdúzcalo de nuevo...\n";
          std::cin >> p;
        }
        std::cout << "\n     Introduzca los datos del segundo alumno...\n";
        std::cin >> q;
        while(!subject.isStudent(q)) {
          std::cout << "\n     No se ha encontrado al alumno, por favor ";
          std::cout << "introdúzcalo de nuevo...\n";
          std::cin >> q;
        }
        std::cout << "\n     Los alumnos comprendidos entre estos dos son...\n";
        std::cout << "\n";
        subject.showUpwardlySortedbetweenTwoStudents(p, q);
        break;
      }
      case 4: {
        edi::Persona p, q;
        subject.listUpwardlySorted();
        std::cout << "\n     Introduzca los datos del primer alumno...\n";
        std::cin >> p;
        while(!subject.isStudent(p)) {
          std::cout << "\n     No se ha encontrado al alumno, por favor ";
          std::cout << "introdúzcalo de nuevo...\n";
          std::cin >> p;
        }
        std::cout << "\n     Introduzca los datos del segundo alumno...\n";
        std::cin >> q;
        while(!subject.isStudent(q)) {
          std::cout << "\n     No se ha encontrado al alumno, por favor ";
          std::cout << "introdúzcalo de nuevo...\n";
          std::cin >> q;
        }
        std::cout << "\n     Los alumnos comprendidos entre estos dos son...\n";
        std::cout << "\n";
        subject.showDescendentSortedbetweenTwoStudents(p, q);
        break;
      }
      case 5: {
        edi::Persona p;
        subject.listUpwardlySorted();
        std::cout << "\n     Introduzca los datos del alumno a borrar...\n";
        std::cin >> p;
        while(!subject.isStudent(p)) {
          std::cout << "\n     No se ha encontrado al alumno, por favor ";
          std::cout << "introdúzcalo de nuevo...\n";
          std::cin >> p;
        }
        subject.modifyStudent(p);
        std::cout << "\n     A continuación se mostrará la lista actualizada";
        std::cout << "...\n";
        subject.listUpwardlySorted();
        break;
      }
    }
    std::cout << "\n     Pulse la tecla ENTER para mostrar de nuevo el menú...";
    getchar();
    getchar();
  }
}
