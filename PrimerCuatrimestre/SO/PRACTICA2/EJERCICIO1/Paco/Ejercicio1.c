#include <pthread.h>
#include <stdio.h>
#include <string.h>

struct hilo{
		char cad1 [10];
		char cad2 [10];
};

void *function(void *structura)
{
  struct hilo *aux = (struct hilo*) structura;

  int i;

  for(i=0 ; i < strlen (aux->cad1) ; i++)
    {
      printf("%s<%c> \e[0m", aux->cad2, aux->cad1[i]);
      fflush(stdout);
      sleep(1);
    }

  return (NULL);
}

int main (void)
{
  struct hilo structHilo1 = {"Hola", "\E[34m"};
  struct hilo structHilo2 = {"mundo", "\E[31m"};

  pthread_t hilo1;
  pthread_t hilo2;

  pthread_create (&hilo1, NULL, function, (void*) &structHilo1);
  pthread_create (&hilo2, NULL, function, (void*) &structHilo2);

  pthread_join (hilo1, NULL);
  pthread_join (hilo2, NULL);

  printf ("\n");
  return (0);
}
