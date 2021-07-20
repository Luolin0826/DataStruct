#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MaxSize 10
#define  DataType int
typedef struct {
  DataType data[MaxSize];//����һ������ռ�
  int top;//ָ��ջ�����±�-1
}SeqStack,*PSeqStakck;

//��ʼ��ջ��
PSeqStakck Init_SeqStack(void) {
  PSeqStakck S;//����һ��ָ��˳��ջ��ָ��
  S = (SeqStack*)malloc(MaxSize * sizeof(SeqStack));//����ռ�
  if (S) {
    S->top = -1;//��ʼջ��ָ��-1
  }
  return S;//����ָ���ַ
}
//��ջ�� 1��ʾ�� 0 ��ʾ�ǿ�
int Empyt_SeqStack(PSeqStakck S) {
  if (S->top==-1) {
    return 1;
  } else {
    return 0;
  }
}
//��ջ x�洢�����ֵ
int Push_SeqStack(PSeqStakck S, DataType x) {
  if (S->top==MaxSize-1) {
    return 0;
  } else {
    S->data[++S->top] = x;
    return 1;
  }
}
//��ջ x�洢ɾ����ֵ ��ΪҪ��ֵ��ȥ���������ó�ָ����ʽ
int Pop_SeqStcak(PSeqStakck S, DataType *x) {
  if (Empyt_SeqStack(S)) {
    return 0;
  } else {
    *x = S->data[S->top];//��ΪҪ��ֵ��ȥ
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
//����ջ ����Ҫ�޸�ջ��ָ�����������Ҫ��ָ���ַ���������������ͷţ����˳��ջָ�븳0
void Destroy_SeqStack(PSeqStakck *S) {
  if (*S) {
    free(*S);
  } else {
    *S = NULL;
  }
}
//��ӡ���ջ
void Printf_SeqStack(PSeqStakck S) {
  int tmp;
  for (int i = 0; i <= S->top ; i++) {
    tmp = S->data[i];
    printf("%d\t", tmp);
  }
}

int main(int argc, char** argv) {
  PSeqStakck S;
  DataType tmp;
  S = Init_SeqStack();
  for (int i = 0; i < 10; i++) {
    Push_SeqStack(S, i);
  }
  printf("��ʼջ��");
  Printf_SeqStack(S);
  printf("\n");

  printf("ȡջ��ָ�룺");
  GetTop_SeqStack(S,&tmp);
  printf("%d",tmp);
  printf("\n");

  printf("��ջ��");
  Pop_SeqStcak(S,&tmp);
  Printf_SeqStack(S);
  printf("\n");

  printf("��ջ��");
  Push_SeqStack(S, 5);
  Printf_SeqStack(S);
  printf("\n");
  system("pause");
  return 0;
}
