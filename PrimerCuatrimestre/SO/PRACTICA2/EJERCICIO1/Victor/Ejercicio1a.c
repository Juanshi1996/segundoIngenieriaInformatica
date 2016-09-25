#include <string.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* holaMundo(void* cadena) {
  int i;

  for(i=0; i<strlen((char*)cadena); i++) {
    if(strcmp((char*)cadena, "hola") == 0) {
      printf("\E[34m\E[1m%c\e[0m", ((char*)cadena)[i]);
      fflush(stdout);
      sleep(1);
    } else if(strcmp((char*)cadena, "mundo") == 0){
      printf("\E[33m\E[22m%c\e[0m", ((char*)cadena)[i]);
      fflush(stdout);
      sleep(1);
    }
  }
  pthread_exit(NULL);
}

int main(void) {
  pthread_t hilo1, hilo2;

  printf("\n");
  pthread_create(&hilo1, NULL, (void*)holaMundo, (void*)"hola");
  pthread_create(&hilo2, NULL, (void*)holaMundo, (void*)"mundo");
  pthread_join(hilo1, NULL);
  pthread_join(hilo2, NULL);
  printf("\n\n");
  return(EXIT_SUCCESS);
}
