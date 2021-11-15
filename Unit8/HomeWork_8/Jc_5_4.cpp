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
//ɾ��һ����fΪ˫�׵Ľ��p��ʹ������������Ȼ����
void DelNode(BinSTree f) {
	BinSTree p, q, s;
	p = f->rchild;
	if (p->lchild == NULL)//������Ϊ�ա�������ֱ�Ӷ���
	{
		f->rchild = p->rchild;
		free(p);
	}
	else //�������ǿգ�ȥ����������ֱ��ǰ��
	{
		q = p->lchild;
		while (q) {//Ѱ���������е�����㣬ע�Ᵽ������ǰ��
			s = q;
			q = q->rchild;
		}//end ��ʱ�ҵ���q�������ڵ�,s��˫�׻�����������
		if (p->lchild == s)//p��������û���Һ���
		{
			p->Elem.key = s->Elem.key;
			p->lchild = s->lchild;
			free(s);
		}
		else//p���������к��ӣ���ʱqΪ���ڵ㣬��û���������������ܴ�����������
			//q��˫����s
		{
			p->Elem.key = q->Elem.key;
			s->rchild = q->lchild;//��˫�����ӹ�q��������
			free(q);
		}
	}
}


int main(int argc, char** argv)
{

	system("pause");
	return 0;
}

