#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkListFunction.h"
//ֱ�Ӳ������� ��������������β��뵽�����������ȥ
//������βָ�룬βָ����Ԫ�ز�Ϊ������Ҳ����룬ÿ�δ�ͷ��㿪ʼ������ң�����ָ��p��ǰ��pre���ҵ��Ժ��������
void DirectInsertSore(LinkList H) {
	LinkList p, q, pre, L;
	p = H->next;
	H->next = NULL;
	H->data = -1;
	L = H;
	pre = Creat_LinkList();  //��ʵ������ ��per���г�ʼ��
	while (p) {
		q = p;
		p = p->next;//p��Ϊ�˱�����㣬Ϊ����һ�εķ���
		while (L != NULL && q->data > L->data) {//Ѱ������ڵ�Ӧ�ô�ŵ�λ��
			pre = L;
			L = L->next;
		}
		q->next = pre->next;  //�˴������ǽ�pre�б�q.data���Ԫ������q����
		pre->next = q;  //���仯�õ�q��pre���ϣ�ͬʱpre�ı仯������H�ı仯
						//��Ϊpre���������ַ��H�����һ���ڵ��ַһ��
		L = H;  //���ȶԺõ�H�����ٴν���L �����´�����
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