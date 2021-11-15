#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "LinkListFunction.h"

//分辨奇偶 奇数放左边，偶数放右边
//n是数组中的元素个数
void divide(int R[], int n) {
	int tmp, low = 0, high = n - 1;
	while (low < high)
	{
		if (low < high && R[low] % 2 == 1)//判断是奇数的话就++，
		{
			low++;
		}
		if (low < high && R[high] % 2 == 0)//判断是不是偶数
		{
			high--;
		}
		if (low < high)//交换
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