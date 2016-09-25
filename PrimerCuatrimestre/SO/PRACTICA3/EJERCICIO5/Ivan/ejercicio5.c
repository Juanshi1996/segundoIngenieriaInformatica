#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_cond_t condicion;
pthread_mutex_t cerrojo;
char buffer[1024];
int bufferlibre;

void* lector(void* arg){
  FILE* fichero;
  char* nombrefichero = (char*) arg;
  fichero = fopen(nombrefichero, "r");
  if(fichero != NULL){

  }
  else
  {
    printf("Error al abrir el archivo %s.\n", nombrefichero);
    exit(EXIT_FAILURE);
  }
}

void* escritor(void* arg){

}

void main(int argc, char** argv){
  if(argc != 3){
    printf("SINTAXIS: ./%s NOMBREFICHERO NUMEROCOPIAS.\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  char* nomfichero = argv[1];
  int copias = atoi(argv[2]);
  int i, s;
  pthread_t hilolector;
  pthread_t hilosescritores[copias];

  pthread_create(&hilolector, NULL, lector, (void*) nomfichero);
  for(i=0; i<copias; i++){
    s = pthread_create(hilosescritores+i, NULL, escritor, (void*) nomfichero);
    if(s != 0){
      printf("ERROR: No ha sido posible crear el hilo %d.\n", i);
      exit(EXIT_FAILURE);
    }
  }
  for(i=0; i<copias; i++){
    s = pthread_join(hilosescritores[i], NULL);
    if(s != 0){
      printf("ERROR: No ha sido posible realizar el join del hilo %d.\n", i);
      exit(EXIT_FAILURE);
    }
  }
  printf("HILO PRINCIPAL: Realizadas %d copias del fichero.");
}
