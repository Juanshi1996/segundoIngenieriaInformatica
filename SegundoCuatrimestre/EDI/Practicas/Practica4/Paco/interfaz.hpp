#include <iostream>
#include <cstdlib>
#include "colores.hpp"

int menu (void){
  int opc = -1;
  while (opc < 0 || opc > 5){
    system ("clear");
    std::cout << std::endl;
    std::cout << restaurar << "\t\t\t   " << fblue << twhite;
    std::cout << "                                                                                           \n";
    std::cout << restaurar << "\t\t\t   " << fblue << tblack;
    std::cout << "                                 Elija una opción del menú                                 \n";
    std::cout << restaurar << "\t\t\t   " << fblue << tblack;
    std::cout << "                                ---------------------------                                \n";
    std::cout << restaurar << "\t\t\t   " << fblue << twhite;
    std::cout << "                                                                                           \n";
    std::cout << restaurar << "\t\t\t   " << fblue;
    std::cout << "   "<<tblack"(1)  "<<twhite<<"Cargar un grafo desde un fichero                                                   \n";
    std::cout << restaurar << "\t\t\t   " << fblue;
    std::cout << "   "<<tblack"(2)  "<<twhite<<"Mostrar el grafo por pantalla                                                      \n";
    std::cout << restaurar << "\t\t\t   " << fblue;
    std::cout << "   "<<tblack"(3)  "<<twhite<<"Realizar el recorrido en profundidad a partir de un nodo                           \n";
    std::cout << restaurar << "\t\t\t   " << fblue;
    std::cout << "   "<<tblack"(4)  "<<twhite<<"Mostrar distancia y camino mínimo entre dos ciudades                               \n";
    std::cout << restaurar << "\t\t\t   " << fblue;
    std::cout << "   "<<tred"(0)  "<< twhite<<"Salir del programa.                                                                \n";
    std::cout << restaurar << "\t\t\t   " << fblue;
    std::cout << "                                                                                           \n";
    std::cout << restaurar << "\t\t\t   " << fblue;
    std::cout << "                                                                                           \n";
    std::cout << restaurar << italic << "\033[15;36H" << "Elija --->"DEFAULT" ";

    std::cin  >> opc;
  }
  return opc;
}


//GraphicsEnabler=No IGPEnabler=Yes IGPlatformID=01660003 "Graphics Mode”=1366x768x32 kext-dev-mode=1 -f -v