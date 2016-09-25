#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

int global=0;

void* incrementaVariableGlobal(){
  int i;

  for(i=0; i<50; i++){
    global = global+1;
  }
  return(NULL);
}

int main(void){
  pthread_t hilo1, hilo2;

  pthread_create(&hilo1, NULL, incrementaVariableGlobal, NULL);
  pthread_create(&hilo2, NULL, incrementaVariableGlobal, NULL);
  pthread_join(hilo1, NULL);
  pthread_join(hilo2, NULL);
  printf("\nEl valor de la variable global es: %i\n\n", global);
  return(EXIT_SUCCESS);
}
