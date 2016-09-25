#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

struct estructura{
  char mensaje[50];
  int entero;
};

void* cambiaEstructura(struct estructura *aux){
  (*aux).mensaje[0] = '9';
  (*aux).entero = (*aux).entero + 1;
  pthread_exit(NULL);
}

int main(void){
  int nHebras, i;

  printf("\nIntroduzca el número de hebras que desea crear: ");
  scanf("%i", &nHebras);

  struct estructura estructuras[nHebras];
  pthread_t hilos[nHebras];

  for(i=0; i<nHebras; i++){
    printf("\nIntroduzca el mensaje de la estructura número %i:\n\t", i+1);
    scanf("%s", estructuras[i].mensaje);
    printf("\nIntroduzca el entero de la estructura número %i: ", i+1);
    scanf("%i", &estructuras[i].entero);
    pthread_create(&hilos[i], NULL, (void*)cambiaEstructura, &estructuras[i]);
  }
  for(i=0; i<nHebras; i++){
    pthread_join(hilos[i], NULL);
    printf("\nHilo %i:\n\tMensaje:\n\t\t%s\n\tNúmero:\n\t\t%i\n", i, estructuras[i].mensaje, estructuras[i].entero);
  }
  printf("\n");
  return(EXIT_SUCCESS);
}
