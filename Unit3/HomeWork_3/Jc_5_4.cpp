#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DataType int
typedef struct node {
  DataType data;
  struct node* next;
} Lnode, *Quenue;

Quenue InitQuenue(Quenue rear) {
  rear = (Quenue)malloc(sizeof(Lnode));
  rear->next = rear;
  return rear;
}

//置空算法 只有尾指针
void Quenue_Empty(Quenue* rear) {
  Lnode *h, *front;
  h = (*rear)->next;
  if ((*rear) == h) {  //初始化的时候 头指针和尾指针都指向头节点！
    printf("队列为空");
    return;
  } else {
    while (h->next !=
           h) {  //这里需要注意 循环队列 不能再以h->next != NULL做条件了
      front = h->next;  // front为队尾指针
      if (front->next) {
        h->next = front->next;
      }
      free(front);
    }
    //循环结束之后只剩下了h节点存在 即为头节点
  }
}
//入队算法
void Quenue_In(Quenue* rear, DataType x) {  //!!!注意参数需要是 Quenue* rear
  Lnode* tmp;
  tmp = (Lnode*)malloc(sizeof(Lnode));  //初始化
  tmp->data = x;
  //入队 队尾指针发生变化
  tmp->next = (*rear)->next;
  (*rear)->next = tmp;
  (*rear) = tmp;
}

void Quenue_Out(Quenue* rear, DataType* x) {
  Lnode *front, *h;
  if ((*rear)->next == (*rear)) {
    printf("队列为空");
    return;
  } else {
    h = (*rear)->next;
    front = h->next;  // front为队尾指针
    *x = front->data;
    if (front->next) {
      h->next = front->next;
    }
    free(front);
  }
}

//输出队列
void Printf_Quenue(Quenue rear) {
  Lnode *tmp, *h;
  h = rear->next;
  tmp = h->next;
  while (tmp != h) {
    printf("%d ", tmp->data);
    tmp = tmp->next;
  }
}

int main(int argc, char** argv) {
  Quenue rear;
  DataType e;
  rear = NULL;
  rear = InitQuenue(rear);
  for (int i = 0; i < 10; i++) {
    Quenue_In(&rear, i);
  }
  Quenue_Out(&rear, &e);
  Printf_Quenue(rear);
  system("pause");
  return 0;
}
