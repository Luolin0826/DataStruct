#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//数组排序 n是数组中元素个数
void OrderInt(int* a, int n) {
  int tmp, low = 0, high = n - 1;
  while (low < high) {
    while (low < high && a[low] < 0) {
      low++;
    }
    while (low < high && a[high] >= 0) {
      high--;
    }
    if (low < high) {  //此处用if
      tmp = a[low];
      a[low] = a[high];
      a[high] = tmp;
    }
  }
}

int main(int argc, char** argv) {
  int a[10] = {1, -2, 0, 3, -4, 8, 9, -7, 0, -10};
  OrderInt(a, 10);
  for (int i = 0; i < 10; i++) {
    printf("%d ", a[i]);
  }
  system("pause");
  return 0;
}
