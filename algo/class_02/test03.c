#include <stdio.h>
#include <math.h>

typedef struct Point2D{
  double x;
  double y;
} Point2D;

typedef struct Triangle{
  Point2D p1;
  Point2D p2;
  Point2D p3;
} Triangle;

double Distance2D( Point2D a, Point2D b )
{
  double sx, sy, dis;

  sx = ( a.x - b.x ) * ( a.x - b.x );
  sy = ( a.y - b.y ) * ( a.y - b.y );
  dis = sqrt( sx + sy );

  return dis;
}

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

double Area( Triangle t )
{
  double area, a, b, c, s;

  a = Distance2D( t.p1, t.p2 );
  b = Distance2D( t.p2, t.p3 );
  c = Distance2D( t.p3, t.p1 );
  s = ( a + b + c ) / 2;
  area = sqrt( s * ( s - a ) * ( s - b ) * ( s - c ) );

  return area;
}

int main(void)
{
  Triangle a;
  double area;

  a.p1 = ScanPoint2D();
  a.p2 = ScanPoint2D();
  a.p3 = ScanPoint2D();

  area = Area( a );

  printf("%f\n", area );

  return 0;
}
