#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkListFunction.h"
//ֱ�Ӳ������� ��������������β��뵽�����������ȥ
//������βָ�룬βָ����Ԫ�ز�Ϊ������Ҳ����룬ÿ�δ�ͷ��㿪ʼ������ң�����ָ��p��ǰ��pre���ҵ��Ժ��������
void DirectInsertSore(LinkList H) {
  LinkList p, q, pre, L;
  p = H->next;
  //���и���H������������ڱ����
  H->next = NULL;
  H->data = -1;
  L = H;
  pre = Creat_LinkList();  //��ʵ������ ��per���г�ʼ��
  while (p) {
    q = p;
    p = p->next;
    while (L != NULL && q->data > L->data) {
      pre = L;
      L = L->next;
    }
    q->next = pre->next;  //�˴������ǽ�pre�б�q.data���Ԫ������q����
    pre->next = q;  //���仯�õ�q��pre���ϣ�ͬʱpre�ı仯������H�ı仯
                    //��Ϊpre���������ַ��H�����һ���ڵ��ַһ��
    L = H;  //���ȶԺõ�H�����ٴν���L �����´�����
  }
}
//��ѡ������ ѡ��һ����ֵ�����뵽����������
//���� �����ڴ˷ֱ������ֵ���н���
void SelectSort(LinkList H) {
  LinkList p, q, min;
  Datatype tmp;
  p = H->next;
  min = Creat_LinkList();
  while (p != NULL) {
    //�ڴ˷�������һ����Ŀ��  ������ҪѰ��һ����Сֵ ����Сֵ��p�����ݽ��н���
    q = p;
    min=q;   //���������������� ע��ÿ��ѭ���ĳ�ʼ������Ȼ������ϴ�ѭ������������ ���ʧ��
    while (q != NULL) {  //Ѱ����Сֵ
      if (min->data > q->data) {
        min = q;
      }
      q = q->next;
    }
    //��ʱ �����Ѿ��ҵ�����α��������е���С�ڵ�q��Ӧ�ĵ�ַmin
    //�����ǽ����ߵ�ֵ�ӻ�һ�°�
    tmp = min->data;
    min->data = p->data;
    p->data = tmp;
    //������һ�����еĶԱ�
    p = p->next;
  }
}

int main(int argc, char** argv) {
  LinkList L, S;
  S = Creat_LinkList();
  L = Creat_LinkList();
  int a[15] = {1, 2, 5, 6, 4, 7, 8, 9, 0, 2, 5, 4, 1, 8, 7};
  int b[15] = {1, 4, 5, 6, 6, 7, 8, 9, 10, 20, 5, 7, 8, 32, 5};
  for (int i = 0; i < 15; i++) {
    ListInsert(L, i + 1, a[i]);
    ListInsert(S, i + 1, b[i]);
  }
  DirectInsertSore(L);
  PrintfList(L);
  printf("\n");
  SelectSort(S);
  PrintfList(S);
  system("pause");
  return 0;
}
