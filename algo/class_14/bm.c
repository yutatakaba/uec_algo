// Boyer-Moore法による文字列探索

#include <stdio.h>
#include <string.h>
#include <limits.h>

int bm_match(const char txt[], const char pat[])
{
  int pt; // txtをなぞるカーソル
  int pp; // patをなぞるカーソル
  int txt_len = strlen(txt); // txtの文字数
  int pat_len = strlen(pat); // patの文字数
  int skip[UCHAR_MAX+1]; // スキップテーブル

  // スキップテーブルの作成
  for (pt=0; pt<=UCHAR_MAX; pt++)
    skip[pt] = pat_len;
  for (pt=0; pt<pat_len-1; pt++)
    skip[pat[pt]] = pat_len - pt - 1;

  // スキップテーブルの表示
  for (pt=0; pt<pat_len; pt++)
    printf("%c : %d\n",pat[pt],skip[pat[pt]]);

  while (pt < txt_len){
    pp = pat_len-1;
    while (txt[pt] == pat[pp]){
      if (pp == 0) return pt; // 検索成功
      pp--; pt--;
    }
    // スキップテーブルに従って，テキストカーソルを移動
    // ただし，移動量が少なくてテキストが右にずれない場合は，パターンを１つ右に移動
    pt += (skip[txt[pt]] > pat_len - pp) ? skip[txt[pt]] : pat_len - pp;
  }
  return -1;
}

int main(void)
{
  int index;
  char text[256];
  char pattern[256];

  printf("text : "); scanf("%s",text);
  printf("pattern : "); scanf("%s",pattern);

  index = bm_match(text,pattern);
  if (index == -1){
    printf("パターンはテキスト中に存在しません．\n");
  } else {
    printf("パターンはテキストの%d文字目からマッチします．\n",index+1);
  }

  return 0;
}
