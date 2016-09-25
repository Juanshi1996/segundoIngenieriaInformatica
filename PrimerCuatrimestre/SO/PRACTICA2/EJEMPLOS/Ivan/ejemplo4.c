#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void* message_print(void* ptr){
  int error = 0;
  char* msg;

  error = pthread_detach(pthread_self());

  msg = (char*) ptr;
  sleep(5);
  printf("THREAD: This is the Message %s\n", msg);
  pthread_exit(NULL);
}

int main(void){
  int error = 0;
  size_t i=0;
  char mess[] = "This is a test";
  int thread_no = 5;

  pthread_t thr[5];
  for(i=0; i<thread_no; i++){
    error = pthread_create(&(thr[i]), NULL, message_print, (void*) mess);

  }
  printf("MAIN: Thread Message: %s\n", mess);
  pthread_exit(NULL);
}
