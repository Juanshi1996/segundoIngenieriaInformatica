#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

struct parametros
{
  float escalar;
  float matriz [3][3];
};

void *matxescalar (void *param)
{
  struct parametros *aux = (struct parametros*) param;
  int i, j;

  for (i = 0 ; i < 3 ; i ++)
    {
      for (j = 0 ; j < 3 ; j ++)
        {
          aux->matriz[i][j] = aux->matriz[i][j]*aux->escalar;
        }
    }

pthread_exit (NULL);
}

main ()
{
  pthread_t hilo1;
  pthread_t hilo2;
  int i, j;

  struct parametros param1;
  struct parametros param2;

  printf ("\E[32mIntroduzca los elementos de la primera matriz: \n");

  for (i = 0 ; i < 3 ; i ++)
    {
      for (j = 0 ; j < 3 ; j ++)
        {
          printf ("Elemento [%d][%d]: ", i+1, j+1);
          scanf  ("%f", &(param1.matriz[i][j]));
        }
    }

  printf ("Introduzca el escalar por el que quiere multiplicar la primera matriz: ");
  scanf  ("%f", &param1.escalar);


  printf ("\E[34mIntroduzca los elementos de la segunda matriz: \n");

  for (i = 0 ; i < 3 ; i ++)
    {
      for (j = 0 ; j < 3 ; j ++)
        {
          printf ("Elemento [%d][%d]: ", i+1, j+1);
          scanf  ("%f", &(param2.matriz[i][j]));
        }
    }

  printf ("Introduzca el escalar por el que quiere multiplicar la segunda matriz: ");
  scanf  ("%f", &param2.escalar);

  pthread_create (&hilo1, NULL, matxescalar, (void*)&param1);
  pthread_create (&hilo2, NULL, matxescalar, (void*)&param2);

  pthread_join (hilo1, NULL);
  pthread_join (hilo2, NULL);

  for (i = 0 ; i < 3 ; i ++)
    {
      for (j = 0 ; j < 3 ; j ++)
        {
          printf ("\n\E[32m[%d][%d]: %.2f", i+1, j+1, param1.matriz[i][j]);
        }
    }

  for (i = 0 ; i < 3 ; i ++)
    {
      for (j = 0 ; j < 3 ; j ++)
        {
          printf ("\n\E[34m[%d][%d]: %.2f", i+1, j+1, param2.matriz[i][j]);
        }
    }

  printf ("\e[0m\n\n");
}
