#include <stdio.h>
#include <pthread.h>
#include <time.h>

void *nAleatorios (void *nHebraVoid)
{
	long nAleatorio1, nAleatorio2, suma, nHebra;
	
	srand (time(NULL));
	nHebra = (long)(nHebraVoid)+1;
	nAleatorio1 = (rand () % 6) + 1;
	nAleatorio2 = (rand () % 6) + 1;
	
	suma = nAleatorio1 + nAleatorio2;
	
	printf("\E[30mHEBRA %ld\e[0m: \E[31mAleatorio1 = %ld\e[0m, \E[32mAleatorio2 = %ld\e[0m, \E[33mSuma = %ld\e[0m\n", nHebra, nAleatorio1, nAleatorio2, suma);
	
	pthread_exit ((void*)suma);
}
	
main ()
{
	long nHebras, i, aux, sumaFinal = 0; // long para que no de warning porque dice que (void*) e (int) no tienen el mismo tamaño
	
	printf ("¿Cuántas hebras quiere crear? ");
	scanf  ("%ld", &nHebras);
	
	pthread_t hilos [nHebras];
	
	for (i = 0 ; i < nHebras ; i ++)
		{
			pthread_create (&hilos[i], NULL, nAleatorios, (void*)(i));
			sleep(1);
		}
	
	for (i = 0 ; i < nHebras ; i ++)
	 	{
    	pthread_join (hilos[i], (void**)&aux);
    	sumaFinal = sumaFinal + aux;
  	}
  	
   printf("\nLa suma de los valores de todas las hebras es %ld\n", sumaFinal);
}
