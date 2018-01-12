#include <stdio.h>
#include <math.h>
#include <time.h>
#define NUM 1000


int main(void)
{
  clock_t start, end;
  start = clock();
  int i, j;
  int p_ptr[NUM];
  unsigned long counter = 0;

  for ( i=0; i<1000; i++ ){
    p_ptr[i] = 1;  // 全ての数に1を立てる
    p_ptr[0] = 0;    // 1は素数ではない
  }


  for (i = 1; i < sqrt(NUM); i++ ) {
    if (p_ptr[i] == 1){          // p_ptr[i]が素数なら
      for (j = (i+1); (i+1) * j <= NUM; j++ ){
        p_ptr[(i+1) * j - 1] = 0;  // 素数の倍数は素数ではない
        counter ++;
      }
    }
  }

  // for (i = 0; i < NUM; i++){
  //   if (p_ptr[i] == 1){  // 1が立っているものが素数
  //     printf("%3d\n", i + 1);
  //   }
  // }　実行結果が長くなるのでコメントアウトしました


  printf("除算を行った回数 : %lu\n", counter );
  end = clock();
  printf( "処理時間:%lu[ms]\n", end - start );

  return 0;

}
