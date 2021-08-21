#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 20
typedef int KeyType;
typedef struct {
  KeyType key;
} DataType;
typedef struct {
  DataType r[MAXSIZE + 1];  // r[0]���û�䵱ǰ��վ
  int length;
} SqList;

//ð������ 0��λ�ò��洢Ԫ��
void BubbleSort(SqList* s) {
  int i, j;
  for (i = 1; i < s->length; i++) {
    bool flag = false;
    for (j = s->length; j > i; j--) {  //��Ϊiǰ������Ѿ��ź����
      if (s->r[j - 1].key > s->r[j].key) {
        s->r[0].key = s->r[j - 1].key;
        s->r[j - 1].key = s->r[j].key;
        s->r[j].key = s->r[0].key;
        flag = true;
      }
    }
    if (flag == false) {  //һ��������û�з�������
      return;
    }
  }
}
//���������㷨
int QuickSort1(SqList* s, int low, int high) {
  KeyType pivotkey =s->r[low].key;
  s->r[0] = s->r[low];
  while (low<high) {
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

void QuickSort(SqList* s, int low, int high) {
  int pivortion;
  if (low<high) {
    pivortion = QuickSort1(s, low, high);
    QuickSort(s, low, pivortion - 1);
    QuickSort(s, pivortion + 1, high);
  }
}

//��ֵ���� nΪ������Ԫ�صĸ���
void InitList(SqList* s, int a[], int n) {
  s->length = 0;
  s->r[0].key = 0;
  for (int i = 1; i <= n; i++) {
    s->r[i].key = a[i-1];
    s->length++;
  }
}
//��ʾ
void PrintfList(SqList s) {
  for (int i = 1; i <= s.length; i++) {
    printf("%d ", s.r[i].key);
  }
}

int main(int argc, char** argv) {
  SqList s, q, p;
  int a[10] = {0, 1, 8, 3, 7, 5, 6, 4, 2, 9};
  InitList(&s, a, 10);
  InitList(&p, a, 10);
  InitList(&q, a, 10);
  //ֱ�Ӳ�������
  BubbleSort(&s);
  printf("ð�ݷ�������Ϊ��");
  PrintfList(s);
  QuickSort(&p,1,10);
  printf("\n����������Ϊ��");
  PrintfList(p);
  system("pause");
  return 0;
}
