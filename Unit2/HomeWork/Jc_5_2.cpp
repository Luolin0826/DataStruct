#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SqListFunction.h"

//高效删除顺序表L在x~y之间的元素
void DelSpeNum(PSqeList S, int x, int y) {
  PSqeList q = InitList();
  int i, j, k = 0;
  int a[Maxsize];
  //将S中的元素给P复制一份之后将S清空
  for (i = 0; i < S->length; i++) {
    q->data[i] = S->data[i];
    q->length++;
    S->data[i] = NULL;
  }
  S->length = 0;
  //寻找值
  for (j = 0; j < q->length; j++) {
    if (q->data[j] <= x || q->data[i] >= y) {
      a[k++] = j;
    }
  }
  for (i = 0; i < k; i++) {  //注意这里的终止条件
    S->data[i] = q->data[a[i]];
    S->length++;
  }
}

//解法二更高效
void DelSpeNum_2(PSqeList S, int x, int y) {
  int i, k = 0;
  for (i = 0; i < S->length; i++) {
    if (S->data[i] > x && S->data[i] < y) {
      k++;
    } else {
      S->data[i - k] = S->data[i];
    }
  }
  S->length = S->length - k;
}

int main(int argc, char** argv) {
  PSqeList S = InitList();
  int a[15] = {1, 2, 5, 6, 4, 7, 8, 9, 0, 2, 5, 4, 1, 8, 7};
  for (int i = 0; i < 15; i++) {
    S->data[i] = a[i];
    S->length++;
  }
  //DelSpeNum(S, 5, 8);
  DelSpeNum_2(S, 5, 8);
  PrintfList(S);
  system("pause");
  return 0;
}
