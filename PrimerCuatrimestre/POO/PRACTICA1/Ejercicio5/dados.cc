/**** archivo dados.cc ****/
#include "dados.h"
#include <cstdlib>
#include <ctime>

void Dados::lanzamiento(){
  dado1_ = rand();
  dado2_ = rand();
  dado1_ = (dado1_%6)+1;
  dado2_ = (dado2_%6)+1;
  ultimosD1_[getLanzamientos1()%5] = dado1_;
  ultimosD2_[getLanzamientos2()%5] = dado2_;
  lanzamientos1_++;
  lanzamientos2_++;
  acumulacion1_ += dado1_;
  acumulacion2_ += dado2_;
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
	ultimosD1_[getLanzamientos1()%5] = dado1_;
    lanzamientos1_++;
    acumulacion1_ += dado1_;
    return true;
  }
  else{
    return false;
  }

}
bool Dados::setDado2(int valor){
  if(valor > 0 && valor < 7){
    dado2_ = valor;
	ultimosD2_[getLanzamientos2()%5] = dado2_;
    lanzamientos2_++;
    acumulacion2_ += dado2_;
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

Dados::Dados(){
  dado1_ = 1;
  dado2_ = 1;
  lanzamientos1_ = 0;
  lanzamientos2_ = 0;
  acumulacion1_ = 0;
  acumulacion2_ = 0;
}

int Dados::getLanzamientos1(){
  return lanzamientos1_;
}

int Dados::getLanzamientos2(){
  return lanzamientos2_;
}

float Dados::getMedia1(){
  if(lanzamientos1_){
      return (float) acumulacion1_ / (float)lanzamientos1_;
  }
  else{
    return 0;
  }
}

float Dados::getMedia2(){
  if(lanzamientos1_){
      return (float) acumulacion2_ / (float)lanzamientos2_;
  }
  else{
    return 0;
  }
}

void Dados::getUltimos1(int* ultimosD1){
	int i;
	for(i=0; i<5; i++){
		ultimosD1[i] = ultimosD1_[i];
	}
}

void Dados::getUltimos2(int* ultimosD2){
	int i;
	for(i=0; i<5; i++){
		ultimosD2[i] = ultimosD2_[i];
	}
}
