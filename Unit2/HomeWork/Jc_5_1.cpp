#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkListFunction.h"
//单链表删除重复值
void DelRepeated(LinkList L) {
  LinkList p, q, tmp, pre;
  p = L->next;
  if (p == NULL) {
    return;
  }
  while (p) {
    q = p->next;
    pre = q;  //这句很重要
    while (q) {
      if (p->data == q->data) {
        tmp = q;
        // p->next = tmp;这句错得离谱 要找前缀节点
        q = q->next;
        pre->next = q;
        free(tmp);
      } else {
        pre = q;
        q = q->next;
      }
    }
    p = p->next;
  }
}

void DelList(LinkList L) {
  Lnode *s, *p, *q;
  p = L;
  s = p;
  q = p->next;
  while (s->next != NULL) {
    while (q!= NULL) {
      if (s->data != q->data) {
        q = q->next;
        p = p->next;
      } else {
        p->next = q->next;
        q = q->next;
      }
    }
    s = s->next;
    p = s;
    q = p->next;
  }
}

int main(int argc, char** argv) {
  LinkList L;
  L = Creat_LinkList();
  int a[15] = {1, 2, 5, 6, 4, 7, 8, 9, 0, 2, 5, 4, 1, 8, 7};
  for (int i = 0; i < 15; i++) {
    ListInsert(L, i + 1, a[i]);
  }
  // DelRepeated(L);
  DelList(L);
  PrintfList(L);
  system("pause");
  return 0;
}
