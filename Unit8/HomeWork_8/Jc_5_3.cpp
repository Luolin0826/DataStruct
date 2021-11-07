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
//增序输出元素，确保相同值的元素只出现一次
void Incr_prt(BinSTree bt) {
	BinSTree p, s[maxsize];//将s作为栈
	p = bt;
	int top = 0;//定义top作为栈指针
	KeyType pre = -65535;//pre为当前节点的前驱，初始赋值最小,类型与关键字相同
	while (p != NULL || top != 0)
	{
		if (p != NULL) {
			s[top++] = p;
			p = p->lchild;
		}
		else
		{
			p = s[--top];//出栈
			if (pre != p->Elem.key)
			{
				printf("%d", p->Elem.key);
				pre = p->Elem.key;//给pre赋个值
			}
			p = p->rchild;//注意位置
		}
	}
}

int main(int argc, char** argv)
{
	system("pause");
	return 0;
}