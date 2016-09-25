#include <iostream>
#include <cstring>
#include "clave.hpp"

using namespace std;
using namespace edi;

namespace edi{


ostream & operator<<(ostream &stream, const Clave &p)
{
	stream << p.dni() << " " << p.numero() << endl;
	return stream;
};

ofstream & operator<<(ofstream &stream, const Clave &p)
{
	stream << p.dni() << " " << p.numero() << endl;
	return stream;
};

istream &operator>>(istream &stream, Clave &p)
{
	int dni;

	stream >> dni;
	p.dni(dni);

	stream >> dni;
	p.numero(dni);

	return stream;
};

ifstream &operator>>(ifstream &stream, Clave &p)
{
	int dni;

	stream >> dni;
	p.dni(dni);

	stream >> dni;
	p.numero(dni);

	return stream;
};
} // fin del espacio de nombres edi

Clave::Clave(const int &d, const int &n)
{
	dni(d);
  numero(n);
};

Clave::Clave()
{
	dni(0);
	numero(0);
};

Clave::Clave(const Clave &p)
{
	*this = p;
};

Clave & Clave::operator=(const Clave &p)
{
	if (this != &p)
	{
		dni(p.dni());
    numero(p.numero());
	}
	return *this;
};

bool Clave::operator==(const Clave &p) const
{
	return dni() == p.dni() and numero() == p.numero();
};

//Sobrecarga del operador < para la ordenación.
bool Clave::operator<(const Clave &p) const
{
	if (dni() < p.dni()) return true;
  else return false;
};

bool Clave::operator<=(const Clave &p) const
{
	return (*this < p or *this == p);
};

bool Clave::operator>(const Clave &p) const
{
	return not (*this <= p);
};

bool Clave::operator>=(const Clave &p) const
{
	return not (*this < p);
};

const int &Clave::dni() const
{
	return dni_;
};

void Clave::dni(const int &dni)
{
	dni_ = dni;
};

const int &Clave::numero() const
{
	return numero_;
};

void Clave::numero(const int &numero)
{
	numero_ = numero;
};
