#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

LinkedList* linkedListAlloc() {
  LinkedList* linkedList = (LinkedList*) malloc(sizeof(LinkedList));

  linkedList->head = NULL;
  linkedList->last = NULL;
  linkedList->size = 0;

  return linkedList;
}

LinkedListNode* linkedListNodeAlloc(void* element) {
  LinkedListNode* node = (LinkedListNode*) malloc(sizeof(LinkedListNode));

  node->info = element;
  node->next = NULL;

  return node;
}

unsigned int linkedListInsert(LinkedList* linkedList, void* element) {
  LinkedListNode* node = linkedListNodeAlloc(element);

  if(linkedList->head == NULL) {
    linkedList->head = linkedList->last = node;
  }
  else {
    linkedList->last->next = node;
    linkedList->last = linkedList->last->next;
  }

  linkedList->size++;

  return linkedList->size;
}

unsigned int linkedListInsertAt(LinkedList* linkedList, void* element, const unsigned int index) {
  if(index > linkedList->size) {
    perror("Index to insert isn't in range of the list...");
    exit(EXIT_FAILURE);
  }

  if(index == linkedList->size) {
    return linkedListInsert(linkedList, element);
  }

  LinkedListNode* node = (LinkedListNode*) malloc(sizeof(LinkedListNode));
  node->info = element;

  if(index == 0) {
    node->next = linkedList->head;
    linkedList->head = node;

    return ++linkedList->size;
  }

  LinkedListNode* nodeBeforeIndex = linkedList->head;

  for(int i = 1; i < index; i++) {
    nodeBeforeIndex = nodeBeforeIndex->next;
  }

  node->next = nodeBeforeIndex->next;
  nodeBeforeIndex->next = node;

  return ++linkedList->size;
}
