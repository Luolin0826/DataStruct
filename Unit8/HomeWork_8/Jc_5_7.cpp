#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
//排序二叉树
#define maxsize 10
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
//寻找公共祖先
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
			return p;//查询到公共祖先，返回祖先节点
		}
	}
}


int main(int argc, char** argv)
{

	system("pause");
	return 0;
}

