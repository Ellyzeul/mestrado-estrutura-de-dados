#include <stdio.h>
#include <stdlib.h>
#include "src/LinkedList.h"

int main(void) {
  LinkedList* list = linkedListAlloc();
  LinkedListNode* node;

  linkedListInsert(list, (void*) 1);
  linkedListInsert(list, (void*) 2);
  linkedListInsert(list, (void*) 3);
  linkedListInsert(list, (void*) 4);
  linkedListInsert(list, (void*) 5);
  linkedListInsert(list, (void*) 6);

  node = list->head;
  for(int i = 0; i < list->size; i++) {
    printf("[%d] = %d\n", i, (int) node->info);
    node = node->next;
  }

  linkedListInsertAt(list, (void*) 7, 0);
  linkedListInsertAt(list, (void*) 8, 1);
  linkedListInsertAt(list, (void*) 9, 2);
  linkedListInsertAt(list, (void*) 10, 3);

  node = list->head;
  printf("\n\n");
  for(int i = 0; i < list->size; i++) {
    printf("[%d] = %d\n", i, (int) node->info);
    node = node->next;
  }

  printf("%x; %x; %u", list->head, list->last, list->size);

  return 0;
}
