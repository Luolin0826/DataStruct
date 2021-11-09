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
//�������Ԫ�أ�ȷ����ֵͬ��Ԫ��ֻ����һ��
void Incr_prt(BinSTree bt) {
	BinSTree p, s[maxsize];//��s��Ϊջ
	p = bt;
	int top = 0;//����top��Ϊջָ��
	KeyType pre = -65535;//preΪ��ǰ�ڵ��ǰ������ʼ��ֵ��С,������ؼ�����ͬ
	while (p != NULL || top != 0)
	{
		if (p != NULL) {
			s[top++] = p;
			p = p->lchild;
		}
		else
		{
			p = s[--top];//��ջ
			if (pre != p->Elem.key)
			{
				printf("%d", p->Elem.key);
				pre = p->Elem.key;//��pre����ֵ
			}
			p = p->rchild;//ע��λ��
		}
	}
}

int main(int argc, char** argv)
{
	system("pause");
	return 0;
}