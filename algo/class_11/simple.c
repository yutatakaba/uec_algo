/*
* simple.c
*/
#include <stdio.h>

void swap(int *data, int i, int j) {
  int t;
  t = data[i]; data[i] = data[j]; data[j] = t;
}

void simplesort(int *data, int N) {
  int i, j;

  for (i = 0; i < N-1; i++) {
    for (j = i+1; j < N; j++){
      if (data[i] > data[j]) {
        swap(data, i, j);
      }
    }
  }
}
