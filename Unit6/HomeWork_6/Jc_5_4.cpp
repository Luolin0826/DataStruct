#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BTreeFunction.h"
#include "QueueFunction.h"
//层次遍历
void LeaveOrder(BTree T) {
  BTree p = T;
  PSqeQueue Q = Init_SeqQueue();
  //利用队列的先进先出特性
  In_SeqQueue(Q, p);
  while (!Empty_SeqQueue(Q)) {//这里需要注意下
    Out_SeqQueue(Q, &p);
    printf("%c", p->data);
    if (p->lchild!=NULL) {
      In_SeqQueue(Q, p->lchild);
    }
    if (p->rchild!=NULL) {
      In_SeqQueue(Q,p->rchild);
    }
  }
  Destroy_SeqQueue(&Q);
}

int main(int argc, char** argv) {
  BTree T = CreateBinTree();
  LeaveOrder(T);
  system("pause");
  return 0;
}
