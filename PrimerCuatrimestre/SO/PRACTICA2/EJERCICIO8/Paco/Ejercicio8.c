/* Implemente un programa que cree dos hebras y cada una incremente 50 veces en un bucle una
variable global (recuerde que la variable global, al estar en el mismo espacio de memoria para las
dos hebras, es compartida, y que su uso es “peligroso”). Imprima al final del programa principal el
valor de la variable (en cada ejecución posiblemente obtenga un valor diferente a 100 – problema de
concurrencia –). Intente razonar el resultado, el cual le servirá como concepto introductorio de la
siguiente práctica de la asignatura*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int global = 0;

void *aumentaGlobal ()
{
  int i;

  for (i = 0 ; i < 50 ; i ++)
    {
      global ++;
    }
    
  return (NULL);
}

main ()
{
  pthread_t hilo1;
  pthread_t hilo2;

  pthread_create (&hilo1, NULL, aumentaGlobal, NULL);
  pthread_create (&hilo2, NULL, aumentaGlobal, NULL);

  pthread_join (hilo1, NULL);
  pthread_join (hilo2, NULL);

  printf ("La variable global vale: %d\n", global);
}
