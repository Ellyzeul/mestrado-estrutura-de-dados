#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "HashMapOpenAddressing.h"

#define DEFAULT_ARRAY_SIZE 100
#define INITIAL_SHIFT_VALUE 1

HashMapOpenAddressing* hashMapOpenAddressingAlloc(unsigned int arraySize) {
  HashMapOpenAddressing* hashMap = (HashMapOpenAddressing*) malloc(sizeof(HashMapOpenAddressing));

  hashMap->allocated = arraySize == 0 ? DEFAULT_ARRAY_SIZE : arraySize;
  hashMap->list = (HashNode**) malloc(sizeof(HashNode**) * hashMap->allocated);

  for(int i = 0; i < hashMap->allocated; i++) {
    hashMap->list[i] = NULL;
  }

  return hashMap;
}

unsigned int hashMapOpenAddressingHash(const char* key, const unsigned int divisor) {
  unsigned int i = 0, hashValue = 0;

  while (key[i] != '\0') {
    hashValue += ((int) key[i]) * (i + 1);
    i++;
  }
  
  return hashValue % divisor;
}

/** Esta função de rehash garante a geração de todos os índices possíves, sem cair num loop infinito */
unsigned int rehash(const unsigned int index, const unsigned int shift, const unsigned int divisor) {
  return (index + shift + (shift / divisor)) % divisor;
}

void hashMapOpenAddressingAdd(HashMapOpenAddressing* hashMap, char* key, void* value) {
  unsigned int index = hashMapOpenAddressingHash(key, hashMap->allocated), shift = INITIAL_SHIFT_VALUE;
  HashNode* node = (HashNode*) malloc(sizeof(HashNode));

  node->key = key;
  node->value = value;

  while(hashMap->list[index] != NULL) {
    index = rehash(index, shift++, hashMap->allocated);
  }

  hashMap->list[index] = node;
}

void* hashMapOpenAddressingGet(HashMapOpenAddressing* hashMap, const char* key) {
  unsigned int index = hashMapOpenAddressingHash(key, hashMap->allocated), shift = INITIAL_SHIFT_VALUE;
  HashNode* node = hashMap->list[index];

  while(node == NULL || strcmp(node->key, key) != 0) {
    index = rehash(index, shift++, hashMap->allocated);
    node = hashMap->list[index];
  }

  return node->value;
}
