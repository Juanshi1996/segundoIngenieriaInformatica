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
#include "dis_KeyTree.hpp"
#include "dis_Key.hpp"
#include <fstream>

int main(int argc, char const *argv[]) {
  int option = 1;
  dis::Subject subject;
  edi::LinkedOrderedBinaryTree<dis::Key> tree;
  bool isSubject = false;
  while(option) {
    system("reset");
    std::cout << "\n(#)  ======================== Elija una opción del menú ==";
    std::cout << "=======================";
    std::cout << "\n(1)  Crear asignatura";
    std::cout << "\n(2)  Guardar asignatura";
    std::cout << "\n(3)  Cargar asignatura";
    std::cout << "\n(4)  Buscar una persona en la asignatura actual";
    std::cout << "\n(5)  Mostrar asignatura";
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
        int n;
        char file[] = "personas.txt";
        std::cout << "\n     Introduzca el número de alumnos que tiene la ";
        std::cout << "asignatura: ";
        std::cin >> n;
        while(n > 100 || n < 0) {
          std::cout << "\n     El número de alumnos debe ser menor o igual ";
          std::cout << "que 100, por favor introduzca un número válido: ";
          std::cin >> n;
        }
        std::vector<edi::Persona> students = generarPersonas(file, n);
        dis::Subject auxSubject(students);
        subject = auxSubject;
        tree.flush();
        keyTreeFromSortedDoublyLinkedList(subject.getStudents(), &tree);
        isSubject = true;
        break;
      }
      case 2: {
        if(isSubject) {
          std::ofstream ofile;
          std::string file;
          std::cout << "\n     Introduzca el nombre de la asignatura: ";
          std::cin >> file;
          ofile.open((file + ".txt").c_str());
          if(ofile.is_open()) {
            ofile << subject;
            ofile.close();
          }
          ofile.open((file + ".idx").c_str());
          if(ofile.is_open()) {
            ofile << tree;
            ofile.close();
          }
        } else {
          std::cout << "\n     Por favor, cree o cargue antes una asignatura.\n";
        }
        break;
      }
      case 3: {
        std::ifstream ifile;
        std::string file;
        std::cout << "\n     Introduzca el nombre de la asignatura: ";
        std::cin >> file;
        ifile.open((file + ".txt").c_str());
        if(ifile.is_open()) {
          dis::Subject aux;
          ifile >> aux;
          ifile.close();
          aux.getStudents().deletePosition(0);
          subject = aux;
        }
        ifile.open((file + ".idx").c_str());
        if(ifile.is_open()) {
          tree.flush();
          ifile >> tree;
          ifile.close();
        }
        isSubject = true;
        break;
      }
      case 4: {
        if(isSubject) {
          int id;
          bool found = false;
          bool finished = false;
          int position;
          std::cout << "\n     Introduzca el dni de la persona: ";
          std::cin >> id;
          edi::LinkedOrderedBinaryTree<dis::Key> aux;
          aux = tree;
          aux.goToRoot();
          while(!finished) {
            if(id < aux.item().getId()) {
              if(aux.hasLeftChild()) {
                aux = *(aux.leftSubTree());
              } else {
                finished = true;
              }
            } else if(id > aux.item().getId()) {
              if(aux.hasRightChild()) {
                aux = *(aux.rightSubTree());
              } else {
                finished = true;
              }
            } else {
              finished = true;
              found = true;
              position = aux.item().getPosition();
            }
          }
          if(found) {
            std::cout << "\n     El alumno con DNI " << id << " es " << subject.getStudents().getItem(position).nombre() << " " << subject.getStudents().getItem(position).apellido() << ".\n";
          } else {
            std::cout << "\n     El DNI introducido no se encuentra en la asignatura.\n";
          }
        } else {
          std::cout << "\n     Por favor, cree o cargue antes una asignatura.\n";
        }
        break;
      }
      case 5: {
        if(isSubject) {
          subject.listUpwardlySorted();
        } else {
          std::cout << "\n     Por favor, cree o cargue antes una asignatura.\n";
        }
        break;
      }
    }
    std::cout << "\n     Pulse la tecla ENTER para mostrar de nuevo el menú...";
    getchar();
    getchar();
  }
}
