#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct estructura{
  int entero;
  char cadena[20];
};

void* funcionEstructura(void* arg){
  struct estructura* estructura = (struct estructura*) arg;
  (*estructura).entero++;
  (*estructura).cadena[0] = '9';
  pthread_exit(NULL);
}

int main(){
  int nhebras, i;
  printf("Introduzca el numero de hebras: ");
  scanf("%d", &nhebras);
  pthread_t hilos[nhebras];
  struct estructura auxiliar[nhebras];

  for(i=0; i<nhebras; i++){
    printf("ESTRUCTURA %d\n", i);
    printf("Introduza el numero: ");
    scanf("%d", &auxiliar[i].entero);
    getchar();
    printf("Introduzca la cadena: ");
    fgets(auxiliar[i].cadena, 20, stdin);
    pthread_create(hilos+i, NULL, (void*) funcionEstructura, auxiliar+i);
  }
  for(i=0; i<nhebras; i++){
    pthread_join(hilos[i], NULL);
    printf("ESTRUCTURA %d\n", i);
    printf("Entero: %d\n", auxiliar[i].entero);
    printf("Cadena: %s\n", auxiliar[i].cadena);
    printf("____________\n\n");
  }
}
