#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StackFunction.h"
#define Datatype int
#define MaxTreeNodeNum 100
//˳��洢
typedef struct {
  Datatype data[MaxTreeNodeNum];  //���洢���±�Ϊ1�����鵥Ԫ��
  int n;                          //��ǰ��ȫ�������Ľڵ����
} QBTree;
void PreOrder_QBTree(QBTree T) {
  PSeqStack S = Init_SeqStack();  //��ʼ��ջ
  int i = 1;
  while (i <= T.n || !Empyt_SeqStack(S)) {
    if (i <= T.n) {
      printf("%d", T.data[i]);
      Push_SeqStack(S, i);  //��i������ջ��
      i = i * 2;            //ȡ����
    } else {
      Pop_SeqStack(S, &i);
      i = i * 2 + 1;  //ȡ�Һ���
    }
  }
}

int main(int argc, char** argv) {
  system("pause");
  return 0;
}
