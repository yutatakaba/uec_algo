/*
*  quick2.c
*/
#include <stdio.h>
#include "array3.h"

int quicksort(Data *a, int l, int r) {
  int t;    // データを仕分ける基準値
  int i, j;
  int mcnt, lcnt, rcnt;

  if (l >= r) return 0;
  mcnt = 0;

  t=a[r];
  i=l-1; j=r;

  while (1) {
    while (a[++i]<t){
      mcnt += i;
    }
    mcnt += 1;
    // printf("%d\n", mcnt );
    while (a[--j]>t){
      mcnt += j;
    }
    mcnt += 1;
    // printf("%d\n", mcnt );
    // printArrayQS(a, 0, 8, "sorting");
    if (i < j)
      swap(a, i, j);
    else
      break;
  }

  a[r]=a[i];
  a[i]=t;

  lcnt = quicksort(a, l, i-1);
  rcnt = quicksort(a, i+1, r);

  return mcnt+lcnt+rcnt;
}
