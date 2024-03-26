#include <stdio.h>
#include <stdlib.h>
#include "src/StaticList.h"

int main(void) {
  StaticList* list1 = staticListAlloc(sizeof(int), 10);
  StaticList* list2 = staticListAlloc(sizeof(int), 15);
  StaticList* concat;

  staticListInsert(list1, (void*) 4);
  staticListInsert(list1, (void*) 3);
  staticListInsert(list1, (void*) 1);
  staticListInsert(list1, (void*) 2);
  staticListInsert(list1, (void*) 7);
  staticListInsert(list1, (void*) 4);

  staticListInsert(list2, (void*) 2);
  staticListInsert(list2, (void*) 8);
  staticListInsert(list2, (void*) 9);
  staticListInsert(list2, (void*) 0);

  concat = staticListConcat(list1, list2);

  for(int i = 0; i < concat->size; i++) {
    printf("[%d] = %d\n", i, (int) staticListElementAt(concat, i));
  }

  printf("Tamanho da lista:\t%u\nAlocado:\t\t%u", concat->size, concat->allocated);

  return 0;
}
