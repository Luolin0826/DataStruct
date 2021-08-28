#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkListFunction.h"
//������ɾ���ظ�ֵ
void DelRepeated(LinkList L) {
  LinkList p, q, tmp, pre;
  p = L->next;
  if (p==NULL) {
    return;
  }
  while (p) {
    q = p->next;
    pre = q;  //������Ҫ
    while (q) {
      if (p->data == q->data) {
        tmp = q;
        // p->next = tmp;��������� Ҫ��ǰ׺�ڵ�
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

int main(int argc, char** argv) {
  LinkList L;
  L = Creat_LinkList();
  int a[15] = {1, 2, 5, 6, 4, 7, 8, 9, 0, 2, 5, 4, 1, 8, 7};
  for (int i = 0; i < 15; i++) {
    ListInsert(L, i + 1, a[i]);
  }
  DelRepeated(L);
  PrintfList(L);
  system("pause");
  return 0;
}
