#include <stdio.h>

double choose( int k, int n )
{
  double c;
  double f = 1.0;
  while( k>0 ){
    f = f * k;
    n--;
  }

  double p = 1.0;
  int i;
  if ( k!=0 ){
    for ( i=k; i<=n; i++ ){
      p = p * i;
    }
  }
  c = p / f;
  return c;
}

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

double sum( int n )
{
  double a[n];
  double sum = 0.0;
  int i;

  for ( i=0; i<=n; i++ ){
    sum = sum + a[i];
  }
  return sum;
}

int main(void)
{
 
}
