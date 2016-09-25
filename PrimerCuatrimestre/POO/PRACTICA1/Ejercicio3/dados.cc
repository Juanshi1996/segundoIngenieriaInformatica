#include "dados.h"
#include <cstdlib>
#include <ctime>

void Dados::lanzamiento()
{
	dado1_ = (rand() %6) +1;
	dado2_ = (rand() %6) +1;
	ultimos1_[getLanzamientos1()%5] = dado1_;
	ultimos2_[getLanzamientos2()%5] = dado2_;
	lanzamientos1_ = lanzamientos1_ +1;
	lanzamientos2_ = lanzamientos2_ +1;
	sumatorioLanzamientos1_ = sumatorioLanzamientos1_ + getDado1();
	sumatorioLanzamientos2_ = sumatorioLanzamientos2_ + getDado2();
	
}

int Dados::getDado1()
{
	return(dado1_);
}

int Dados::getDado2()
{
	return(dado2_);
}

bool Dados::setDado1(int valor)
{
	if ((valor>0) && (valor<7))
	{
		dado1_ = valor;
		ultimos1_[getLanzamientos1()%5] = valor;
		lanzamientos1_ = getLanzamientos1() +1;
		sumatorioLanzamientos1_ = sumatorioLanzamientos1_ + getDado1();
		return(true);
	}
	else
	{
		return(false);
	}
}

bool Dados::setDado2(int valor)
{
	if ((valor>0) && (valor<7))
	{
		dado2_ = valor;
		ultimos2_[getLanzamientos2()%5] = valor;
		lanzamientos2_ = getLanzamientos2() +1;
		sumatorioLanzamientos2_ = sumatorioLanzamientos2_ + getDado2();
		return(true);
	}
	else
	{
		return(false);
	}
}

int Dados::getSuma()
{
	return(getDado1()+getDado2());
}

int Dados::getDiferencia()
{
	if (getDado1() > getDado2())
	{
		return(getDado1()-getDado2());
	}
	else
	{
		return(getDado2()-getDado1());
	}
}

int Dados::getLanzamientos1()
{
	return(lanzamientos1_);
}

int Dados::getLanzamientos2()
{
	return(lanzamientos2_);
}

float Dados::getMedia1()
{
	if (getLanzamientos1() == 0)
	{
		return(0);
	}
	else
	{
		return ((float)sumatorioLanzamientos1_/(float)getLanzamientos1());
	}
}

float Dados::getMedia2()
{
	if (getLanzamientos2() == 0)
	{
		return(0);
	}
	else
	{
		return ((float)sumatorioLanzamientos2_/(float)getLanzamientos2());
	}
}

void Dados::getUltimos1(int *ultimos1)
{
	int i;
	
	for (i=0; i<5; i++)
	{
		ultimos1[i] = ultimos1_[i];
	}
}

void Dados::getUltimos2(int *ultimos2)
{
	int i;
	
	for (i=0; i<5; i++)
	{
		ultimos2[i] = ultimos2_[i];
	}
}

Dados::Dados()
{
	srand(time(NULL));
	dado1_ = 1;
	dado2_ = 1;
	lanzamientos1_ = 0;
	lanzamientos2_ = 0;
	sumatorioLanzamientos1_ = 0;
	sumatorioLanzamientos2_ = 0;
}
