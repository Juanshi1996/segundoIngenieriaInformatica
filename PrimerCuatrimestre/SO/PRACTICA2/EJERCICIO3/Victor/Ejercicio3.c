#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define NELEMENTOS 10

void* sumaParalela(void* numero) {
  fflush(stdout);
  pthread_exit((void*)numero);
}

int main(int argc, char *argv[]){
  long vector[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  long i, j, sumaParcial=0, sumatorio=0;

  if(argc != 2){
    printf("\nERROR de sintaxis: ./Ejercicio3 <nHilos>\n\n");
    exit(EXIT_FAILURE);
  }
  if((atoi(argv[1])<1) || (atoi(argv[1])>10)){
    printf("\nERROR: El número de hilos debe estar comprendido entre 1 y 10.\n\n");
    exit(EXIT_FAILURE);
  }

  long nHilos = atoi(argv[1]);
  pthread_t hilos [nHilos];

  for(i=1; i<=NELEMENTOS; i++){
    pthread_create(&hilos[(i-1)%nHilos], NULL, sumaParalela, (void*)vector[i-1]);
    printf("\nSoy el hilo número %ld y voy a sumar %ld.", ((i-1)%nHilos)+1, vector[i-1]);
    if (i%nHilos == 0){
      for (j=0; j<nHilos; j++){
        pthread_join(hilos[j], (void**)&sumaParcial);
        sumatorio = sumatorio+sumaParcial;
      }
    }
  }
  for (i=NELEMENTOS-NELEMENTOS%nHilos; i<10; i++){
    pthread_join(hilos[i%nHilos], (void**)&sumaParcial);
    sumatorio = sumatorio+sumaParcial;
  }
  printf("\nLa suma total de los elementos del vector es %ld.\n\n", sumatorio);
  return(EXIT_SUCCESS);
}
