#include <stdio.h>
#include <stdlib.h>

// ノードを表す構造体
typedef struct _Node {
  int data, num; //データと番号
  struct _Node *next;
  struct _Node *prev;
} Node;

//リストの構造体を作成
typedef struct _List {
  struct _Node *head; // 先頭ノード
  struct _Node *tail; // 先頭ノード
} List;

/* --- 要素数nの構造体リストからkeyと一致する要素を２分探索 --- */
int bin_search(Node *head, Node *tail, int num, Node *data, int key)
{
  int center;
  int center_vol;
  int left = 0;
  int right;
  int count = 0;
  // printf("%d",center->data);
  Node *p, *atama, *sippo;

  atama = head;
  sippo = tail;
  p = atama;
  right = num -1;

  do{
    center = (left + right) / 2;
    p=head;
    while(count<=center){
      p=p->next; // 次のノードへ
      center_vol = data->data;
      printf("%d\n", center_vol );
      count++;
    }
    if ( center_vol == key || center == 0 ){
      return (center);     /* 探索成功 */
    }else if ( center_vol < key ){
      left = center + 1;
    }else{
      right = center - 1;
    }
  } while (left <= right );

   return (-1);         /* 探索失敗 */
}

Node *gen_node(void){
  return (Node *)calloc(1,sizeof(Node));
}

int main(void){
  List *list;
  Node *p,*head,*tail;
  int num=0, ky, idx;
  FILE *fp;
  char *data_file="test.csv";

  if((fp=fopen(data_file,"r"))==NULL){
    printf("ファイルを開けません。");
    return -1;
  }

  head = gen_node();
  fscanf(fp,"%d",&head->data);
  head->num = num++;
  tail = head;
  while(p = gen_node(),fscanf(fp,"%d",&p->data)!=EOF){
    p->num = num++;
    tail->next=p;
    tail=p;
  }
  tail->next=NULL;
  list=(List *)malloc(sizeof(List));
  list->head=head;
  list->tail=tail;

  printf("探す値を入力してください: ");
  scanf("%d", &ky);

  idx = bin_search(head, tail, num, p, ky);  /* 値がkyである要素を２分探索 */

  if(idx == -1)
    printf("探索に失敗しました。\n");
  else
    printf("%dは%d番目にあります\n", ky, idx+1);

  return (0);
}
