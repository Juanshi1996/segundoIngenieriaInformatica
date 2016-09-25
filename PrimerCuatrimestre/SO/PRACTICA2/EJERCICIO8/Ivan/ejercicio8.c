#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int global = 0;

void* incrementaGlobal(){
  int i;
  for(i=0; i<50; i++){
    global++;
  }
  pthread_exit(NULL);
}

int main(){
  pthread_t hilos[2];
  pthread_create(hilos, NULL, (void*) incrementaGlobal, NULL);
  pthread_create(hilos+1, NULL, (void*) incrementaGlobal, NULL);
  pthread_join(hilos[0], NULL);
  pthread_join(hilos[1], NULL);
  printf("EL resultado de la variable global es %d\n", global);
  return 0;
}
