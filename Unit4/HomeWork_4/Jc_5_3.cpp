#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//判断是否是数字
int IsNum(char c) {  //注意没有星号
  if ('0' <= c && c <= '9') {
    return 1;
  } else {
    return 0;
  }
}
int CountInt(char* s, int a[]) {
  int i = 0, j = 0;
  while (s[j] != '\0') {
    if (IsNum(s[j])) {  //是数字 将后续遇到的数字拼接起来
      int num = 0;      //初始化
      while (IsNum(s[j])) {
        num = num * 10 + s[j] - '0';
        j++;
      }
      a[i++] = num;
    } else {
      j++;
    }
  }
  for (int m = 0; m < i; m++) {  //输出
    printf("第%d个数是%d\n", m + 1, a[m]);
  }
  return i;  //数量
}

int main(int argc, char** argv) {
  char str[40] = "12m34a4545a56656ns56h34a235n645";
  int a[10];
  int result = CountInt(str, a);
  system("pause");
  return 0;
}
