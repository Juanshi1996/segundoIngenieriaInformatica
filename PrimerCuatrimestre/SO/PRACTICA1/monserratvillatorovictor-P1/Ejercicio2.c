#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(void)
{
	pid_t pid;
	int n, i, status;
	
	printf("\nIntroduzca el número de hijos que desea crear: ");
	scanf("%i", &n);
	for (i=0; i<n; i++)
	{
		pid = fork();
		switch (pid)
		{
			case -1:
			{
				perror("fork error");
				printf("errno value = %i\n", errno);
				exit(EXIT_FAILURE);
			}
			case 0:
			{
				printf("Proceso hijo%i con PID = %i.\n", i+1, getpid());
				sleep(10*(i+1));
				exit(EXIT_SUCCESS);
			}
			default:
			{
				printf("He creado al hijo%i exitosamente.\n", i+1);
			}
		}
	}
	while((pid=wait(&status))!=-1)
	{
		if (WIFEXITED(status))
		{
			printf("El hijo %i terminó normalmente y su valor devuelto fue %i.\n\n", pid, WEXITSTATUS(status));
		}
	}
	exit(EXIT_SUCCESS);
}
