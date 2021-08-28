#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkListFunction.h"
//�󽻼�
//�ж���ͬԪ�أ����A������ͬԪ�� ����1�����û�з���0
int PredictSame(LinkList S, Datatype x) {
  Lnode* p = S->next;
  while (p != NULL && p->data != x) {  //���﷢�������󣬺�����p=null�����
    //ͬʱҪ�ǳ��ǳ�ע�����
    //���������ķ���˳���ܳ��ִ��󣬷���������ڴ��ȡ�쳣
    //�²��������Ϊp->data != x ����ǰ�� ��p=nullʱ�����ִ��
    p = p->next;
  }
  if (p) {
    return 1;
  } else {
    return 0;
  }
}

//��ʽ����
void JiaoJi(LinkList L, LinkList S) {
  LinkList p, q, pre;
  p = L->next;
  pre = L;
  while (p) {
    if (PredictSame(S, p->data)) {  //������ͬԪ�أ�ȥ��һ��
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
