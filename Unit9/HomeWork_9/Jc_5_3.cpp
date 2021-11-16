#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "LinkListFunction.h"

//�ֱ���ż ��������ߣ�ż�����ұ�
//n�������е�Ԫ�ظ���
void divide(int R[], int n) {
	int tmp, low = 0, high = n - 1;
	while (low < high)
	{
		if (low < high && R[low] % 2 == 1)//�ж��������Ļ���++��
		{
			low++;
		}
		if (low < high && R[high] % 2 == 0)//�ж��ǲ���ż��
		{
			high--;
		}
		if (low < high)//����
		{
			tmp = R[low];
			R[low] = R[high];
			R[high] = tmp;
		}
	}
}

int main(int argc, char** argv)
{
	int a[15] = { 1, 2, 1, 6, 4, 7, 8, 9, 15, 2, 5, 4, 1, 8, 7 };
	divide(a, 15);
	for (int i = 0; i < 15; i++)
	{
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}