#ifndef __ELLYZ__DATA_STRUCTURES__STACK__
#define __ELLYZ__DATA_STRUCTURES__STACK__

#include <stdbool.h>

typedef struct StackNode {
  void* info;
  struct StackNode* next;
} StackNode;

typedef struct {
  StackNode* top;
} Stack;

Stack* stackAlloc();
bool stackIsEmpty(const Stack* stack);
void stackPush(Stack* stack, void* element);
void* stackPop(Stack* stack);

#endif//__ELLYZ__DATA_STRUCTURES__STACK__