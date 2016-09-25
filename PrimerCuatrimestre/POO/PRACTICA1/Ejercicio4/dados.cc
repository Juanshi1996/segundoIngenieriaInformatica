/**** archivo dados.cc ****/
#include "dados.h"
#include <cstdlib>
#include <ctime>

void Dados::lanzamiento(){
  dado1_ = rand();
  dado2_ = rand();
  dado1_ = (dado1_%6)+1;
  dado2_ = (dado2_%6)+1;
}

int Dados::getDado1(){
  return dado1_;
}

int Dados::getDado2(){
  return dado2_;
}

bool Dados::setDado1(int valor){
  if(valor > 0 && valor < 7){
    dado1_ = valor;
    return true;
  }
  else{
    return false;
  }

}

bool Dados::setDado2(int valor){
  if(valor > 0 && valor < 7){
    dado2_ = valor;
    return true;
  }
  else{
    return false;
  }
}

int Dados::getSuma(){
  return getDado1()+getDado2();
}

int Dados::getDiferencia(){
  if(dado1_ > dado2_){
    return dado1_-dado2_;
  }
  else{
    return dado2_-dado1_;
  }
}

Dados::Dados(int initdado1, int initdado2){
  dado1_ = initdado1;
  dado2_  = initdado2;
}
