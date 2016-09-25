/*!\mainpage Program that calculates the error made by the poligonal
    approximation of a contour (closed curve).
   \author Víctor Monserrat Villatoro
   \date 16-02-2015
   \version 1.0*/

/*!\file main.cpp
   \brief Main file that uses the implemented classes Punto2D and Recta2D.
   \author Víctor Monserrat Villatoro
   \date 16-02-2015*/

#include <cstring>
#include <vector>
#include "punto2D.hpp"
#include "recta2D.hpp"
#include "poligonalAproximationError.hpp"
#include <iostream>
#include <cstdlib>

int main(int argc, char const *argv[]) {
  char ficheroContorno[] = "abrelatas.txt";
  char ficheroAproximacionPoligonal[] = "aproximacion.txt";
  std::vector<ds::Punto2D <double> > contorno;
  std::vector<double> aproximacionPoligonal;

  ds::cargarContorno(contorno, ficheroContorno);
  ds::cargarAproximacionPoligonal(aproximacionPoligonal,
  ficheroAproximacionPoligonal);
  std::cout << "\nEl error de aproximación poligonal cometido al aproximar el ";
  std::cout << "contorno del fichero \"" << ficheroContorno << "\" con la ";
  std::cout << "aproximación del fichero \"" << ficheroAproximacionPoligonal;
  std::cout << "\" es: " << ds::calcularError(contorno, aproximacionPoligonal);
  std::cout << "\n\n";
  return(EXIT_SUCCESS);
}
