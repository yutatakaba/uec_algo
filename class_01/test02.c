#include <stdio.h>
#define N 100

int a[N+2];
int main(void)
{
  FILE *fp;
  int i, j, max, min;


  for ( i=0; i<N; i++ ){
    scanf("%d", &a[i]);
  }

  max = a[0];
  min = a[0];
  for ( i=1; i<N; i++ ){
    if ( max<=a[i]) {
      max = a[i];
    }
    if ( min>=a[i]) {
      min = a[i];
    }
  }

 a[100] = min;
 a[101] = max;

 if ((fp = fopen("rand10000_min_max.crv", "w")) != NULL ){
   for ( j=0; j<N+2; j++ ){
     if(fprintf( fp, "%d\n", a[j] ) <0 ){
       break;
     }
   }
   fclose( fp );
 }else{}

  return 0;
}
