#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define DataType char
//�������Һ��
typedef struct ThreadNode {
	DataType data;
	struct ThreadNode* lchild, * rchild;
	int ltag, rtag;//���λ 0�����Ǻ��ӣ�1����������
} ThreadNode, * ThreadTree;

ThreadNode* OutPostNode(ThreadNode* p, ThreadNode* f) {
	ThreadNode* post;
	post = p->rchild;
	if (p->rtag == 0)
	{
		if ((f->rchild == p) || (f->lchild == p) && (f->rtag = 1))
			//p��˫�׽����Һ��ӣ���P��˫�׽���������˫�׽��û���Һ���
		{
			post = f;//˫�׽��������ĺ��
		}
		else if ((f->rtag == 0) && (f->lchild = p)) {//p��˫�׵���ڵ���˫�����ҽڵ�
			post = f->rchild;
			while (post->ltag == 0 || post->rtag == 0)//post����Ҷ�ӽڵ�
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