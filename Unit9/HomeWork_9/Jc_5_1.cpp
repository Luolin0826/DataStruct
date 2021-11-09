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
	H->next = NULL;
	H->data = -1;
	L = H;
	pre = Creat_LinkList();  //无实际意义 对per进行初始化
	while (p) {
		q = p;
		p = p->next;//p是为了保留结点，为了下一次的分析
		while (L != NULL && q->data > L->data) {//寻找这个节点应该存放的位置
			pre = L;
			L = L->next;
		}
		q->next = pre->next;  //此处看作是将pre中比q.data大的元素连接q后面
		pre->next = q;  //将变化好的q给pre接上，同时pre的变化会引起H的变化
						//因为pre结点的物理地址和H中最后一个节点地址一致
		L = H;  //将比对好的H序列再次交给L 便于下次排序
	}
}

int main(int argc, char** argv) {
	LinkList L, S;
	L = Creat_LinkList();
	int a[15] = { 1, 2, 1, 6, 4, 7, 8, 9, 0, 2, 5, 4, 1, 8, 7 };
	for (int i = 0; i < 15; i++) {
		ListInsert(L, i + 1, a[i]);
	}
	DirectInsertSore(L);
	PrintfList(L);
	system("pause");
	return 0;
}