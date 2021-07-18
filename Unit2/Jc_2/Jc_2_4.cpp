#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkListFunction.h"

//���Һ��� 0��ʾʧ�� ��0��ʾ�ɹ�
LinkList GetLocation(LinkList A, ElemType e) {
  LNode* p = A->next;
  while (p != NULL && p->data != e) {
    p = p->next;
  }
  return (p);
}
//�󽻼����� ���A���е�Bû�У���ôɾ����
void Intersection(LinkList A, LinkList B) {
  int tmp;
  LinkList per, p;
  per = A;
  p = per->next;
  while (p) {
    tmp = p->data;
    if (!GetLocation(B, tmp)) {
      per->next = p->next;
      free(p);
      p=per->next;//����Ҫע�⣬���ֹ��ڴ�й©�ĵ����⣬��仰�ı����ǿ�����һ�ڵ�
    } else  //�ҵ���һ��ͬ���Ľ�㣬����ڵ�ĵ�ַ��p
    {
      per = p;
      p = p->next;
    }
  }
}

int main(int argc, char** argv) {
  LinkList A, B;
  InitialLNode(A);
  InitialLNode(B);
  for (int i = 0; i < 10; i++) {
    InsertNextNode(A, i);
  }
  for (int i = 4; i < 12; i++) {
    InsertNextNode(B, i);
  }
  Intersection(A, B);
  printfLinkList(A);
  system("pause");
  return 0;
}
