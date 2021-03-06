#include <stdio.h>
#include <stdlib.h>
#define DATA_FILE "rand_bsearch.csv"

// ノードを表す構造体
typedef struct _Node {
  int data; //値を格納するint型の変数
  int count; //何番目の構造体かを示すint型の変数
  struct _Node *prev; // 逆方向のポインタ
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

/* --- 要素数nの配列aからkeyと一致する要素を２分探索 --- */
int bin_search(const DlinkList *dlink, int key)
{
  int left = 0;     /* 探索範囲先頭の添字 */
  int right; /*    〃   末尾の添字 */
  int center;         /*    〃   中央の添字 */
  int center_vol;
  Node *p,*head,*tail;

  head=dlink->head;
  tail=dlink->tail;

  p=head;
  right = p->count -1;

  do{
    center = (left + right) / 2;
    p=tail;
    while(p->count<=center){
      p=p->prev; // 次のノードへ
      center_vol = p->data;
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


int main(void){
  DlinkList *dlink;
  int ky, idx;

  printf("探す値 : ");
  scanf("%d", &ky);

  dlink=gen_dlink_list();

  idx = bin_search(dlink, ky);// count);  /* 配列xから値がkyである要素を２分探索 */

  if(idx == -1)
    printf("探索に失敗しました。\n");
  else
    printf("%dは%d番目にあります\n", ky, idx+1);

  return (0);
}

//双方向リストの生成
DlinkList *gen_dlink_list(void)
{
  Node *p,*head,*tail;
  DlinkList *dlink;
  FILE *fp;
  char *data_file=DATA_FILE;
  int n = 0;

  if((fp=fopen(data_file,"r"))==NULL){
    printf("%s can not be open\n",data_file);
  }

// リストの作成（順方向ポインタも作成）
  head=NULL;
  while(p=gen_node(),fscanf(fp,"%d", &(p->data))!=EOF){
    p->next=head;
    head=p;
    n++;
    p->count = n;
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

Node *gen_node(void)
{
  return (Node *)malloc(sizeof(Node));
}
