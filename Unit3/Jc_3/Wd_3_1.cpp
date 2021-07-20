#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StackFunction.h"
#define DataType char
#define MaxSize 10
typedef struct {
  DataType data[MaxSize];  //申请一个数组空间
  int top;                 //指向栈顶的下标-1
} SeqStack_c, *PSeqStakck_c;
  //入栈 x存储输入的值
int Push_SeqStack_c(PSeqStakck S, char x) {
  if (S->top == MaxSize - 1) {
    return 0;
  } else {
    S->data[++S->top] = x;
    return 1;
  }
}
//出栈 x存储删除的值 因为要带值回去，所以设置成指针形式
int Pop_SeqStcak_c(PSeqStakck S, char* x) {
  if (Empyt_SeqStack(S)) {
    return 0;
  } else {
    *x = S->data[S->top];  //因为要带值回去
    S->top--;
    return 1;
  }
}
//符号匹配函数 判断函数中的符号是否成双成对
int bracketCheker(char str[], int length) {
  PSeqStakck S = Init_SeqStack();  //初始化栈
  for (int i = 0; i < length; i++) {
    if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
      Push_SeqStack_c(S, str[i]);  //扫描左括号 入栈
    } else {
      if (Empyt_SeqStack(S)) {  //扫描右括号时，当前的栈为空
        printf("匹配失败！ 栈空");
        return (0);
      }
      char TopElem;
      Pop_SeqStcak_c(S, &TopElem);  //取出栈顶的符号和它匹配
      if (str[i] == ')' && TopElem != '(') {
        printf("匹配失败！ ')'不匹配");
        return (0);
      }
      if (str[i] == ']' && TopElem != '[') {
        printf("匹配失败！ ']'不匹配");
        return (0);
      }
      if (str[i] == '}' && TopElem != '{') {
        printf("匹配失败！ '}'不匹配");
        return (0);
      }
    }
  }
  printf("匹配成功！");
  return (1);
}

int main(int argc, char** argv) {
  char str[10] = {'(', '(', '(', '}', '（', ')', '{', '}'};
  bracketCheker(str, 8);
  system("pause");
  return 0;
}
