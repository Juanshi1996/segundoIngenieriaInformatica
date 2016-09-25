#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	pid_t pid;
	int status;
	
	if (argc != 3)
	{
		printf("\nERROR en el número de parámetros introducido.\n");
		printf("\nSintáxis establecida: %s <time (s)> <status>\n\n", argv[0]);
		exit(-1);
	}
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
			sleep(atoi(argv[1]));
			exit(atoi(argv[2]));
		}
		default:
		{
			while(pid !=wait(&status));
			if(status == atoi(argv[2]))
			{
				printf("\nEl mandato se ejecutó de forma normal\n\n");
			}
			else
			{
				if(WIFEXITED(status))
				{
					printf("\nEl hijo terminó normalmente y su valor devuelto fue %i.\n\n", WEXITSTATUS(status));
				}
				if(WIFSIGNALED(status))
				{
					printf("\nEl hijo terminó al recibir la señal %i\n\n", WTERMSIG(status));
				}
			}
		}
	}
	return(EXIT_SUCCESS);
}
