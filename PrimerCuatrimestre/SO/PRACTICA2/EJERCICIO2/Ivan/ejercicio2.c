#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void* numerosAleatorios(void* numero){
  int aleatorio1, aleatorio2, suma;
  sleep((int)numero);
  srand(time(NULL));
  aleatorio1 = rand()%10;
  aleatorio2 = rand()%10;
  suma = aleatorio1 + aleatorio2;
  printf("HEBRA %d: Aleatorio1 = %d, Aleatorio2 = %d, Suma= %d\n", (int) numero, aleatorio1, aleatorio2, suma);
  pthread_exit((void*) suma);
}

int main(void){
  int nhebras,i, sumaac = 0;
  printf("Cuantas hebras desea crear? ");
  scanf("%d", &nhebras);

  pthread_t hilos[nhebras];

  for(i = 0; i<nhebras; i++){
    pthread_create(hilos+i, NULL, numerosAleatorios, (void*) i);
  }
  int aux;
  for(i = 0; i<nhebras; i++){
    pthread_join(hilos[i], (void**)&aux);
    sumaac += aux;
  }

  printf("Suma total de los valores de todas las hebras = %d\n", sumaac);
  return 0;
}
