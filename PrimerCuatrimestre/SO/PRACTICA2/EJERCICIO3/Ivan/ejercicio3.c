#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

struct datos{
  int comienza;
  int* vector;
  int para;
};

void* sumaHilos(void* estructura){
  struct datos *auxiliar;
  int i;
  long suma = 0;
  auxiliar = (struct datos*) estructura;
  for(i = (*auxiliar).comienza; i<(*auxiliar).para; i++){
    suma += (*auxiliar).vector[i];
  }
  printf("\E[33mHILO %d-%d: El resultado de mi semisuma es %ld\n\e[0m",(*auxiliar).comienza, (*auxiliar).para, suma);
  pthread_exit((void*) suma);
}

int main(void){
  int nhebras, i, sumaac = 0, division, sobra;
  long res;
  struct datos *aux = malloc(sizeof(struct datos));
  printf("Introduzca el numero de hebras: ");
  scanf("%d", &nhebras);
  pthread_t hilos[nhebras];

  int vector[] = {0,1,2,3,4,5,6,7,8,9};

  (*aux).vector = vector;
  (*aux).comienza = 0;
  division = (10/nhebras)+1;
  sobra = 10%nhebras;
  (*aux).para = division;
  if((*aux).para > 10){
    (*aux).para = 10;
  }
  for(i=0; i<nhebras; i++){
      pthread_create(hilos+i, NULL, (void*) sumaHilos, (void*) aux);
      sleep(1);
      fflush(stdout);
      (*aux).comienza += division;
      (*aux).para += division;
      if((*aux).para > 10){
        (*aux).para = 10;
      }
  }
  /*
  if(10%sobra != 0){
    (*aux).comienza = 10-sobra;
    (*aux).para = (*aux).comienza+1;
    for(i=0; i<10%nhebras; i++){
        pthread_create(hilos+i, NULL, (void*) sumaHilos, (void*) aux);
        sleep(1);
        fflush(stdout);
        (*aux).comienza++;
        (*aux).para++;
    }
  }*/
  for(i=0; i<nhebras; i++){
    pthread_join(hilos[i], (void **)&res);
    sumaac += res;
  }

  printf("\E[31mHILO PRINCIPAL: El resultado de la suma total es %d\n\e[0m", sumaac);

  return 0;
}
