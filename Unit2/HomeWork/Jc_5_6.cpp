#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "LinkListFunction.h"
//不申请新的节点的情况下 将最小的节点移动到前面来
void GetMin(LinkList L) {
  LinkList p, q, min;
  Datatype tmp;
  p = L->next;
  q = p;//留一个锚点
  min = p;
  while (p!=NULL) {
    if (min->data>p->data) {
      min = p;
    }
    p = p->next;
  }
  tmp = min->data;
  min->data = q->data;
  q->data = tmp;
}

int main(int argc, char** argv) {
  LinkList L;
  L = Creat_LinkList();
  int a[15] = {1, 2, 5, 6, 4, 7, 8, 9, 0, 2, 5, 4, 1, 8, 7};
  for (int i = 0; i < 15; i++) {
    ListInsert(L, i + 1, a[i]);
  }
  GetMin(L);
  PrintfList(L);
  system("pause");
  return 0;
}
