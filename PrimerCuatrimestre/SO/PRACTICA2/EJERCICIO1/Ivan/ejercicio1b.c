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
  printf("\n");
  return NULL;
}

int main(int argc, char** argv){
  if(argc != 3){
    printf("SINTAXIS: %s CADENA1 CADENA2\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  pthread_t hilo1;
  pthread_t hilo2;

  pthread_create(&hilo1, NULL, mifuncion, (void*) argv[1]);
  pthread_create(&hilo2, NULL, mifuncion, (void*) argv[2]);

  pthread_join(hilo1, NULL);
  pthread_join(hilo2, NULL);

  return 0;
}
