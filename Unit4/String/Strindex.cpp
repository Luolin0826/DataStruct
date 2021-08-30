#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSTRLEN 80  //在255范围内定义最大串长(255为1个字节)
typedef char SString[MAXSTRLEN + 1];  //位置0存放串的长度

//简单字符匹配 匹配到返回起始位置 没匹配到返回-1
int Strindex_bf(SString s, SString t) {
  int i = 1, j = 1;
  while (i <= s[0] && j <= t[0]) {  //没到达终点
    if (s[i] == t[j]) {
      i++;
      j++;
    } else {
      i = i - j + 2;
      j = 1;
    }
  }
  if (j > t[0]) {  //匹配到终点了
    return (i - t[0]);
  } else {
    return -1;
  }
}

//获取next数组
void GetNext(SString s, int next[]) {
  int i = 1, j = 0;
  next[1] = 0;
  while (i < s[0]) {
    if (s[i] == s[j] || j == 0) {
      next[++i] = ++j;
    } else {
      j = next[j];
    }
  }
}

// KMP 匹配到返回起始位置 没匹配到返回-1
int Strindex_kmp(SString s, SString t) {
  int i = 1, j = 1;
  int next[20];
  GetNext(t, next);
  while (i <= s[0] && j <= t[0]) {  //没到达终点
    if (s[i] == t[j] || j == 0) {   //记得此处要加上j==0
      i++;
      j++;
    } else {
      j = next[j];
    }
  }
  if (j > t[0]) {  //匹配到终点了
    return (i - t[0]);
  } else {
    return -1;
  }
}
//求串长
int StrLength(char* s) {
  int i = 0;
  while (s[i] != '\0') {
    i++;
  }
  return i;
}
//串赋值
void StrAssign(SString T, char* chars) {
  int i;
  if (StrLength(chars) > MAXSTRLEN) {
    for (i = 1; i <= MAXSTRLEN; ++i)
      T[i] = *(chars + i - 1);
    T[0] = MAXSTRLEN;
  } else {
    T[0] = StrLength(chars);  // 此时T[0]存入的是int类型的数据,打印%s时无法显示
    for (i = 1; i <= MAXSTRLEN; ++i)
      T[i] = *(chars + i - 1);
  }
}

int main(int argc, char** argv) {
  SString S1, T;
  char str1[20] = "maanshanxueyuan";
  char str2[13] = "xxyxy";
  StrAssign(S1, str1);
  StrAssign(T, str2);
  /*
  int bf = Strindex_bf(S1, T);
    printf("bf匹配%d\n", bf);
  */

  int kmp = Strindex_kmp(S1, T);
  printf("kmp匹配%d\n", kmp);
  system("pause");
  return 0;
}
