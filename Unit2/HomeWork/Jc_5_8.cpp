#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "LinkListFunction.h"

void DelPre(LinkList p) {
  LinkList q, pre;
  q = p;
  while (q->next->next!=p) {
    q=q->next;
  }
  pre = q->next;
  q->next = p;
  free(pre);
}


int main(int argc, char** argv) {
  system("pause");
  return 0;
}
