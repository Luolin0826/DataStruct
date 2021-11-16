#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define Datatype int
typedef struct node {
	Datatype data;
	struct node* prior, * next;
}DuNode, * DlinkList;//˫���������ݽṹ
//˫��ð������
void TowWayBubbleSort(DlinkList L) {
	DlinkList head, tail, p;
	Datatype tmp;//��㽻��ֵ�ĸ�������
	int exchange = 1;//��Ϊ������־��
	head = L;
	tail = NULL;
	while (exchange)
	{
		exchange = 0;
		p = head->next;//p��Ϊ����ָ��
		//����Ϊ˳������
		while (p->next != tail)//�����tailҪע�⣬������Ѱַ����ֹ����
		{
			if (p->data > p->next->data)
			{
				exchange = 1;
				tmp = p->next->data;//����ֵ
				p->next->data = p->data;
				p->data = tmp;
			}
			p = p->next;
		}
		if (exchange)//���ǰ���й��������ʹӺ���ǰ��ɨһ��
		{
			exchange = 0;
			tail = p;//��������βָ��
			p = tail->prior;//��������ָ��
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

