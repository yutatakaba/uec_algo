#include <stdio.h>

int main(void)
{
  int n, m, i;

  m = 9;

  for ( i=1; i<=m; i++){
    for( n=1; n<=m; n++ ){
      if ( n < i ){
        printf("   ");
      }else{
        printf("%3d", i * n );
      }
    }
    printf("\n");
  }
    return 0;
}
