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
	int i, status;
	
	for(i=0; i<2; i++)
	{
		pid = fork();
		switch (pid)
		{
			case -1:
			{
				perror("fork error");
				printf("errno value = %i.\n", errno);
				exit(EXIT_FAILURE);
			}
			case 0:
			{
				if(i==0)
				{
					if (openGnomeCalculator(argv[1]) == EXIT_FAILURE)
					{
						perror("exec <./Ejercicio6a> <gnome-calculator> <gedit> <file1> ... <fileN> error");
						printf("errno value = %i\n", errno);
						exit(EXIT_FAILURE);
					}
				}
				if(i==1)
				{
					if (openGedit(argv) == EXIT_FAILURE)
					{
						perror("exec <./Ejercicio6a> <gnome-calculator> <gedit> <file1> ... <fileN> error");
						printf("errno value = %i\n", errno);
						exit(EXIT_FAILURE);
					}
				}
				exit(EXIT_SUCCESS);
			}
		}
	}
	while(pid=wait(&status)!=-1);
	return(EXIT_SUCCESS);
}

int openGnomeCalculator(char *args)
{
	if(execlp(args, args, NULL)==-1)
	{
		return(EXIT_FAILURE);
	}
	else
	{
		return(EXIT_SUCCESS);
	}
}

int openGedit(char **args)
{
	if (execvp(args[2], &args[2])==-1)
	{
		return(EXIT_FAILURE);
	}
	else
	{
		return(EXIT_SUCCESS);
	}
}
