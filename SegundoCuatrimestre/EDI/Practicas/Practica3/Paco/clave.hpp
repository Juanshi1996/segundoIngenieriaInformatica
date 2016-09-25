#ifndef __CLAVE_HPP__
#define __CLAVE_HPP__

#include <iostream>
#include <fstream>

using std::ostream;
using std::istream;
using std::ofstream;
using std::ifstream;

namespace edi {

class Clave
{
	private:
		int dni_;
		int numero_;

	public:
		Clave();

		Clave(const int &dni, const int &n);

		Clave(const Clave &p);

    const int &dni()const;

    const int &numero()const;

		void dni(const int &dni);

    void numero(const int &numero);

		Clave & operator=(const Clave &p);

		bool operator==(const Clave &p)const;

		bool operator<(const Clave &p) const;

		bool operator>(const Clave &p) const;

		bool operator<=(const Clave &p) const;

		bool operator>=(const Clave &p) const;

		friend ostream & operator<<(ostream &stream, const Clave &p);

		friend ofstream & operator<<(ofstream &stream, const Clave &p);

		friend istream &operator>>(istream &stream, Clave &p);

		friend ifstream &operator>>(ifstream &stream, Clave &p);



};

}

#endif
