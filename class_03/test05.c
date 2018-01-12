#include <stdio.h>
#include <math.h>
#include <time.h>

int main(void)
{
  clock_t start, end;
  int mod_1 = 3;
  int mod_2 = 3;
  int mod_4 = 3;
  int mod_8 = 3;
  int mod_16 = 3;
  int mod_32 = 3;
  int mod_64 = 3;
  int i,n,a,b,c,d,e,f;
  int p_1,p_2,p_4,p_8,p_16,p_32,p_64;
  int remain = 1;

  p_1= p_2 = p_4 = p_8 = p_16 = p_32 = p_64 = 1;


  start = clock();

  printf("3^x mod(997) ?\n");
  printf("x = " );
  scanf("%d", &n );

  if ( n / 64 > 0 ){
    for( i=0; i<6; i++ ){
      mod_64 = ( mod_64 % 997 ) * ( mod_64 % 997 ) % 997;
    }
    p_64 = mod_64;
    a = n % 64;
  }else{
    a = n;
  }

  if ( a / 32 > 0 ){
    for( i=0; i<5; i++ ){
      mod_32 = ( mod_32 % 997 ) * ( mod_32 % 997 ) % 997;
    }
    p_32 =  mod_32;
    b = a % 32;
  }else{
    b = a;
  }

  if ( b / 16 > 0 ){
    for( i=0; i<4; i++ ){
      mod_16 = ( mod_16 % 997 ) * ( mod_16 % 997 ) % 997;
    }
    p_16 =  mod_16;
    c = b % 16;
  }else{
    c = b;
  }

  if ( c / 8 > 0 ){
    for( i=0; i<3; i++ ){
      mod_8 = ( mod_8 % 997 ) * ( mod_8 % 997 ) % 997;
    }
    p_8 =  mod_8;
    d = c % 8;
  }else{
    d = c;
  }

  if ( d / 4 > 0 ){
    for( i=0; i<2; i++ ){
      mod_4 = ( mod_4 % 997 ) * ( mod_4 % 997 ) % 997;
    }
    p_4 =  mod_4;
    e = d % 4;
  }else{
    e = d;
  }

  if ( e / 2 > 0 ){
    for( i=0; i<1; i++ ){
      mod_2 = ( mod_2 % 997 ) * ( mod_2 % 997 ) % 997;
    }
    p_2 =  mod_2;
    f = e % 2;
  }else{
    f = e;
  }

  if( f == 1){
    p_1 = mod_1;
  }

  remain = ( p_64 * p_32 * p_16 * p_8 * p_4 * p_2 *p_1 ) % 997;
  printf("%d\n", remain );

  end = clock();
  printf( "処理時間:%lu[ms]\n", end - start );

  return 0;
}
