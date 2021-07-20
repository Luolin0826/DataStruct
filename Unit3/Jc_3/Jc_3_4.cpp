#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define DataType char
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
//求算符优先级
int priority(char op) {
  switch (op) {
    case '#':
      return (1);
    case '-':
    case '+':
      return (3);
    case '*':
    case '/':
      return (4);
    case '(':
      return (5);
    default:
      return (0);
      break;
  }
}

//中置转后置表达式
int infix_exp_value(char* infixexp, char* postfixexp) {
  PSeqStakck_c S = Init_SeqStack_c();//初始化一个栈
  char c, w, TopElement;//c用于存储栈中取出得值，w用于存放中置表达式
  Push_SeqStack_c(S, '#');//先在栈中放一个#，以便于终止界定
  w = *infixexp;//存储中置表达式
  while ((GetTop_SeqStack_c(S, &c), c) != '#' || w !='#') {//栈顶元素不是#或w中的元素不是#
    if (IsNum(w)) {//遇到操作数，加入带到后缀表达式
      *postfixexp = w;
      postfixexp++;
      w = *(++infixexp);
    } else {
      if ((GetTop_SeqStack_c(S, &c), c) == '(' && w ==')') {//遇到界限符且两个括号连再一次 去除括号
        Pop_SeqStcak_c(S, &TopElement);
        w = *(++infixexp);
      } else {
        if ((GetTop_SeqStack_c(S, &c), c) == '('||priority((GetTop_SeqStack_c(S, &c), c))<priority(w) ) {//栈顶元素为（或者栈内符号优先级小于当前运算符优先级 入栈
          Push_SeqStack_c(S, w);
          w = *(++infixexp);
        } else {
          Pop_SeqStcak_c(S, &TopElement);//栈中符号优先级大于等于当前运算的优先级 出栈 加到后缀表达式
          *postfixexp = TopElement;
          postfixexp++;
        }
      }
    }
  }
  *postfixexp = '#';
  *(++postfixexp) = '\0';//在末尾处加上标识符
  Destroy_SeqStack_c(&S);
  return (1);
}

int main(int argc, char** argv) {
  system("pause");
  return 0;
}
