#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "StackFunction.h"
//�ж��ַ����Ƿ��ǻ������� 
void PredictHuiWen(char ch[10]) {
  int i,j,k=0;
  char tmp;
  PSeqStack S = Init_SeqStack();
  for (i = 0; ch[i] !='@'; i++) {
    Push_SeqStack(S, ch[i]);//��ջ
  }
  for ( j = 0; j <i; j++) {//��ջ���Ա�
    Pop_SeqStcak(S, &tmp);//����д��tmp = Pop_SeqStcak(S, &tmp); ������
    if (tmp!=ch[j]) {//���������
      printf("�ǻ�������");
      return;
    }
  }
  if (Empty_SeqStack(S)) {//�Ա��������һ����ĸ����ͬ
    printf("�ǻ�������");
  }
  Destroy_SeqStack(&S);//����������
}




int main(int argc, char** argv) {
  char ch[10] = {'c', 's', 'w', 's', 's', 'w', 'a', 'e', 'e', '@'};
  char ch1[10] = "abcddcba@";
  PredictHuiWen(ch1);

  system("pause");
  return 0;
}
