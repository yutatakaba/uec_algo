//  リストの検索とリストへの挿入

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATA_FILE "name-tel.txt"
#define NAME_LENGTH 20
#define TEL_LENGTH 15

typedef struct _Node {
  char name[NAME_LENGTH];
  char tel[TEL_LENGTH];
  struct _Node *next;
} Node;

typedef struct _List {
  struct _Node *head; // 先頭ノード
} List;

Node *gen_node(void);
List *gen_list(void);
int disp_list(List *);
int key_link(char *, List *);

int main(void){
  char key[NAME_LENGTH];
  List *list;

  list = gen_list();
  disp_list(list);
  while(printf("Key Name: "),scanf("%s",key)!=EOF){
    key_link(key, list);
  }
  disp_list(list);

  return 0;
}

// keyとリストのデータを検索・照合して，新規データを挿入
int key_link(char *key, List *list)
{
  Node *p, *new, *head;
  head=list->head;

  p=head;
  while(p!=NULL){ // リストの終端まで検索する
    if(strcmp(key,p->name)==0){ // keyと一致するノードがある場合
      new=gen_node();           // 新規ノードを作成してデータを入力
      printf("Extra Data (Name Tel): ");
      scanf("%s %s",new->name,new->tel);
      new->next=p->next; // ポインタの付け替え
      p->next=new;       // ポインタの付け替え
      return 0;
    }
    p=p->next; // 次のノードへ
  }
  printf("Key Data not found\n");
  return 1;
}

// ファイルからデータを読み込み，リストを作成
List *gen_list(void)
{
  Node *p,*head;
  List *list;
  FILE *fp;
  char *data_file=DATA_FILE;

  if((fp=fopen(data_file,"r"))==NULL){
    printf("%s can not be open\n",data_file);
  }

// リストの作成
  head=NULL;
  while(p=gen_node(),fscanf(fp,"%s %s",p->name,p->tel)!=EOF){
    p->next=head;
    head=p;
  }

  list=(List *)malloc(sizeof(List));
  list->head=head;
  //dlink->tail=tail;

  return list;
}

// リストを表示
int disp_list(List *list)
{
  Node *p,*head;

  head=list->head;

  p=head;
  printf("\n");
  while(p!=NULL){
    printf("%20s %15s\n",p->name,p->tel);
    p=p->next;
  }

  return 0;
}


Node *gen_node(void)
{
  return (Node *)malloc(sizeof(Node));
}
