#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "StackFunction.h"

//数值转换 S为顺序栈的入口指针 N为输入的数 r是转换的进制
void Data_convert(PSeqStakck S, DataType N, DataType r) {
  DataType tmp=N;
  while (tmp/r!=0) {
    Push_SeqStack(S, tmp % r);//压入栈
    tmp /= r;//计算公式
  }
}

int main(int argc, char** argv) {
  PSeqStakck S;
  S = Init_SeqStack();
  Data_convert(S, 10, 2);
  Printf_SeqStack(S);
  system("pause");
  return 0;
}
