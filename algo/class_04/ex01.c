// 線形リスト（入力とは逆順に格納される）

#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
  char name[20];
  char tel[20];
  struct _Node *next;
} Node;

Node *gen_node(void);

int main(void){
  Node *head, *p;
// headはリストの先頭を，pは新規ノードを指す

// リストの作成
  head=NULL;
  while(p=gen_node(),scanf("%s %s",p->name,p->tel)!=EOF){
    p->next=head; // 新規ノードのnextは，これまでのリストの先頭を指す
    head=p;       // リストの先頭を新規ノードに更新
  }

// リストの表示
  p=head;
  while(p!=NULL){
    printf("%15s %15s\n",p->name,p->tel);
    p=p->next;
  }

  return 0;
}


Node *gen_node(void)
{
  return (Node *)malloc(sizeof(Node));
}
