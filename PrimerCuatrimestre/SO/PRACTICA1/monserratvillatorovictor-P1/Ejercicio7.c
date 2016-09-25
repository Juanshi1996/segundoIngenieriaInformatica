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
	FILE *file;
	
	if(argc != 2)
	{
		printf("\nError de sintaxis: ./Ejercicio7 <nombreFichero>\n\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		file = fopen(argv[1], "w");
		pid = fork();
		for(i=0; i<5; i++)
		{
			switch(pid)
			{
				case -1:
				{
					perror("FORK ERROR\n");
					printf("Errno value = %i\n", errno);
					exit(EXIT_FAILURE);
				}
				case 0:
				{
					fputs("+++++\n", file);
					fflush(file);
					sleep(1);
					break;
				}
				default:
				{
					fputs("-----\n", file);
					fflush(file);
					sleep(2);
				}
			}
		}
		if (pid == 0)
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			while(pid!=wait(&status));
			fclose(file);
			if (execlp("gedit", "gedit", argv[1], NULL)==-1)
			{
				exit(EXIT_FAILURE);
				return(EXIT_FAILURE);
			}
			else
			{
				exit(EXIT_SUCCESS);
				return(EXIT_SUCCESS);
			}
		}
	}
}
