#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
//��������Һ��
#define DataType char
typedef struct ThreadNode {
	DataType data;
	struct ThreadNode* lchild, * rchild;
	int ltag, rtag;//���λ 0�����Ǻ��ӣ�1����������
} ThreadNode, * ThreadTree;

ThreadNode* OutSuccNode(ThreadNode* p) {
	ThreadNode* post;
	post = p->rchild;//��ʼ��post
	if (p->rtag == 0)
	{
		if (p->ltag == 0)
		{
			post = p->lchild;
		}
	}
	else
	{
		post = p->rchild;
	}
	return (post);
}

int main(int argc, char** argv)
{
	system("pause");
	return 0;
}