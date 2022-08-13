#include <stdio.h>
#include "linked_list.h"

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
