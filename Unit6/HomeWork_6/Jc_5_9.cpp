#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define DataType char
//后续查找后继
typedef struct ThreadNode {
	DataType data;
	struct ThreadNode* lchild, * rchild;
	int ltag, rtag;//标记位 0代表是孩子，1代表是线索
} ThreadNode, * ThreadTree;

ThreadNode* OutPostNode(ThreadNode* p, ThreadNode* f) {
	ThreadNode* post;
	post = p->rchild;
	if (p->rtag == 0)
	{
		if ((f->rchild == p) || (f->lchild == p) && (f->rtag = 1))
			//p是双亲结点的右孩子，获P是双亲结点的左孩子且双亲结点没有右孩子
		{
			post = f;//双亲结点就是他的后继
		}
		else if ((f->rtag == 0) && (f->lchild = p)) {//p是双亲的左节点且双亲有右节点
			post = f->rchild;
			while (post->ltag == 0 || post->rtag == 0)//post不是叶子节点
			{
				if (post->ltag == 0) {
					post = post->lchild;
				}
				else
				{
					post = post->rchild;
				}
			}
		}
	}
	return (post);
}

int main(int argc, char** argv)
{
	system("pause");
	return 0;
}