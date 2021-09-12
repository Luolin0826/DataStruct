#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BTreeFunction.h"
#include "StackFunction.h"
//打印值为x的节点的所有祖先
//利用树的非递归后序遍历 当遍历到值为x的结点时，栈中剩余的元素就是
void PostSearchX(BTree T, char x) {
  PSeqStack S = Init_SeqStack();
  ElementType Sq;//为了在栈中存储而创建的
  Bnode* p = T;
  while (p || !Empyt_SeqStack(S)) {
    if (p) {
      Sq.flag = 0;
      Sq.node = p;
      Push_SeqStack(S, Sq);  //将p指针以及flag压入栈中
      p = p->lchild;
    } else {
      Pop_SeqStack(S, &Sq);
      p = Sq.node;
      if (Sq.flag == 0) {
        Sq.flag = 1;
        Push_SeqStack(S, Sq);  //再次进栈
        p = p->rchild;
      } else {
        if (p->data == x) {  //找到了
          break;
        }
        p = NULL;  //把p赋值为空表示当前节点处理完毕需要从栈中弹出下个节点
      }
    }
  }  // end while
  if (Empyt_SeqStack(S)) {
    printf("空结点或x为根节点或树中没有x");
    return;
  }
  while (!Empyt_SeqStack(S)) {
    Pop_SeqStack(S, &Sq);
    printf("%c ", Sq.node->data);
  }
  Destroy_SeqStack(&S);
}

int main(int argc, char** argv) {
  char x = 'F';
  printf("输入第一棵树:");
  BTree T = CreateBinTree();
  PostSearchX(T, x);
  system("pause");
  return 0;
}
