#include <stdio.h>
#include <stdlib.h>
#include "src/StaticList.h"

int main(void) {
  StaticList* staticList = staticListAlloc(sizeof(int), 10);

  staticListInsert(staticList, (void*) 4);
  staticListInsert(staticList, (void*) 3);
  staticListInsert(staticList, (void*) 1);
  staticListInsert(staticList, (void*) 2);
  staticListInsert(staticList, (void*) 7);
  staticListInsert(staticList, (void*) 4);
  staticListInsert(staticList, (void*) 3);
  staticListInsert(staticList, (void*) 1);
  staticListInsert(staticList, (void*) 2);
  staticListInsert(staticList, (void*) 7);

  printf("Indice do elemento 3: %ld", staticListFind(staticList, (void*) 3));

  return 0;
}
