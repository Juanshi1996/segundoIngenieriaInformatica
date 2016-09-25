/**** arcivo dados.h ****/
#ifndef _DADOS_H
#define _DADOS_H

class Dados{
private:
  int dado1_;
  int dado2_;
  int lanzamientos1_;
  int lanzamientos2_;
  int acumulacion1_;
  int acumulacion2_;
  int ultimosD1_[5];
  int ultimosD2_[5];

public:
  void lanzamiento();
  int getDado1();
  int getDado2();
  bool setDado1(int valor);
  bool setDado2(int valor);
  int getSuma();
  int getDiferencia();
  int getLanzamientos1();
  int getLanzamientos2();
  Dados();
  float getMedia1();
  float getMedia2();
  void getUltimos1(int* ultimosD1);
  void getUltimos2(int* ultimosD2);
};


#endif
