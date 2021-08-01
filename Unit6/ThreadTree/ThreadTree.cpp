#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//线索二叉树
typedef char DataType;
typedef struct Threadnode {
  DataType data;                       //数据位
  int ltag, rtag;                      //标识符
  struct Threadnode *lchild, *rchild;  //左孩子结点和右孩子结点
} Threadnode, *ThreadTree;

//显示二叉树
void Visit(ThreadTree t) {
  printf("%c\t", t->data);
}
//中序线索二叉树
// pre指向t所指的前驱节点，函数调用前pre为空
void InThread(ThreadTree t, ThreadTree pre) {
  if (t) {
    InThread(t->lchild, pre);  //中序化左子树
    if (t->lchild == NULL) {
      t->ltag = 1;
      t->lchild = pre;  //左孩子指向前驱节点 最开始指向null
    }
    if (t->rchild == NULL) {  //尾端点特殊处理
      t->rtag = 1;
    }
    if (pre && pre->rtag == 1) {  //前驱节点没有右子树的时候
      pre->rchild = t;            //为前驱节点建立后继
    }
    pre = t;                   //前驱指针和当前指针指向一致
    InThread(t->rchild, pre);  //中序化右子树
  }
}
//先序线索二叉树
// pre指向t所指的前驱节点，函数调用前pre为空
void PreThread(ThreadTree t, ThreadTree pre) {
  if (t) {
    if (t->lchild == NULL) {
      t->ltag = 1;
      t->lchild = pre;  //左孩子指向前驱节点 最开始指向null
    }
    if (t->rchild == NULL) {  //尾端点特殊处理
      t->rtag = 1;
    }
    if (pre && pre->rtag == 1) {  //前驱节点没有右子树的时候
      pre->rchild = t;            //为前驱节点建立后继
    }
    pre = t;                      //前驱指针和当前指针指向一致
    if (t->ltag == 0) {           //避免爱的魔力转圈圈
      PreThread(t->lchild, pre);  //中序化左子树
    }
    PreThread(t->rchild, pre);  //中序化右子树
  }
}
//后序线索二叉树
// pre指向t所指的前驱节点，函数调用前pre为空
void PreThread(ThreadTree t, ThreadTree pre) {
  if (t) {
    PreThread(t->lchild, pre);  //中序化左子树
    PreThread(t->rchild, pre);  //中序化右子树
    if (t->lchild == NULL) {
      t->ltag = 1;
      t->lchild = pre;  //左孩子指向前驱节点 最开始指向null
    }
    if (t->rchild == NULL) {  //尾端点特殊处理
      t->rtag = 1;
    }
    if (pre && pre->rtag == 1) {  //前驱节点没有右子树的时候
      pre->rchild = t;            //为前驱节点建立后继
    }
    pre = t;  //前驱指针和当前指针指向一致
  }
}
//中序找前驱
//当前指针的ltag==1时 前驱是左孩子
// 当前指针的ltag=0时
// 前驱是当前指针的左子树的最后一个右孩子结点
//如果左子树没有右孩子，那就是它自己
ThreadTree InPreNode(ThreadTree p) {
  ThreadTree pre;
  pre = p->lchild;//指向左孩子
  if (p->ltag == 1) {//如果标识符为1
    return pre;
  } else {
    while (pre->rtag == 0) {//pre->rtag == 0则有右孩子
      pre = pre->rchild;//一直寻找右孩子
    }
    return pre;
  }
}
//中序找后继
//当前指针的rtag==1时 后继是右孩子
// 当前指针的rtag=0时
// 后继是当前指针的右子树的最后一个左孩子结点
//如果右子树没有左孩子，那就是它自己
ThreadTree InPostNode(ThreadTree p) {
  ThreadTree pre;
  pre = p->rchild;     //指向右孩子
  if (p->rtag == 1) {  //如果标识符为1
    return pre;
  } else {
    while (pre->ltag == 0) {  // pre->ltag == 0则有左孩子
      pre = pre->lchild;      //一直寻找左孩子
    }
    return pre;
  }
}
//中序实现遍历
void InOrderTh(ThreadTree t) {
  ThreadTree p;
  if (t) {
    p = t;
    while (p->ltag==0) {//寻找最左节点
      p = p->lchild;
    }
    while (p) {//遍历
      Visit(p);//打印
      p = InPostNode(p);//寻找后续节点
    }
  }
}
//在中序线索二叉树上实现查找值为x的值
ThreadTree Search(ThreadTree t,DataType x) {
  ThreadTree p;
  if (t) {
    p = t;
    while (p->ltag == 0) {  //寻找最左节点
      p = p->lchild;
    }
    while (p&&p->data!=x) {           //遍历
      p = InPostNode(p);  //寻找后续节点
    }
    return p;
  }
}

int main(int argc, char** argv) {
  system("pause");
  return 0;
}
