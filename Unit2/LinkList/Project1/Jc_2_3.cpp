#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkListFunction.h"

void Reserve_LinkList(LinkList L) {
  LinkList P;
  P = L->next;     //将L表给P表
  L->next = NULL;  //初始化L表
  while (P) {
    LNode* s = (LNode*)malloc(sizeof(LNode));
    s->data = P->data;
    P = P->next;
    s->next = L->next;
    L->next = s;
  }
  printfLinkList(L);
}
int main(int argc, char** argv) {
  LinkList L;
  InitialLNode(L);
  for (int i = 0; i < 10; i++) {
    InsertNextNode(L, i);
  }
  Reserve_LinkList(L);
  return 0;
}
