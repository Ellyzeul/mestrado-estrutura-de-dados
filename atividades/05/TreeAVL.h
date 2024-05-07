#ifndef __ELLYZ__DATA_STRUCTURES__TREE_BINARY__
#define __ELLYZ__DATA_STRUCTURES__TREE_BINARY__

typedef struct TreeAVLNode {
  char* key;
  void* info;
  int factor; // Fator de balanceamento
  struct TreeAVLNode* left;
  struct TreeAVLNode* right;
} TreeAVLNode;

typedef struct {
  TreeAVLNode* root;
  unsigned int size;
} TreeAVL;

enum TreeTraversal {
  PREORDER = 0,
  INORDER = 1,
  POSTORDER = 2
};

TreeAVL* treeAVLAlloc();
TreeAVLNode* treeAVLNodeAlloc(char* key, void* info);
void treeAVLInsert(TreeAVL* tree, char* key, void* info);
void treeAVLRemove(TreeAVL* tree, char* key);
void* treeAVLFind(TreeAVL* tree, const char* key);
void treeAVLForEach(TreeAVL* tree, void(*handler)(TreeAVLNode* node, unsigned int size), enum TreeTraversal order);

#endif//__ELLYZ__DATA_STRUCTURES__TREE_BINARY__