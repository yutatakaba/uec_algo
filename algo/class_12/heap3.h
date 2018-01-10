/*
* heap3.h
*/
typedef int Data;

void buildHeap(Data *, int);
void upHeap(Data *, int, int);
void heapQ(Data *a, int n);
void downHeap(Data *a, int i, int k); // 新たに追加したもの
