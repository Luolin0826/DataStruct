#pragma once
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DataType int
#define MaxSize 10
typedef struct {
  DataType data[MaxSize];  //申请一个数组空间
  int top;                 //指向栈顶的下标-1
} SeqStack, *PSeqStakck;

//初始化栈空
PSeqStakck Init_SeqStack(void) {
  PSeqStakck S;  //定义一个指向顺序栈的指针
  S = (SeqStack*)malloc(MaxSize * sizeof(SeqStack));  //分配空间
  if (S) {
    S->top = -1;  //初始栈顶指向-1
  }
  return S;  //返回指针地址
}
//判栈空 1表示空 0 表示非空
int Empyt_SeqStack(PSeqStakck S) {
  if (S->top == -1) {
    return 1;
  } else {
    return 0;
  }
}
//入栈 x存储输入的值
int Push_SeqStack(PSeqStakck S, DataType x) {
  if (S->top == MaxSize - 1) {
    return 0;
  } else {
    S->data[++S->top] = x;
    return 1;
  }
}
//出栈 x存储删除的值 因为要带值回去，所以设置成指针形式
int Pop_SeqStcak(PSeqStakck S, DataType* x) {
  if (Empyt_SeqStack(S)) {
    return 0;
  } else {
    *x = S->data[S->top];  //因为要带值回去
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
//销毁栈
//由于要修改栈的指针变量，所以要将指针地址传给函数，依次释放，最后讲顺序栈指针赋0
void Destroy_SeqStack(PSeqStakck* S) {
  if (*S) {
    free(*S);
  } else {
    *S = NULL;
  }
}
//打印输出栈
void Printf_SeqStack(PSeqStakck S) {
  int tmp;
  for (int i = S->top; i >= 0; i--) {//注意输出的顺序，只能从一端输出
    tmp = S->data[i];
    printf("%d\t", tmp);
  }
}

//定义栈的结点
typedef struct node {
  DataType data;
  struct node* next;
} StackNode, *PStackNode;

//定义一个栈
typedef struct {
  PStackNode top;
} linkStack, *PlinkStack;

//栈的初始化
PlinkStack Init_LinkStack(void) {
  PlinkStack S;
  S = (linkStack*)malloc(sizeof(linkStack));  //注意这里是linkStack
  if (S) {
    S->top = NULL;
  }
  return S;
}

//判栈空
int Empty_LinkStack(PlinkStack S) {
  return (S->top == NULL);
}

//入栈
int Push_LinkStack(PlinkStack S, DataType x) {
  PStackNode p;  //注意 这里创建的是一个结点
  p = (PStackNode)malloc(sizeof(StackNode));
  if (!p) {
    printf("内存溢出！");
    return (0);  // Return0表示程序正常退出，Return（0）表示程序异常退出
  }
  p->data = x;
  p->next = S->top;
  S->top = p;  //这里出过错
  return (1);
}

//出栈操作
int Pop_LinkStack(PlinkStack S, DataType& x) {
  StackNode* p;
  if (Empty_LinkStack(S)) {
    printf("栈空！");
    return (0);
  } else {
    p = S->top;
    x = p->data;
    S->top = p->next;
    free(p);
    return (1);
  }
}

//取栈顶元素
int GetTop_LinkStack(PlinkStack S, DataType& x) {
  StackNode* p;
  if (Empty_LinkStack(S)) {
    printf("栈空！");
    return (0);
  } else {
    p = S->top;
    x = p->data;  //也可以直接x = S->top->data;
    return (1);
  }
}

//销毁链栈 入口参数为要销毁的链栈指针地址
int Destroy_LinkStack(PlinkStack* LS) {
  PStackNode p, q;
  if (*LS) {
    p = (*LS)->top;
    while (p) {
      q = p;        // q是替死鬼
      p = p->next;  // p继续去考察下一个节点
      free(q);
    }
    free(*LS);
  }
  *LS = NULL;  //防止脏数据
  return (1);
}

//遍历打印
int Printf_LinkStack(PlinkStack S) {
  int tmp;
  StackNode* p;
  p = S->top;
  if (Empty_LinkStack(S)) {
    printf("栈空！");
    return (0);
  }
  while (p) {
    tmp = p->data;
    printf("%d\t", tmp);
    p = p->next;
  }
  return (1);
}