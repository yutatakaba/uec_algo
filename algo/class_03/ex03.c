#include <stdio.h>
#include <math.h>

int main(void)
{
  int mod_4 = 3;
  int mod_64 = 3;
  int mod_32 = 3;
  int i;
  int remain;

  for( i=0; i<6; i++ ){
    mod_64 = ( mod_64 % 997 ) * ( mod_64 % 997 ) % 997;
  }

  for( i=0; i<5; i++ ){
    mod_32 = ( mod_32 % 997 ) * ( mod_32 % 997 ) % 997;
  }

  for( i=0; i<2; i++ ){
    mod_4 = ( mod_4 % 997 ) * ( mod_4 % 997 ) % 997;
  }

  remain = ( mod_4 * mod_32 * mod_64 ) % 997;
  printf("%d\n", remain );

  return 0;
}
