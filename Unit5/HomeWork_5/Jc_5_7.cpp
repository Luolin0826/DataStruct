#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GListFunction.h"

//�ݹ�ʵ��
int length(Glist L) {
	if (L == NULL) {
		return 0;
	}
	else {
		return (1 + length(L->ptr.tp));
	}
}
//�ǵݹ�ʵ��
int length_f(Glist L) {
	Glist p = L;
	int count = 0;
	while (p != NULL) {
		p = p->ptr.tp;
		count++;
	}
	return count;
}

int main(int argc, char** argv) {
	printf("hello");
	system("pause");
	return 0;
}