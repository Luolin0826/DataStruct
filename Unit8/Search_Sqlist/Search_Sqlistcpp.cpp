#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Maxsize 100
typedef int KeyType;
//关键字段
typedef struct {
  KeyType key;
} DataType;
typedef struct {
  DataType r[Maxsize];  //数据元素的存储空间
  int length;
} Sqlist;

//顺序查找
//查找关键字k 如果找到了 返回位置，如果没找到 返回-1
int SeqSeqrch(Sqlist S, KeyType K) {
  int i;
  for (i = 0; i < S.length; i++) {
    if (S.r[i].key == K) {
      return i;  //查找成功
    }
  }
  return -1;  //查找失败
}
//带哨兵的查找 无需判断数组是否越界 效率高一点
int SeqSearch_gai(Sqlist S, KeyType K) {
  int n, i = 0;
  n = S.length;
  S.r[n].key = K;  //设置前哨战 这里和王道不一样 需要注意
  while (S.r[i].key != K) {  //注意这里依次向后遍历对比 和不带哨兵的略微不一致
    i++;
  }
  if (i == n) {  //查找失败
    return -1;
  } else {
    return i;  //查找成功
  }
}

//折半查找法
int BinSearch(Sqlist S, KeyType K) {
  int low, mid, high;  //定义索引
  low = 0;
  high = S.length - 1;
  while (low < high) {
    mid = (low + high) / 2;  //取中间点
    if (S.r[mid].key == K) {
      return mid;
    } else if (S.r[mid].key < K) {  //比中间点大
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}
//递归的折半查找实现 low为起使低位 high为高位
int BinSearch_Recur(Sqlist S, KeyType K,int low,int high) {
  int  mid;  //定义索引
  while (low < high) {
    mid = (low + high) / 2;  //取中间点
    if (S.r[mid].key == K) {
      return mid;
    } else if (S.r[mid].key < K) {  //比中间点大
      low = mid + 1;
      return (S, K, low, high);
    } else {
      high = mid - 1;
      return (S, K, low, high);
    }
  }
  return -1;
}



int main(int argc, char** argv) {
  system("pause");
  return 0;
}
