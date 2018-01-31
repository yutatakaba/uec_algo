// strstr関数の利用例

#include <stdio.h>
#include <string.h>

int main(void)
{
  char text[256];
  char pattern[256];
  char *p;

  printf("text : "); scanf("%s",text);
  printf("pattern : "); scanf("%s",pattern);

  p = strstr(text,pattern);

  if (p == NULL){
    printf("パターンはテキスト中に存在しません．\n");
  } else {
    int offset = p - text;
    printf("\n%s\n",text);
    printf("%*s|\n",offset,"");
    printf("%*s%s\n",offset,"",pattern);
  }

  return 0;
}
