#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

#define equal ==
#define reading vector[0]
#define writing vector[1]

int main(int argc, char const *argv[]) {
  pid_t pid;
  int status;
  int vector[2];
  char buffer[256];
  size_t i;

  if((status = pipe(vector)) equal -1) {//Error al crear la tubería
    perror("pipe error");
    printf("errno value = %i.\n", errno);
    exit(EXIT_FAILURE);
  }
  pid = fork();
  switch(pid) {
    case -1: {
      perror("fork error");
      printf("errno value = %i.\n", errno);
      exit(EXIT_FAILURE);
    }
    case 0: {
      printf("[HIJO]: mi PID es %i y mi PPID es %i\n", getpid(), getppid());
      for(i = 0; i < 5; i++) {
        close(writing);
        read(reading, buffer, 256);
        printf("[HIJO]: leemos el número aleatorio %s de la tubería\n", buffer);
      }
      close(reading);
      printf("[HIJO]: tubería cerrada. Salgo...\n");
      exit(EXIT_SUCCESS);
    }
    default: {
      printf("[PADRE]: mi PID es %i y el PID de mi hijo es %i\n", getpid(), pid);
      srand(time(NULL));
      for(i = 0; i < 5; i++) {
        int n = rand()%5000;
        sprintf(buffer, "%i", n);
        close(reading);
        printf("[PADRE]: escribimos el número aleatorio %i en la tubería...\n", n);
        write(writing, buffer, 256);
      }
      close(writing);
      printf("[PADRE]: tubería cerrada.\n");
      wait(&status);
    }
  }
  return(EXIT_SUCCESS);
}
