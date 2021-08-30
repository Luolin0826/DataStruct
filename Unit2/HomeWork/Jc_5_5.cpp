#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SqListFunction.h"

void QuickSort(PSqeList S, int low, int high) {
  Datatype tmp, pivotkey = 0;
  tmp = S->data[low];  //�����һ��λ��
  while (low < high) {
    while (low < high && pivotkey <= S->data[high]) {
      high--;
    }
    //��ʱ�����˲��������
    S->data[low] = S->data[high];
    while (low < high && pivotkey > S->data[low]) {
      low++;
    }
    S->data[high] = S->data[low];
  }
  //������ ��ʱ��low=high+1,һ�����������紦����tmp ��ֵ��lowλ��
  S->data[low] = tmp;
}

int main(int argc, char** argv) {
  PSqeList S = InitList();
  int a[15] = {1, -2, 5, 6, 4, -7, 8, 9, 0, 2, -5, 4, 1, -8, 7};
  for (int i = 0; i < 15; i++) {
    S->data[i] = a[i];
    S->length++;
  }
  QuickSort(S, 0, S->length - 1);
  PrintfList(S);

  system("pause");
  return 0;
}
