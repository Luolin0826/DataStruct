#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DataType int
//�������ݽṹ
typedef struct node {
  DataType data;
  struct node* next;
} Qnode, *PQNode;
typedef struct {
  PQNode front, rear;  //��������ָ��
} LinkQueue, *PLinkQueue;

//��ʼ��
PLinkQueue Init_LinkQueue(void) {
  PLinkQueue Q;
  Q = (PLinkQueue)malloc(sizeof(LinkQueue));
  if (Q) {
    Q->front = NULL;
    Q->rear = NULL;
  }
  return Q;
}
//�жϿ�
int Empty_LinkQueue(PLinkQueue Q) {
  if (Q && Q->front == NULL) {
    return 1;
  } else {
    return 0;
  }
}
//���
int In_LinkQueue(PLinkQueue Q, DataType x) {
  PQNode p;
  p = (PQNode)malloc(sizeof(Qnode));
  if (!p) {
    printf("�ڴ������");
    return (0);
  }
  p->data = x;
  p->next = NULL;
  if (Empty_LinkQueue(Q)) {
    Q->rear = Q->front = p;  //��һ��Ԫ�ص����⴦��
  } else {
    Q->rear->next = p;  //��������һ��Ԫ�غͱ�Ԫ�ص���ϵ
    Q->rear = p;        //ָ��ǰԪ�� Ϊ��һ�β�����׼��
  }
  return (1);
}
//����
int Out_LinkQueue(PLinkQueue Q, DataType* x) {
  if (Empty_LinkQueue(Q)) {
    printf("�ӿ�");
    return (0);
  } else {
    PQNode p = Q->front;
    *x = p->data;
    Q->front = p->next;
    if (Q->rear == p) {           //ɾ�����Ƕ�β��Ԫ��
      Q->rear = Q->front = NULL;  //�ÿ�
    }
    free(p);
  }
  return (1);
}
//ȡ��ͷԪ��
int Front_LinkQueue(PLinkQueue Q, DataType* x) {
  if (Empty_LinkQueue(Q)) {
    printf("�ӿ�");
    return (0);
  } else {
    PQNode p = Q->front;
    *x = p->data;
  }
  return (1);
}
//����
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

//������ӡ  �����ǶԵ� ������һ���ڵ���Ϊ�˲�Ӱ��ԭ���Ľڵ�
int Printf_LinkQueue(PLinkQueue Q) {
  if (Empty_LinkQueue(Q)) {
    printf("�ӿ�");
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
  printf("��ȡ��һ��");
  Out_LinkQueue(Q, &x);
  Printf_LinkQueue(Q);
  system("pause");
  return 0;
}
