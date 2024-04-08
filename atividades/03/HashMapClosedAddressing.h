#ifndef __ELLYZ__DATA_STRUCTURES__HASH_MAP_CLOSED_ADDRESSING__
#define __ELLYZ__DATA_STRUCTURES__HASH_MAP_CLOSED_ADDRESSING__

#include "LinkedList.h"

typedef struct {
  unsigned int allocated;
  LinkedList** list;
} HashMapClosedAddressing;

HashMapClosedAddressing* hashMapClosedAddressingAlloc(unsigned int arraySize);
void hashMapClosedAddressingAdd(HashMapClosedAddressing* hashMap, char* key, void* value);
void* hashMapClosedAddressingGet(HashMapClosedAddressing* hashMap, const char* key);

#endif//__ELLYZ__DATA_STRUCTURES__HASH_MAP_CLOSED_ADDRESSING__
