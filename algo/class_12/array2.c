/*
* array.c
*/
#include <stdio.h>
#include <string.h>
#include "heap2.h"
#include "array2.h"

// データの読み込み
int getDataInArray(Data *a, FILE *f) {
  char line[512], *s;
  int n = 0;


  while (fgets(line, sizeof(line), f)) {
    s = strtok(line, " ");
    sscanf(s, "%d", &a[++n]); // read at index 1
    while (s) {
      s = strtok(NULL, " ");
      if (s)
        sscanf(s, "%d", &a[++n]);
    }
  }



  return n;
}

void swap(Data *a, int i, int j) {
  Data t;
  t = a[i];
  a[i] = a[j];
  a[j] = t;
}

void printArray(Data *a, int n) {
  int i;
  for (i=0; i<n; i++)
    printf("%7d\n", a[i+1]);
  printf("\n");
}
