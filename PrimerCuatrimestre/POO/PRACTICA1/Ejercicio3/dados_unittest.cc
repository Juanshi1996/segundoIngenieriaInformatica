// dados_unittest.cc: Juan A. Romero
// A sample program demonstrating using Google C++ testing framework.
//


// This sample shows how to write a more complex unit test for a class
// that has multiple member functions.
//
// Usually, it's a good idea to have one test for each method in your
// class.  You don't have to do that exactly, but it helps to keep
// your tests organized.  You may also throw in additional tests as
// needed.

#include "dados.h"
#include "gtest/gtest.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Tests the c'tor.
TEST(Dados, Constructor) {
  Dados d;
  
  EXPECT_EQ(1, d.getDado1());
  EXPECT_EQ(1, d.getDado2());
  EXPECT_EQ(2, d.getSuma());
  
}

// Tests operación lanzamiento
TEST(Dados, Lanzamiento) {
  Dados d;
  for (int i=0; i<100; i++){
  d.lanzamiento();
  EXPECT_GT(d.getDado1(), 0);
  EXPECT_LT(d.getDado1(), 7);
  EXPECT_GT(d.getDado2(), 0);
  EXPECT_LT(d.getDado2(), 7);
}

}

// Tests operación suma
TEST(Dados, Suma) {
  Dados d;
  
  EXPECT_EQ(d.getDado1()+d.getDado2(), d.getSuma());
}

// Tests operación diferencia
TEST(Dados, Diferencia) {
	Dados d;
	
	d.lanzamiento ();
	if (d.getDado1() > d.getDado2())
	{
		EXPECT_EQ(d.getDado1()-d.getDado2(), d.getDiferencia());
	}
	else
	{
		EXPECT_EQ(d.getDado2()-d.getDado1(), d.getDiferencia());
	}
}

// Tests modificadores
TEST(Dados, Modificadores) {
  Dados d;
  
  EXPECT_FALSE(d.setDado1(9));
  EXPECT_FALSE(d.setDado1(-9));
  EXPECT_FALSE(d.setDado2(9));
  EXPECT_FALSE(d.setDado2(-9));
  d.setDado1(3);
  EXPECT_EQ(3, d.getDado1());
  d.setDado2(2);
  EXPECT_EQ(2, d.getDado2());
  EXPECT_EQ(5, d.getSuma());
}

//Tests lanzamientos
TEST(Dados, Lanzamientos) {
	Dados d;
	int n, i;
	
	EXPECT_EQ(0, d.getLanzamientos1());
	EXPECT_EQ(0, d.getLanzamientos2());
	cout<< "\nIntroduzca el número de veces que desea lanzar el dado: ";
	cin>> n;
	cout<< "\n";
	for (i=0; i<n; i++)
	{
		d.lanzamiento();
	}
	EXPECT_EQ(n, d.getLanzamientos1());
	EXPECT_EQ(n, d.getLanzamientos2());
}

//Tests medias
TEST(Dados, Medias) {
	Dados d;
	int i, sumatorioSetDado1=0, sumatorioSetDado2=0;
	
	EXPECT_EQ(0, d.getMedia1());
	EXPECT_EQ(0, d.getMedia2());
	srand(time(NULL));
	for (i=0; i<100; i++)
	{
		d.setDado1((rand()%6)+1);
		d.setDado2((rand()%6)+1);
		sumatorioSetDado1 = sumatorioSetDado1 + d.getDado1();
		sumatorioSetDado2 = sumatorioSetDado2 + d.getDado2();
	}
	EXPECT_EQ((float)sumatorioSetDado1/(float)100, d.getMedia1());
	EXPECT_EQ((float)sumatorioSetDado2/(float)100, d.getMedia2());
}

//Tests últimos
TEST(Dados, Ultimos) {
	Dados d;
	int i;
	int aux1[5], aux2[5], ultimos1[5], ultimos2[5];
	
	for (i=0; i<100; i++)
	{
		d.lanzamiento();
		aux1 [i%5] = d.getDado1();
		aux2 [i%5] = d.getDado2();
	}
	d.getUltimos1(ultimos1);
	d.getUltimos2(ultimos2);
	for (i=0; i<5; i++)
	{
		EXPECT_EQ(aux1[i], ultimos1[i]);
		EXPECT_EQ(aux2[i], ultimos2[i]);
	}
}
