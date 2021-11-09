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
//删除一个以f为双亲的结点p，使二叉排序树仍然成立
void DelNode(BinSTree f) {
	BinSTree p, q, s;
	p = f->rchild;
	if (p->lchild == NULL)//左子树为空。右子树直接顶替
	{
		f->rchild = p->rchild;
		free(p);
	}
	else //左子树非空，去找左子树的直接前驱
	{
		q = p->lchild;
		while (q) {//寻找左子树中的最大结点，注意保留他的前驱
			s = q;
			q = q->rchild;
		}//end 此时找到的q就是最大节点,s是双亲或者是他本身
		if (p->lchild == s)//p的左子树没有右孩子
		{
			p->Elem.key = s->Elem.key;
			p->lchild = s->lchild;
			free(s);
		}
		else//p的左子树有孩子，此时q为最大节点，且没有右子树，但可能存在左子树。
			//q的双亲是s
		{
			p->Elem.key = q->Elem.key;
			s->rchild = q->lchild;//让双亲来接管q的右子树
			free(q);
		}
	}
}


int main(int argc, char** argv)
{

	system("pause");
	return 0;
}

