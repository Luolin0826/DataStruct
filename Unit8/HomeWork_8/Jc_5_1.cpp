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
//折半查找的递归算法
int BinSearch(Sqlist S, KeyType k, int low, int high) {
	int mid;
	if (low <= high)//注意是小于等于
	{
		mid = (low + high) / 2;
		if (S.r[mid].key = k)
		{
			return mid;
		}
		else if (S.r[mid].key < k) {
			low = mid + 1;
			return BinSearch(S, k, low, high);
		}
		else
		{
			high = mid - 1;
			return BinSearch(S, k, low, high);
		}
	}
	else
	{
		return 0;//注意这里 不要搞错了，是low>mile的时候，查找失败
	}
}

int main(int argc, char** argv)
{
	system("pause");
	return 0;
}