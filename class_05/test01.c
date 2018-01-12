// キュー（ポインタを用いたリスト構造による実現）

#include <stdio.h>
#include <stdlib.h>

// ノードを表す構造体
typedef struct _Node {
  int data;
  struct _Node *next;
} Node;

// キューを表す構造体
typedef struct {
  Node *head;
  Node *tail;
} Queue;

Node *gen_node(void);
Queue *gen_queue(void);
int is_empty(Queue *q);
void enqueue(Queue *q,int data);
void disp_queue_0(Queue *q);
void disp_queue_1(Queue *q);


int main()
{
  Queue *q_0, *q_1;
  q_0=gen_queue();    //偶数のキュー
  q_1=gen_queue();    //奇数のキュー

    int menu, data;

    while(scanf("%d", &data)!=EOF){
      if (data % 2 == 1){
        enqueue(q_1,data);    //奇数ならq_1に代入
      }else{
        enqueue(q_0,data);    //偶数ならq_0に代入
      }
    }

    disp_queue_0(q_0);
    disp_queue_1(q_1);

  return 0;
}

Queue *gen_queue(void)
{
  Queue *q;

  q=(Queue *)calloc(1,sizeof(Queue));
// q=(Queue *)malloc(sizeof(Queue));
  q->head=q->head=NULL;

  return q;
}

int is_empty(Queue *q)
{
  if (q->head==NULL){
    return 1;
  } else {
    return 0;
  }
}

void enqueue(Queue *q,int data)
{
  Node *new;

  new=gen_node();
  new->data=data;
  new->next=NULL;

  if (is_empty(q)){
    q->head=q->tail=new;
  } else {
    q->tail->next=new;
    q->tail=new;
  }
}

int dequeue(Queue *q)
{
  int data;
  Node *old;

  if (is_empty(q)){
    printf("In function dequeue: queue is empty.\n");
    exit(1);
  }
  old=q->head;
  data=old->data;
  q->head=old->next;
  free(old);

  return data;
}

void disp_queue_0(Queue *q)
{
  Node *ptr;

  ptr=q->head;
  while(ptr!=NULL){
    printf("Q[0]: %d \n",ptr->data);
    ptr=ptr->next;
  }
}

void disp_queue_1(Queue *q)
{
  Node *ptr;

  ptr=q->head;
  while(ptr!=NULL){
    printf("Q[1]: %d \n",ptr->data);
    ptr=ptr->next;
  }
}

Node *gen_node(void)
{
  return (Node *)calloc(1,sizeof(Node));
// return (Node *)malloc(sizeof(Node));
}
