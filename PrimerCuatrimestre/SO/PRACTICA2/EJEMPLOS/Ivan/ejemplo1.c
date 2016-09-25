#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct param{
  char* frase;
  int numero;
};

void hiloMensaje(struct param *mensa){
  struct param *aux = (struct param*) mensa;
  printf("%s %d\n", aux->frase, aux->numero);
  printf("%s %d\n", mensa->frase, mensa->numero);
}

int main(){
  pthread_t thd1, thd2;
  struct param param1 = {"Soy el hilo", 1};
  struct param param2 = {"Digo otra cosa", 2};

  pthread_create(&thd1, NULL, (void*) hiloMensaje, &param1);
  pthread_create(&thd2, NULL, (void*) hiloMensaje, &param2);

  pthread_join(thd1, NULL);
  pthread_join(thd2, NULL);

  printf("Han finalizado los thread.\n");
  exit(EXIT_SUCCESS);
}
