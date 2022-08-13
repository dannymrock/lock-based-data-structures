#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "linked_list.h"

#define NUM_THREADS 8
#define USLEEP_TIME 500000

list_t L;
int nthreads;
int usleeptime;
pthread_t *tids;
  

int main() {
  int i;  
  List_Init(&L);
  //struct info *infos;
  nthreads = NUM_THREADS;
  usleeptime = USLEEP_TIME;

  tids = (pthread_t *) malloc(sizeof(pthread_t) * nthreads);
  for (i = 0; i < nthreads; i++) {
    //pthread_create(tids+i, NULL, share_counter, (void *) &infos[i]);
  }
  return 0;
}



void add_keys(void *args){
   int *num_elements = (int *) args;
   for(int i = 0; i < *num_elements; i++) {
     List_Insert(&L, i);
   }


  /**

    args_t *myargs = (args_t *) args;
    int office_id = myargs->id;
    unsigned int myseed = (unsigned int)myargs->seed;

    printf("my id %d, my seed %d \n", office_id, myseed);

    char lend_id[100]; 
    int i, rand_id;

    // local counters for successful and failed loans
    int success_c = 0, fail_c = 0;
    book_t *lended_book;
        
    for (i = 0; i < LEND_BOOKS; i++){
        myseed++;
        rand_id = generate_rand_id(&myseed);
        #ifdef DEBUG
        if (i < 5)
            printf("office_id %d, rand_id %d \n", office_id, rand_id);
        #endif
        sprintf(lend_id, "%d", rand_id);
        lended_book = lend_book(available_books, lend_id);
        if (lended_book != NULL) {
            success_c++;
            delete_book(lended_book);
        } else {
            fail_c++;
        }
    }
    pthread_mutex_lock(&lend_lock);
    total_success_c += success_c;
    total_fail_c += fail_c;
    pthread_mutex_unlock(&lend_lock);
    
    printf("Office %d has finished its workload, successful loans %d, failed loans %d\n", office_id, success_c, fail_c);
    */
}


/*
int main() {
  int found;
  list_t L;
  List_Init(&L);
  List_Insert(&L,3);
  List_Insert(&L,8);
  found = List_Lookup(&L, 3);
  found = List_Lookup(&L, 8);
  printf("3 in L? %d\n",found);
  found = List_Lookup(&L, 5);
  printf("3 in L? %d\n",found);
  return 0;
}
*/
