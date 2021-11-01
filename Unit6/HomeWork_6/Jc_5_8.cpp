#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
//先序遍历找后继
#define DataType char
typedef struct ThreadNode {
	DataType data;
	struct ThreadNode* lchild, * rchild;
	int ltag, rtag;//标记位 0代表是孩子，1代表是线索
} ThreadNode, * ThreadTree;

ThreadNode* OutSuccNode(ThreadNode* p) {
	ThreadNode* post;
	post = p->rchild;//初始化post
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