#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char **argv)
{
	pid_t pid;
	int i, status;
	
	if (argc != 3)
	{
		printf("\nERROR en el número de parámetros introducido.\n");
		printf("\nSintáxis establecida: %s <num1> <num2>\n\n", argv[0]);
		exit(-1);
	}
	for(i=0; i<1; i++)
	{
		pid = fork();
		switch(pid)
		{
			case -1:
			{
				perror("fork error");
				printf("errno value = %i.\n", errno);
				exit(EXIT_FAILURE);
			}
			case 0:
			{
				printf("\nProceso hijo %i; padre = %i.\n", getpid(), getppid());
				if (execl("./Ejercicio3a", "./Ejercicio3a", argv[i+1], NULL)==-1)
				{
					perror("exec <./Ejercicio3a> <const char *arg1> error");
					printf("errno value = %i\n", errno);
					exit(EXIT_FAILURE);
				}
			}
		}
	}
	while(pid = wait(&status) != -1);
	return(EXIT_SUCCESS);
}
