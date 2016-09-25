#ifndef _PERSONA_H
#define _PERSONA_H

#include <string>

using namespace std;

class Persona
{
	private:
		string DNI_;
		string nombre_;
		string apellidos_;
		string direccion_;
		string localidad_;
		string provincia_;
		string pais_;
	
	public:
		string getDNI();
		string getNombre();
		string getApellidos();
		string getApellidosyNombre();
		string getDireccion();
		string getLocalidad();
		string getProvincia();
		string getPais();
		void setDNI(string);
		void setNombre(string);
		void setApellidos(string);
		void setDireccion(string);
		void setLocalidad(string);
		void setProvincia(string);
		void setPais(string);
		Persona(string initDNI,
						string initNombre = "",
						string initApellidos = "",
						string initDireccion = "",
						string initLocalidad = "",
						string initProvincia = "",
						string initPais = "");
};

#endif
