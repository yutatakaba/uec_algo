#include <stdio.h>
#include <time.h>

int main(void)
{
  clock_t start, end;
  start = clock();
  int i, n;
  unsigned long counter = 0;	/* 除算の回数 */

  for (n = 2; n <= 1000; n++) {
    for (i = 2; i < n; i++) {
      counter++;
      if (n % i == 0)		/* 割り切れると素数ではない */
        break;		/* それ以上の繰返しは不要 */
    }
    // if (n == i)			/* 最後まで割り切れなかった */
      // printf("%d\n", n);　実行結果が長くなるためコメントアウトしました
  }
  printf("除算を行った回数：%lu\n", counter);
  end = clock();
  printf( "処理時間:%lu[ms]\n", end - start );

  return 0;
}
