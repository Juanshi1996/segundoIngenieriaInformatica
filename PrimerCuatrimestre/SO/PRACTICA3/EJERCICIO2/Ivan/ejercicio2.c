#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t cerrojo;

struct caracteres{
  char caracter1;
  char caracter2;
  char caracter3;
  int actual;
};

struct caracteres aux;

void* imprime(void* arg){
  char caracter;
  int i, s;
  s = pthread_mutex_lock(&cerrojo);
  if(s != 0){
    printf("HILO %d: Error al cerrar el cerrojo.\n", (unsigned int) pthread_self());
  }
  if(aux.actual == 1){
    caracter = aux.caracter1;
  }
  else if(aux.actual == 2){
    caracter = aux.caracter2;
  }
  else{
    caracter = aux.caracter3;
  }
  for(i = 0; i<5; i++){
    fflush(stdout);
    putc(caracter, stdout);
    sleep(1);
  }
  printf("\n");
  (aux.actual)++;
  s = pthread_mutex_unlock(&cerrojo);
  if(s != 0){
    printf("HILO %d: Error al abrir el cerrojo.\n", (unsigned int) pthread_self());
  }

  pthread_exit(NULL);
}

int main (int argc, char const *argv[])
{
  pthread_t hilos[3];
  int i,s;
  aux.caracter1 = '@';
  aux.caracter2 = '#';
  aux.caracter3 = '%';
  aux.actual = 0;
  pthread_mutex_init(&cerrojo, NULL);
  s = pthread_create(hilos+0, NULL, (void*) imprime, NULL);
  if(s!=0){
    printf("HILO PRINCIPAL: Error al crear el hilo");
  }
  s = pthread_create(hilos+1, NULL, (void*) imprime, NULL);
  if(s!=0){
    printf("HILO PRINCIPAL: Error al crear el hilo");
  }
  s = pthread_create(hilos+2, NULL, (void*) imprime, NULL);
  if(s!=0){
    printf("HILO PRINCIPAL: Error al crear el hilo");
  }

  for(i = 0; i < 3; i++)
  {
    pthread_join(hilos[i], NULL);
  }
  return 0;
}
