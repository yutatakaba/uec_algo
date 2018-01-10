/*
* search.c
*/
#include <stdio.h>
#include "tree.h"

int searchBST(Node *n, int x) {
  int c = 0;


  if (n == NULL) {
    printf("unsuccessful search: not found the key\n");
  } else if (x == n->key) {
    printf("successful search: found the key at node %d\n", n->id);
  } else {
    if (x < n->key)
      c = searchBST(n->left, x);
    else /* x > p->data */
      c = searchBST(n->right, x);
  }
  return c+1;
}
