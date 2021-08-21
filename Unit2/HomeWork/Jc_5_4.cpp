#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkListFunction.h"
//直接插入排序 将待排序的数渐次插入到有序的序列中去
//先设立尾指针，尾指针后的元素不为空则查找并插入，每次从头结点开始往后查找，设立指针p和前驱pre，找到以后断链插入
void DirectInsertSore(LinkList H) {
  LinkList p, q, pre, L;
  p = H->next;
  //下列改造H，让他来存放哨兵结点
  H->next = NULL;
  H->data = -1;
  L = H;
  pre = Creat_LinkList();  //无实际意义 对per进行初始化
  while (p) {
    q = p;
    p = p->next;
    while (L != NULL && q->data > L->data) {
      pre = L;
      L = L->next;
    }
    q->next = pre->next;  //此处看作是将pre中比q.data大的元素连接q后面
    pre->next = q;  //将变化好的q给pre接上，同时pre的变化会引起H的变化
                    //因为pre结点的物理地址和H中最后一个节点地址一致
    L = H;  //将比对好的H序列再次交给L 便于下次排序
  }
}
//简单选择排序 选择一个极值数加入到已有序列中
//所以 我们在此分别对他的值进行交换
void SelectSort(LinkList H) {
  LinkList p, q, min;
  Datatype tmp;
  p = H->next;
  min = Creat_LinkList();
  while (p != NULL) {
    //在此分析下下一步的目的  我们想要寻找一个最小值 将最小值和p的数据进行交换
    q = p;
    min=q;   //这里曾经犯过错误 注意每次循环的初始化，不然会调用上次循环的遗留数据 造成失误
    while (q != NULL) {  //寻找最小值
      if (min->data > q->data) {
        min = q;
      }
      q = q->next;
    }
    //此时 我们已经找到了这次遍历序列中的最小节点q对应的地址min
    //让我们将两边的值加换一下吧
    tmp = min->data;
    min->data = p->data;
    p->data = tmp;
    //进入下一个序列的对比
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
