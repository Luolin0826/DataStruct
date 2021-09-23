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
//创建二叉链表存储的二叉树
//利用先序序列构造二叉树
BTree CreateBinTree() {
  BTree t;
  char ch = getchar();
  if (ch == '#') {
    t = NULL;
  } else {
    t = (Bnode*)malloc(sizeof(Bnode));  //分配空间
    t->data = ch;
    t->lchild = CreateBinTree();  //构造二叉树的左子树
    t->rchild = CreateBinTree();  //构造右子树
  }
  return t;  //返回根节点对应的指针
}
//显示二叉树
void Visit(BTree t) {
  printf("%c\t", t->data);
}
//递归算法
//先序遍历
void PreOrder(BTree t) {
  if (t) {
    Visit(t);             //访问结点内容
    PreOrder(t->lchild);  //遍历左子树
    PreOrder(t->rchild);  //遍历右子树
  }
}
//输出叶子节点
void PreOrderPrintLeaves(BTree BT) {
  if (BT) {
    if (!BT->lchild && !BT->rchild)
      printf("%c", BT->data);
    PreOrderPrintLeaves(BT->lchild);
    PreOrderPrintLeaves(BT->rchild);
  }
}