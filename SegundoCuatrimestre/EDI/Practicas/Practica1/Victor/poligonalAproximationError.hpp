/*!\file poligonalAproximationError.hpp
   \brief Functions to calculate the error made by the poligonal approximation
    of a contour (closed curve).
   \author Víctor Monserrat Villatoro
   \date 16-02-2015*/

#ifndef __POLIGONALAPROXIMATIONERROR_HPP__
#define __POLIGONALAPROXIMATIONERROR_HPP__

#include <vector>
#include "punto2D.hpp"
#include "recta2D.hpp"
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <cmath>

namespace ds {
  template <class T>
  /*!\fn void cargarContorno(std::vector<ds::Punto2D <T> > &contorno,
         char *ficheroContorno)
     \brief Loads the contour of two-dimensional points, of generic type
      coordinates, in a vector from a file.
     \arg[in] contorno The vector where it saves the points contour.
     \arg[in] ficheroContorno The name of the file where is the points contour.
     \pre None.
     \post None.
     \sa Punto2D::setX(), Punto2D::setY()*/
  void cargarContorno(std::vector<ds::Punto2D <T> > &contorno,
  char *ficheroContorno) {
    std::ifstream ifile;
    T auxX, auxY;
    ds::Punto2D<T> aux(0, 0);

    ifile.open(ficheroContorno);
    if(ifile.is_open()){
      while(ifile >> auxX >> auxY) {
        aux.setX(auxX);
        aux.setY(auxY);
        contorno.push_back(aux);
      }
      ifile.close();
    } else {
      std::cout << "\nError trying to open the file " << ficheroContorno;
      std::cout << "\n\n";
      exit(EXIT_FAILURE);
    }
  }

  template <class T>
  /*!\fn void cargarAproximacionPoligonal(std::vector<T> &aproximacionPoligonal,
         char *ficheroAproximacionPoligonal)
     \brief Loads file indexes from another file with which the contour will be
      approximated.
     \arg[in] aproximacionPoligonal The vector where it saves the indexes.
     \arg[in] ficheroAproximacionPoligonal The name of file where the indexes
      are.
     \pre None.
     \post None.*/
  void cargarAproximacionPoligonal(std::vector<T> &aproximacionPoligonal,
  char *ficheroAproximacionPoligonal) {
    std::ifstream ifile;
    T aux;

    ifile.open(ficheroAproximacionPoligonal);
    if(ifile.is_open()){
      while(ifile >> aux) {
        aproximacionPoligonal.push_back(aux);
      }
      ifile.close();
    } else {
      std::cout << "\nError trying to open the file ";
      std::cout << ficheroAproximacionPoligonal << "\n\n";
      exit(EXIT_FAILURE);
    }
  }

  template <class T>
  /*!\fn double calcularError(const std::vector<ds::Punto2D <T> > &contorno,
         const std::vector<T> &aproximacionPoligonal)
     \brief Calculates the error made by the poligonal approximation of a
      contour (closed curve).
     \arg[in] contorno The vector where the points contour are.
     \arg[in] aproximacionPoligonal The vector where the indexes are.
     \pre None.
     \post None.
     \return The error made by the poligonal approximation of a contour (closed
      curve).
     \sa Recta2D::distancia()*/
  double calcularError(const std::vector<ds::Punto2D <T> > &contorno,
  const std::vector<T> &aproximacionPoligonal) {
    double error = 0;

    for(size_t i=0; i<aproximacionPoligonal.size()-2; i++) {
      ds::Recta2D<T> r(contorno[aproximacionPoligonal[i]],
      contorno[aproximacionPoligonal[i+1]]);
      for(size_t j=aproximacionPoligonal[i]+1; j<aproximacionPoligonal[i+1];
      j++) {
        error += pow(r.distancia(contorno[j]), 2);
      }
    }
    ds::Recta2D<T> r(contorno[aproximacionPoligonal[aproximacionPoligonal.size()
    -2]], contorno[aproximacionPoligonal[0]]);
    for(size_t j=aproximacionPoligonal[aproximacionPoligonal.size()-2]+1;
    j<contorno.size()-1; j++) {
      error += pow(r.distancia(contorno[j]), 2);
    }
    for(size_t j=0; j<aproximacionPoligonal[0]; j++) {
      error += pow(r.distancia(contorno[j]), 2);
    }
    return(error);
  }
}

#endif
