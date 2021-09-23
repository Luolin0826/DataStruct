#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "QueueFunction.h"

//按层次建立二叉树
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
    Out_SeqQueue(Q, &t);  //从队列中取出元素
    ch1 = getchar();      //按层次顺序读入字符
    if (ch1 != '#') {     //建立左子树
      q = (BTree)malloc(sizeof(Bnode));
      q->data = ch1;
      t->lchild = q;
      In_SeqQueue(Q, q);
    } else {
      t->lchild = NULL;
    }
    ch2 = getchar();
    if (ch2 != '#') {  //建立右子树
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
