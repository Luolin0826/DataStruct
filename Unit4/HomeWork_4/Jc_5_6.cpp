#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
//���������ݽṹ
typedef struct node {
  char data;
  struct node *next;
}LinkStrNode;
typedef LinkStrNode *LinkString;//LinkStringΪ��������
//��ʼ��
LinkString InitLink() {
  LinkString ls;
  ls = (LinkStrNode*)malloc(sizeof(LinkStrNode));
  ls->next = NULL;
  return ls;
}
//�����ظ���
LinkString SearchNoin(LinkString x, LinkString y) {
  LinkStrNode *p, *q;
  p = x;//ע�� ������ݽṹ�в���ͷ�����
  while (p != NULL) {
    q = y;
    while (q != NULL&&p->data!=q->data) {
      q = q->next;
    }
    if (q) {//�ҵ�����ͬ��
      p = p->next;
    } else {
      return p;
    }
  }
  return NULL;//û�в���ͬ�ĵ�
}

int main(int argc, char** argv) {
  system("pause");
  return 0;
}
