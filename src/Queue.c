#include <stdlib.h>
#include <stdio.h>
#include "Queue.h"

Queue* queueAlloc() {
  Queue* queue = (Queue*) malloc(sizeof(Queue));

  queue->head = NULL;
  queue->last = NULL;

  return queue;
}

void queuePush(Queue* queue, void* element) {
  QueueNode* node = (QueueNode*) malloc(sizeof(QueueNode));

  node->info = element;
  node->next = NULL;

  if(queue->last == NULL) {
    queue->head = queue->last = node;

    return;
  }

  queue->last->next = node;
  queue->last = node;
}

void* queuePop(Queue* queue) {
  if(queue->head == NULL) {
    perror("Attempting to pop an empty queue...");
    exit(EXIT_FAILURE);
  }

  QueueNode* toFree = queue->head;
  void* element = toFree->info;

  queue->head = toFree->next;
  free(toFree);

  if(queue->head == NULL) {
    queue->last = NULL;
  }

  return element;
}
