#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;
typedef struct DNode {
  Elemtype data;
  struct DNode *prior, *next;
} DNode, *DLinkList;

//��ʼ��˫����
bool InitDLinkList(DLinkList& L) {
  L = (DNode*)malloc(sizeof(DNode));
  if (L == NULL) {
    printf("Error");
    return false;
  }
  L->prior = NULL;
  L->next = NULL;
  return true;
}
//�ж��Ƿ�Ϊ��
bool Empty(DLinkList& L) {
  if (L->next == NULL) {
    return true;
  } else {
    return false;
  }
}
//˫����Ĳ������ ��P���֮�����S���
bool InsertNextDNode(DNode* p, DNode* s) {
  //�Ƿ�����
  if (p == NULL || s == NULL) {
    return false;
  }
  s->next = p->next;
  if (p->next != NULL) {
    p->next->prior = s;  //��ֹP��������һ���ڵ����BUG
  }
  s->prior = p;
  p->next = s;
  return true;
}
//˫�����ɾ������ ɾ��P���ĺ�̽��
bool DeleteNextDNode(DNode* p) {
  if (p == NULL) {
    return false;
  }
  DNode* q = p->next;  //�ҵ�P�ĺ�̽��
  if (q == NULL) {     // P��������һ�����
    printf("P��������һ�����");
    return false;
  }
  p->next = q->next;
  if (q->next != NULL) {  // q����ǲ������һ�����
    q->next->prior = p;
  }
  free(q);
  return true;
}
//˫��������ٲ���
void DestoryList(DLinkList& L) {
  //ѭ���ͷŸ������ݽ��
  while (L->next != NULL) {
    DeleteNextDNode(L);
  }
  free(L);   //�ͷ�ͷ�ڵ�
  L = NULL;  //ͷָ��ָ��NULL
}

int main(int argc, char** argv) {
  DLinkList L;
  InitDLinkList(L);

  system("pause");
  return 0;
}
