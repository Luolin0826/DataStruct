#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkListFunction.h"

//查找函数 0表示失败 非0表示成功
LinkList GetLocation(LinkList A, ElemType e) {
  LNode* p = A->next;
  while (p != NULL && p->data != e) {
    p = p->next;
  }
  return (p);
}
//求交集操作 如果A里有的B没有，那么删除。
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
      p=per->next;//这里要注意，出现过内存泄漏的的问题，这句话的本意是考察下一节点
    } else  //找到了一个同样的结点，这个节点的地址是p
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
