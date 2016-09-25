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

#include "jugador.h"
#include "gtest/gtest.h"
#include <fstream>
#include <string>
#include <iostream>

TEST(Jugador, ConstructorParametrosDefecto) {
  Jugador p("33XX", "XX33");

  EXPECT_EQ("33XX", p.getDNI());
  EXPECT_EQ("XX33", p.getCodigoJugador());
  EXPECT_EQ("", p.getNombre());
  EXPECT_EQ("", p.getApellidos());
  EXPECT_EQ("", p.getDireccion());
  EXPECT_EQ("", p.getLocalidad());
  EXPECT_EQ("", p.getProvincia());
  EXPECT_EQ("", p.getPais());
  EXPECT_EQ(", ", p.getApellidosyNombre());
}

TEST(Jugador, ConstructorParametros) {
  Jugador p("44XX", "XX44", "Carlos", "Gutierrez", "C/ Mesa 1", "Aguilar", "Sevilla", "España");

  EXPECT_EQ("44XX", p.getDNI());
  EXPECT_EQ("XX44", p.getCodigoJugador());
  EXPECT_EQ("Carlos", p.getNombre());
  EXPECT_EQ("Gutierrez", p.getApellidos());
  EXPECT_EQ("C/ Mesa 1", p.getDireccion());
  EXPECT_EQ("Aguilar", p.getLocalidad());
  EXPECT_EQ("Sevilla", p.getProvincia());
  EXPECT_EQ("España", p.getPais());
  EXPECT_EQ("Gutierrez, Carlos", p.getApellidosyNombre());
}

TEST(Jugador, ConstructorCopiaDefecto) {
  Jugador p("44XX","XX44", "Carlos", "Gutierrez", "C/ Mesa 1", "Aguilar", "Sevilla", "España");
  Jugador q(p);
  Jugador r=q;
  EXPECT_EQ("44XX", q.getDNI());
  EXPECT_EQ("XX44", q.getCodigoJugador());
  EXPECT_EQ("Carlos", q.getNombre());
  EXPECT_EQ("Gutierrez", q.getApellidos());
  EXPECT_EQ("C/ Mesa 1", q.getDireccion());
  EXPECT_EQ("Aguilar", q.getLocalidad());
  EXPECT_EQ("Sevilla", q.getProvincia());
  EXPECT_EQ("España", q.getPais());
  EXPECT_EQ("Gutierrez, Carlos", q.getApellidosyNombre());

  EXPECT_EQ("44XX", r.getDNI());
  EXPECT_EQ("XX44", r.getCodigoJugador());
  EXPECT_EQ("Carlos", r.getNombre());
  EXPECT_EQ("Gutierrez", r.getApellidos());
  EXPECT_EQ("C/ Mesa 1", r.getDireccion());
  EXPECT_EQ("Aguilar", r.getLocalidad());
  EXPECT_EQ("Sevilla", r.getProvincia());
  EXPECT_EQ("España", r.getPais());
  EXPECT_EQ("Gutierrez, Carlos", r.getApellidosyNombre());
}

TEST(Jugador, OperadorIgualDefecto) {
  Jugador p("44XX","XX44", "Carlos", "Gutierrez", "C/ Mesa 1", "Aguilar", "Sevilla", "España");
  Jugador q("33XX","XX33");
  q=p;
  EXPECT_EQ("44XX", q.getDNI());
  EXPECT_EQ("XX44", p.getCodigoJugador());
  EXPECT_EQ("Carlos", q.getNombre());
  EXPECT_EQ("Gutierrez", q.getApellidos());
  EXPECT_EQ("C/ Mesa 1", q.getDireccion());
  EXPECT_EQ("Aguilar", q.getLocalidad());
  EXPECT_EQ("Sevilla", q.getProvincia());
  EXPECT_EQ("España", q.getPais());
  EXPECT_EQ("Gutierrez, Carlos", q.getApellidosyNombre());
}

TEST(Jugador, MetodosApuestas){
	ifstream file;
  Jugador p("44XX", "XX44");
  list<Apuesta> aux;
  Apuesta auxiliar, original;
  char line[30];

  p.setApuestas();
  aux = p.getApuestas();
  file.open((p.getDNI()+".txt").c_str());
  if(file.is_open()){
    while (file.getline(line, 100, ','))
    {
      auxiliar = aux.front();
      aux.pop_front();
      original.tipo = atoi(line);
      file.getline (line, 100, ',');
      original.valor = line;
      file.getline (line, 100);
      original.cantidad = atoi(line);
      EXPECT_EQ(original.tipo, auxiliar.tipo);
      EXPECT_EQ(original.valor, auxiliar.valor);
      EXPECT_EQ(original.cantidad, auxiliar.cantidad);
    }
  }
  file.close();
}
