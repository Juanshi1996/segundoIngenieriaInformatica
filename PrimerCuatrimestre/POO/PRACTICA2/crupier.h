#ifndef _CRUPIER_H
#define _CRUPIER_H //TENIAS PUESTO CRUPRIER ENTONCES SALTARIA UN ERROR EN TAL CASO xD

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
