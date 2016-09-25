#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

void* MP4ToMP3 (void *cadena){
  char **aux = (char**)cadena;

  execvp(aux[0], &aux[0]);
  pthread_exit(NULL);
}

int main (int argc, char *argv[]){
  if(argc != 3){
    printf("\nERROR de sintaxis: ./Ejercicio4 <vídeo1> <vídeo2>\n\n");
    exit(EXIT_FAILURE);
  }

  char *cadena1[] = {"ffmpeg", "-i", argv[1], "-f", "mp3", "-ab" ,"192000", "-ar", "48000", "-vn", "ficheroNuevoMP3a.mp3", NULL};
  char *cadena2[] = {"ffmpeg", "-i", argv[2], "-f", "mp3", "-ab" ,"192000", "-ar", "48000", "-vn", "ficheroNuevoMP3b.mp3", NULL};
  pthread_t hilo1, hilo2;

  pthread_create (&hilo1, NULL, MP4ToMP3, (void*)cadena1);
  pthread_create (&hilo2, NULL, MP4ToMP3, (void*)cadena2);
  pthread_join(hilo1, NULL);
  pthread_join(hilo2, NULL);
  return(EXIT_SUCCESS);
}
