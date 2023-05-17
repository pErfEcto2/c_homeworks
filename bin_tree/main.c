#include "lib.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  BinTree *tree = NULL;

  tree = add(tree, 4);
  tree = add(tree, 5);
  tree = add(tree, 6);

  print(tree);

  printf("\nmin: %d\n", min(tree)->val);

  tree = del(tree, 4);
  tree = del(tree, 8);

  print(tree);

  free_tree(tree);
  return 0;
}
