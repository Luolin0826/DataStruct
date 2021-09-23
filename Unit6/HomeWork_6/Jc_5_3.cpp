#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StackFunction.h"
#define Datatype int
#define MaxTreeNodeNum 100
//顺序存储
typedef struct {
  Datatype data[MaxTreeNodeNum];  //根存储在下标为1的数组单元中
  int n;                          //当前完全二叉树的节点个数
} QBTree;
void PreOrder_QBTree(QBTree T) {
  PSeqStack S = Init_SeqStack();  //初始化栈
  int i = 1;
  while (i <= T.n || !Empyt_SeqStack(S)) {
    if (i <= T.n) {
      printf("%d", T.data[i]);
      Push_SeqStack(S, i);  //将i保存在栈中
      i = i * 2;            //取左孩子
    } else {
      Pop_SeqStack(S, &i);
      i = i * 2 + 1;  //取右孩子
    }
  }
}

int main(int argc, char** argv) {
  system("pause");
  return 0;
}
