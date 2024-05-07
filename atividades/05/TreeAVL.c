#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TreeAVL.h"

TreeAVL* treeAVLAlloc() {
  TreeAVL* tree = malloc(sizeof(*tree));

  tree->root = NULL;
  tree->size = 0;

  return tree;
}

TreeAVLNode* treeAVLNodeAlloc(char* key, void* info) {
  TreeAVLNode* node = malloc(sizeof(*node));

  node->key = key;
  node->info = info;
  node->factor = 0;
  node->left = NULL;
  node->right = NULL;

  return node;
}

int nodeAVLFactor(TreeAVLNode* node) {
  if(node == NULL) {
    return 0;
  }

  return node->factor;
}

int updateNodeAVLFactor(TreeAVLNode* node) {
  node->factor = nodeAVLFactor(node->left) - nodeAVLFactor(node->right);

  return node->factor;
}

void validateChildOrientation(int orientation) {
  if(orientation != -1 && orientation != 1) {
    perror("Invalid orientation value passed to rotation function...");
    exit(EXIT_FAILURE);
  }
}

void treeAVLRightRotate(TreeAVL* tree, TreeAVLNode* parent, int childOrientation) {
  int isParentNull = parent == NULL;
  TreeAVLNode *pivot, *subLeft;

  validateChildOrientation(childOrientation);

  if(isParentNull) parent = tree->root;

  pivot = childOrientation == -1 ? parent->left : parent->right;
  subLeft = pivot->left;

  pivot->left = subLeft->right;
  subLeft->right = pivot;

  if(isParentNull) {
    tree->root = subLeft;
  } else if(childOrientation == -1) {
    parent->left = subLeft;
  } else {
    parent->right = subLeft;
  }
}

void treeAVLLeftRotate(TreeAVL* tree, TreeAVLNode* parent, int childOrientation) {
  int isParentNull = parent == NULL;
  TreeAVLNode *pivot, *subRight;

  validateChildOrientation(childOrientation);

  if(isParentNull) parent = tree->root;

  pivot = childOrientation == -1 ? parent->left : parent->right;
  subRight = pivot->right;

  pivot->right = subRight->left;
  subRight->left = pivot;

  if(isParentNull) {
    tree->root = subRight;
  } else if(childOrientation == -1) {
    parent->left = subRight;
  } else {
    parent->right = subRight;
  }
}

void treeAVLInsert(TreeAVL* tree, char* key, void* info) {
  TreeAVLNode *node = treeAVLNodeAlloc(key, info), *current = tree->root, *parent = NULL;
  short compare, currentOrientation = 1;
  int balance;

  tree->size++;
  if(current == NULL) {
    tree->root = node;
    return;
  }

  compare = strcmp(key, current->key);
  while(compare == 1 ? (current->right != NULL) : (compare == -1 ? (current->left != NULL) : 1)) {
    if(compare == 0) {
      perror("Trying to insert duplicate key on Tree AVL...");
      exit(EXIT_FAILURE);
    }

    parent = current;
    current = compare == 1
      ? current->right
      : current->left;

    currentOrientation = compare;
    compare = strcmp(key, current->key);
  }

  if(compare == 1) {
    current->right = node;
  } else {    
    current->left = node;
  }

  balance = updateNodeAVLFactor(current);

  if(balance > 1 && compare == -1) {
    treeAVLRightRotate(tree, parent, currentOrientation);
  } else if(balance < -1 && compare == 1) {
    treeAVLLeftRotate(tree, parent, currentOrientation);
  } else if(balance > 1 && compare == 1) {
    treeAVLLeftRotate(tree, parent, currentOrientation);
    treeAVLRightRotate(tree, parent, currentOrientation);
  } else if(balance < -1 && compare == -1) {
    treeAVLRightRotate(tree, parent, currentOrientation);
    treeAVLLeftRotate(tree, parent, currentOrientation);
  }
}

void validateNodeNulity(TreeAVLNode* node, const char* errMsg) {
  if(node == NULL) {
    perror(errMsg);
    exit(EXIT_FAILURE);
  }
}

/**
 * Params
 *   TreeAVLNode *node       - nó atual da árvore
 *   short    orientation - caso deseje o próximo nó à esquerda, -1, caso à direita, 1
*/
TreeAVLNode* nextNode(TreeAVLNode* node, short orientation) {
  if(orientation != -1 && orientation != 1) {
    perror("Orientation value is invalid for getting the next tree node...");
    exit(EXIT_FAILURE);
  }

  return orientation == -1 ? node->left : node->right;
}

void treeAVLRemove(TreeAVL* tree, char* key) {
  TreeAVLNode *current = tree->root, *leaf, *preLeaf = NULL;
  short compare, nextNodeOrientation, currentOrientation = 1;
  int balance;

  validateNodeNulity(current, "Trying to remove from empty tree...");
  compare = strcmp(key, current->key);

  while(compare != 0) {
    preLeaf = current;
    current = compare == 1
      ? current->right
      : current->left;

    validateNodeNulity(current, "Key not found in tree...");
    currentOrientation = compare;
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

  balance = updateNodeAVLFactor(current);

  if(balance > 1 && compare == -1) {
    treeAVLRightRotate(tree, preLeaf, currentOrientation);
  } else if(balance < -1 && compare == 1) {
    treeAVLLeftRotate(tree, preLeaf, currentOrientation);
  } else if(balance > 1 && compare == 1) {
    treeAVLLeftRotate(tree, preLeaf, currentOrientation);
    treeAVLRightRotate(tree, preLeaf, currentOrientation);
  } else if(balance < -1 && compare == -1) {
    treeAVLRightRotate(tree, preLeaf, currentOrientation);
    treeAVLLeftRotate(tree, preLeaf, currentOrientation);
  }
}

void* treeAVLFind(TreeAVL* tree, const char* key) {
  TreeAVLNode* node = tree->root;
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

void treeAVLForEachRecursive(TreeAVLNode* node, unsigned int size, void(*handler)(TreeAVLNode* node, unsigned int size), enum TreeTraversal order) {
  if(node == NULL) {
    return;
  }

  if(order == PREORDER) handler(node, size);
  treeAVLForEachRecursive(node->left, size, handler, order);
  if(order == INORDER) handler(node, size);
  treeAVLForEachRecursive(node->right, size, handler, order);
  if(order == POSTORDER) handler(node, size);
}

void treeAVLForEach(TreeAVL* tree, void(*handler)(TreeAVLNode* node, unsigned int size), enum TreeTraversal order) {
  treeAVLForEachRecursive(tree->root, tree->size, handler, order);
}
