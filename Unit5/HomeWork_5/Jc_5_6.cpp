#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "GListFunction.h"
//�б�����������Ƿ���ͬ
int PreEquGlist(Glist p, Glist q) {
	//����ȵ����
	if (p == NULL && q != NULL)
		return 0;
	else if (p != NULL && q == NULL)
		return 0;
	else if (p == NULL & q == NULL)  //�ձ������
		return 1;
	else if (p->tag == 0 && q->tag == 0 && p->data == q->data)  //��������ͬ
		return 1;
	else if (p->tag == 1 && q->tag == 1)  //�ж�p��q�ı�ͷ��β�Ƿ���ͬ
		return (PreEquGlist(p->ptr.hp, q->ptr.hp) &&
			PreEquGlist(p->ptr.tp, q->ptr.tp));
}

int main(int argc, char** argv) {
	system("pause");
	return 0;
}