#include "persona.h"
#include "jugador.h"
#include <list>
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

int Jugador::getDinero()
{
	return(dinero_);
}

string Jugador::getCodigoJugador()
{
	return(codigoJugador_);
}

void Jugador::setDinero(int dinero)
{
		dinero_ = dinero;
}

void Jugador::setCodigoJugador(string codigoJugador)
{
	codigoJugador_ = codigoJugador;
}

list<Apuesta> Jugador::getApuestas()
{
	return(apuestas_);
}

bool Jugador::setApuestas()
{
	ifstream file;
	char line[30];
	struct Apuesta aux;

	file.open((getDNI()+".txt").c_str());
	if(file.is_open())
	{
		while (file.getline(line, 100, ','))
		{
			aux.tipo = atoi(line);
			file.getline(line, 100, ',');
			aux.valor = line;
			file.getline(line, 100, '\n');
			aux.cantidad = atoi(line);
			apuestas_.push_back(aux);			
		}
		file.close();
		return(true);
	}
	else
	{
		cout<<endl<<"Error al intentar abrir el fichero \""<<getDNI()+".txt\""<<endl;
		return(false);
	}
}

Jugador::Jugador(string initDNI, string initCodigoJugador,
								 string initNombre, string initApellidos,
								 string initDireccion, string initLocalidad,
								 string initProvincia, string initPais)
				:Persona(initDNI, initNombre, initApellidos, initDireccion,
								 initLocalidad, initProvincia, initPais)
								 {
								 		setCodigoJugador(initCodigoJugador);
								 		setDinero(1000);
								 }
