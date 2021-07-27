#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

//栈的递归之全排列算法 
//数组中两个数据交换
void Swap(int a[], int i, int j) {
  int x = a[j];
  a[j] = a[i];
  a[i] = x;
}

//求数组中下标k~m的元素的全排列
void Perm(int List[], int k, int m) {
  int i;
  //当k==m是表示当前全排列结束，输出这次排序
  //输出后会退出当前栈 然后继续排列输出
  if (k==m) {
    for ( i = 0; i <= m; i++) {
      printf("%d", List[i]);
    }
    printf("\n");
  } else {
    for ( i = k; i <= m; i++) {
      //依次将（ri）移动至待排列数组第一位置，即下表为k处
      Swap(List, k, i);
      //递归求Perm(Ri),构成（ri）Prem(Ri)
      //注意堆栈调用关系 形成层级调用
      Perm(List, k + 1, m);
      //将（ri）换回原位置
      Swap(List, k, i);
    }
  }
}

int main(int argc, char** argv) {
  int a[3] = {1, 2, 3};
  Perm(a, 0, 2);
  system("pause");
  return 0;
}
