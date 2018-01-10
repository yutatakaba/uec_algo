#include <stdio.h>
#define N 100

int main(void)
{
  FILE *fp;
  int i,  max, min;
  int a[N];

  for ( i=0; i<N; i++ ){
    scanf("%d", &a[i]);
  }

  // i = 0;
  // if ( fp == NULL){
  //   printf("Not file\n");
  // }else{
  //   while( fscanf( fp, "%d" , &a ) == 1 && i < N ){
  //     n[i] = a;
  //     i++;
  //   }
  // }

  max = a[0];
  min = a[0];
  for ( i=1; i<N; i++ ){
    if ( max<=a[i]) {
      max = a[i];
    }
    if ( min>=a[i]) {
      min = a[i];
    }
  }

  printf("Max : %d\n", max);
  printf("Min : %d\n", min);

  return 0;
}
