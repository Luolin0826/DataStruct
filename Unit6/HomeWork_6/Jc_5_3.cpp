#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define Datatype char
#define MaxTreeNodeNum 100
//顺序存储
typedef struct {
  Datatype data[MaxTreeNodeNum];//根存储在下标为1的数组单元中
  int n;//当前完全二叉树的节点个数
}QBTree;





int main(int argc, char** argv) {
  system("pause");
  return 0;
}
