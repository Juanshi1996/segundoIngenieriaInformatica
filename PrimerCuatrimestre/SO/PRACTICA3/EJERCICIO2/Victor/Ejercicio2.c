#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
struct caracteres{
  char vector[4][8];
  int caracter;
} aux = {"\E[31m*", "\E[32m?", "\E[33m+", "\E[34m-"};

void* escribe(void* argv){
  int i;

  if(pthread_mutex_lock(&mtx)!=0){
    printf("ERROR: ha habido un error al bloquear el mutex el hilo %i.\n", (unsigned int)pthread_self());
  }
  for(i = 0; i<5; i++){
    printf("\E[1m%s", aux.vector[aux.caracter]);
    fflush(stdout);
    usleep(250000);
  }
  (aux.caracter)++;
  if(pthread_mutex_unlock(&mtx)!=0){
    printf("ERROR: ha habido un error al desbloquear el mutex el hilo %i.\n", (unsigned int)pthread_self());
  }
  pthread_exit(NULL);
}

int main (int argc, char const *argv[]){
  int i;
  pthread_t hilos[3];

  pthread_mutex_init(&mtx, NULL);
  printf("\n");
  for(i=0; i<3; i++)
  {
    if(pthread_create(hilos+i, NULL, (void*)escribe, NULL)!=0){
      printf("ERROR: ha habido un error al crear el hilo %i.\n", i);
    }
  }
  for(i=0; i<3; i++){
    pthread_join(hilos[i], NULL);
  }
  for(i = 0; i<5; i++){
    printf("\E[1m%s", aux.vector[aux.caracter]);
    fflush(stdout);
    usleep(250000);
  }
  printf("\E[m\n\n");
  return EXIT_SUCCESS;
}
