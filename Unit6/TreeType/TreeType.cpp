#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define DataType char
//双亲表示法
//寻找双亲比较容易 寻找子节点比较困难
#define MaxNodeNum 100
typedef struct {
  DataType data;
  int parent;
}ParentList;
typedef struct {
  ParentList elem[MaxNodeNum];
  int n;//当前节点数
}ParentTree;
//孩子表示法
struct CTNode {
  int child;//孩子节点在数组中的位置
  struct CTNode *node;//下一个孩子
};
typedef struct {
  DataType data;
  struct CTNode *firstChild;//第一个孩子
}CTBox;
typedef struct {
  CTBox nodes[MaxNodeNum];
  int n, r;//结点数和根的位置
}CTree;
//孩子兄弟表示法
typedef struct tnode {
  DataType data;
  struct tnode *firstnode,*nextnode;
}Tnode;

int main(int argc, char** argv) {
  system("pause");
  return 0;
}
