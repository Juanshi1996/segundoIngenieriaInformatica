#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

void *leeFicheros (void *nombreFichero)
{
  FILE *f;
  char lee [100];
  long contador = 0;
  if ((f = fopen ((char*)nombreFichero, "r")) == NULL)
    {
      printf ("No se ha podido abrir el fichero %s porque no existe. Por tanto, no se contarán las líneas de este fichero.\n", (char*)nombreFichero);
      pthread_exit (NULL);
    }

  while (fgets (lee, 100, f))
    {
      contador++;
    }
  fclose (f);
  pthread_exit ((void*)contador);
}

main (int argc, char *argv [])
{
  if (argc < 2)
    {
      printf ("Introduzca al menos un fichero.\n");
      exit (EXIT_SUCCESS);
    }

  int i;
  long aux, sumaFinal = 0;
  pthread_t hilos [argc-1];

  for (i = 0 ; i < argc-1 ; i ++)
    {
      pthread_create (&hilos[i], NULL, leeFicheros, (void*)argv[i+1]);
      sleep(1);
    }

  for (i = 0 ; i < argc-1 ; i ++)
    {
      pthread_join (hilos[i], (void**)&aux);
      sumaFinal = sumaFinal + aux;
    }

  printf ("\n\tLa suma total de líneas es: %ld\n\n", sumaFinal);
}
