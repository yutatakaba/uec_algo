//  リストからのノード削除

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

Node *gen_node(void);
int gen_list(void);
int disp_list(void);
int del(char *);

// リストの先頭を保持する大域変数
Node *head;

int main(void){
  char key[NAME_LENGTH];

  gen_list();
  disp_list();
  while(printf("Key Name: "),scanf("%s",key)!=EOF){
    del(key);
  }
  disp_list();

  return 0;
}

// keyとリストのデータを検索・照合して，keyが見つかったら削除する
int del(char *key)
{
  Node *p, *prev;
// pはkeyと比較中のノードを，prev はその前(previous)のノードを指す

  p=prev=head;
  while(p!=NULL){
    if(strcmp(key,p->name)==0){ // keyと一致するデータが見つかった場合
      if(p==head){
// keyが先頭にある場合，次のノードを先頭にする
        head=p->next;
      } else {
// keyが先頭にない場合，前のノードを次のノードへ繋ぐ（ノードpを飛ばして繋ぐ）
        prev->next=p->next;
      }
      free(p); // メモリ開放
      return 0;
    }
    prev=p;
    p=p->next;
  }
  printf("Key Data not found\n");
  return 1;
}

int gen_list(void)
{
  Node *p;
  FILE *fp;
  char *data_file=DATA_FILE;

  if((fp=fopen(data_file,"r"))==NULL){
    printf("%s can not be open\n",data_file);
    return 1;
  }
  head=NULL;
  while(p=gen_node(),fscanf(fp,"%s %s",p->name,p->tel)!=EOF){
    p->next=head;
    head=p;
  }

  return 0;
}

int disp_list(void)
{
  Node *p;

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
