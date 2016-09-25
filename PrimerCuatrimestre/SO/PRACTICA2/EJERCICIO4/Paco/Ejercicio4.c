#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Para usar exec
#include <string.h>


void *mp4tomp3 (void *cadena)
{
  char **cadaux = (char**)cadena;
  /*
  *****************************************************************************************************************
  *Al hacer execvp, el proceso actual (Ejercicio4), se cierra y con ello, todos los hilos asociados a ese proceso.*
  *****************************************************************************************************************
  */
  execvp (cadaux[0], &cadaux[0]);
  //fflush (stdout);
  pthread_exit (NULL);
}

int main (int argc, char *argv[])
{
  if (argc != 3)
    {
      printf ("Error. <./programa> <vídeo1> <vídeo2>\n");
      exit (EXIT_FAILURE);
    }

  char *cad1 [13] = {"ffmpeg", "-i", argv[1], "-f", "mp3", "-ab" ,"192000", "-ar", "48000", "-vn", "ficheroNuevoMP3a.mp3", NULL};
  char *cad2 [13] = {"ffmpeg", "-i", argv[2], "-f", "mp3", "-ab" ,"192000", "-ar", "48000", "-vn", "ficheroNuevoMP3b.mp3", NULL};

  pthread_t hilo1;
  pthread_t hilo2;

  pthread_create (&hilo1, NULL, mp4tomp3, (void*)cad1);
  pthread_create (&hilo2, NULL, mp4tomp3, (void*)cad2);
  pthread_join(hilo1, NULL);
  pthread_join(hilo2, NULL);




  //system ("ffmpeg -i Hilos_POSIX.mp4 -f mp3 -ab 192000 -ar 48000 -vn ficheroNuevoMP3.mp3");
  //system ("ffmpeg -i Hilos_POSIX.mp4 -f mp3 -ab 192000 -ar 48000 -vn ficheroNuevoMP3.mp3");
  //pthread_exit (NULL);
  return (0);
}
