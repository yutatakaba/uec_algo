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
    if( p->data == key ){ // keyと一致するノードがある場合
      result = 1;
      return i+1;
    }
    p=p->next; // 次のノードへ
    i++;
  }
  return result;
}

/*二つの値の間に含まれる要素が格納されている箇所をすべて表示する関数*/
int display( const Node *p, int result_1, int result_2, int n )
{
  int i = 0;

  while( i <= n ){
    if( result_2 <= i+1 && i < result_1 ){    //searchの引数から表示する区間を限定
      printf("%dは%d番目にあります\n", p->data, i+1);
    }
    p=p->next; // 次のノードへ
    i++;
  }
  return 0;
}

int main(void)
{
  int ky_1, ky_2, count, result_1, result_2;
  int area;
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

  printf("キー１を入力して下さい:");
  scanf("%d", &ky_1);
  printf("キ−２を入力して下さい:");
  scanf("%d", &ky_2);

  result_1 = search(head, ky_1, count);
  result_2 = search(head, ky_2, count);
  area = result_1 - result_2;

  if(result_1 == 0 || result_2 == 0 ){
    printf("探索に失敗しました\n");
    exit(1);
  }

  if( area > 0 ){
    display(head, result_1, result_2, count);
  }else if( area < 0 ){
    display(head, result_2, result_1, count);
  }else if( area == 0 ){
    printf("同値が入力されています\n");
  }

  return 0;
}

Node *gen_node(void)
{
  return (Node *)malloc(sizeof(Node));
}
