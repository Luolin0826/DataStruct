#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "QueueFunction.h"

//将一串数组向左循环k位
//a为数组 n为数组的位数 k为迁移的个数 成功返回1 失败返回0
int Array_LeftCircle_Move(int a[],DataType n, DataType k) {
  if (!a||k>=n||k<0) {
    printf("参数错误！");
    return (0);
  }
  PSqeQueue Q = Init_SeqQueue();
  for (int i = 0; i < n; i++) {//送到队列里面去
    In_SeqQueue(Q, a[i]);
  }
  for (int i = k; i < n; i++) {//操作下数组
    a[i-k] = a[i];
  }
  for (int i = n-k; i < n; i++) {//拼接一下
    Out_SeqQueue(Q, &a[i]);  
  }
  Destroy_SeqQueue(&Q);
  return (1);
}


int main(int argc, char** argv) {
  int a[] = {1, 2, 3, 4, 5, 6};
  Array_LeftCircle_Move(a, 6, 3);
  for (int i = 0; i < 6; i++) {
    printf("%d", a[i]);
  }
  system("pause");
  return 0;
}
