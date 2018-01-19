/*
*  main.c
*/

#include <stdio.h>
#include "array3.h"
#include "quick.h"

#define NMAX 1000

int main() {
  Data a[NMAX];
  int n;

  // stdin は main() で定義されている標準入力
  n = getDataInArray(a, stdin);

  printArrayQS(a, 0, n-1, "input data");

  quicksort(a, 0, n-1);

  printArrayQS(a, 0, n-1, "sorted");

  return 0;
}
