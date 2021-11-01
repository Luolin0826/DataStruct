#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "BTreeFunction.h"

//判断两棵树是否等价
int PreEqualTree(BTree s, BTree t) {
	int like1, like2;
	if ((s == NULL) && (t == NULL))//两树均空
	{
		return 1;//等价
	}
	else if ((s == NULL) || (t == NULL))//两棵树只有一颗为空
	{
		return 0;//不等价
	}
	else
	{
		like1 = PreEqualTree(s->lchild, t->lchild);//判断左子树是否等价
		like2 = PreEqualTree(s->rchild, t->rchild);//判断右子树是否等价
		return (like1 && like2);
	}
}

int main(int argc, char** argv)
{

	system("pause");
	return 0;
}

