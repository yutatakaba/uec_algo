/*
*  main2.c
*/

#include <stdio.h>
#include "array3.h"
#include "quick2.h"

#define NMAX 1000

int main() {
  Data a[NMAX];
  int n, count;

  // stdin は main() で定義されている標準入力
  n = getDataInArray(a, stdin);

  printArrayQS(a, 0, n-1, "input data");

  count = quicksort(a, 0, n-1);

  printArrayQS(a, 0, n-1, "sorted");
  printf("%d\n", count );

  return 0;
}
