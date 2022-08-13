#include <stdio.h>
#include <assert.h>
#include <pthread.h>
#include <sys/time.h>
//#include "counter_wo_locks.h"
#include "counter_locks.h"

#define N_THREADS 4

volatile counter_t my_counter;

void* my_thread(void* arg){
  int i;
  for (i = 0; i < 100000000; i++){
    increment(&my_counter);
  }
  return NULL;
}


int main(){
  init(&my_counter);
  pthread_t threads[N_THREADS];

  struct timeval start, end;
  gettimeofday(&start, NULL); 
  int i;
  for (i = 0; i < N_THREADS; i++){
    int rc = pthread_create(&threads[i], NULL, my_thread, NULL);
    assert(rc == 0);
  }
  
  for (i = 0; i < N_THREADS; i++){
    pthread_join(threads[i], NULL);
  }

  gettimeofday(&end, NULL);
  
  int value = get(&my_counter);
  float time = ((end.tv_sec - start.tv_sec) * 1000.0) +
    ((end.tv_usec - start.tv_usec)/1000.0);
  
  printf("My counter value is %d\n", value);
  printf("Execution time %3.2f ms\n", time);

  return 0;
}
