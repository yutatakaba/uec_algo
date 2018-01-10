/*
* search.c
*/
#include <stdio.h>
#include "tree.h"

void searchBST(Node *n, int x) {
  if (n == NULL) {
    printf("unsuccessful search: not found the key\n");
    return;
  }
  if (x == n->key) {
    printf("successful search: found the key at node %d\n", n->id);
    return;
  } else {
    if (x < n->key)
      searchBST(n->left, x);
    else /* x > p->data */
      searchBST(n->right, x);
  }
}