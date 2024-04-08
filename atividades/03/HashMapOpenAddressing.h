#ifndef __ELLYZ__DATA_STRUCTURES__HASH_MAP_OPEN_ADDRESSING__
#define __ELLYZ__DATA_STRUCTURES__HASH_MAP_OPEN_ADDRESSING__

#include "LinkedList.h"

typedef struct {
  char* key;
  void* value;
} HashNode;

typedef struct {
  unsigned int allocated;
  HashNode** list;
} HashMapOpenAddressing;

HashMapOpenAddressing* hashMapOpenAddressingAlloc(unsigned int arraySize);
void hashMapOpenAddressingAdd(HashMapOpenAddressing* hashMap, char* key, void* value);
void* hashMapOpenAddressingGet(HashMapOpenAddressing* hashMap, const char* key);

#endif//__ELLYZ__DATA_STRUCTURES__HASH_MAP_OPEN_ADDRESSING__
