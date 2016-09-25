#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int i;
	long factorial=1;
	
	if (argc != 2)
	{
		printf("\nERROR en el número de parámetros introducido.\n");
		printf("\nSintáxis establecida: %s <número>\n\n", argv[0]);
		exit(-1);
	}
	if (atoi(argv[1]) < 0)
	{
		printf("\nLos números negativos no tienen factorial.\n\n");
		exit(-1);
	}
	for (i=1; i<=atoi(argv[1]); i++)
	{
		factorial = factorial * i;
	}
	printf("\nEl factorial de %i es %li.\n\n", atoi (argv[1]), factorial);
	return(EXIT_SUCCESS);
}
