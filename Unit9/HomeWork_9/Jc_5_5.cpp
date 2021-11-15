#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define Datatype int
typedef struct node {
	Datatype data;
	struct node* prior, * next;
}DuNode, * DlinkList;//双向链表数据结构
//双向冒泡排序
void TowWayBubbleSort(DlinkList L) {
	DlinkList head, tail, p;
	Datatype tmp;//结点交换值的辅助变量
	int exchange = 1;//作为交换标志符
	head = L;
	tail = NULL;
	while (exchange)
	{
		exchange = 0;
		p = head->next;//p作为搜索指针
		//以下为顺序搜索
		while (p->next != tail)//这里的tail要注意，代表着寻址的终止条件
		{
			if (p->data > p->next->data)
			{
				exchange = 1;
				tmp = p->next->data;//交换值
				p->next->data = p->data;
				p->data = tmp;
			}
			p = p->next;
		}
		if (exchange)//如果前面有过交换，就从后向前再扫一遍
		{
			exchange = 0;
			tail = p;//重新设立尾指针
			p = tail->prior;//设立搜索指针
			while (p->prior != head)
			{
				if (p->data < p->prior->data) {
					exchange = 1;
					tmp = p->prior->data;
					p->prior->data = p->data;
					p->data = tmp;
				}
				p = p->prior;
			}
			head = p;
		}
	}
}


int main(int argc, char** argv)
{

	system("pause");
	return 0;
}

