#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
//排序二叉树
typedef int KeyType;
//关键字段
typedef struct {
	KeyType key;
} DataType;
typedef struct BinSTreeNode {
	DataType Elem;
	struct BinSTreeNode* lchild;
	struct BinSTreeNode* rchild;
} *BinSTree;
//查找结点层数
int	BstSearch(BinSTree bst, KeyType k) {
	BinSTree p;
	p = bst;
	int count = 0;//记录层数
	if (p == NULL)
	{
		return 0;//空树
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
	return count + 1;//要加一
}

int main(int argc, char** argv)
{
	system("pause");
	return 0;
}