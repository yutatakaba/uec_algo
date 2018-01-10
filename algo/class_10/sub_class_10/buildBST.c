/*
* buildBST.c
*/
#include <stdio.h>
#include "tree.h"

Node *buildBST(Node *n, int x) {
  if (n == NULL)
    return newNodeBST(x);    // 初期探索木 B_1 を作成する．
  if (n->key > x) {
    n->left = buildBST(n->left, x);
  } else {
    n->right = buildBST(n->right, x);
  }
  return n;
}
