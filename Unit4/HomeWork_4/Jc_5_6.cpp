#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
//链串的数据结构
typedef struct node {
  char data;
  struct node *next;
}LinkStrNode;
typedef LinkStrNode *LinkString;//LinkString为链串类型
//初始化
LinkString InitLink() {
  LinkString ls;
  ls = (LinkStrNode*)malloc(sizeof(LinkStrNode));
  ls->next = NULL;
  return ls;
}
//查找重复点
LinkString SearchNoin(LinkString x, LinkString y) {
  LinkStrNode *p, *q;
  p = x;//注意 这个数据结构中不带头结点了
  while (p != NULL) {
    q = y;
    while (q != NULL&&p->data!=q->data) {
      q = q->next;
    }
    if (q) {//找到了相同点
      p = p->next;
    } else {
      return p;
    }
  }
  return NULL;//没有不相同的点
}

int main(int argc, char** argv) {
  system("pause");
  return 0;
}
