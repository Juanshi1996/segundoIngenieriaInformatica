/**** arcivo dados.h ****/
#ifndef _DADOS_H
#define _DADOS_H

class Dados{
private:
  int dado1_;
  int dado2_;
public:
  void lanzamiento();
  int getDado1();
  int getDado2();
  bool setDado1(int valor);
  bool setDado2(int valor);
  int getSuma();
  int getDiferencia();
  Dados(int initdado1 = 1, int initdado2 = 1);
};


#endif
