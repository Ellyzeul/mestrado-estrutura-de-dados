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

void* staticListElementAt(const StaticList* staticList, unsigned int index) {
  return staticList->list[index];
}

unsigned int staticListSize(const StaticList* staticList) {
  return staticList->size;
}

long staticListFind(const StaticList* staticList, const void* element) {
  for(unsigned int i = 0; i < staticList->size; i++) {
    if(staticList->list[i] == element) return i;
  }

  return -1;
}

StaticList* staticListConcat(const StaticList* prepend, const StaticList* append) {
  StaticList* staticList = staticListAlloc(sizeof(prepend->list[0]), prepend->allocated + append->allocated);

  staticList->size = prepend->size + append->size;

  for(int i = 0; i < staticList->size; i++) {
    staticList->list[i] = i < prepend->size
      ? prepend->list[i]
      : append->list[i - prepend->size];
  }

  return staticList;
}
