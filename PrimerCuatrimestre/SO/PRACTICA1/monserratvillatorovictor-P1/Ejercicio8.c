#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(void)
{
	pid_t pid;
	int i, n, status;
	int variable = 0;
	
	printf("\nIntroduzca el número de hijos que quiere crear del proceso padre: ");
	scanf("%i", &n);
	if (n<=0)
	{
		exit(-1);
	}
	printf("\nProceso %i.\n", getpid());
	for (i=0; i<n; i++)
	{
		pid = fork();
		switch(pid)
		{
			case -1:
			{
				perror("\nfork error");
				printf("\nerrno value = %i.\n", errno);
				exit(EXIT_FAILURE);
			}
			case 0:
			{
				printf("Proceso hijo%i = %i; padre = %i.\n", i+1, getpid(), getppid());
				variable = variable+1;
				exit(EXIT_SUCCESS);
			}
			default:
			{
				while (pid!=wait(&status));
				printf("El valor de la variable es igual a %i.\n", variable);
			}
		}
	}
	printf("\n");
	return (EXIT_SUCCESS);
}
