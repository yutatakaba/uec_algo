//  双方向リスト

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATA_FILE "name-tel.txt"
#define NAME_LENGTH 20
#define TEL_LENGTH 15

// ノードを表す構造体
typedef struct _Node {
  struct _Node *prev; // 逆方向のポインタ
  char name[NAME_LENGTH];
  char tel[TEL_LENGTH];
  struct _Node *next; // 順方向のポインタ
} Node;

// 双方向リストを表す構造体
typedef struct _DlinkList {
  struct _Node *head; // 先頭ノード
  struct _Node *tail; // 末尾ノード
} DlinkList;

Node *gen_node(void);
DlinkList *gen_dlink_list(void);
int disp_dlink_list(DlinkList *);

int main(void)
{
  DlinkList *dlink;

  dlink=gen_dlink_list();
  disp_dlink_list(dlink);

  return 0;
}

// 双方向リストの生成
DlinkList *gen_dlink_list(void)
{
  Node *p,*head,*tail;
  DlinkList *dlink;
  FILE *fp;
  char *data_file=DATA_FILE;

  if((fp=fopen(data_file,"r"))==NULL){
    printf("%s can not be open\n",data_file);
  }

// リストの作成（順方向ポインタも作成）
  head=NULL;
  while(p=gen_node(),fscanf(fp,"%s %s",p->name,p->tel)!=EOF){
    p->next=head;
    head=p;
  }

// 逆向きポインタの作成
  tail=NULL;
  p=head;
  while(p!=NULL){
    p->prev=tail;
    tail=p;
    p=p->next;
  }

  dlink=(DlinkList *)malloc(sizeof(DlinkList));
  dlink->head=head;
  dlink->tail=tail;

  return dlink;
}

// 双方向リストの表示
int disp_dlink_list(DlinkList *dlink)
{
  Node *p,*head,*tail;

  head=dlink->head;
  tail=dlink->tail;

  p=tail;
  printf("\n");
  while(p!=NULL){
    printf("%20s %15s\n",p->name,p->tel);
    p=p->prev;
  }

  return 0;
}

Node *gen_node(void)
{
  return (Node *)malloc(sizeof(Node));
}
