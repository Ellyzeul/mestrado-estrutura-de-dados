#include <stdio.h>
#include "TreeBinary.h"

void printNode(TreeNode* node, unsigned int size) {
  printf("key: %s\tinfo: %d\n", node->key, (int) node->info);
}

int main(void) {
  TreeBinary* tree = treeBinaryAlloc();

  treeBinaryInsert(tree, "D", (void*) 0);
  treeBinaryInsert(tree, "B", (void*) 1);
  treeBinaryInsert(tree, "A", (void*) 2);
  treeBinaryInsert(tree, "C", (void*) 3);
  treeBinaryInsert(tree, "E", (void*) 4);
  treeBinaryInsert(tree, "F", (void*) 5);
  treeBinaryInsert(tree, "G", (void*) 6);

  printf("Insercao de A a G\n");
  treeBinaryForEach(tree, printNode, INORDER);

  treeBinaryRemove(tree, "A"); // A é um nó folha
  treeBinaryRemove(tree, "E"); // E tem nós filhos

  printf("\nRemocao de A e E\n");
  treeBinaryForEach(tree, printNode, INORDER);

  printf("\nProcurando por C\n");
  printf("C == %d", (int) treeBinaryFind(tree, "C"));

  return 0;
}
