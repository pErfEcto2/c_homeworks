#include "lib.h"
#include <stdio.h>
#include <stdlib.h>

BinTree *add(BinTree *tree, int v) {
  if (tree == NULL) {
    if ((tree = malloc(sizeof(BinTree))) == NULL)
      exit(1);
    tree->right = NULL;
    tree->left = NULL;
    tree->val = v;
    return tree;
  }
  if (v < tree->val)
    tree->left = add(tree->left, v);
  else if (v > tree->val)
    tree->right = add(tree->right, v);
  return tree;
}

void print(BinTree *tree) {
  if (tree == NULL)
    return;

  if (tree->right != NULL)
    print(tree->right);
  if (tree->left != NULL)
    print(tree->left);

  printf("%d ", tree->val);
}

BinTree *min(BinTree *tree) {
  if (tree == NULL)
    return tree;
  else if (tree->left == NULL)
    return tree;
  return min(tree->left);
}

BinTree *get(BinTree *tree, int val) {
  if (tree == NULL)
    return NULL;
  else if (tree->val == val)
    return tree;
  if (val < tree->val)
    return get(tree->left, val);
  else
    return get(tree->right, val);
}

BinTree *del(BinTree *tree, int v) {
  if (tree == NULL)
    return tree;

  if (v < tree->val)
    tree->left = del(tree->left, v);
  else if (v > tree->val)
    tree->right = del(tree->right, v);
  else {
    if (tree->left == NULL && tree->right != NULL) {
      BinTree *tmp = tree->right;
      free(tree);
      return tmp;
    } else if (tree->left != NULL && tree->right == NULL) {
      BinTree *tmp = tree->left;
      free(tree);
      return tmp;
    }
    BinTree *tmp = min(tree->right);
    tree->val = tmp->val;
    tree->right = del(tree->right, tmp->val);
  }
  return tree;
}

void free_tree(BinTree *tree) {
  if (tree == NULL)
    return;
  if (tree->right && tree->left == NULL) {
    free(tree);
    return;
  }

  free_tree(tree->left);
  free_tree(tree->right);
}
