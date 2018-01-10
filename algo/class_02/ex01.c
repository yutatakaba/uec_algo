#include <stdio.h>

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
  double m;
  int a[10] = { 8, 3, 2, 4, 5, 7, 6, 9, 0, 1 };

  m = mean( &a[3], 4 );
  printf("average of a = %f\n", m );

  return 0;

}
