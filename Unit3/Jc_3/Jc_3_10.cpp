#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "QueueFunction.h"

//打印杨辉三角 n表示打印的行数
int YangHui(int n) {
  int s = 0, i;
  PSqeQueue Q = Init_SeqQueue();  //初始化一个栈
  In_SeqQueue(Q, 1);              //插入第一行的元素
  In_SeqQueue(Q, 1);
  for (i = 1; i <= n; i++) {//注意是从1开始的
    printf("\n");
    for (int k = 0; k < 40-4*i; k+=2) {//位置控制 记住就行
      printf(" ");
    }
    In_SeqQueue(Q, 0);//每一行最后加上个0
    for (int j = 1; j <= i + 2; j++) {//小于等于
      int t;
      Out_SeqQueue(Q, &t);
      In_SeqQueue(Q, s + t);
      s = t;
      if (j != i + 2) {  //不是最后一个元素的时候
        printf("%4d",s);//注意位置
      }
    }
  }
  printf("\n");
  Destroy_SeqQueue(&Q);
  return (1);
}

int main(int argc, char** argv) {
  int n = 5;
  YangHui(n);
  system("pause");
  return 0;
}
