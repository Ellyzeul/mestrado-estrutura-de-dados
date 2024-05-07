#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Heap.h"

Heap* heapAlloc(short isMax, unsigned int total) {
  Heap* heap;

  if(isMax != 0 && isMax != 1) {
    perror("heap isMax value must be 0 or 1...");
    exit(EXIT_FAILURE);
  }

  heap = malloc(sizeof(heap));

  heap->isMax = isMax;
  heap->array = malloc(sizeof(HeapNode*) * total);
  heap->allocated = total;
  heap->size = 0;

  return heap;
}

int parent(unsigned int i) {
  if(i == 0) {
    return -1;
  }

  return (i - 1) / 2;
}

short shouldSwap(const Heap* heap, unsigned int i, unsigned int j) {
  short cmp;

  if(i < 0) {
    return 0;
  }

  cmp = strcmp(heap->array[i]->key, heap->array[j]->key);

  if(heap->isMax) {
    return cmp < 0;
  }

  return cmp > 0;
}

void swap(Heap* heap, unsigned int i, unsigned int j) {
  HeapNode* aux = heap->array[i];

  heap->array[i] = heap->array[j];
  heap->array[j] = aux;
}

void heapInsert(Heap* heap, char* key, void* value) {
  HeapNode* node;

  if(heap->size >= heap->allocated) {
    perror("heap is full...");
    exit(EXIT_FAILURE);
  }

  node = malloc(sizeof(node));
  node->key = key;
  node->value = value;

  heap->array[heap->size] = node;

  for(int i = heap->size; i > 0; i = parent(i)) {
    if(shouldSwap(heap, parent(i), i)) {
      swap(heap, parent(i), i);
    }
  }

  heap->size++;
}

unsigned int leftChild(unsigned int i) {
  return 2 * i + 1;
}

unsigned int rightChild(unsigned int i) {
  return 2 * i + 2;
}

void heapify(Heap* heap, unsigned int i) {
  unsigned int left = leftChild(i),
               right = rightChild(i),
               top = i;

  if(left < heap->size && shouldSwap(heap, top, left)) {
    top = left;
  }
  if(right < heap->size && shouldSwap(heap, top, right)) {
    top = right;
  }
  if(top != i) {
    swap(heap, i, top);
    heapify(heap, top);
  }
}

HeapNode heapRemoveTop(Heap* heap) {
  HeapNode node = *(heap->array[0]);

  swap(heap, 0, heap->size-1);
  heap->size--;
  free(heap->array[heap->size]);

  heapify(heap, 0);

  return node;
}
