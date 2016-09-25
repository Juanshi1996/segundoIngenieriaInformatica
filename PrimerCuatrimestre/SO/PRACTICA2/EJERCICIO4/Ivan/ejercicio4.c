#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

void* conversionHilos(void* fichero){
  char* cadena = (char*) fichero;
  char mp3[strlen(cadena)];
  strcpy(mp3, cadena);
  mp3[strlen(mp3)-1] = '3';
  char* comando[13] = {"./ffmpeg", "-i", cadena, "-f", "mp3", "-ab" ,"192000", "-ar", "48000", "-vn", mp3, NULL};
  execvp(comando[0], &comando[0]);
  pthread_exit(NULL);
}

int main(int argc, char** argv){
  if(argc != 3){
    printf("SINTAXIS: %s FICHERO1 FICHERO2.\n", argv[0]);
    exit(-1);
  }

  pthread_t hilos[2];
  pthread_create(hilos, NULL, (void*) conversionHilos, (void*) argv[1]);
  pthread_create(hilos+1, NULL, (void*) conversionHilos, (void*) argv[2]);
  pthread_join(hilos[0], NULL);
  pthread_join(hilos[1], NULL);
  printf("Archivos %s y %s convertidos correctamente.\n", argv[1], argv[2]);
}
