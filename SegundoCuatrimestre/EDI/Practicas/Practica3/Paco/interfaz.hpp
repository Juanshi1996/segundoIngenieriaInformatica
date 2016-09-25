#include <iostream>
#include <cstdlib>

int menu (void){
  int opc = -1;
  while (opc < 0 || opc > 5){
    system ("clear");
    std::cout << "************************************************************";
    std::cout << "*******************************";
    std::cout << "\n******************************** Elija una opción del menú ";
    std::cout << "********************************";
    std::cout << "\n**                              ---------------------------";
    std::cout << "                              **";
    std::cout << "\n** (1)  Crear asignatura.                                    ";
    std::cout << "                            **";
    std::cout << "\n** (2)  Cargar asignatura.                                   ";
    std::cout << "                            **";
    std::cout << "\n** (3)  Guardar asignatura.                                  ";
    std::cout << "                            **";
    std::cout << "\n** (4)  Buscar una persona en la asignatura actual           ";
    std::cout << "                            **";
    std::cout << "\n** (5)  Mostrar asignatura.                                  ";
    std::cout << "                            **";
    std::cout << "\n** (0)  Salir del programa.                                  ";
    std::cout << "                            **";
    std::cout << "\n**                                                           ";
    std::cout << "                            **\n";
    std::cout << "************************************************************";
    std::cout << "*******************************\n";
    std::cout << "\nElija -- > ";
    std::cin  >> opc;
  }
  return opc;
}
