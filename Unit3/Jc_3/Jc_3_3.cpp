#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StackFunction.h"
#define DataType double
//后缀表达式求值 假设后缀表达式已经被存到了一个足够大的字符数组A中 并且以#结束
#define MaxSize 10
typedef struct {
  DataType data[MaxSize];  //申请一个数组空间
  int top;                 //指向栈顶的下标-1
} SeqStack_c, *PSeqStakck_c;
//初始化
PSeqStakck_c Init_SeqStack_c(void) {
  PSeqStakck_c S;  //定义一个指向顺序栈的指针
  S = (SeqStack_c*)malloc(MaxSize * sizeof(SeqStack_c));  //分配空间
  if (S) {
    S->top = -1;  //初始栈顶指向-1
  }
  return S;  //返回指针地址
}
//判栈空 1表示空 0 表示非空
int Empyt_SeqStack_c(PSeqStakck_c S) {
  if (S->top == -1) {
    return 1;
  } else {
    return 0;
  }
}
//入栈 x存储输入的值
int Push_SeqStack_c(PSeqStakck_c S, DataType x) {
  if (S->top == MaxSize - 1) {
    return 0;
  } else {
    S->data[++S->top] = x;
    return 1;
  }
}
//出栈 x存储删除的值 因为要带值回去，所以设置成指针形式
int Pop_SeqStcak_c(PSeqStakck_c S, DataType* x) {
  if (Empyt_SeqStack_c(S)) {
    return 0;
  } else {
    *x = S->data[S->top];  //因为要带值回去
    S->top--;
    return 1;
  }
}
//取栈顶指针
int GetTop_SeqStack_c(PSeqStakck_c S, DataType* x) {
  if (Empyt_SeqStack_c(S)) {
    return 0;
  } else {
    *x = S->data[S->top];  //因为要带值回去
    return 1;
  }
}
//销毁栈
//由于要修改栈的指针变量，所以要将指针地址传给函数，依次释放，最后讲顺序栈指针赋0
void Destroy_SeqStack_c(PSeqStakck_c* S) {
  if (*S) {
    free(*S);
  } else {
    *S = NULL;
  }
}
//判断函数是否是操作数
int IsNum(char c) {
  if (c >= '0' && c <= '9') {
    return (1);
  } else {
    return (0);
  }
}
//本函数计算后缀表达式A表示的运算结果
DataType postfix_exp(char* A) {
  PSeqStakck_c S;
  DataType a, b, c, Result;
  char ch;
  ch = *A++;
  S = Init_SeqStack_c();  //初始化栈
  while (ch != '#') {
    if (IsNum(ch)) {
      Push_SeqStack_c(S, ch - '0');//注意此处的(DataType)ch - '0' 从char类型转换成int
    } else {
      Pop_SeqStcak_c(S, &b);  //因为先出栈的是后面的数，所以此处用b
      Pop_SeqStcak_c(S, &a);  //后出栈的 至此 取出了两个运算符
      switch (ch) {
        case '+':
          c = a + b;
          break;
        case '-':
          c = a - b;
          break;
        case '*':
          c = a * b;
          break;
        case '/':
          c = a / b;
          break;
      }
      Push_SeqStack_c(S, c);
    }
    ch = *A++;
  }
  GetTop_SeqStack_c(S, &Result);
  Destroy_SeqStack_c(&S);
  return Result;
}

int main(int argc, char** argv) {
  // char a[] = "1285-*+42/-#";
  char ch[10] = {'1', '4', '+', '3', '*', '5', '6', '/', '+', '#'};
  DataType result = postfix_exp(ch);
  printf("%f", result);
  system("pause");
  return 0;
}
