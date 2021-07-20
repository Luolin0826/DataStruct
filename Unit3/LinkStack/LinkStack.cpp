#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DataType int
//����ջ�Ľ��
typedef struct node {
  DataType data;
  struct node* next;
} StackNode, *PStackNode;

//����һ��ջ
typedef struct {
  PStackNode top;
} linkStack, *PlinkStack;

//ջ�ĳ�ʼ��
PlinkStack Init_LinkStack(void) {
  PlinkStack S;
  S = (linkStack*)malloc(sizeof(linkStack));  //ע��������linkStack
  if (S) {
    S->top = NULL;
  }
  return S;
}

//��ջ��
int Empty_LinkStack(PlinkStack S) {
  return (S->top == NULL);
}

//��ջ
int Push_LinkStack(PlinkStack S, DataType x) {
  PStackNode p;  //ע�� ���ﴴ������һ�����
  p = (PStackNode)malloc(sizeof(StackNode));
  if (!p) {
    printf("�ڴ������");
    return (0);  // Return0��ʾ���������˳���Return��0����ʾ�����쳣�˳�
  }
  p->data = x;
  p->next = S->top;
  S->top = p;//���������
  return (1);
}

//��ջ����
int Pop_LinkStack(PlinkStack S, DataType& x) {
  StackNode* p;
  if (Empty_LinkStack(S)) {
    printf("ջ�գ�");
    return (0);
  } else {
    p = S->top;
    x = p->data;
    S->top = p->next;
    free(p);
    return (1);
  }
}

//ȡջ��Ԫ��
int GetTop_LinkStack(PlinkStack S, DataType& x) {
  StackNode* p;
  if (Empty_LinkStack(S)) {
    printf("ջ�գ�");
    return (0);
  } else {
    p = S->top;
    x = p->data;  //Ҳ����ֱ��x = S->top->data;
    return (1);
  }
}

//������ջ ��ڲ���ΪҪ���ٵ���ջָ���ַ
int Destroy_LinkStack(PlinkStack* LS) {
  PStackNode p, q;
  if (*LS) {
    p = (*LS)->top;
    while (p) {
      q = p;        // q��������
      p = p->next;  // p����ȥ������һ���ڵ�
      free(q);
    }
    free(*LS);
  }
  *LS = NULL;  //��ֹ������
  return (1);
}

//������ӡ
int Printf_LinkStack(PlinkStack S) {
  int tmp;
  StackNode* p;
  p = S->top;
  if (Empty_LinkStack(S)) {
    printf("ջ�գ�");
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
  printf("��ʼջ��");
  Printf_LinkStack(S);
  printf("\n");

  printf("ȡջ��ָ�룺");
  GetTop_LinkStack(S, tmp);
  printf("%d", tmp);
  printf("\n");

  printf("��ջ��");
  Pop_LinkStack(S, tmp);
  Printf_LinkStack(S);
  printf("\n");

  printf("��ջ��");
  Push_LinkStack(S, 5);
  Printf_LinkStack(S);
  printf("\n");
  system("pause");
  return 0;
}
