#include <stdio.h>

typedef struct Point2D{
  double x;
  double y;
} Point2D;

Point2D ScanPoint2D(void)
{
  Point2D p;
  printf("Input 2 values\n");
  printf("x : ");
  scanf("%lf", &p.x);
  printf("y : ");
  scanf("%lf", &p.y);
  return p;
}

double Innerprod( Point2D a, Point2D b )
{
  double inpro;
  inpro = a.x * b.x + a.y * b.y;

  return inpro;
}

int main(void)
{
  Point2D p, q;
  double i;
  p = ScanPoint2D();
  q = ScanPoint2D();

  i = Innerprod( p, q );
  printf("Innerprod = %f\n", i );

  return 0;
}
