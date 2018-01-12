#include <stdio.h>
#include <stdlib.h>

double dist( int a[], int n )
{
  int i;
  double avg = 0.0;
  double powx = 0.0;
  double dis;

  for ( i=0; i<n; i++ ){
    avg = avg + a[i];
  }
  avg = avg / n;

  for ( i=0; i<n; i++ ){
    powx = powx + ( a[i] * a[i] );
  }

  dis = ( powx / n ) - ( avg * avg );
  return dis;
}

int main(void)
{
  int n, i, a;
  int *p;
  FILE *fp;
  double dis;

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
    dis = dist( p, n );
    free( p );
    printf("Sample distribution : %f\n", dis );

  return 0;

}
