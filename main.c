#include <stdio.h>
#include <stdlib.h>
#include "src/Stack.h"

int main(void) {
  Stack* stack = stackAlloc();

  stackPush(stack, (void*) 1);
  stackPush(stack, (void*) 2);
  stackPush(stack, (void*) 3);
  stackPush(stack, (void*) 4);
  stackPush(stack, (void*) 5);

  while(!stackIsEmpty(stack)) {
    printf("%d\n", stackPop(stack));
  }

  return 0;
}
