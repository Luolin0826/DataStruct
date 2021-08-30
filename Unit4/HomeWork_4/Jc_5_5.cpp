#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//字母频度表
//判断是大写或者小写或者其他字符 如果是大写 返回ch-65 小写 返回ch-97
//其他字符返回-1
int PredictCh(char ch) {
  if ('A' <= ch && ch <= 'Z') {
    return ch - 65;
  } else if ('a' <= ch && ch <= 'z') {
    return ch - 97;
  } else {
    return -1;
  }
}
// s是被统计字符，f是频度表
void frequency(char* s) {
  int f[26] = {}, i = 0, tmp;  //注意f的初始化方式
  while (s[i] != '\0') {
    tmp = PredictCh(s[i]);
    if (tmp != -1) {
      f[tmp]++;
      i++;
    } else {
      i++;
    }
  }
}

int main(int argc, char** argv) {
  char str[60] = "vsxasgyjafasd2m34asfa45saf45a56656ns56h34a2dasdnasasvsa5";
  frequency(str);
  system("pause");
  return 0;
}
