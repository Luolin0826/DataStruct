#pragma once
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DataType int
#define MaxSize 10
typedef struct {
  DataType data[MaxSize];  //����һ������ռ�
  int top;                 //ָ��ջ�����±�-1
} SeqStack, *PSeqStakck;

//��ʼ��ջ��
PSeqStakck Init_SeqStack(void) {
  PSeqStakck S;  //����һ��ָ��˳��ջ��ָ��
  S = (SeqStack*)malloc(MaxSize * sizeof(SeqStack));  //����ռ�
  if (S) {
    S->top = -1;  //��ʼջ��ָ��-1
  }
  return S;  //����ָ���ַ
}
//��ջ�� 1��ʾ�� 0 ��ʾ�ǿ�
int Empyt_SeqStack(PSeqStakck S) {
  if (S->top == -1) {
    return 1;
  } else {
    return 0;
  }
}
//��ջ x�洢�����ֵ
int Push_SeqStack(PSeqStakck S, DataType x) {
  if (S->top == MaxSize - 1) {
    return 0;
  } else {
    S->data[++S->top] = x;
    return 1;
  }
}
//��ջ x�洢ɾ����ֵ ��ΪҪ��ֵ��ȥ���������ó�ָ����ʽ
int Pop_SeqStcak(PSeqStakck S, DataType* x) {
  if (Empyt_SeqStack(S)) {
    return 0;
  } else {
    *x = S->data[S->top];  //��ΪҪ��ֵ��ȥ
    S->top--;
    return 1;
  }
}
//ȡջ��ָ��
int GetTop_SeqStack(PSeqStakck S, DataType* x) {
  if (Empyt_SeqStack(S)) {
    return 0;
  } else {
    *x = S->data[S->top];  //��ΪҪ��ֵ��ȥ
    return 1;
  }
}
//����ջ
//����Ҫ�޸�ջ��ָ�����������Ҫ��ָ���ַ���������������ͷţ����˳��ջָ�븳0
void Destroy_SeqStack(PSeqStakck* S) {
  if (*S) {
    free(*S);
  } else {
    *S = NULL;
  }
}
//��ӡ���ջ
void Printf_SeqStack(PSeqStakck S) {
  int tmp;
  for (int i = S->top; i >= 0; i--) {//ע�������˳��ֻ�ܴ�һ�����
    tmp = S->data[i];
    printf("%d\t", tmp);
  }
}

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
  S->top = p;  //���������
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