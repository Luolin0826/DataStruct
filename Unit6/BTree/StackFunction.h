#pragma once
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define MaxSize 20
#define DataType Bnode
typedef struct {
  DataType data[MaxSize];  //����һ������ռ�
  int top;                 //ָ��ջ�����±�-1
} SeqStack, *PSeqStack;

//��ʼ��ջ��
PSeqStack Init_SeqStack(void) {
  PSeqStack S;  //����һ��ָ��˳��ջ��ָ��
  S = (SeqStack*)malloc(MaxSize * sizeof(SeqStack));  //����ռ�
  if (S) {
    S->top = -1;  //��ʼջ��ָ��-1
  }
  return S;  //����ָ���ַ
}
//��ջ�� 1��ʾ�� 0 ��ʾ�ǿ�
int Empyt_SeqStack(PSeqStack S) {
  if (S->top == -1) {
    return 1;
  } else {
    return 0;
  }
}
//��ջ x�洢�����ֵ
int Push_SeqStack(PSeqStack S, DataType x) {
  if (S->top == MaxSize - 1) {
    return 0;
  } else {
    S->data[++S->top] = x;
    return 1;
  }
}
//��ջ x�洢ɾ����ֵ ��ΪҪ��ֵ��ȥ���������ó�ָ����ʽ
int Pop_SeqStack(PSeqStack S, DataType* x) {
  if (Empyt_SeqStack(S)) {
    return 0;
  } else {
    *x = S->data[S->top];  //��ΪҪ��ֵ��ȥ
    S->top--;
    return 1;
  }
}
//ȡջ��ָ��
int GetTop_SeqStack(PSeqStack S, DataType* x) {
  if (Empyt_SeqStack(S)) {
    return 0;
  } else {
    *x = S->data[S->top];  //��ΪҪ��ֵ��ȥ
    return 1;
  }
}
//����ջ
//����Ҫ�޸�ջ��ָ�����������Ҫ��ָ���ַ���������������ͷţ����˳��ջָ�븳0
void Destroy_SeqStack(PSeqStack* S) {
  if (*S) {
    free(*S);
  } else {
    *S = NULL;
  }
}
//��ӡ���ջ
void Printf_SeqStack(PSeqStack S) {
  int tmp;
  for (int i = 0; i <= S->top; i++) {
    tmp = S->data[i];
    printf("%d\t", tmp);
  }
}