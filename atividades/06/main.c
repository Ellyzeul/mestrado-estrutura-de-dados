#include "Heap.h"
#include <stdio.h>

void printHeap(const Heap* heap) {
  for(int i = 0; i < heap->size; i++) {
    printf("Chave: %s\tValor: %d\n", heap->array[i]->key, (int) heap->array[i]->value);
  }

  printf("\nTamanho: %u, Alocado: %u\n\n", heap->size, heap->allocated);
}

int main(void) {
  Heap *min = heapAlloc(0, 10),
       *max = heapAlloc(1, 10);
  HeapNode node;

  printf("Heap minimo!!!\nInsercao de elementos!\n\n");
  heapInsert(min, "B", (void*) 1);
  heapInsert(min, "A", (void*) 0);
  heapInsert(min, "E", (void*) 4);
  heapInsert(min, "D", (void*) 3);
  heapInsert(min, "C", (void*) 2);
  heapInsert(min, "F", (void*) 5);

  printHeap(min);

  printf("Remocao do valor minimo!\n\n");

  node = heapRemoveTop(min);
  printf("Chave: %s, Valor: %d\n\n", node.key, (int) node.value);

  printHeap(min);

  printf("-----------------------\nHeap maximo!!!\nInsercao de elementos!\n\n");
  heapInsert(max, "A", (void*) 0);
  heapInsert(max, "C", (void*) 2);
  heapInsert(max, "E", (void*) 4);
  heapInsert(max, "D", (void*) 3);
  heapInsert(max, "F", (void*) 5);
  heapInsert(max, "B", (void*) 1);

  printHeap(max);

  printf("Remocao do valor maximo!\n\n");

  node = heapRemoveTop(max);
  printf("Chave: %s, Valor: %d\n\n", node.key, (int) node.value);

  printHeap(max);

  return 0;
}
