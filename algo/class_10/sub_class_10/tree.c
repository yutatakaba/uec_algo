/*
 * tree.c
 */
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include "tree.h"

Node *newNode(int id, char *data)
{
  Node *n;

  n = (Node *)malloc(sizeof(Node));
  n->id = id;
  n->data = strcpy(malloc(strlen(data)+1), data);
  n->left = n->right = NULL;
  return n;
}

static int id = 0;
Node *newNodeBST(int key)
{
  Node *n;
  n = (Node *)malloc(sizeof(Node));
  n->id = id++;
  n->key = key;
  n->left = n->right = NULL;
  n->data = NULL; // 本来は，登録データのアドレスを代入するが省略
  return n;
}

void printNode(Node *v) {
  printf("node: %d ", v->id);
  if (v->left != NULL)
    printf("left: %d", v->left->id);
  else
    printf("left: null");
  if (v->right != NULL)
    printf(" right: %d", v->right->id);
  else
    printf(" right: null");
  printf(" data: %s\n", v->data);
}

void printTree(Node *n) {
  if (n != NULL) { // DFS走査においてpreOrder(行きがけ)処理を行う
    printNode(n);
    printTree(n->left);
    printTree(n->right);
  }
}

void deleteTree(Node *n) {
  if (n != NULL) {
    deleteTree(n->left);
    deleteTree(n->right);
    if (n->data != NULL)
      free(n->data);
    free(n);
    // deleteTree(n);
  }
}
