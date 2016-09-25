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

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "dados.h"
#include "gtest/gtest.h"

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

// Tests operación diferencia
TEST(Dados, Diferencia) {
  Dados d;
  d.lanzamiento();
  if(d.getDado1() > d.getDado2()){
      EXPECT_EQ(d.getDado1()-d.getDado2(), d.getDiferencia());
  }
  else{
      EXPECT_EQ(d.getDado2()-d.getDado1(), d.getDiferencia());
  }
}

TEST(Dados, ObtenerLanzamientos) {
  Dados d;
  int n = 100,i;

  EXPECT_EQ(0, d.getLanzamientos1());
  EXPECT_EQ(0, d.getLanzamientos2());


  for(i=0 ; i< n; i++){
    d.lanzamiento();
  }
  EXPECT_EQ(n, d.getLanzamientos1());
  EXPECT_EQ(n, d.getLanzamientos2());

}

TEST(Dados, Media){
  Dados d;
  srand(time(NULL));

  EXPECT_EQ(0, d.getMedia1());
  EXPECT_EQ(0, d.getMedia2());
  int i, acumulacion1 = 0, acumulacion2 = 0;

  for(i = 0; i< 10; i++){
    d.setDado1((rand()%6)+1);
    d.setDado2((rand()%6)+1);
    acumulacion1 += d.getDado1();
    acumulacion2 += d.getDado2();
  }

  EXPECT_EQ((float)acumulacion1/(float)10, d.getMedia1());
  EXPECT_EQ((float)acumulacion2/(float)10, d.getMedia2());

}

TEST(Dados, Vector){
	Dados d;
	int vector1[5];
	int vector2[5];
	int vectoraux1[5];
	int vectoraux2[5];

	int i,n = 100;
	for(i=0; i<n; i++){
		d.lanzamiento();
		vector1[i%5] = d.getDado1();
		vector2[i%5] = d.getDado2();
	}
	d.getUltimos1(vectoraux1);
	d.getUltimos2(vectoraux2);
	for(i=0; i<5; i++){
		 EXPECT_EQ(vector1[i], vectoraux1[i]);
		 EXPECT_EQ(vector2[i], vectoraux2[i]);
	}
}
