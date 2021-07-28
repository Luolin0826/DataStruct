#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define  Datatype int
typedef struct GenealNode {
  int tag;//取值0或者1
  union {
    Datatype data;
    struct {
      struct GenealNode *hp, *tp;
    }ptr;
  };
}*Glist;
 //取表头 空时返回null，否则返回表头指针
Glist GetHead(Glist p) {
  if (!p||p->tag==0) {
    printf("表为空表或者只含有一个原子");
    return (NULL);
  }
  return p->ptr.hp;//非空表，返回表头结点的头指针
}
//取表尾 空表或者单个原子 没意义 否则返回表尾指针
Glist GetTail(Glist p) {
  if (!p || p->tag == 0) {
    printf("表为空表或者只含有一个原子");
    return (NULL);
  }
  return p->ptr.tp;//返回表尾指针
}
//计算深度
int depth(Glist ls) {
  int max=0;
  Glist tmp = ls;
  if (tmp==NULL) {//空表
    return 1;
  }
  if (tmp->tag==0) {//只有一个原子
    return 0;
  }
  while (tmp!=NULL) {
    int dep = depth(tmp->ptr.hp);//求ai的深度
    if (dep>max) {
      max = dep;
    }
    tmp = tmp->ptr.tp;//到下一个指针
  }
  return max + 1;//要加上最外面的括号
}

int main(int argc, char** argv) {
  system("pause");
  return 0;
}
