/*
 * main3.c
 *  for a merge sorting method
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "data.h"
#include "clock.h"

#define NMAX 1000000

extern void merge_sort(int *a, int l, int r);

int main(int argc, char **argv) {
  int  n;
  int dArray[NMAX];

  if (argc == 2)
    n = atoi(argv[1]);
  else {
    printf("Usage: mergesort n\n");
    return 1;
  }

  generateRandomData(dArray, n);

  startClock();
  merge_sort(dArray, 0, n-1);
  stopClock();
  printClock();

  return 0;
 }
