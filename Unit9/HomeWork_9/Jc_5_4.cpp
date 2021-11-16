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
//���ÿ�������ݹ��ҳ���m����Сֵ
//���������㷨
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
	s->r[low] = s->r[0];//�������ǹ� Ҫ���¸�ֵ��ȥ
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
//�ٶ�n��Ԫ�ش洢��Sqlist.[1]~[n]��
DataType Search(Sqlist* s, int low, int high, int m) {
	int k;
	if (low < high)
	{
		k = QuickSort1(s, low, high);
		if (k - low == m)//ע�����������
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