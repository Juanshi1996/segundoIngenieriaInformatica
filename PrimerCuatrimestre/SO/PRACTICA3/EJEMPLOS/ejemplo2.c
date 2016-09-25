#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUMTHRDS 3
#define VECLEN 3

typedef struct{
  int* a;
  int* b;
  int sum;
  int veclem;
} DOTDATA;

DOTDATA dotstr;
pthread_t callThd[NUMTHRDS];
pthread_mutex_t mutexsum;

void* dotprod(void* arg){
  int i, start, end, len;
  long offset;
  int mysum = 0, *x, *y;
  offset = *((long*) arg);
  len = dotstr.veclen;
  start = offset*len;
  end = start+len;
  x = dotstr.a;
  y = dotstr.b;
  for(i = start; i < end; i++)
  {
    mysum += (x[i] * y[i]); 
    /*
    Lock a mutex prior to updating the value in the shared structure, and unlock it upon updating.
    */
    pthread_mutex_lock (&mutexsum);
    dotstr.sum += mysum;
    printf("\nThread %ld did %d to %d: mysum=%d global sum=%d\n",offset,start,end-1,mysum,dotstr.sum);
    pthread_mutex_unlock (&mutexsum);
    pthread_exit((void*) 0);
  }
}

int main (int argc, char const *argv[])
{

  return 0;
}
