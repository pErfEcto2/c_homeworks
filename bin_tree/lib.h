typedef struct BinTree {
  int val;
  struct BinTree *left;
  struct BinTree *right;
} BinTree;

BinTree *add(BinTree *tree, int v);
BinTree *min(BinTree *tree);
BinTree *max(BinTree *tree);
BinTree *del(BinTree *tree, int v);
void print(BinTree *tree);
void free_tree(BinTree *tree);
BinTree *get(BinTree *tree, int val);
