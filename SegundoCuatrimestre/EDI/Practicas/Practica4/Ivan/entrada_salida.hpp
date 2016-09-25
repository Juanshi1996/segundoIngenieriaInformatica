/*!
  \file entrada_salida.hpp
  \author Iván Portillo Leal
*/
#ifndef __ENTRADA_SALIDA_HPP__
#define __ENTRADA_SALIDA_HPP__
#include <iostream>
#include <fstream>
#include "graph_matrix.hpp"

/*!
  \fn        bool cargarGrafo(edi::GraphMatrix * &g, std::string fileGraph)
  \brief     Carga un grafo de un fichero
  \param g  El grafo donde se va a almacenar
  \param fileGraph El fichero desde donde se va a cargar
  \return    True si se cargo correctamente
*/
bool cargarGrafo(edi::GraphMatrix * &g, std::string fileGraph);
/*!
  \fn        void mostrarGrafo(edi::GraphMatrix & g)
  \brief     Muestra un grafo por pantalla
  \param g  El grafo a mostrar
*/
void mostrarGrafo(edi::GraphMatrix & g);

#endif
