#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
//���������
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
//���ҽ�����
int	BstSearch(BinSTree bst, KeyType k) {
	BinSTree p;
	p = bst;
	int count = 0;//��¼����
	if (p == NULL)
	{
		return 0;//����
	}
	while (p != NULL && p->Elem.key != k)
	{
		if (p->Elem.key < k)
		{
			p = p->rchild;
		}
		else {
			p = p->lchild;
		}
		count++;
	}
	return count + 1;//Ҫ��һ
}

int main(int argc, char** argv)
{
	system("pause");
	return 0;
}