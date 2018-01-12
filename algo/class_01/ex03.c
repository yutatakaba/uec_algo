#include <stdio.h>
#include <math.h>

double power( int n )
{
  double p;
  int i;

  p = 1.0;
  if ( n > 0 ){
    for ( i=0; i<n; i++ ){
      p = p * 2;
    }
  }
  return p;
}

int main(void)
{
  int n;
  double f, p;

  printf("Please input number\n");
  scanf("%d", &n );

  f = power( n );
  p = pow( 2, n );

  printf("2^%d        : %f\n", n, f );
  printf("2^%d( pow ) : %f\n", n, p );

  return 0;

}
