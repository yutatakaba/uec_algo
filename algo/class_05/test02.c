// スタック（ポインタを用いたリスト構造による実現）

#include <stdio.h>
#include <stdlib.h>

// ノードを表す構造体
typedef struct _Node {
  int data;
  struct _Node *next;
} Node;

// スタックを表す構造体
typedef struct {
  Node *top; // スタックの頂上
} Stack;

Node *gen_node(void);
Stack *gen_stack(void);
int is_empty(Stack *q);
void push(Stack *s,int data);
int pop(Stack *s);
void disp_stack(Stack *s);

int main()
{
  Stack *s_0, *s_1, *s_2; // スタックの実態のアドレスを表すポインタ変数
  s_0=gen_stack(); // スタックの実態をメモリに生成して，アドレスをポインタ変数sに格納
  s_1=gen_stack();
  s_2=gen_stack();
  int menu, data, i;

  for ( i=10; i<=40; i=i+10 ){
    data = i;
    push(s_0,data);
  }
  printf("s[0]: TOP| "); disp_stack(s_0); printf("|BOTTOM\n");

  while ( is_empty(s_0) != 1 ){
    data=pop(s_0);
    push(s_1,data);
  }
  printf("s[1]: TOP| "); disp_stack(s_1); printf("|BOTTOM\n");

  while ( is_empty(s_1) != 1 ){
    data=pop(s_1);
    push(s_2,data);
  }
  printf("s[2]: TOP| "); disp_stack(s_2); printf("|BOTTOM\n");

  while ( is_empty(s_2) != 1 ){
    data=pop(s_2);
    push(s_0,data);
  }
  printf("s[0]: TOP| "); disp_stack(s_0); printf("|BOTTOM\n");

  return 0;
}

Stack *gen_stack(void)
{
  Stack *s;

  s=(Stack *)calloc(1,sizeof(Stack));
// s=(Stack *)malloc(sizeof(Stack));
  s->top=NULL; // 空のスタックで初期化

  return s;
}

int is_empty(Stack *s)
{
  if (s->top==NULL){
    return 1;
  } else {
    return 0;
  }
}

void push(Stack *s,int data)
{
  Node *new;

  // 新しいノードを生成して，これまでの頂上に追加
  new=gen_node();
  new->data=data;
  new->next=s->top;
  // 頂上を追加ノードに更新
  s->top=new;
}

int pop(Stack *s)
{
  int data;
  Node *old;

  if (is_empty(s)){
    printf("In function pop: stack is empty.\n");
    exit(1);
  }
  old=s->top;
  data=old->data;
  s->top=old->next;
  free(old);

  return data;
}

void disp_stack(Stack *s)
{
  Node *ptr;

  ptr=s->top;
  while(ptr!=NULL){
    printf("%d ",ptr->data);
    ptr=ptr->next;
  }
}

Node *gen_node(void)
{
  return (Node *)calloc(1,sizeof(Node));
// return (Node *)malloc(sizeof(Node));
}
