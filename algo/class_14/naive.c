// 単純法（力まかせ法）による文字列探索

#include <stdio.h>

int bf_match(const char txt[], const char pat[])
{
  int pt = 0; // txtをなぞるカーソル
  int pp = 0; // patをなぞるカーソル

  while (txt[pt] != '\0' && pat[pp] != '\0'){
    if (txt[pt] == pat[pp]){
      pt++; pp++;
    } else {
      pt = pt - pp + 1;
      pp = 0;
    }
  }
  if (pat[pp] == '\0') // パターンの最後までマッチ
    return pt - pp;

  return -1;
}

int main(void)
{
  int index;
  char text[] = "penpineappleapplepen";
  char pattern[] = "apple";

//  printf("text : "); scanf("%s",text);
//  printf("pattern : "); scanf("%s",pattern);
  printf("text : "); printf("%s\n",text);
  printf("pattern : "); printf("%s\n",pattern);

  index = bf_match(text,pattern);

  if (index == -1){
    printf("パターンはテキスト中に存在しません．\n");
  } else {
    printf("パターンはテキストの%d文字目からマッチします．\n",index+1);
  }

  return 0;
}
