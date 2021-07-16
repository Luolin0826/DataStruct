#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MaxSize 10
#define  DataType int
typedef struct {
  DataType data[MaxSize];//申请一个数组空间
  int top;//指向栈顶的下标-1
}SeqStack,*PSeqStakck;

//初始化栈空
PSeqStakck Init_SeqStack(void) {
  PSeqStakck S;//定义一个指向顺序栈的指针
  S = (SeqStack*)malloc(MaxSize * sizeof(SeqStack));//分配空间
  if (S) {
    S->top = -1;//初始栈顶指向-1
  }
  return S;//返回指针地址
}
//判栈空 1表示空 0 表示非空
int Empyt_SeqStack(PSeqStakck S) {
  if (S->top==-1) {
    return 1;
  } else {
    return 0;
  }
}
//入栈 x存储输入的值
int Push_SeqStack(PSeqStakck S, DataType x) {
  if (S->top==MaxSize-1) {
    return 0;
  } else {
    S->data[++S->top] = x;
    return 1;
  }
}
//出栈 x存储删除的值 因为要带值回去，所以设置成指针形式
int Pop_SeqStcak(PSeqStakck S, DataType *x) {
  if (Empyt_SeqStack(S)) {
    return 0;
  } else {
    *x = S->data[S->top];//因为要带值回去
    S->top--;
    return 1;
  }
}
//取栈顶指针
int GetTop_SeqStack(PSeqStakck S, DataType* x) {
  if (Empyt_SeqStack(S)) {
    return 0;
  } else {
    *x = S->data[S->top];  //因为要带值回去
    return 1;
  }
}
//销毁栈 由于要修改栈的指针变量，所以要将指针地址传给函数，依次释放，最后讲顺序栈指针赋0
void Destroy_SeqStack(PSeqStakck *S) {
  if (*S) {
    free(*S);
  } else {
    *S = NULL;
  }
}
//打印输出栈
void Printf_SeqStack(PSeqStakck S) {
  int tmp;
  for (int i = 0; i <= S->top ; i++) {
    tmp = S->data[i];
    printf("%d\t", tmp);
  }
}

int main(int argc, char** argv) {
  PSeqStakck S;
  DataType tmp;
  S = Init_SeqStack();
  for (int i = 0; i < 10; i++) {
    Push_SeqStack(S, i);
  }
  printf("初始栈是");
  Printf_SeqStack(S);
  printf("\n");

  printf("取栈顶指针：");
  GetTop_SeqStack(S,&tmp);
  printf("%d",tmp);
  printf("\n");

  printf("出栈后：");
  Pop_SeqStcak(S,&tmp);
  Printf_SeqStack(S);
  printf("\n");

  printf("入栈后：");
  Push_SeqStack(S, 5);
  Printf_SeqStack(S);
  printf("\n");
  system("pause");
  return 0;
}
