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

//�ÿ��㷨 ֻ��βָ��
void Quenue_Empty(Quenue* rear) {
  Lnode *h, *front;
  h = (*rear)->next;
  if ((*rear) == h) {  //��ʼ����ʱ�� ͷָ���βָ�붼ָ��ͷ�ڵ㣡
    printf("����Ϊ��");
    return;
  } else {
    while (h->next !=
           h) {  //������Ҫע�� ѭ������ ��������h->next != NULL��������
      front = h->next;  // frontΪ��βָ��
      if (front->next) {
        h->next = front->next;
      }
      free(front);
    }
    //ѭ������֮��ֻʣ����h�ڵ���� ��Ϊͷ�ڵ�
  }
}
//����㷨
void Quenue_In(Quenue* rear, DataType x) {  //!!!ע�������Ҫ�� Quenue* rear
  Lnode* tmp;
  tmp = (Lnode*)malloc(sizeof(Lnode));  //��ʼ��
  tmp->data = x;
  //��� ��βָ�뷢���仯
  tmp->next = (*rear)->next;
  (*rear)->next = tmp;
  (*rear) = tmp;
}

void Quenue_Out(Quenue* rear, DataType* x) {
  Lnode *front, *h;
  if ((*rear)->next == (*rear)) {
    printf("����Ϊ��");
    return;
  } else {
    h = (*rear)->next;
    front = h->next;  // frontΪ��βָ��
    *x = front->data;
    if (front->next) {
      h->next = front->next;
    }
    free(front);
  }
}

//�������
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
