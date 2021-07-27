#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DataType int
//定义数据结构
typedef struct node {
  DataType data;
  struct node* next;
} Qnode, *PQNode;
typedef struct {
  PQNode front, rear;  //定义两个指针
} LinkQueue, *PLinkQueue;

//初始化
PLinkQueue Init_LinkQueue(void) {
  PLinkQueue Q;
  Q = (PLinkQueue)malloc(sizeof(LinkQueue));
  if (Q) {
    Q->front = NULL;
    Q->rear = NULL;
  }
  return Q;
}
//判断空
int Empty_LinkQueue(PLinkQueue Q) {
  if (Q && Q->front == NULL) {
    return 1;
  } else {
    return 0;
  }
}
//入队
int In_LinkQueue(PLinkQueue Q, DataType x) {
  PQNode p;
  p = (PQNode)malloc(sizeof(Qnode));
  if (!p) {
    printf("内存溢出！");
    return (0);
  }
  p->data = x;
  p->next = NULL;
  if (Empty_LinkQueue(Q)) {
    Q->rear = Q->front = p;  //第一个元素的特殊处理
  } else {
    Q->rear->next = p;  //建立起上一个元素和本元素的联系
    Q->rear = p;        //指向当前元素 为下一次插入坐准备
  }
  return (1);
}
//出队
int Out_LinkQueue(PLinkQueue Q, DataType* x) {
  if (Empty_LinkQueue(Q)) {
    printf("队空");
    return (0);
  } else {
    PQNode p = Q->front;
    *x = p->data;
    Q->front = p->next;
    if (Q->rear == p) {           //删除的是队尾的元素
      Q->rear = Q->front = NULL;  //置空
    }
    free(p);
  }
  return (1);
}
//取队头元素
int Front_LinkQueue(PLinkQueue Q, DataType* x) {
  if (Empty_LinkQueue(Q)) {
    printf("队空");
    return (0);
  } else {
    PQNode p = Q->front;
    *x = p->data;
  }
  return (1);
}
//销毁
void Destroy_LinkQueue(PLinkQueue Q) {
  PQNode p, s;
  if (Q) {
    while (Q->front) {
      p = Q->front;
      Q->front = Q->front->next;
      free(p);
    }
    free(Q);
  }
  Q = NULL;
}

//遍历打印  猜想是对的 建立另一个节点是为了不影响原本的节点
int Printf_LinkQueue(PLinkQueue Q) {
  if (Empty_LinkQueue(Q)) {
    printf("队空");
    return (0);
  } else {
    PQNode p = Q->front;
    while (p != NULL) {
      int tmp;
      tmp = p->data;
      printf("%d ", tmp);
      p = p->next;
    }
  }
}

int main(int argc, char** argv) {
  DataType x;
  PLinkQueue Q = Init_LinkQueue();
  for (int i = 0; i < 10; i++) {
    In_LinkQueue(Q, i);
  }
  Out_LinkQueue(Q, &x);
  Printf_LinkQueue(Q);
  printf("再取出一次");
  Out_LinkQueue(Q, &x);
  Printf_LinkQueue(Q);
  system("pause");
  return 0;
}
