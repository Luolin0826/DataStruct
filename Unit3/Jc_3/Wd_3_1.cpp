#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StackFunction.h"
#define DataType char
#define MaxSize 10
typedef struct {
  DataType data[MaxSize];  //����һ������ռ�
  int top;                 //ָ��ջ�����±�-1
} SeqStack_c, *PSeqStakck_c;
  //��ջ x�洢�����ֵ
int Push_SeqStack_c(PSeqStakck S, char x) {
  if (S->top == MaxSize - 1) {
    return 0;
  } else {
    S->data[++S->top] = x;
    return 1;
  }
}
//��ջ x�洢ɾ����ֵ ��ΪҪ��ֵ��ȥ���������ó�ָ����ʽ
int Pop_SeqStcak_c(PSeqStakck S, char* x) {
  if (Empyt_SeqStack(S)) {
    return 0;
  } else {
    *x = S->data[S->top];  //��ΪҪ��ֵ��ȥ
    S->top--;
    return 1;
  }
}
//����ƥ�亯�� �жϺ����еķ����Ƿ��˫�ɶ�
int bracketCheker(char str[], int length) {
  PSeqStakck S = Init_SeqStack();  //��ʼ��ջ
  for (int i = 0; i < length; i++) {
    if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
      Push_SeqStack_c(S, str[i]);  //ɨ�������� ��ջ
    } else {
      if (Empyt_SeqStack(S)) {  //ɨ��������ʱ����ǰ��ջΪ��
        printf("ƥ��ʧ�ܣ� ջ��");
        return (0);
      }
      char TopElem;
      Pop_SeqStcak_c(S, &TopElem);  //ȡ��ջ���ķ��ź���ƥ��
      if (str[i] == ')' && TopElem != '(') {
        printf("ƥ��ʧ�ܣ� ')'��ƥ��");
        return (0);
      }
      if (str[i] == ']' && TopElem != '[') {
        printf("ƥ��ʧ�ܣ� ']'��ƥ��");
        return (0);
      }
      if (str[i] == '}' && TopElem != '{') {
        printf("ƥ��ʧ�ܣ� '}'��ƥ��");
        return (0);
      }
    }
  }
  printf("ƥ��ɹ���");
  return (1);
}

int main(int argc, char** argv) {
  char str[10] = {'(', '(', '(', '}', '��', ')', '{', '}'};
  bracketCheker(str, 8);
  system("pause");
  return 0;
}
