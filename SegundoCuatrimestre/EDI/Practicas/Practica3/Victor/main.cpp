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
#include <fstream>

#include "persona.hpp"
#include "generarpersona.hpp"
#include "dis_Subject.hpp"
#include "edi_LinkedOrderedBinaryTree.hpp"
#include "dis_Key.hpp"
#include "dis_KeyTree.hpp"


/*!
	\fn     int main()
	\brief  Progra princial
	\return Valor de control
*/
int main()
{
	srand(time(0));
	int numeroPersonas;
	edi::Persona p;
	std::string fichero = "personas.txt";

	std::vector <edi::Persona> personas;

	std::cout <<" Personas a generar: ";
	std::cin >> numeroPersonas;

	std::ofstream f(fichero.c_str());

	for(int i = 1; i <= numeroPersonas ; i++)
	{
		p = generarPersona();
		std::cout << p;
		f << p;
	}

	f.close();

	personas = generarPersonas(fichero, numeroPersonas);
	edi::Persona aux;

	unsigned int minimo = 0;

	for(unsigned int i = 0; i <= personas.size() -2; i++)
	{
		minimo = i;
		for(unsigned int j = i + 1; j <= personas.size() -1; j++)
	  {
			if (personas[j] < personas[minimo])
				minimo = j;
		}
		aux = personas[minimo];
		personas[minimo] = personas[i];
		personas[i] = aux;
	}

	for(unsigned int i = 0; i < personas.size(); i++)
	{
		std::cout << i + 1 << ". ";
		std::cout << personas[i];
	}

	dis::Subject subject(personas);
	edi::LinkedOrderedBinaryTree<dis::Key> tree;
	//keyTreeFromSortedDoublyLinkedList(subject.getStudents(), &otree);
	std::ofstream ofile;
	std::ifstream ifile;
	ifile.open("ofile.txt");
	if(ifile.is_open()) {
		ifile >> tree;
		ifile.close();
	}
	ofile.open("ifile.txt");
	if(ofile.is_open()) {
		ofile << tree;
		ofile.close();
	}

	return 0;
}
