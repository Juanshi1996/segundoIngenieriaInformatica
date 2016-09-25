#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(void)
{
	pid_t pid;
	
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
			printf("Proceso hijo %i; padre = %i.\n", getpid(), getppid());
			exit(EXIT_SUCCESS);
		}
		default:
		{
			sleep(30);
			exit(EXIT_SUCCESS);
		}
	}
	return(EXIT_SUCCESS);
}
