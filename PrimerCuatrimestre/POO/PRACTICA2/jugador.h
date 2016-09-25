#ifndef _JUGADOR_H
#define _JUGADOR_H

#include "persona.h"
#include <string>
#include <list>
#include <fstream>

using namespace std;

struct Apuesta{
	int tipo;
	string valor;
	int cantidad;
};

class Jugador:public Persona{
	private:
		int dinero_;
		string codigoJugador_;
		list<Apuesta> apuestas_;
	public:
		int getDinero();
		string getCodigoJugador();
		void setDinero(int dinero);
		void setCodigoJugador(string codigoJugador);
		list<Apuesta> getApuestas();
		bool setApuestas();
		Jugador(string initDNI, string initCodigoJugador,
						string initNombre = "", string initApellidos = "",
						string initDireccion = "", string initLocalidad = "", 						string initProvincia = "", string initPais = "");
};

#endif
