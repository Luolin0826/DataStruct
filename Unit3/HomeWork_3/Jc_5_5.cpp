#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StackFunction.h"

int IsSingal(char ch) {
  if (ch == '(') {
    return 1;
  } else {
    return 0;
  }
}

void MatchSingal(char* Str) {
  char ch, tmp;
  PSeqStack S = Init_SeqStack();
  ch = *Str++;
  while (ch != '\0') {
    if (IsSingal(ch)) {  //右括号进栈
      Push_SeqStack(S, ch);
    } else if (ch == ')') {
      if (!Pop_SeqStcak(S, &tmp)) {//这里至关重要
        printf("匹配失败！");
        return;//直接跳出循环 否则会显示两个结果
      }
    }
    ch = *Str++;
  }
  if (!Empty_SeqStack(S)) {
    printf("匹配失败！");
  } else {
    printf("匹配成功！");
  }
}

int main(int argc, char** argv) {
  char str[MaxSize] = {"((3+2)*5))"};
  MatchSingal(str);
  system("pause");
  return 0;
}
