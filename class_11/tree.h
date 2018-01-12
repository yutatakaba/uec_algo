/*
 * tree.h
 */

typedef struct _node
{
  int   id;
  int   key;
  char  *data;
  struct _node *left, *right;
} Node;

Node *newNode(int id, char *data);
Node *newNodeBST(int key);
void printNode(Node *nList);
void printTree(Node *n);
void deleteTree(Node *n);
void saveKeyInOrder(Node *n, int *d);
int orderTree(Node *n);
