#include <stdio.h>
#include <stdlib.h>

// ノードを表す構造体
typedef struct _Node {
  int data;
  struct _Node *next;
} Node;

Node *gen_node(void);

/*-- 要素数nの配列aからkeyと一致する要素を線形探索 ---*/
int search( const Node *p, int key, int n )
{
  int i = 0;
  int result = 0;

  while( i <= n ){
    if( p->data == key){ // keyと一致するノードがある場合
      result = 1;
      printf("%dは%d番目にあります\n", key, i+1);
    }
    p=p->next; // 次のノードへ
    i++;
  }
  return result;
}

int main(void)
{
  int ky_1, ky_2, count, result, i;
  FILE *fp;
  Node *p,*head, *tail;

  // 逆順リストの作成
  count = 0;
  fp = fopen("rand10000.csv", "r");
  head=gen_node();
  fscanf(fp,"%d",&(head->data));
  tail=head;
  while(p=gen_node(),fscanf(fp,"%d",&(p->data))!=EOF){
    tail->next=p;
    tail=p;
    count++;
  }
  tail->next=NULL;
  fclose( fp );

  printf("キー１を入力して下さい");
  scanf("%d", &ky_1);
  printf("キー２を入力して下さい");
  scanf("%d", &ky_2);

  if(ky_1 <= ky_2){
    for(i=ky_1; i<=ky_2; i++){
      result = search(head, i, count);
      if( result == 0 )
        printf("%dはありません\n", i);
    }
  }else if( ky_2 < ky_1){
    for(i=ky_2; i<=ky_1; i++){
      result = search(head, i, count);
      if( result == 0 )
        printf("%dはありません\n", i);
    }
  }

  return 0;
}

Node *gen_node(void)
{
  return (Node *)malloc(sizeof(Node));
}
