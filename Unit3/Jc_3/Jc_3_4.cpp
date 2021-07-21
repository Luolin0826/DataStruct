#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define DataType char
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
//��������ȼ�
int priority(char op) {
  switch (op) {
    case '#':
      return (1);
    case '-':
    case '+':
      return (3);
    case '*':
    case '/':
      return (4);
    case '(':
      return (5);
    default:
      return (0);
      break;
  }
}

//����ת���ñ��ʽ
int infix_exp_value(char* infixexp, char* postfixexp) {
  PSeqStakck_c S = Init_SeqStack_c();//��ʼ��һ��ջ
  char c, w, TopElement;//c���ڴ洢ջ��ȡ����ֵ��w���ڴ�����ñ��ʽ
  Push_SeqStack_c(S, '#');//����ջ�з�һ��#���Ա�����ֹ�綨
  w = *infixexp;//�洢���ñ��ʽ
  while ((GetTop_SeqStack_c(S, &c), c) != '#' || w !='#') {//ջ��Ԫ�ز���#��w�е�Ԫ�ز���#
    if (IsNum(w)) {//���������������������׺���ʽ
      *postfixexp = w;
      postfixexp++;
      w = *(++infixexp);
    } else {
      if ((GetTop_SeqStack_c(S, &c), c) == '(' && w ==')') {//�������޷���������������һ�� ȥ������
        Pop_SeqStcak_c(S, &TopElement);
        w = *(++infixexp);
      } else {
        if ((GetTop_SeqStack_c(S, &c), c) == '('||priority((GetTop_SeqStack_c(S, &c), c))<priority(w) ) {//ջ��Ԫ��Ϊ������ջ�ڷ������ȼ�С�ڵ�ǰ��������ȼ� ��ջ
          Push_SeqStack_c(S, w);
          w = *(++infixexp);
        } else {
          Pop_SeqStcak_c(S, &TopElement);//ջ�з������ȼ����ڵ��ڵ�ǰ��������ȼ� ��ջ �ӵ���׺���ʽ
          *postfixexp = TopElement;
          postfixexp++;
        }
      }
    }
  }
  *postfixexp = '#';
  *(++postfixexp) = '\0';//��ĩβ�����ϱ�ʶ��
  Destroy_SeqStack_c(&S);
  return (1);
}

int main(int argc, char** argv) {
  system("pause");
  return 0;
}
