#include "StaticList.h"
#include <stdio.h>
#include <stdlib.h>

StaticList* staticListAlloc(const unsigned long long byteSize, const unsigned int length) {
  StaticList* staticList = (StaticList*) malloc(sizeof(StaticList));

  staticList->list = (void**) malloc(byteSize * length);
  staticList->size = 0;
  staticList->allocated = length;

  return staticList;
}

unsigned int staticListInsert(StaticList* staticList, void* element) {
  if(staticList->size == staticList->allocated) {
    perror("Error inserting element on a full static list...\n");
    exit(EXIT_FAILURE);
  }

  staticList->list[staticList->size] = element;

  return staticList->size++;
}

long staticListFind(const StaticList* staticList, const void* element) {
  for(unsigned int i = 0; i < staticList->size; i++) {
    if(staticList->list[i] == element) return i;
  }

  return -1;
}
