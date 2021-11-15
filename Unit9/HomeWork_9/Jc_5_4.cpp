#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define Maxsize 100
typedef int KeyType;
//关键字段
typedef struct {
	KeyType key;
} DataType;
typedef struct {
	DataType r[Maxsize];  //数据元素的存储空间
	int length;
} Sqlist;
//利用快速排序递归找出第m个最小值
//快速排序算法
int QuickSort1(Sqlist* s, int low, int high) {
	KeyType pivotkey = s->r[low].key;
	s->r[0] = s->r[low];
	while (low < high) {
		while (low < high && pivotkey <= s->r[high].key) {
			high--;
		}
		s->r[low] = s->r[high];
		while (low < high && pivotkey >= s->r[low].key) {
			low++;
		}
		s->r[high] = s->r[low];
	}
	s->r[low] = s->r[0];//这里忘记过 要重新赋值回去
	return low;
}

void QuickSort(Sqlist* s, int low, int high) {
	int pivortion = 0;
	if (low < high) {
		pivortion = QuickSort1(s, low, high);
		QuickSort(s, low, pivortion - 1);
		QuickSort(s, pivortion + 1, high);
	}
}
//假定n个元素存储在Sqlist.[1]~[n]中
DataType Search(Sqlist* s, int low, int high, int m) {
	int k;
	if (low < high)
	{
		k = QuickSort1(s, low, high);
		if (k - low == m)//注意这里的条件
		{
			return s->r[k];
		}
		else if (k - low < m)
		{
			return Search(s, k + 1, high, m - k);
		}
		else
		{
			return Search(s, low, k - 1, m);
		}
	}
}

int main(int argc, char** argv)
{
	system("pause");
	return 0;
}