#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "QueueFunction.h"

//��ӡ������� n��ʾ��ӡ������
int YangHui(int n) {
  int s = 0, i;
  PSqeQueue Q = Init_SeqQueue();  //��ʼ��һ��ջ
  In_SeqQueue(Q, 1);              //�����һ�е�Ԫ��
  In_SeqQueue(Q, 1);
  for (i = 1; i <= n; i++) {//ע���Ǵ�1��ʼ��
    printf("\n");
    for (int k = 0; k < 40-4*i; k+=2) {//λ�ÿ��� ��ס����
      printf(" ");
    }
    In_SeqQueue(Q, 0);//ÿһ�������ϸ�0
    for (int j = 1; j <= i + 2; j++) {//С�ڵ���
      int t;
      Out_SeqQueue(Q, &t);
      In_SeqQueue(Q, s + t);
      s = t;
      if (j != i + 2) {  //�������һ��Ԫ�ص�ʱ��
        printf("%4d",s);//ע��λ��
      }
    }
  }
  printf("\n");
  Destroy_SeqQueue(&Q);
  return (1);
}

int main(int argc, char** argv) {
  int n = 5;
  YangHui(n);
  system("pause");
  return 0;
}
