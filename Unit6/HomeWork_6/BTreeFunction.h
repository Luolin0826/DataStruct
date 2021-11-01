#pragma once
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define ElemType char
typedef struct bnode {
  ElemType data;
  struct bnode *lchild, *rchild;
} Bnode, *BTree;
//������������洢�Ķ�����
//�����������й��������
BTree CreateBinTree() {
  BTree t;
  char ch = getchar();
  if (ch == '#') {
    t = NULL;
  } else {
    t = (Bnode*)malloc(sizeof(Bnode));  //����ռ�
    t->data = ch;
    t->lchild = CreateBinTree();  //�����������������
    t->rchild = CreateBinTree();  //����������
  }
  return t;  //���ظ��ڵ��Ӧ��ָ��
}
//��ʾ������
void Visit(BTree t) {
  printf("%c\t", t->data);
}
//�ݹ��㷨
//�������
void PreOrder(BTree t) {
  if (t) {
    Visit(t);             //���ʽ������
    PreOrder(t->lchild);  //����������
    PreOrder(t->rchild);  //����������
  }
}
//���Ҷ�ӽڵ�
void PreOrderPrintLeaves(BTree BT) {
  if (BT) {
    if (!BT->lchild && !BT->rchild)
      printf("%c", BT->data);
    PreOrderPrintLeaves(BT->lchild);
    PreOrderPrintLeaves(BT->rchild);
  }
}