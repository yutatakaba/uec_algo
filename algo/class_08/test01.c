#include <stdio.h>
#include <stdlib.h>
#define DATA_FILE "rand_bsearch.csv"


#define  NO    1  /* 番号（入力用）*/

/*--- メニュー ---*/
typedef enum {//列挙：書いた順番に番号が割り当てられる
  Term,  Delete, SrcNo
} Menu;

/*--- データ ---*/
typedef struct {
  int  no;       /* 番号 */
} Data;

/*--- ノード ---*/
typedef struct __node {
  Data           data;  /* データ */
  struct __node *next;  /* 後続ノードへのポインタ */
} Node;

/*--- ハッシュ表 ---*/
typedef struct {
  int  size;     /* ハッシュ表の大きさ */
  Node **table;  /* ハッシュ表の先頭要素へのポインタ */
} Hash;

/*--- ハッシュ関数（keyのハッシュ値を返す） ---*/
int hash(int key)
{
  return (key % 559);
}

/*--- ノードの各メンバに値を設定 ---*/
void SetNode(Node *n, int x, Node *next)
{
  n->data.no = x;     /* データ */
  n->next = next;  /* 後続ノードへのポインタ */
}

/*--- ハッシュ表を初期化 ---*/
int InitHash(Hash *h, int size)
{
  int i;

  h->size = 0;
  if((h->table = calloc(size, sizeof(Node *))) == NULL)  /* calloc = ヒープからメモリを確保 */
    return (0);

  h->size = size;         /* バケット数をセット */
  for(i=0; i<size; i++)
    h->table[i] = NULL;   /* 全バケットを初期化 */

  return (1);
}

/*--- ハッシュ表を後始末 ---*/
void TermHash(Hash *h)
{
  int i;

  for(i=0; i<h->size; i++){
    Node *p = h->table[i];
    while(p != NULL){
      Node *next = p->next;
      free(p);
      p = next;
    }
  }
  free(h->table);

}

/*--- 探索 ---*/
Node *SearchNode(Hash *h, Data x)
{
  int key = hash(x.no);        /* 探索するデータのハッシュ値 */
  Node *p = h->table[key];     /* 着目ノード */

  while(p != NULL){
    if(p->data.no == x.no)     /* このキーは登録済み */
      return (p);
    p = p->next;               /* 後続ノードに着目 */

  }
  return (NULL);               /* 探索失敗 */

}

/*--- データの格納 ---*/
int InsertNode(Hash *h)
{
  FILE *fp;
  char *data_file=DATA_FILE;
  int x;
  int ret;

  if((fp=fopen(data_file,"r"))==NULL){
    printf("%s can not be open\n",data_file);
  }

  while((ret = fscanf(fp,"%d", &x))!=EOF){
    int key = hash(x);               /* 追加するデータのハッシュ値 */
    Node *p = h->table[key];            /* 着目ノード */
    Node *temp;

    while(p != NULL){
      if(p->data.no == x)            /* このキーは登録済み */
        return (1);
        p = p->next;                      /* 後続ノードに着目 */
      }
    if ((temp = (Node *)calloc(1, sizeof(Node))) == NULL )  /* callocでメモリが確保できなかった場合 */
      return(2);
    SetNode(temp, x, h->table[key]);    /* 追加するノードの値を設定 */
    h->table[key] = temp;
  }
    return (0);
}


/*--- データの削除 ---*/
int DeleteNode(Hash *h, Data x)
{
  int key = hash(x.no);       /* 削除するデータのハッシュ値 */
  Node *p = h->table[key];    /* 着目ノード */
  Node **pp = &h->table[key]; /* 着目ノードへのポインタ */

  while(p != NULL){
    if(p->data.no == x.no){   /* 見つけたら */
      *pp = p->next;
      free(p);                /* 開放 */
      return (0);
    }
    pp = &p->next;            /* 後続ノードに着目 */
    p = p->next;
  }
  return (1);                 /* そのキー値は存在しない */
}

/*--- データの番号と氏名を表示 ---*/
void PrintData(Data x)
{
  printf("%d\n", x.no);
}

/*--- データの入力 ---*/
Data Read(char *message, int sw)
{
  Data temp;

  printf("%sするデータを入力してください\n", message);
  printf("番号：");  scanf("%d", &temp.no);
  return (temp);
}

/*--- メニュー選択 ---*/
Menu SelectMenu(void)
{
  int  ch;

  do{
    printf(" (1) 削除 (2) 探索  (0) 終了：");
    scanf("%d", &ch);
  } while (ch < Term || ch > SrcNo );

  return((Menu)ch);
}

/*--- メイン ---*/
int main(void)
{
  Menu menu;
  Hash hash;

  InitHash(&hash, 559);     /* ハッシュ表の初期化 */

  do{
    int result;
    Data x;
    Node *temp;

    InsertNode(&hash);

    switch(menu = SelectMenu()){
    case Delete : x = Read("削除", NO);
                  result = DeleteNode(&hash, x);
                  if(result == 1)
            printf("その番号のデータは存在しません.\n");
                  break;
    case SrcNo :  x = Read("探索", NO);
                  temp = SearchNode(&hash, x);
                  if(temp == NULL)
            printf("探索に失敗しました.\n");
                  else {
                    printf("探索に成功しました.\n");
                    PrintData(temp->data);
                  }
                  break;
    }
  } while (menu != Term);

  TermHash(&hash);      /* ハッシュ表の後始末 */

  return (0);
}
