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
  DataType r[MAXSIZE + 1];  // r[0]闲置或充当前哨站
  int length;
} SqList;

//冒泡排序 0号位置不存储元素
void BubbleSort(SqList* s) {
  int i, j;
  for (i = 1; i < s->length; i++) {
    bool flag = false;
    for (j = s->length; j > i; j--) {  //因为i前面的是已经排好序的
      if (s->r[j - 1].key > s->r[j].key) {
        s->r[0].key = s->r[j - 1].key;
        s->r[j - 1].key = s->r[j].key;
        s->r[j].key = s->r[0].key;
        flag = true;
      }
    }
    if (flag == false) {  //一趟序列中没有发生交换
      return;
    }
  }
}
//快速排序算法
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
  s->r[low] = s->r[0];//这里忘记过 要重新赋值回去
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

//赋值操作 n为数组内元素的个数
void InitList(SqList* s, int a[], int n) {
  s->length = 0;
  s->r[0].key = 0;
  for (int i = 1; i <= n; i++) {
    s->r[i].key = a[i-1];
    s->length++;
  }
}
//显示
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
  //直接插入排序
  BubbleSort(&s);
  printf("冒泡法排序结果为：");
  PrintfList(s);
  QuickSort(&p,1,10);
  printf("\n快速排序结果为：");
  PrintfList(p);
  system("pause");
  return 0;
}
