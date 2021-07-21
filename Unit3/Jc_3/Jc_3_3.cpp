#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StackFunction.h"
#define DataType double
//��׺���ʽ��ֵ �����׺���ʽ�Ѿ����浽��һ���㹻����ַ�����A�� ������#����
#define MaxSize 10
typedef struct {
  DataType data[MaxSize];  //����һ������ռ�
  int top;                 //ָ��ջ�����±�-1
} SeqStack_c, *PSeqStakck_c;
//��ʼ��
PSeqStakck_c Init_SeqStack_c(void) {
  PSeqStakck_c S;  //����һ��ָ��˳��ջ��ָ��
  S = (SeqStack_c*)malloc(MaxSize * sizeof(SeqStack_c));  //����ռ�
  if (S) {
    S->top = -1;  //��ʼջ��ָ��-1
  }
  return S;  //����ָ���ַ
}
//��ջ�� 1��ʾ�� 0 ��ʾ�ǿ�
int Empyt_SeqStack_c(PSeqStakck_c S) {
  if (S->top == -1) {
    return 1;
  } else {
    return 0;
  }
}
//��ջ x�洢�����ֵ
int Push_SeqStack_c(PSeqStakck_c S, DataType x) {
  if (S->top == MaxSize - 1) {
    return 0;
  } else {
    S->data[++S->top] = x;
    return 1;
  }
}
//��ջ x�洢ɾ����ֵ ��ΪҪ��ֵ��ȥ���������ó�ָ����ʽ
int Pop_SeqStcak_c(PSeqStakck_c S, DataType* x) {
  if (Empyt_SeqStack_c(S)) {
    return 0;
  } else {
    *x = S->data[S->top];  //��ΪҪ��ֵ��ȥ
    S->top--;
    return 1;
  }
}
//ȡջ��ָ��
int GetTop_SeqStack_c(PSeqStakck_c S, DataType* x) {
  if (Empyt_SeqStack_c(S)) {
    return 0;
  } else {
    *x = S->data[S->top];  //��ΪҪ��ֵ��ȥ
    return 1;
  }
}
//����ջ
//����Ҫ�޸�ջ��ָ�����������Ҫ��ָ���ַ���������������ͷţ����˳��ջָ�븳0
void Destroy_SeqStack_c(PSeqStakck_c* S) {
  if (*S) {
    free(*S);
  } else {
    *S = NULL;
  }
}
//�жϺ����Ƿ��ǲ�����
int IsNum(char c) {
  if (c >= '0' && c <= '9') {
    return (1);
  } else {
    return (0);
  }
}
//�����������׺���ʽA��ʾ��������
DataType postfix_exp(char* A) {
  PSeqStakck_c S;
  DataType a, b, c, Result;
  char ch;
  ch = *A++;
  S = Init_SeqStack_c();  //��ʼ��ջ
  while (ch != '#') {
    if (IsNum(ch)) {
      Push_SeqStack_c(S, ch - '0');//ע��˴���(DataType)ch - '0' ��char����ת����int
    } else {
      Pop_SeqStcak_c(S, &b);  //��Ϊ�ȳ�ջ���Ǻ�����������Դ˴���b
      Pop_SeqStcak_c(S, &a);  //���ջ�� ���� ȡ�������������
      switch (ch) {
        case '+':
          c = a + b;
          break;
        case '-':
          c = a - b;
          break;
        case '*':
          c = a * b;
          break;
        case '/':
          c = a / b;
          break;
      }
      Push_SeqStack_c(S, c);
    }
    ch = *A++;
  }
  GetTop_SeqStack_c(S, &Result);
  Destroy_SeqStack_c(&S);
  return Result;
}

int main(int argc, char** argv) {
  // char a[] = "1285-*+42/-#";
  char ch[10] = {'1', '4', '+', '3', '*', '5', '6', '/', '+', '#'};
  DataType result = postfix_exp(ch);
  printf("%f", result);
  system("pause");
  return 0;
}
