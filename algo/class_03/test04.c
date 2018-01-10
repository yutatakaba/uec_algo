#include <stdio.h>
#include <time.h>


int main(void)
{
  clock_t start, end;
  start = clock();
  int i, v, n;

  v = 1;
  printf("3^x ?\n");
  printf("x = " );
  scanf("%d", &n );
  for (i = 0; i < n; i++) {
    v *= 3;
    v = v % 997;
  }
  printf("3^%d : %d\n",i, v);

  end = clock();
  printf( "処理時間:%lu[ms]\n", end - start );

  return 0;
}
