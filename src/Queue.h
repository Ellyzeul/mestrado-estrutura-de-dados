#ifndef __ELLYZ__DATA_STRUCTURES__QUEUE__
#define __ELLYZ__DATA_STRUCTURES__QUEUE__

typedef struct QueueNode {
  void* info;
  struct QueueNode* next;
} QueueNode;

typedef struct {
  QueueNode* head;
  QueueNode* last;
} Queue;

Queue* queueAlloc();
void queuePush(Queue* queue, void* element);
void* queuePop(Queue* queue);

#endif//__ELLYZ__DATA_STRUCTURES__QUEUE__