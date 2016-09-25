#include <pthread.h>
#include <stdio.h>

void* thread(void* vargp){
  sleep(3);
  pthread_detach(pthread_self());
  pthread_exit((void*) 42);
}

int main(){
  int i = 0;
  pthread_t tid;

  pthread_create(&tid, NULL, thread, NULL);
  pthread_join(tid, (void**)&i);
  printf("%d\n", i);
}
