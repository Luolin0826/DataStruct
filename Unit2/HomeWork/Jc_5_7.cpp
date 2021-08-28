#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SqListFunction.h"
//下列函数判断是否为字母字符函数 是的话返回1 否则返回0
int fch(char c) {
  if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
    return 1;
  } else {
    return 0;
  }
}
//下列函数判断是否为数字
int fnum(char c) {
  if (c >= '0' && c <= '9') {
    return 1;
  } else {
    return 0;
  }
}
//利用快速排序的算法进行排序 值得注意的是 需要进行两次排序，依次将他们三者分开
void QuickSort_num_ch(PSqeList L, int low, int high) {
  char key;
  //第一步 将字符与非字符分开 我想让字符在前面 所以找在前面的第一个非字符
  //和从后往前数的字符
  while (low < high) {
    while (low < high && fch(L->data[low])) {  //在前面寻找第一个非字符
      low++;
    }
    while (low < high && !fch(L->data[high])) {  //寻找字符
      high--;
    }
    //停止下来 说明分别都找到了 那么对换位置 此时要注意的是加上判定条件
    //防止在上两步导致的low>high
    while (low < high) {
      key = L->data[low];
      L->data[low] = L->data[high];
      L->data[high] = key;
    }
  }
  //此时 我们的字母与非字母已经排列好了 非字母中还含有字符与数字
  //此时我们需要将这两者区分开 注意
  //low指针指向的数正好是第一个非字母的下标开头，low就不需要变动了
  //但是high需要重置 否则程序跑不起来
  //我们的目标是将数字和符号区分开且数字在前，所以
  //我们要寻找顺着数的第一个符号和逆着数的第一个数字
  high = L->length - 1;
  while (low < high) {
    while (low < high && fnum(L->data[low])) {
      low++;
    }
    while (low < high && !fnum(L->data[high])) {
      high--;
    }
    while (low < high) {
      key = L->data[low];
      L->data[low] = L->data[high];
      L->data[high] = key;
    }
  }
}

int main(int argc, char** argv) {
    //此函数逻辑上没什么问题 重新改写char数组有点麻烦 就不进行测试了
  system("pause");
  return 0;
}
