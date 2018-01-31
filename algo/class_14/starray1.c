// 配列による文字列の格納

#include <stdio.h>

int main(void)
{
  char st[10];

  st[0] = 'A';
  st[1] = 'B';
  st[2] = 'C';
  st[3] = 'D';
  st[4] = '\0';

  printf("文字列 st には\"%s\"が格納されています．\n",st);

  return 0;
}
