#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "BTreeFunction.h"

//�ж��������Ƿ�ȼ�
int PreEqualTree(BTree s, BTree t) {
	int like1, like2;
	if ((s == NULL) && (t == NULL))//��������
	{
		return 1;//�ȼ�
	}
	else if ((s == NULL) || (t == NULL))//������ֻ��һ��Ϊ��
	{
		return 0;//���ȼ�
	}
	else
	{
		like1 = PreEqualTree(s->lchild, t->lchild);//�ж��������Ƿ�ȼ�
		like2 = PreEqualTree(s->rchild, t->rchild);//�ж��������Ƿ�ȼ�
		return (like1 && like2);
	}
}

int main(int argc, char** argv)
{

	system("pause");
	return 0;
}

