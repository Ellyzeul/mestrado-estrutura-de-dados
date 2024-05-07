#include "TreeAVL.h"

void printNode(TreeAVLNode* node, unsigned int size) {
  printf("key: %s\tinfo: %d\n", node->key, (int) node->info);
}

int main(void) {
  TreeAVL* tree = treeAVLAlloc();

  treeAVLInsert(tree, "A", (void*) 0);
  treeAVLInsert(tree, "B", (void*) 1);
  treeAVLInsert(tree, "C", (void*) 2);
  treeAVLInsert(tree, "D", (void*) 3);
  treeAVLInsert(tree, "E", (void*) 4);
  treeAVLInsert(tree, "F", (void*) 5);
  treeAVLInsert(tree, "G", (void*) 6);

  printf("Insercao de A a G\n");
  treeBinaryForEach(tree, printNode, INORDER);

  treeBinaryRemove(tree, "A");
  treeBinaryRemove(tree, "E");

  printf("\nRemocao de A e E\n");
  treeBinaryForEach(tree, printNode, INORDER);

  printf("\nProcurando por C\n");
  printf("C == %d", (int) treeBinaryFind(tree, "C"));

  return 0;
}
