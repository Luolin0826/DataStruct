#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define Maxsize 100
typedef int KeyType;
//�ؼ��ֶ�
typedef struct {
	KeyType key;
} DataType;
typedef struct {
	DataType r[Maxsize];  //����Ԫ�صĴ洢�ռ�
	int length;
} Sqlist;
//�۰���ҵĵݹ��㷨
int BinSearch(Sqlist S, KeyType k, int low, int high) {
	int mid;
	if (low <= high)//ע����С�ڵ���
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
		return 0;//ע������ ��Ҫ����ˣ���low>mile��ʱ�򣬲���ʧ��
	}
}

int main(int argc, char** argv)
{
	system("pause");
	return 0;
}