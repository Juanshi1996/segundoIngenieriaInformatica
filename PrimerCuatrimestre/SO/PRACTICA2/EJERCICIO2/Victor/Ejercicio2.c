#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

void* numerosAleatorios(void* nHebra) {
  long nAleatorio1, nAleatorio2, suma;

  srand(time(NULL));
  nAleatorio1 = (rand()%5)+1;
  nAleatorio2 = (rand()%5)+1;
  suma = nAleatorio1+nAleatorio2;
  printf("\nHebra número %li; número1: %li, número2: %li; suma = %li.", ((long)nHebra)+1, nAleatorio1, nAleatorio2, suma);
  pthread_exit((void*)suma);
}

int main(void) {
  long nHebras, i, aux, sumatorio=0;

  printf("\nIntroduzca el número de hebras que desea crear: ");
  scanf("%li", &nHebras);
  pthread_t hilos [nHebras];
  for(i=0; i<nHebras; i++){
    pthread_create(&hilos[i], NULL, (void*)numerosAleatorios, (void*)i);
    sleep(1);
  }
  for(i=0; i<nHebras; i++) {
    pthread_join(hilos[i], (void**)&aux);
    sumatorio = sumatorio+aux;
  }
  printf("\n\nEl valor del sumatorio de los números generados aleatoriamente en cada hebra es %li.\n\n", sumatorio);
  return(EXIT_SUCCESS);
}
