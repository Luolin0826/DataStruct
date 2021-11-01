#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "QueueFunction.h"

//����ν���������
BTree Creat_Tree() {
  char ch, ch1, ch2;
  BTree t, p, q;
  PSqeQueue Q = Init_SeqQueue();
  ch = getchar();
  if (ch != '#') {
    p = (BTree)malloc(sizeof(Bnode));
    p->data = ch;
    In_SeqQueue(Q, p);
  } else {
    return NULL;
  }
  while (!Empty_SeqQueue(Q)) {
    Out_SeqQueue(Q, &t);  //�Ӷ�����ȡ��Ԫ��
    ch1 = getchar();      //�����˳������ַ�
    if (ch1 != '#') {     //����������
      q = (BTree)malloc(sizeof(Bnode));
      q->data = ch1;
      t->lchild = q;
      In_SeqQueue(Q, q);
    } else {
      t->lchild = NULL;
    }
    ch2 = getchar();
    if (ch2 != '#') {  //����������
      q = (BTree)malloc(sizeof(Bnode));
      q->data = ch2;
      t->rchild = q;
      In_SeqQueue(Q, q);
    } else {
      t->rchild = NULL;
    }
  }
  return (p);
}

int main(int argc, char** argv) {
  BTree T= Creat_Tree();
  system("pause");
  return 0;
}
