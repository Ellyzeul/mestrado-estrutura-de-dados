#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Stack.h"

Stack* stackAlloc() {
  Stack* stack = (Stack*) malloc(sizeof(Stack));

  stack->top = NULL;

  return stack;
}

bool stackIsEmpty(const Stack* stack) {
  return stack->top == NULL;
}

void stackPush(Stack* stack, void* element) {
  StackNode* node = (StackNode*) malloc(sizeof(StackNode));

  node->info = element;
  node->next = stack->top;

  if(stackIsEmpty(stack)) {
    stack->top = node;
  }

  stack->top = node;
}

void* stackPop(Stack* stack) {
  if(stackIsEmpty(stack)) {
    perror("Attempting to pop an empty stack...");
    exit(EXIT_FAILURE);
  }

  StackNode* toFree = stack->top;
  void* element = toFree->info;

  stack->top = toFree->next;
  free(toFree);

  return element;
}
