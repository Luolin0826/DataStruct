#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
//���������
#define maxsize 10
typedef int KeyType;
//�ؼ��ֶ�
typedef struct {
	KeyType key;
} DataType;
typedef struct BinSTreeNode {
	DataType Elem;
	struct BinSTreeNode* lchild;
	struct BinSTreeNode* rchild;
} *BinSTree;
//Ѱ�ҹ�������
BinSTree Search_common(BinSTree bst, KeyType x, KeyType y) {
	BinSTree p = bst;
	while (1)
	{
		if (x < p->Elem.key && y < p->Elem.key) {
			p = p->lchild;
		}
		else if (x > p->Elem.key && y > p->Elem.key)
		{
			p = p->rchild;
		}
		else
		{
			return p;//��ѯ���������ȣ��������Ƚڵ�
		}
	}
}


int main(int argc, char** argv)
{

	system("pause");
	return 0;
}

