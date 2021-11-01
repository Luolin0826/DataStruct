#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BTreeFunction.h"
#include "StackFunction.h"
//建立后续线索二叉树
typedef struct ThreadNode {
	DataType data;
	struct ThreadNode* lchild, * rchild;
	int ltag, rtag;//标记位 0代表是孩子，1代表是线索
} ThreadNode, * ThreadTree;
ThreadTree pre;//全局变量 用于二叉树的线索化
void PostThread(ThreadNode* t) {
	if (t)
	{
		PostThread(t->lchild);
		PostThread(t->rchild);
		if (t->lchild != NULL)//写前驱
		{
			t->ltag = 1;
			t->lchild = pre;
		}
		if (t->rchild == NULL)
		{
			t->rtag = 1;
		}
		if (pre && pre->rtag == 1)//为前驱写后继
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