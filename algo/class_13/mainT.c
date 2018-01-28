/*
*  mainT.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "array3.h"
#include "quick.h"
#include <time.h>
#include "clock.h"
#include "data.h"

#define NMAX 1000001

int *allocateMemoryForIntData(int n) {
  // check the value of n
  int *d;
  if (n > NMAX) {
    printf("The input data size exeeds %d\n", NMAX);
    exit(2);
  } else if (n<0) {
    printf("n must be positive integer.\n");
    exit(1);
  }
  d = (int *)calloc(n, sizeof(int));
  if (d == NULL) {
    printf("Failed to allocate memoryn");
    exit(9);
  } else
    return d;
}


int main( int argc, char **argv ) {
  Data a[NMAX];
  int n, *data;;

  if (argc == 2)
    n = atoi(argv[1]);
  else {
    printf("Usage: mergesort n\n");
    return 1;
  }

  data = allocateMemoryForIntData(n);
  generateRandomData(data, n);

  // printArrayQS(a, 0, n-1, "input data");

  startClock();

  quicksort(a, 0, n-1);

  stopClock();
  printClock();

  // printArrayQS(a, 0, n-1, "sorted");

  return 0;
}
