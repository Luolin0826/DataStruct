#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
//假设元素存储在A[1]~A[k]中，新插入的元素放在A[K+1]
void sift(int A[], int k) {
	int x = A[k + 1];
	int j = k + 1;
	int i = j / 2;
	while (i >= 1 && x > A[i])
	{
		A[i] = A[j];
		j = i;
		i = i / 2;
	}
	A[i] = x;//找到合适的位置了，放入元素
}
void HeapBuild(int A[], int n) {
	for (int i = 1; i < n; i++)
	{
		sift(A, i);
	}
}

int main(int argc, char** argv)
{

	system("pause");
	return 0;
}

