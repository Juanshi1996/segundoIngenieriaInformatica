/*Cree una estructura que contenga dentro un mensaje y un entero. Cree N hebras a las que se le pase
a cada una una estructura (puede crearse un array de estructuras), de forma que la hebra incremente
en 1 el entero y sustituya el primer carácter del mensaje por el número 9. Desde el proceso principal
imprima el array de estructuras para comprobar los cambios*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

struct tura
{
  char mensaje [40];
  int number;
};


void *cambiaStruct  (struct tura *structura)
{
  structura->mensaje[0] = '9';
  structura->number++;
  pthread_exit (NULL);
}

main ()
{
  int nHebras, i;

  printf ("¿Cuántas hebras quiere crear? ");
  scanf  ("%d", &nHebras);

  struct tura structura [nHebras];
  pthread_t hilito [nHebras];

  for (i = 0 ; i < nHebras ; i ++)
    {
      printf ("Introduzca un mensaje de menos de 40 caracteres: ");
      scanf  ("%s", structura[i].mensaje);
      printf ("Introduzca un número: ");
      scanf  ("%d", &structura[i].number);
    }

  for (i = 0 ; i < nHebras ; i ++)
    {
        pthread_create (&hilito[i], NULL, (void*)cambiaStruct, &structura[i]);
    }

  for (i = 0 ; i < nHebras ; i ++)
    {
        pthread_join (hilito[i], NULL);
        printf ("Hilo 1:\n\tmensaje: %s\n\tnúmero: %d\n", structura[i].mensaje, structura[i].number);
    }

  return (0);
}
