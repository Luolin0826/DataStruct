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
//递减输出二叉排序树中的左子树为空，右子树不为空的节点的值
void Nest_dec_printf(BinSTree t) {
	if (t != NULL)
	{
		Nest_dec_printf(t->rchild);
		if ((t->lchild == NULL) && (t->rchild != NULL))
		{
			printf("%d", t->Elem.key);
		}
		Nest_dec_printf(t->lchild);
	}
}

//非递归
void dec_printf(BinSTree t) {
	BinSTree s[maxsize];//作为栈
	int top = 0;
	while (t != NULL || top != 0)
	{
		if (t != NULL) {
			s[top++] = t;
			t = t->rchild;
		}
		else
		{
			if ((t->lchild == NULL) && (t->rchild != NULL))
			{
				printf("%d", t->Elem.key);
			}
			t = t->lchild;
		}
	}
}

int main(int argc, char** argv)
{

	system("pause");
	return 0;
}

