#include <stdio.h>
#include <stdlib.h>
#include "StaticList.h"

void printList(const char* msg, const StaticList* list) {
  printf("-- %s --\n", msg);

  for(int i = 0; i < list->size; i++) {
    printf("[%d] = %d\n", i, (int) list->list[i]);
  }

  printf("\nArmazenado: %u\n", list->size);
  printf("Alocado:    %u\n\n", list->allocated);
}

int main(void) {
  StaticList* list = staticListAlloc(sizeof(int), 10);

  staticListInsert(list, (void*) 1);
  staticListInsert(list, (void*) 2);
  staticListInsert(list, (void*) 3);
  staticListInsert(list, (void*) 4);
  staticListInsert(list, (void*) 5);
  staticListInsert(list, (void*) 6);
  staticListInsert(list, (void*) 7);
  staticListInsert(list, (void*) 8);
  staticListInsert(list, (void*) 9);

  printList("Insercao na lista", list);

  staticListDelete(list, 6);

  printList("Exclusao do indice [6]", list);

  staticListInsertAt(list, (void*) 12, 5);

  printList("Alteracao do indice [5] para 12", list);

  system("pause");

  return 0;
}
