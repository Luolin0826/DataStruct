#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkListFunction.h"
//求交集
//判断相同元素，如果A中有相同元素 返回1，如果没有返回0
int PredictSame(LinkList S, Datatype x) {
  Lnode* p = S->next;
  while (p != NULL && p->data != x) {  //这里发生过错误，忽略了p=null的情况
    //同时要非常非常注意的是
    //两个条件的放置顺序不能出现错误，否则会引发内存读取异常
    //猜测可能是因为p->data != x 放在前面 当p=null时会继续执行
    p = p->next;
  }
  if (p) {
    return 1;
  } else {
    return 0;
  }
}

//正式运算
void JiaoJi(LinkList L, LinkList S) {
  LinkList p, q, pre;
  p = L->next;
  pre = L;
  while (p) {
    if (PredictSame(S, p->data)) {  //存在相同元素，去下一个
      pre = p;
      p = p->next;
    } else {
      q = p;
      p = p->next;
      pre->next = p;
      free(q);
    }
  }
}

int main(int argc, char** argv) {
  LinkList L, S;
  L = Creat_LinkList();
  S = Creat_LinkList();
  int a[10] = {1, 2, 5, 6, 7, 8, 9, 10, 12, 15};
  int b[10] = {1, 4, 5, 6, 6, 7, 8, 9, 10, 20};
  for (int i = 0; i < 10; i++) {
    ListInsert(L, i + 1, a[i]);
    ListInsert(S, i + 1, b[i]);
  }
  JiaoJi(L, S);
  PrintfList(L);
  system("pause");
  return 0;
}
