#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "QueueFunction.h"
#include "StackFunction.h"
#define Datatype char
#define MaxTreeNodeNum 100
//˳��洢
/*typedef struct {
  Datatype data[MaxTreeNodeNum];//���洢���±�Ϊ1�����鵥Ԫ��
  int n;//��ǰ��ȫ�������Ľڵ����
}QBTree;*/
//��ʽ�洢
// typedef char DataType;//����洢�����ַ���Ԫ��
typedef struct bnode {
  DataType data;
  struct bnode *lchild, *rchild;
} Bnode, *BTree;

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
//�������
void InOrder(BTree t) {
  if (t) {
    InOrder(t->lchild);
    Visit(t);
    InOrder(t->rchild);
  }
}
//�������
void PostOrder(BTree t) {
  if (t) {
    PostOrder(t->lchild);
    PostOrder(t->rchild);
    Visit(t);
  }
}

//�ǵݹ��㷨
//ǰ����� �� �� ��
void PerOrder_s(BTree t) {
  PSeqStack S = Init_SeqStack();  //��ʼ��һ��ջ
  BTree p = t;  //����һ������������ֹ��ԭ��Ԫ�ص�Ӱ��
  while (p || !Empyt_SeqStack(S)) {  //��ջ�д���ָ�����ָ��ǿ�ʱ
    if (p) {                         //�����p
      Push_SeqStack(S, p);           //��ַ��һ��
      Visit(p);
      p = p->lchild;
    } else {
      Pop_SeqStack(S, &p);
      p = p->rchild;
    }
  }
  Destroy_SeqStack(&S);
}
//�б���  ��  �� ��
void InOrder_s(BTree t) {
  PSeqStack S = Init_SeqStack();  //��ʼ��һ��ջ
  BTree p = t;  //����һ������������ֹ��ԭ��Ԫ�ص�Ӱ��
  while (p || !Empyt_SeqStack(S)) {  //��ջ�д���ָ�����ָ��ǿ�ʱ
    if (p) {                         //�����p
      Push_SeqStack(S, p);           //��ַ��һ��
      p = p->lchild;
    } else {
      Pop_SeqStack(S, &p);
      Visit(p);
      p = p->rchild;
    }
  }
  Destroy_SeqStack(&S);
}
//������� �� �� ��
//�����������������������ÿ�η��ʵ��Ľ�㲻��ֱ����������Ǳ��浽��һ��ջ��
void PostOrder_s(BTree t) {
  PSeqStack S1 = Init_SeqStack();  //��ʼ��һ��ջ
  PSeqStack S2 = Init_SeqStack();  //��ʼ��һ��ջ
  BTree p = t;  //����һ������������ֹ��ԭ��Ԫ�ص�Ӱ��
  while (p || !Empyt_SeqStack(S2)) {  //��ջ�д���ָ�����ָ��ǿ�ʱ
    if (p) {                          //�����p
      Push_SeqStack(S1, p);           //��ַ��һ��
      Push_SeqStack(S2, p);
      p = p->rchild;
    } else {
      Pop_SeqStack(S2, &p);
      p = p->lchild;
    }
  }
  while (!Empyt_SeqStack(S1)) {
    //��ջ�еĽ�����γ�ջ����Ǻ�������Ľ��
    Pop_SeqStack(S1, &p);
    Visit(p);
  }
  Destroy_SeqStack(&S1);
  Destroy_SeqStack(&S2);
}
//��α���
void LevelOrder(BTree t) {
  BTree p = t;
  PSqeQueue Q = Init_SeqQueue();
  if (p) {
    In_SeqQueue(Q, p);  //���ʸ��ڵ㣬�����ڵ����
    while (!Empty_SeqQueue(Q)) {//�����в�Ϊ��
      Out_SeqQueue(Q, &p);  //����
      if (p->lchild) {      //��ڵ�
        In_SeqQueue(Q, p->lchild);
      }
      if (p->rchild) {//�ҽڵ�
        In_SeqQueue(Q, p->rchild);
      }
    }
  }
}

//�������
int TreeDepth(BTree T) {
  if (T == NULL) {
    return 0;
  } else {
    int l = TreeDepth(T->lchild);
    int r = TreeDepth(T->rchild);
    return l > r ? l + 1 : r + 1;
  }
}

int main(int argc, char** argv) {
  system("pause");
  return 0;
}
