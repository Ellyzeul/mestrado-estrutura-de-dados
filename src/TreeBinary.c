#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TreeBinary.h"

TreeBinary* treeBinaryAlloc() {
  TreeBinary* tree = malloc(sizeof(*tree));

  tree->root = NULL;
  tree->size = 0;

  return tree;
}

TreeNode* treeNodeAlloc(char* key, void* info) {
  TreeNode* node = malloc(sizeof(*node));

  node->key = key;
  node->info = info;
  node->left = NULL;
  node->right = NULL;

  return node;
}

void treeBinaryInsert(TreeBinary* tree, char* key, void* info) {
  TreeNode *node = treeNodeAlloc(key, info), *current = tree->root;
  short compare;

  tree->size++;
  if(current == NULL) {
    tree->root = node;
    return;
  }

  compare = strcmp(key, current->key);
  while(compare == 1 ? (current->right != NULL) : (compare == -1 ? (current->left != NULL) : 1)) {
    if(compare == 0) {
      perror("Trying to insert duplicate key on Tree Binary...");
      exit(EXIT_FAILURE);
    }

    current = compare == 1
      ? current->right
      : current->left;

    compare = strcmp(key, current->key);
  }

  if(compare == 1) {
    current->right = node;
    return;
  }

  current->left = node;
}

void validateNodeNulity(TreeNode* node, const char* errMsg) {
  if(node == NULL) {
    perror(errMsg);
    exit(EXIT_FAILURE);
  }
}

/**
 * Params
 *   TreeNode *node       - nó atual da árvore
 *   short    orientation - caso deseje o próximo nó à esquerda, -1, caso à direita, 1
*/
TreeNode* nextNode(TreeNode* node, short orientation) {
  if(orientation != -1 && orientation != 1) {
    perror("Orientation value is invalid for getting the next tree node...");
    exit(EXIT_FAILURE);
  }

  return orientation == -1 ? node->left : node->right;
}

void treeBinaryRemove(TreeBinary* tree, char* key) {
  TreeNode *current = tree->root, *leaf, *preLeaf = NULL;
  short compare, nextNodeOrientation;

  validateNodeNulity(current, "Trying to remove from empty tree...");
  compare = strcmp(key, current->key);

  while(compare != 0) {
    preLeaf = current;
    current = compare == 1
      ? current->right
      : current->left;

    validateNodeNulity(current, "Key not found in tree...");
    compare = strcmp(key, current->key);
  }

  nextNodeOrientation = current->left != NULL ? -1 : (current->right != NULL ? 1 : 0);

  if(nextNodeOrientation != 0) {
    preLeaf = current;
    leaf = nextNode(current, nextNodeOrientation);
    while(nextNodeOrientation == -1 ? (leaf->left != NULL) : (leaf->right != NULL)) {
      preLeaf = leaf;
      leaf = nextNode(leaf, nextNodeOrientation);
    }
  }

  if(nextNodeOrientation == 0) {
    nextNodeOrientation = strcmp(key, preLeaf->key);
  }

  if(nextNodeOrientation == -1) {
    preLeaf->left = NULL;
  }
  else if(nextNodeOrientation == 1) {
    preLeaf->right = NULL;
  }

  current->key = leaf->key;
  current->info = leaf->info;
  free(leaf);
}

void* treeBinaryFind(TreeBinary* tree, const char* key) {
  TreeNode* node = tree->root;
  short compare = strcmp(key, node->key);

  while(compare != 0) {
    validateNodeNulity(node, "Key not found in tree...");
    node = compare == -1
      ? node->left
      : node->right;
    
    compare = strcmp(key, node->key);
  }

  return node->info;
}

void treeBinaryForEachRecursive(TreeNode* node, unsigned int size, void(*handler)(TreeNode* node, unsigned int size), enum TreeTraversal order) {
  if(node == NULL) {
    return;
  }

  if(order == PREORDER) handler(node, size);
  treeBinaryForEachRecursive(node->left, size, handler, order);
  if(order == INORDER) handler(node, size);
  treeBinaryForEachRecursive(node->right, size, handler, order);
  if(order == POSTORDER) handler(node, size);
}

void treeBinaryForEach(TreeBinary* tree, void(*handler)(TreeNode* node, unsigned int size), enum TreeTraversal order) {
  treeBinaryForEachRecursive(tree->root, tree->size, handler, order);
}
