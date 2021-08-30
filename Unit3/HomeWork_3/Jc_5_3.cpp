#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StackFunction.h"

int IsNum(char s) {
  if ('0' <= s && s <= '9') {  //或和且的关系搞反了 不应该！
    return 1;
  } else {
    return 0;
  }
}

void GetResult_BoLan(char* str) {
  double pre, hind, result = 0;  //数据类型,result的初始化要注意
  char ch;
  int i = 0;
  if (!str) {
    printf("字符串不存在 ");
    return;
  } else {
    PSeqStack S = Init_SeqStack();
    while (str[i] != '$') {
      ch = str[i];
      if (IsNum(ch)) {
        Push_SeqStack(S, ch - '0');  //这里 字符串进栈转化成double格式
      } else {
        Pop_SeqStcak(S, &hind);  //先出栈的是后面的
        Pop_SeqStcak(S, &pre);   //后出栈的在前面
        switch (ch) {
          case '+':
            result = pre + hind;  //注意这两个的操作顺序！！！
            break;
          case '-':
            result = pre - hind;
            break;
          case '*':
            result = pre * hind;
            break;
          case '/':
            result = pre / hind;
            break;
          default:
            printf("数据表达错误");
            break;
        }
        Push_SeqStack(S, result);
      }
      i++;
    }
    GetTop_SeqStack(S, &result);
    Destroy_SeqStack(&S);
    printf("%f", result);
  }
}

int main(int argc, char** argv) {
  char ch[10] = {'1', '4', '+', '3', '*', '5', '6', '/', '+', '$'};
  GetResult_BoLan(ch);
  system("pause");
  return 0;
}
