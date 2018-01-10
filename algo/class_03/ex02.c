#include <stdio.h>

int main(void)
{
  int i, v, n;

  v = 1;
  for (i = 0; i < 100; i++) {
    v *= 3;
    v = v % 997;
    printf("3^%d : %d\n",i+1, v);
  }


  return 0;
}
