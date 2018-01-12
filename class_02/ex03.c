#include <stdio.h>
#include <stdlib.h>

double mean( int a[], int n )
{
  int i;
  double avg = 0.0;

  for ( i=0; i<n; i++ ){
    avg = avg + a[i];
  }
  avg = avg / n;
  return avg;
}


int main(void)
{
  int n, i, a;
  int *p;
  FILE *fp;
  double avg;

  printf("Elements : ");
  scanf("%d", &n);

  p = (int *)calloc( n, sizeof(int) );

  if ( p == NULL){
    printf("Falied");
  }else{
      i = 0;
      fp = fopen("rand10000.csv", "r" );
      if ( fp == NULL){
        printf("Not file\n");
      }else{
        while( fscanf( fp, "%d" , &a ) == 1 && i < n ){
          p[i] = a;
          i++;
        }
      }
    }
    avg = mean( p, n );
    free( p );
    printf("Average : %f\n", avg );

  return 0;

}
