#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

// extern void searchBST(Node *n, int x);

Node *buildBST(Node *n, int key);
int path = 0;

int path_length( Node *n ){ //全パス数を求める関数
  if (n != NULL) {  //行きがけ処理を行う
      path = path + orderTree(n) -1;  //漸化式に基づくpathの値の更新
      path_length(n->left);
      path_length(n->right);
  }
  return path;
}


int main() {
  char line[512], *s;
  int key;
  int path;
  Node *root;

  printf("key values entered:\n");
  root = NULL;
  while (fgets(line, 512, stdin) != NULL) {
    s = strtok(line, ",");
    sscanf(s, "%d", &key);
    printf(" %2d", key);

    root = buildBST(root, key);

    while (s != NULL) {
      // 2回目以降は第１引数はNULL
      s = strtok(NULL, ",");
      if (s != NULL) {
        sscanf(s, "%d", &key);
        printf(" %2d", key);
        root = buildBST(root, key);
      }
    }
  }
  printf("\nthe BST:\n");
  printTree(root);

  path = path_length( root );
  printf("path length: %d\n", path);

  deleteTree(root);

  return 0;
}
