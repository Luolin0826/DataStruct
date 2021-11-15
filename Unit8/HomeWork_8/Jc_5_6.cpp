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
//�ݼ���������������е�������Ϊ�գ���������Ϊ�յĽڵ��ֵ
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

//�ǵݹ�
void dec_printf(BinSTree t) {
	BinSTree s[maxsize];//��Ϊջ
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

