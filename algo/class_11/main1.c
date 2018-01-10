/*
 * main1.c
 */
#include <stdio.h>
#include <stdlib.h>
#include "clock.h"
#include "data.h"

extern void simplesort(int *d, int n);

#define NMAX 1000000

int main(int argc, char **argv) {
  int n;
  int dArray[NMAX];

  if (argc == 2)
    n = atoi(argv[1]);
  else {
    printf("Usage: mergesort n\n");
    return 1;
  }

  generateRandomData(dArray, n);
  startClock();
  simplesort(dArray, n);
  stopClock();
  printClock();

  return 0;
}
