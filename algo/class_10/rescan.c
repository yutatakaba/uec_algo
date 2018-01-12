#include <stdio.h>
#include <stdlib.h>
/*
 * recscan.c
 */

#include "tree.h"

void recursiveScan(Node *n) {
  if (n != NULL) {
    printNode(n);
    recursiveScan(n->left);
    recursiveScan(n->right);
  }
}
