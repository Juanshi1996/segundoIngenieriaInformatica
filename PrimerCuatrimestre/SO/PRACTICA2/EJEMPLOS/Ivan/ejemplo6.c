#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* start_function(void* value){
  printf("%s is now entering the thread function.\n", (char*) value);
  printf("%s is now leaving the thread function.\n", (char*) value);
  sleep(4);
  printf("After sleep(4)..\n");
  pthread_exit((void*) 99);
}

main(){
  int res, err;
  pthread_attr_t attr;
  pthread_t thread1;
  int i = 0;

  res = pthread_attr_init(&attr);
  if(res != 0){
    perror("Attribute init failed");
    exit(EXIT_FAILURE);
  }
  res = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
  if(res != 0){
    perror("Setting detached state failed");
    exit(EXIT_FAILURE);
  }

  res = pthread_create(&thread1, &attr, start_function, (void*)"Thread 1");
  if(res != 0){
    perror("Creation of thread failed");
    exit(EXIT_FAILURE);
  }

  pthread_attr_destroy(&attr);

  pthread_join(thread1, (void**) &i);
  printf("Valor devuelto: %d\n", i);
}
