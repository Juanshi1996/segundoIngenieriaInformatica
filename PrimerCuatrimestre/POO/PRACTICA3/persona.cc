#include "persona.h"
#include <string>

using namespace std;

string Persona::getDNI()
{
	return(DNI_);
}

string Persona::getNombre()
{
	return(nombre_);
}

string Persona::getApellidos()
{
	return(apellidos_);
}

string Persona::getApellidosyNombre()
{
	return(getApellidos()+", "+getNombre());
}

string Persona::getDireccion()
{
	return(direccion_);
}

string Persona::getLocalidad()
{
	return(localidad_);
}

string Persona::getProvincia()
{
	return(provincia_);
}

string Persona::getPais()
{
	return(pais_);
}

void Persona::setDNI(string DNI)
{
	DNI_ = DNI;
}

void Persona::setNombre(string nombre)
{
	nombre_ = nombre;
}

void Persona::setApellidos(string apellidos)
{
	apellidos_ = apellidos;
}

void Persona::setDireccion(string direccion)
{
	direccion_ = direccion;
}

void Persona::setLocalidad(string localidad)
{
	localidad_ = localidad;
}

void Persona::setProvincia(string provincia)
{
	provincia_ = provincia;
}

void Persona::setPais(string pais)
{
	pais_ = pais;
}

Persona::Persona(string initDNI,
								 string initNombre,
								 string initApellidos,
								 string initDireccion,
								 string initLocalidad,
								 string initProvincia,
								 string initPais)
{
	DNI_ = initDNI;
	nombre_ = initNombre;
	apellidos_ = initApellidos;
	direccion_ = initDireccion;
	localidad_ = initLocalidad;
	provincia_ = initProvincia;
	pais_ = initPais;
}
