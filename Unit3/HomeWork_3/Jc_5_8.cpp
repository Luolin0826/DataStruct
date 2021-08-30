#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//获取m和n的公因数 非递归
int GetCommonFactor(int m, int n) {
  int tmp;
  if (n == 0) {
    return m;
  } else if (m < n) {
    tmp = m;
    m = n;
    n = tmp;
  } else if (m > n) {
    tmp = m;
    m = n;
    n = tmp % n;
  }
  return GetCommonFactor(m, n);  //注意这种表达方式 有效解决返回值不好取的问题
}

//尾递归可以不使用栈来解决
int GetCommon(int m, int n) {
  int tmp;
  while (n != 0) {
    if (m < n) {
      tmp = m;
      m = n;
      n = tmp;
    } else if (m > n) {
      tmp = m;
      m = n;
      n = tmp % n;
    }
  }
  return m;
}

int main(int argc, char** argv) {
  int i, j, result,result1;
  i = 4, j = 7;
  result = GetCommonFactor(i, j);
  printf("%d", result);
  result1 = GetCommon(i, j);
  printf("\n%d", result1);
  system("pause");
  return 0;
}
