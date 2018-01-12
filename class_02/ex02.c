#include <stdio.h>
#define N 200

double min( int a[], int n )
{
  int i;
  int min;

  min = a[0];
  for ( i=1; i<n; i++ ){
    if ( min>=a[i]) {
      min = a[i];
    }
  }
  return min;
}

int main(void)
{
  int i,  minimum;
  int a[N];

  for ( i=0; i<N; i++ ){
    scanf("%d", &a[i]);
  }

  minimum = min( &a[20], 100 );

  printf("Min : %d\n", minimum);

  return 0;
}
