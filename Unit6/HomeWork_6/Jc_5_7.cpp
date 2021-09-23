#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BTreeFunction.h"
#include "StackFunction.h"
//建立后续线索二叉树
typedef enum { Link, Thread } PointerTag;
typedef struct ThreadNode {
  DataType data;
  struct ThreadNode *lchild, *rchild;
  PointerTag ltag, rtag;
} ThreadNode, ThreadTree;

int main(int argc, char** argv) {
  system("pause");
  return 0;
}
