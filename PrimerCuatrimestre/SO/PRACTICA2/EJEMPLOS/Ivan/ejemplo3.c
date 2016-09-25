#include <stdio.h>
#include <pthread.h>

void* mifuncion(void* arg);

void main(){
  pthread_t tid;

  int misargs[2];
  misargs[0] = -5;
  misargs[1] = -6;

  printf("Se va a crear un hilo...\n");
  pthread_create(&tid, NULL, mifuncion, (void*)misargs);
  printf("Hilo creado. Esperando su finalizacion con pthread_join()...\n");

  pthread_join(tid, NULL);
  printf("Hilo finalizado..\n");
}

void* mifuncion(void* arg){
  int* argu;
  printf("Hilo hijo ejecutando...\n");
  argu = (int*) arg;
  printf("Hilo hijo: arg1 = %d, arg2 = %d\n", argu[0], argu[1]);

  printf("Hilo hijo finalizando...\n");
  pthread_exit(NULL);
}
