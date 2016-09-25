#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void* mifuncion(void* cadena){
  char* aux = (char*) cadena;
  int i;

  for(i=0; i<strlen(aux); i++){
    printf("[%c] ", aux[i]);
    fflush(stdout);
    sleep(1);
  }
  return NULL;
}

int main(void){
  pthread_t hilo1;
  pthread_t hilo2;

  pthread_create(&hilo1, NULL, mifuncion, (void*) "hola");
  pthread_create(&hilo2, NULL, mifuncion, (void*) "mundo");

  pthread_join(hilo1, NULL);
  pthread_join(hilo2, NULL);

  return 0;
}
