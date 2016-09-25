#include "dados.h"
#include <iostream>

using namespace std;

int main(void)
{
	Dados d;
	int valor1=1, valor2=1, aux;

	cout<< "\nHemos creado un objeto de la clase Dados cuyos valores iniciales son para el dado 1 (" << d.getDado1() << ") y para el dado 2 (" << d.getDado2() << ").\n\n";
	d.lanzamiento();
	cout<< "Tras el lanzamiento de los dados el valor obtenido para el dado 1 es " << d.getDado1() << " y para el dado 2 es " << d.getDado2() << ".\n\n";
	do
	{
		cout<< "Introduzca un valor para el dado 1: ";
		cin>> valor1;
		aux = d.setDado1(valor1);
	}
	while (aux == false);
	do
	{
		cout<< "Introduzca un valor para el dado 2: ";
		cin>> valor2;
		aux = d.setDado2(valor2);
	}
	while (aux == false);
	cout<< "\nLos valores nuevos son para el dado 1 (" << d.getDado1() << ") y para el dado 2 (" << d.getDado2() << ").\n\n";
	cout<< "El valor de la suma es " << d.getSuma() << ".\n\n";
	cout<< "El valor de la diferencia es " << d.getDiferencia() << ".\n\n";
	return(0);
}
