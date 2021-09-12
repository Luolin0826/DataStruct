#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GListFunction.h"

//复制一个广义表
Glist GlistCopy(Glist L) {
  Glist p;
  if (L == NULL) {  //设置出口
    return NULL;
  }
  p = (Glist)malloc(sizeof(Glist));//申请空间
  p->tag = L->tag;
  if (p->tag == 0) {  //如果含有的是单个原子
    p->data = L->data;
  } else {
    p->ptr.hp = GlistCopy(L->ptr.hp);  //循环复制
    p->ptr.tp = GlistCopy(L->ptr.tp);  //复制广义表
  }
  return p;
}

int main(int argc, char** argv) {
  system("pause");
  return 0;
}
