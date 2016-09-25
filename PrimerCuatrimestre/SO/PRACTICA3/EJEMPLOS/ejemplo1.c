#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t cerrojo;
int global = 0;

void* funcion(void* arg){
  int ciclos = *((int*) arg);
  int loc, j, s;
  for(j = 0;j < ciclos ;j++)
  {
    s = pthread_mutex_lock(&cerrojo);
    if(s != 0){
      printf("ERROR: Fallo en el bloqueo del cerrojo.\n");
    }
    loc = global;
    loc++;
    global = loc;
    printf("Hilo %d incrementando la variable global\n", (unsigned int) pthread_self());
    s = pthread_mutex_unlock(&cerrojo);
    if(s != 0){
      printf("ERROR: Fallo en el desbloqueo del cerrojo.\n");
    }
  }
  pthread_exit(NULL);
}

int main (int argc, char const *argv[])
{
  pthread_t hilo1, hilo2;
  pthread_mutex_init(&cerrojo, NULL);
  int ciclos, s;
  if(argc != 2){
    printf("SINTAXIS: %s NUMERODECICLOS\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  ciclos = atoi(argv[1]);
  s = pthread_create(&hilo1, NULL, (void*) funcion, (void*) &ciclos);
  if(s != 0){
    printf("ERROR: Fallo al crear el hilo 1.\n");
  }
  s = pthread_create(&hilo2, NULL, (void*) funcion, (void*) &ciclos);
  if(s != 0){
    printf("ERROR: Fallo al crear el hilo 2.\n");
  }
  printf("HILO PRINCIPAL: Parando a los hilos con join.\n");
  s = pthread_join(hilo1, NULL);
  if(s != 0){
    printf("ERROR: Fallo en el join del hilo 1.\n");
  }
  s = pthread_join(hilo2, NULL);
  if(s != 0){
    printf("ERROR: Fallo en el join del hilo 2.\n");
  }
  printf("HILO PRINICIPAL: Han finalizado los join, el valor de la global es %d\n", global);
  return 0;
}
