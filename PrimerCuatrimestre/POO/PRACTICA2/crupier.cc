#include "crupier.h"
#include "persona.h"
#include <string.h>

using namespace std;

string Crupier::getCodigo()
{
	return(codigo_);
}

void Crupier::setCodigo(string codigo)
{
	codigo_ = codigo;
}

Crupier::Crupier(string initDNI, string initCodigo, 
								 string initNombre, string initApellidos,
								 string initDireccion, string initLocalidad,
								 string initProvincia, string initPais)
				:Persona(initDNI, initNombre, initApellidos, initDireccion,
								 initLocalidad, initProvincia, initPais)
								 {
								 		codigo_ = initCodigo;
								 }
