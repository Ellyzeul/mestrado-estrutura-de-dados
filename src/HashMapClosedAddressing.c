#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "HashMapClosedAddressing.h"

#define DEFAULT_ARRAY_SIZE 100

typedef struct {
  char* key;
  void* value;
} HashNode;

HashMapClosedAddressing* hashMapClosedAddressingAlloc(unsigned int arraySize) {
  HashMapClosedAddressing* hashMap = (HashMapClosedAddressing*) malloc(sizeof(HashMapClosedAddressing));

  hashMap->allocated = arraySize == 0 ? DEFAULT_ARRAY_SIZE : arraySize;
  hashMap->list = (LinkedList**) malloc(sizeof(LinkedList**) * hashMap->allocated);

  for(int i = 0; i < hashMap->allocated; i++) {
    hashMap->list[i] = NULL;
  }

  return hashMap;
}

unsigned int hashMapClosedAddressingHash(const char* key, const unsigned int divisor) {
  unsigned int i = 0, hashValue = 0;

  while (key[i] != '\0') {
    hashValue += ((int) key[i]) * (i + 1);
    i++;
  }
  
  return hashValue % divisor;
}

void hashMapClosedAddressingAdd(HashMapClosedAddressing* hashMap, char* key, void* value) {
  unsigned int index = hashMapClosedAddressingHash(key, hashMap->allocated);
  HashNode* node = (HashNode*) malloc(sizeof(HashNode));

  node->key = key;
  node->value = value;

  if(hashMap->list[index] == NULL) {
    hashMap->list[index] = linkedListAlloc();
  }

  linkedListInsert(hashMap->list[index], (void*) node);
}

void* hashMapClosedAddressingGet(HashMapClosedAddressing* hashMap, const char* key) {
  unsigned int index = hashMapClosedAddressingHash(key, hashMap->allocated);
  LinkedListNode* listNode = hashMap->list[index]->head;

  while(strcmp(((HashNode*) listNode->info)->key, key) != 0) {
    listNode = listNode->next;
  }

  return ((HashNode*) listNode->info)->value;
}
