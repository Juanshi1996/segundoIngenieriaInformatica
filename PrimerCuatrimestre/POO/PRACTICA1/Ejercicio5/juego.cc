//juego.cc
//Implementacion de un juego de dados con la clase Dados

#include "dados.h"
#include <iostream>

using namespace std;

int main(void){
  Dados p;
  int valor1, valor2, aux;
  cout<< "Al crear un objeto de la clase Dados, el constructor inicializa\n";
  cout<< "Los siguientes valores: \n";
  cout<< "Dado1 -> " << p.getDado1() << endl;
  cout<< "Dado2 -> " << p.getDado2() << endl;
  cout<< "Ahora realizamos un lanzamiento de los dados.\n";
  p.lanzamiento();
  cout<< "Mostramos ahora el valor de los dados: \n";
  cout<< "Dado1 -> " << p.getDado1() << endl;
  cout<< "Dado2 -> " << p.getDado2() << endl;
  do{
      cout<< "Ahora, introduzca un valor para el dado1: ";
      cin>> valor1;
      aux = p.setDado1(valor1);
  }while(aux == false);
  do{
      cout<< "Ahora, introduzca un valor para el dado2: ";
      cin>> valor2;
      aux = p.setDado2(valor2);
  }while(aux == false);
  cout<< "Volvemos a mostrar los dados.\n";
  cout<< "Dado1 -> " << p.getDado1() << endl;
  cout<< "Dado2 -> " << p.getDado2() << endl;
  cout<< "No nos olvidamos de mostrar la suma: " << p.getSuma() << endl;
  cout<< "Y por ultimo, mostramos la diferencia: " << p.getDiferencia() << endl;

  return 0;
}
