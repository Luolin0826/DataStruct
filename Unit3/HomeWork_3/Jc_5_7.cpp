#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//对数组中的n个元素求最大最小值 注意max和min是另外设计的数组
void GetMaxMin(int* a, int n, int* max, int* min) {
  if (n == 1) {
    *max = a[0];
    *min = a[0];
  } else {
    //有n个元素时，先获得前n-1个数中的最大元素max和最小元素min
    GetMaxMin(a, n - 1, max, min);
    //如果第n个元素大于max，则这n个元素中最大的元素为max
    if (a[n - 1] > *max) {
      *max = a[n - 1];
    }
    //如果第n个元素小于max，则这n个元素中最小的元素为min
    if (a[n - 1] < *min) {
      *min = a[n - 1];
    }
  }
}

int main(int argc, char** argv) {
  int a[5] = {5, 4, 7, 1, 3};
  int max[1];
  int min[1];
  GetMaxMin(a, 5, max, min);
  system("pause");
  return 0;
}
