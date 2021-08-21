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
//归并排序
void Merge(DataType A[], DataType B[], int low, int mid, int high) {
  int i, j, k;
  //以下将序列划分成两个部分
  for (i = low, j = mid + 1, k = low; i <= mid && j <= high; k++) {
    if (A[i].key <= A[j].key) {
      B[k] = A[i++];
    } else {
      B[k] = A[j++];
    }
  }
  while (i <= mid) {
    B[k++] = A[i++];
  }
  while (j <= high) {
    B[k++] = A[j++];
  }
}
//两路归并排序 将整个序列划分成若干有序的子序列，然后将这两个子序列进行归并
void MSort(DataType A[], DataType B[], int low, int high) {
  int mid;
  DataType C[MAXSIZE + 1];  //中间变量，存放部分排序结果
  if (low == high) {
    B[low] = A[low];  //只有一个元素，不需要进行归并操作
  } else {
    mid = (low + high) / 2;
    MSort(A, C, low, mid);
    MSort(A, C, mid + 1, high);
    Merge(C, B, low, mid, high);//C只是用来存储对比中所需要的值，最后的比对结果存储在B中
  }
}
void MergeSort(SqList* s) {
  MSort(s->r, s->r, 1, s->length);
}

//赋值操作 n为数组内元素的个数
void InitList(SqList* s, int a[], int n) {
  s->length = 0;
  s->r[0].key = 0;
  for (int i = 1; i <= n; i++) {
    s->r[i].key = a[i - 1];
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
  SqList s;
  int a[10] = {0, 1, 8, 3, 7, 5, 6, 4, 2, 9};
  InitList(&s, a, 10);
  //直接插入排序
  MergeSort(&s);
  printf("简单选择排序结果为：");
  PrintfList(s);
  system("pause");
  return 0;
}
