#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BTreeFunction.h"
#include "StackFunction.h"
//������������������
typedef struct ThreadNode {
	DataType data;
	struct ThreadNode* lchild, * rchild;
	int ltag, rtag;//���λ 0�����Ǻ��ӣ�1����������
} ThreadNode, * ThreadTree;
ThreadTree pre;//ȫ�ֱ��� ���ڶ�������������
void PostThread(ThreadNode* t) {
	if (t)
	{
		PostThread(t->lchild);
		PostThread(t->rchild);
		if (t->lchild != NULL)//дǰ��
		{
			t->ltag = 1;
			t->lchild = pre;
		}
		if (t->rchild == NULL)
		{
			t->rtag = 1;
		}
		if (pre && pre->rtag == 1)//Ϊǰ��д���
		{
			pre->rchild = t;
		}
		pre = t;
	}
}

int main(int argc, char** argv) {
	system("pause");
	return 0;
}