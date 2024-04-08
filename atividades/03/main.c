#include <stdlib.h>
#include <stdio.h>
#include "HashMapClosedAddressing.h"
#include "HashMapOpenAddressing.h"

int main(void) {
  HashMapClosedAddressing* hashMapClosed = hashMapClosedAddressingAlloc(0);
  HashMapOpenAddressing* hashMapOpen = hashMapOpenAddressingAlloc(0);

  printf("--------------------\nEnderecamento aberto\n--------------------\n");

  hashMapOpenAddressingAdd(hashMapOpen, "name", (void*) "Gabriel Augusto");
  hashMapOpenAddressingAdd(hashMapOpen, "age", (void*) 22);
  hashMapOpenAddressingAdd(hashMapOpen, "MAddgdaff", (void*) "Teste"); // Essa chave dá colisão com a chave "name"

  printf("- name: %s\n", (char*) hashMapOpenAddressingGet(hashMapOpen, "name"));
  printf("- age: %d\n", (int) hashMapOpenAddressingGet(hashMapOpen, "age"));
  printf("- MAddgdaff: %s\n", (char*) hashMapOpenAddressingGet(hashMapOpen, "MAddgdaff"));

  printf("---------------------\nEnderecamento fechado\n---------------------\n");

  hashMapClosedAddressingAdd(hashMapClosed, "name", (void*) "Gabriel Augusto");
  hashMapClosedAddressingAdd(hashMapClosed, "age", (void*) 22);
  hashMapClosedAddressingAdd(hashMapClosed, "MAddgdaff", (void*) "Teste"); // Essa chave dá colisão com a chave "name"

  printf("- name: %s\n", (char*) hashMapClosedAddressingGet(hashMapClosed, "name"));
  printf("- age: %d\n", (int) hashMapClosedAddressingGet(hashMapClosed, "age"));
  printf("- MAddgdaff: %s\n\n", (char*) hashMapClosedAddressingGet(hashMapClosed, "MAddgdaff"));

  return 0;
}
