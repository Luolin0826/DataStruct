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
//�鲢����
void Merge(DataType A[], DataType B[], int low, int mid, int high) {
  int i, j, k;
  //���½����л��ֳ���������
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
//��·�鲢���� ���������л��ֳ���������������У�Ȼ�������������н��й鲢
void MSort(DataType A[], DataType B[], int low, int high) {
  int mid;
  DataType C[MAXSIZE + 1];  //�м��������Ų���������
  if (low == high) {
    B[low] = A[low];  //ֻ��һ��Ԫ�أ�����Ҫ���й鲢����
  } else {
    mid = (low + high) / 2;
    MSort(A, C, low, mid);
    MSort(A, C, mid + 1, high);
    Merge(C, B, low, mid, high);//Cֻ�������洢�Ա�������Ҫ��ֵ�����ıȶԽ���洢��B��
  }
}
void MergeSort(SqList* s) {
  MSort(s->r, s->r, 1, s->length);
}

//��ֵ���� nΪ������Ԫ�صĸ���
void InitList(SqList* s, int a[], int n) {
  s->length = 0;
  s->r[0].key = 0;
  for (int i = 1; i <= n; i++) {
    s->r[i].key = a[i - 1];
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
  SqList s;
  int a[10] = {0, 1, 8, 3, 7, 5, 6, 4, 2, 9};
  InitList(&s, a, 10);
  //ֱ�Ӳ�������
  MergeSort(&s);
  printf("��ѡ��������Ϊ��");
  PrintfList(s);
  system("pause");
  return 0;
}
