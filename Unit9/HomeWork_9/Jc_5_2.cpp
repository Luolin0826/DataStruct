#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "LinkListFunction.h"

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
        min = q;   //这里曾经犯过错误 注意每次循环的初始化，不然会调用上次循环的遗留数据 造成失误
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

int main(int argc, char** argv)
{
    LinkList L, S;
    S = Creat_LinkList();
    L = Creat_LinkList();
    int a[15] = { 1, 2, 5, 6, 4, 7, 8, 9, 0, 2, 5, 4, 1, 8, 7 };
    int b[15] = { 1, 4, 5, 6, 6, 7, 8, 9, 10, 20, 5, 7, 8, 32, 5 };
    for (int i = 0; i < 15; i++) {
        ListInsert(L, i + 1, a[i]);
        ListInsert(S, i + 1, b[i]);
    }
    SelectSort(S);
    PrintfList(S);
    system("pause");
    return 0;
}

