#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

struct parametros{
  float escalar;
  float matriz[3][3];
};

void* multiplicar(void* matriz){
  int i, j;
  struct parametros *aux = (struct parametros*)matriz;

  for(i=0; i<3; i++){
    for(j=0; j<3; j++){
      (*aux).matriz[i][j] = (*aux).matriz[i][j]*(*aux).escalar;
    }
  }
  pthread_exit(NULL);
}

int main(void){
  int i, j;
  struct parametros matriz1, matriz2;
  pthread_t hilo1, hilo2;

  printf("\n\E[33mIntroduzca la primera matriz.\n\n");
  for(i=0; i<3; i++){
    for(j=0; j<3; j++){
      printf("Elemento [%i][%i]: ", i, j);
      scanf("%f", &(matriz1.matriz[i][j]));
    }
  }
  printf("\nIntroduzca el escalar por el que quiere multiplicar su primera matriz: ");
  scanf("%f", &(matriz1.escalar));
  printf("\n\E[32mIntroduzca la segunda matriz.\n\n");
  for(i=0; i<3; i++){
    for(j=0; j<3; j++){
      printf("Elemento [%i][%i]: ", i, j);
      scanf("%f", &(matriz2.matriz[i][j]));
    }
  }
  printf("\nIntroduzca el escalar por el que quiere multiplicar su segunda matriz: ");
  scanf("%f", &(matriz2.escalar));
  pthread_create(&hilo1, NULL, multiplicar, (void*)&matriz1);
  pthread_create(&hilo2, NULL, multiplicar, (void*)&matriz2);
  pthread_join(hilo1, NULL);
  pthread_join(hilo2, NULL);
  printf("\n\E[33mLa primera matriz multiplicada por %.2f, es:\n", matriz1.escalar);
  for(i=0; i<3; i++){
    for(j=0; j<3; j++){
      printf("\nElemento [%i][%i]: %.2f", i, j, matriz1.matriz[i][j]);
    }
  }
  printf("\n\n\E[32mLa primera matriz multiplicada por %.2f, es:\n", matriz2.escalar);
  for(i=0; i<3; i++){
    for(j=0; j<3; j++){
      printf("\nElemento [%i][%i]: %.2f", i, j, matriz2.matriz[i][j]);
    }
  }
  printf("\e[0m\n\n");
  return(EXIT_SUCCESS);
}
