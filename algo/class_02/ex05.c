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

double Angela( Triangle t )
{
  double ang, a2, b, b2, c, c2, x;

  b = Distance2D( t.p2, t.p3 );
  c = Distance2D( t.p3, t.p1 );
  a2 =  pow( Distance2D( t.p1, t.p2 ), 2 );
  b2 =  pow( Distance2D( t.p2, t.p3 ), 2 );
  c2 =  pow( Distance2D( t.p3, t.p1 ), 2 );

  x = ( b2 + c2 - a2 ) / ( 2 * b * c);

  ang = acos( x );

  return ang;
}

int main(void)
{
  Triangle a;
  double angle;

  a.p1 = ScanPoint2D();
  a.p2 = ScanPoint2D();
  a.p3 = ScanPoint2D();

  angle = Angela( a ) * 180 / M_PI;

  printf("%f\n", angle );

  return 0;
}
