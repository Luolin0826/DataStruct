#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "QueueFunction.h"
#include "StackFunction.h"
#define Datatype char
#define MaxTreeNodeNum 100
//顺序存储
/*typedef struct {
  Datatype data[MaxTreeNodeNum];//根存储在下标为1的数组单元中
  int n;//当前完全二叉树的节点个数
}QBTree;*/
//链式存储
// typedef char DataType;//假设存储的是字符型元素
typedef struct bnode {
  DataType data;
  struct bnode *lchild, *rchild;
} Bnode, *BTree;

//显示二叉树
void Visit(BTree t) {
  printf("%c\t",t->data);
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
//中序遍历
void InOrder(BTree t) {
  if (t) {
    InOrder(t->lchild);
    Visit(t);
    InOrder(t->rchild);
  }
}
//后序遍历
void PostOrder(BTree t) {
  if (t) {
    PostOrder(t->lchild);
    PostOrder(t->rchild);
    Visit(t);
  }
}
/*
//非递归算法
//前序遍历 中 左 右
void PerOrder_s(BTree t) {
  PSeqStack S = Init_SeqStack();  //初始化一个栈
  BTree p = t;  //定义一个备份量，防止对原本元素的影响
  while (p || !Empyt_SeqStack(S)) {  //当栈中存在指针或者指针非空时
    if (p) {                         //如果有p
      Push_SeqStack(S, p);           //地址存一下
      Visit(p);
      p = p->lchild;
    } else {
      Pop_SeqStack(S, &p);
      p = p->rchild;
    }
  }
  Destroy_SeqStack(&S);
}
//中遍历  左  中 右
void InOrder_s(BTree t) {
  PSeqStack S = Init_SeqStack();  //初始化一个栈
  BTree p = t;  //定义一个备份量，防止对原本元素的影响
  while (p || !Empyt_SeqStack(S)) {  //当栈中存在指针或者指针非空时
    if (p) {                         //如果有p
      Push_SeqStack(S, p);           //地址存一下
      p = p->lchild;
    } else {
      Pop_SeqStack(S, &p);
      Visit(p);
      p = p->rchild;
    }
  }
  Destroy_SeqStack(&S);
}
//后序遍历 左 右 中
//自右向左先序遍历二叉树，每次访问到的结点不是直接输出，而是保存到另一个栈中
void PostOrder_s(BTree t) {
  PSeqStack S1 = Init_SeqStack();  //初始化一个栈
  PSeqStack S2 = Init_SeqStack();  //初始化一个栈
  BTree p = t;  //定义一个备份量，防止对原本元素的影响
  while (p || !Empyt_SeqStack(S2)) {  //当栈中存在指针或者指针非空时
    if (p) {                          //如果有p
      Push_SeqStack(S1, p);           //地址存一下
      Push_SeqStack(S2, p);
      p = p->rchild;
    } else {
      Pop_SeqStack(S2, &p);
      p = p->lchild;
    }
  }
  while (!Empyt_SeqStack(S1)) {
    //将栈中的结果依次出栈后就是后序遍历的结果
    Pop_SeqStack(S1, &p);
    Visit(p);
  }
  Destroy_SeqStack(&S1);
  Destroy_SeqStack(&S2);
}
//层次遍历
void LevelOrder(BTree t) {
  BTree p = t;
  PSqeQueue Q = Init_SeqQueue();
  if (p) {
    In_SeqQueue(Q, p);  //访问根节点，并将节点存入
    while (!Empty_SeqQueue(Q)) {//队列中不为空
      Out_SeqQueue(Q, &p);  //出队
      if (p->lchild) {      //左节点
        In_SeqQueue(Q, p->lchild);
      }
      if (p->rchild) {//右节点
        In_SeqQueue(Q, p->rchild);
      }
    }
  }
}
*/


//计算深度
int TreeDepth(BTree T) {
  if (T == NULL) {
    return 0;
  } else {
    int l = TreeDepth(T->lchild);
    int r = TreeDepth(T->rchild);
    return l > r ? l + 1 : r + 1;
  }
}
//计算二叉树节点个数 
//方法一 采用前序遍历 存储在全局变量count中
int count = 0;
void Count_Tree(BTree t) {
  if (t) {
    Count_Tree(t->lchild);
    Visit(t);
    count++;
    Count_Tree(t->rchild);
  }
}
//方法二 分别计算 然后返回
int Count(BTree t) {
  int lcount, rcount;
  if (t==NULL) {
    return 0;
  }
  lcount = Count(t->lchild);
  rcount = Count(t->rchild);
  return lcount + rcount + 1;
}
//二叉树复制
//分别复制树的根节点，左子树，右子树 最后合到一起
BTree CopyTree(BTree t) {
  if (t==NULL) {
    return (NULL);
  } 
    BTree p, q, s;
    p = CopyTree(t->lchild);//p存储左子树
    q = CopyTree(t->rchild);//q存右子树
    s = (Bnode *)malloc(sizeof(Bnode));//给s开辟新空间
    s->data = t->data;
    s->lchild = p;
    s->rchild = q;
    return s;
}
//创建二叉链表存储的二叉树
//利用先序序列构造二叉树
BTree CreateBinTree() {
  BTree t;
  char ch = getchar();
  if (ch =='#') {
    t = NULL;
  } else {
    t = (Bnode*)malloc(sizeof(Bnode));//分配空间
    t->data = ch;
    t->lchild = CreateBinTree();//构造二叉树的左子树
    t->rchild = CreateBinTree();//构造右子树
  }
  return t;//返回根节点对应的指针
}
//求二叉树每层的节点个数
//利用数组进行存储，数组的下标代表层数，存储的值代表那一层的节点数
void LevCount(BTree t, int l, int num[]) {
  if (t) {
    Visit(t);
    num[l]++;
    LevCount(t->lchild, l + 1, num);//求下一层的节点数
    LevCount(t->rchild, l + 1, num);
  }
}

int main(int argc, char** argv) {
  BTree t = CreateBinTree();
  Visit(t);
  system("pause");
  return 0;
}
