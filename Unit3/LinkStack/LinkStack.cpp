#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DataType int
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
  S->top = p;//这里出过错
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

int main(int argc, char** argv) {
  PlinkStack S;
  DataType tmp;
  S = Init_LinkStack();
  for (int i = 0; i < 10; i++) {
    Push_LinkStack(S, i);
  }
  printf("初始栈是");
  Printf_LinkStack(S);
  printf("\n");

  printf("取栈顶指针：");
  GetTop_LinkStack(S, tmp);
  printf("%d", tmp);
  printf("\n");

  printf("出栈后：");
  Pop_LinkStack(S, tmp);
  Printf_LinkStack(S);
  printf("\n");

  printf("入栈后：");
  Push_LinkStack(S, 5);
  Printf_LinkStack(S);
  printf("\n");
  system("pause");
  return 0;
}
