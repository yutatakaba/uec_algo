/*
* heap2.c
*/
#include <stdio.h>
#include "heap2.h"
#include "array2.h"

void buildHeap(Data *a, int n) {
  int l, r, k, power2=1;

  if (n > 1) {
    for (l=1; ; l++) {
      power2 <<= 1;    // power2 = 2^l
      for (r = 0; r<power2; r++) {
        k=power2+r;
        upHeap(a, k, l);
        if (k==n)
          return;
      } // end of the inner loop
    } // end of the outer loop
  } // end of if
}

void upHeap(Data *a, int k, int l) {
  int i, j, p, b;

  b = 1;
  p = j = k;

  for (i = 1; i <= l; i++) {
    p = (k & b)?((j-1)/2):j/2;
    if (a[p] < a[j]) {
      swap(a, p, j);
      j = p;
    } else
      break;
    b <<= 1;
  }
}

static int _max3(int a, int b, int c) {
  int v;

  if ( a > b ){
    v = a;
  }else{
    v = b;
  }

  if ( v > c ){
    return v;
  }else{
    v = c;
    return v;
  }
}

static int _getMaxCBT(Data *a, int n, int k) {
  int lv, rv;

  if (k > n) { // 節点kは配列の範囲を越えている
    return -1;
  } else {
    lv = _getMaxCBT(a, n, 2*k);
    rv = _getMaxCBT(a, n, 2*k+1);
  }
  return _max3(lv, a[k], rv);
}

void heapQ(Data *a, int n) {
  int i, maxv;

  for (i = 1; i <= n; i++) {
    maxv = _getMaxCBT(a, n, i);
    if (a[i] != maxv) {
      break;
    }
  }
  printf("This array is%sa heap.\n", (i==n+1)?" ":" NOT ");
}
