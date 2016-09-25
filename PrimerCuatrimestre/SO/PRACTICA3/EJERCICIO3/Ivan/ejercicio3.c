#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define TAMVECTOR 5

int contador;
int vector[5] = {1,2,3,4,5};
pthread_mutex_t cerrojo;

void mostrarVector(int* vector, int nEle){
  int i;
  printf("[");
  for(i=0; i<nEle; i++){
    printf("%d ", vector[i]);
  }
  printf("]\n");
}

void* productor(void* arg){
  int elemento = 0;
  while(1){
    elemento = rand();
    pthread_mutex_lock(&cerrojo);
    if(vector[0] == 0){
      vector[0] = elemento;
    }
    else if(vector[1] == 0){
      vector[1] = elemento;
    }
    else if(vector[2] == 0){
      vector[2] = elemento;
    }
    else if(vector[3] == 0){
      vector[3] = elemento;
    }
    else if(vector[4] == 0){
      vector[4] = elemento;
    }
    printf("HILO PRODUCTOR: He introducido un entero %d.\n", elemento);
    pthread_mutex_unlock(&cerrojo);
  }
}

void* consumidor(void* arg){
  int elemento;
  while(1){
    pthread_mutex_lock(&cerrojo);
    if(vector[4] != 0){
      elemento = vector[4];
      vector[4] = 0;
    }
    else if(vector[3] != 0){
      elemento = vector[3];
      vector[3] = 0;
    }
    else if(vector[2] != 0){
      elemento = vector[2];
      vector[2] = 0;
    }
    else if(vector[1] != 0){
      elemento = vector[1];
      vector[1] = 0;
    }
    else if(vector[0] != 0){
      elemento = vector[0];
      vector[0] = 0;
    }
    printf("HILO CONSUMIDOR: He consumido un entero %d.\n", elemento);
    pthread_mutex_unlock(&cerrojo);
  }
}

int main (int argc, char const *argv[])
{
  srand(time(NULL));
  pthread_mutex_init(&cerrojo, NULL);
  pthread_t hiloproductor, hiloconsumidor;

  pthread_create(&hiloproductor, NULL, (void*) productor, NULL);
  pthread_create(&hiloconsumidor, NULL, (void*) consumidor, NULL);

  pthread_join(hiloproductor, NULL);
  pthread_join(hiloconsumidor, NULL);

  return 0;
}
