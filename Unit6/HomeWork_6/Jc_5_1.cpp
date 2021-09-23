#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BTreeFunction.h"
//��ֵΪx�Ľ��Ϊ���ڵ㴴������
//����ʹ�õ�������������㷨
void SplitTree(BTree T, BTree* Tx, DataType x) {
  if (T) {
    if (T->lchild != NULL) {
      if (T->lchild->data == x) {
        *Tx = T->lchild;
        T->lchild = NULL;
        return;
      }
    }
    if (T->rchild != NULL) {
      if (T->rchild->data == x) {
        *Tx = T->rchild;
        T->rchild = NULL;
        return;
      }
    }
    SplitTree(T->lchild, Tx, x);
    SplitTree(T->rchild, Tx, x);
  }
}

int main(int argc, char** argv) {
  char x = 'B';
  printf("�����һ����:");
  BTree T = CreateBinTree();
  BTree Tx ;
  Tx = NULL;
  SplitTree(T, &Tx, x);
  printf("\n");
  PreOrder(T);
  printf("\n");
  PreOrder(Tx);
  system("pause");
  return 0;
}
