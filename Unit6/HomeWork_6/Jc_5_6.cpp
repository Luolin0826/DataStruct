#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "BTreeFunction.h"

void ConveyLR(BTree T) {//Btree���Ѿ���ָ����ʽ����
  Bnode *p;//ע����*p
  if (T) {
    p = T->lchild;
    T->lchild = T->rchild;
    T->rchild = p;
    ConveyLR(T->lchild);
    ConveyLR(T->rchild);
  }
}

int main(int argc, char** argv) {
  system("pause");
  return 0;
}
