#include <stdio.h>

double power( double x, double n )
{
  int i;
  double p;

  p = 1.0;
  if ( n > 0 ){
    for ( i=0; i<n; i++ ){
      p = p * x ;
    }
  }
  return p;
}

double fact( int n )
{
  double f = 1.0;
  while( n>0 ){
    f = f * n;
    n--;
  }

  return f;
}

int main(void)
{
  int n, m;
  double x, a, b;
  double f, p, ans;

  printf("Please input number\n");
  printf("a^x^n + b^m!\n" );
  printf("a : ");
  scanf("%lf", &a );
  printf("x : ");
  scanf("%lf", &x );
  printf("n : ");
  scanf("%d", &n );
  printf("b : ");
  scanf("%lf", &b );
  printf("m : ");
  scanf("%d", &m );


  p = power( x, n );
  f = fact( m );
  ans = power( a, p ) + power( b, f );

  printf("%f^%f^%d + %f^%d! : %f\n", a, x, n, b, m, ans );

  return 0;
}
