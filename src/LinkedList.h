#ifndef __ELLYZ__DATA_STRUCTURES__LINKED_LIST__
#define __ELLYZ__DATA_STRUCTURES__LINKED_LIST__

typedef struct LinkedListNode {
  void* info;
  struct LinkedListNode* next;
} LinkedListNode;

typedef struct {
  LinkedListNode* head;
  LinkedListNode* last;
  unsigned int size;
} LinkedList;

LinkedList* linkedListAlloc();
unsigned int linkedListInsert(LinkedList* linkedList, void* element);
unsigned int linkedListInsertAt(LinkedList* linkedList, void* element, const unsigned int index);

#endif//__ELLYZ__DATA_STRUCTURES__LINKED_LIST__