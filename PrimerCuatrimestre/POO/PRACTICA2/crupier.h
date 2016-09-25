#ifndef _CRUPIER_H
#define _CRUPRIER_H

#include <string>
#include "persona.h"

using namespace std;

class Crupier:public Persona
{
	private:
		string codigo_;
		
	public:
		string getCodigo();
		void setCodigo(string);
		Crupier(string initDNI, string initCodigo, 
						string initNombre = "", string initApellidos = "",
						string initDireccion = "", string initLocalidad = "",
						string initProvincia = "", string initPais = "");
};

#endif
