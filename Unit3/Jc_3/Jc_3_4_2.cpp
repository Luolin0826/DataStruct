#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

//数组递归求和 i代表当前的位数 h代表数组里面的数 代表着求A[i]+...+A[h]
int sum(int a[],int i,int h) {
  if (h==i) {
    return a[i];
  } else {
    return (a[h] + sum(a, i, h - 1));
  }
}


int main(int argc, char** argv) {
  int a[10];
  for (int i = 0; i < 10; i++) {
    a[i] = i;
  }
  int result = sum(a, 5, 6);
  printf("%d",result);
  system("pause");
  return 0;
}
