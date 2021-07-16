#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;
typedef struct DNode {
  Elemtype data;
  struct DNode *prior, *next;
} DNode, *DLinkList;

//初始化双链表
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
//判断是否为空
bool Empty(DLinkList& L) {
  if (L->next == NULL) {
    return true;
  } else {
    return false;
  }
}
//双链表的插入操作 在P结点之后插入S结点
bool InsertNextDNode(DNode* p, DNode* s) {
  //非法参数
  if (p == NULL || s == NULL) {
    return false;
  }
  s->next = p->next;
  if (p->next != NULL) {
    p->next->prior = s;  //防止P结点是左后一个节点产生BUG
  }
  s->prior = p;
  p->next = s;
  return true;
}
//双链表的删除操作 删除P结点的后继结点
bool DeleteNextDNode(DNode* p) {
  if (p == NULL) {
    return false;
  }
  DNode* q = p->next;  //找到P的后继结点
  if (q == NULL) {     // P结点是最后一个结点
    printf("P结点是最后一个结点");
    return false;
  }
  p->next = q->next;
  if (q->next != NULL) {  // q结点是不是最后一个结点
    q->next->prior = p;
  }
  free(q);
  return true;
}
//双链表的销毁操作
void DestoryList(DLinkList& L) {
  //循环释放各个数据结点
  while (L->next != NULL) {
    DeleteNextDNode(L);
  }
  free(L);   //释放头节点
  L = NULL;  //头指针指向NULL
}

int main(int argc, char** argv) {
  DLinkList L;
  InitDLinkList(L);

  system("pause");
  return 0;
}
