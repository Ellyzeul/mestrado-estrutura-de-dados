#ifndef __ELLYZ__DATA_STRUCTURES__TREE_BINARY__
#define __ELLYZ__DATA_STRUCTURES__TREE_BINARY__

typedef struct TreeNode {
  char* key;
  void* info;
  struct TreeNode* left;
  struct TreeNode* right;
} TreeNode;

typedef struct {
  TreeNode* root;
  unsigned int size;
} TreeBinary;

enum TreeTraversal {
  PREORDER = 0,
  INORDER = 1,
  POSTORDER = 2
};

TreeBinary* treeBinaryAlloc();
TreeNode* treeNodeAlloc(char* key, void* info);
void treeBinaryInsert(TreeBinary* tree, char* key, void* info);
void treeBinaryRemove(TreeBinary* tree, char* key);
void* treeBinaryFind(TreeBinary* tree, const char* key);
void treeBinaryForEach(TreeBinary* tree, void(*handler)(TreeNode* node, unsigned int size), enum TreeTraversal order);

#endif//__ELLYZ__DATA_STRUCTURES__TREE_BINARY__