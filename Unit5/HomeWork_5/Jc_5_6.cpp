#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "GListFunction.h"
//判别两个广义表是否相同
int PreEquGlist(Glist p, Glist q) {
	//不相等的情况
	if (p == NULL && q != NULL)
		return 0;
	else if (p != NULL && q == NULL)
		return 0;
	else if (p == NULL & q == NULL)  //空表则相等
		return 1;
	else if (p->tag == 0 && q->tag == 0 && p->data == q->data)  //数据域相同
		return 1;
	else if (p->tag == 1 && q->tag == 1)  //判断p与q的表头表尾是否相同
		return (PreEquGlist(p->ptr.hp, q->ptr.hp) &&
			PreEquGlist(p->ptr.tp, q->ptr.tp));
}

int main(int argc, char** argv) {
	system("pause");
	return 0;
}