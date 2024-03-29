#include "Stack.h"
#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

void pushToStack(Stack* stack, int element) {
  printf("Adicionou %d na pilha\n", element);
  stackPush(stack, (void*) element);
}

void pushToQueue(Queue* queue, int element) {
  printf("Adicionou %d na fila\n", element);
  queuePush(queue, (void*) element);
}

int main(void) {
  Stack* stack = stackAlloc();
	Queue* queue = queueAlloc();
  int total = 5;

  srand((unsigned) stack);

  printf("--- Exemplo de pilha ---\n\n");

  for(int i = 0; i < total; i++) {
    pushToStack(stack, (int) rand() % 100);
  }

  printf("\n");

  for(int i = 0; i < total; i++) {
    printf("Removeu %d da pilha\n", (int) stackPop(stack));
  }

  printf("\n--- Exemplo de fila ---\n\n");

  for(int i = 0; i < total; i++) {
    pushToQueue(queue, (int) rand() % 100);
  }

  printf("\n");

  for(int i = 0; i < total; i++) {
    printf("Removeu %d da fila\n", (int) queuePop(queue));
  }

  return 0;
}
