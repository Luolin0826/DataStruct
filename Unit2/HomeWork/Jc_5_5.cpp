#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SqListFunction.h"

void QuickSort(PSqeList S, int low, int high) {
  Datatype tmp, pivotkey = 0;
  tmp = S->data[low];  //提出来一个位置
  while (low < high) {
    while (low < high && pivotkey <= S->data[high]) {
      high--;
    }
    //此时出现了不满足的数
    S->data[low] = S->data[high];
    while (low < high && pivotkey > S->data[low]) {
      low++;
    }
    S->data[high] = S->data[low];
  }
  //结束后 此时的low=high+1,一定是正负交界处，将tmp 赋值给low位置
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
