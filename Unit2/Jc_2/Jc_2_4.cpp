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
  LinkList per, p;  //前驱节点per，当前结点p
  per = A;
  p = per->next;  //定义的p结点可以有效防止出现空指针问题
  while (p) {
    tmp = p->data;
    if (!GetLocation(B, tmp)) {
      per->next = p->next;
      free(p);
      p = per->next;  //这里要注意，出现过内存泄漏的问题，这句话的本意是考察下一节点
    } else  //找到了一个同样的结点，这个节点的地址是p
    {
      per = p;  //此处理解为per是p指针的辅助指针，确保per始终是p指针的的前驱指针，如果不这样修改，在没匹配到的时候就无法删除操作了
      p = p->next;  //考察下一个结点
    }
  }
}
//求并集操作 删除B中的A出现过的元素，再将B链表连接到A链表后面
void Union(LinkList A, LinkList B) {
  LinkList per, p;
  per = B;
  p =  B->next;
  ElemType tmp;  //辅助变量，用以存储值
  while (p) {
    tmp = p->data;
    if (GetLocation(A, tmp)) {//定位到了相同的元素，需要执行删除操作
      per->next = p->next;//删除
      free(p);//释放
      p = per->next;//置指针
    } else {
      per = p;//为了执行后续操作的先决条件
      p = p->next;//考察下一节点
    }
  }
  //此处 我们设法将两个链表连接起来
  while (A->next!=NULL) {
    A = A->next;
  }
  A->next = B->next;
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
  //Intersection(A, B);
  //printf("交集是：");
  //printfLinkList(A);
  printf("\n并集是：");
  Union(A, B);
  printfLinkList(A);
  system("pause");
  return 0;
}
