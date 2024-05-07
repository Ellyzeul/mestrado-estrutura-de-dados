#ifndef __ELLYZ__DATA_STRUCTURES__HEAP__
#define __ELLYZ__DATA_STRUCTURES__HEAP__

typedef struct {
  char* key;
  void* value;
} HeapNode;

typedef struct {
  short isMax;
  HeapNode** array;
  unsigned int allocated;
  unsigned int size;
} Heap;

Heap* heapAlloc(short isMax, unsigned int total);
void heapInsert(Heap* heap, char* key, void* value);
HeapNode heapRemoveTop(Heap* heap);

#endif//__ELLYZ__DATA_STRUCTURES__HEAP__
