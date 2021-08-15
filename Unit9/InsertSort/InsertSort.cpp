#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 20
typedef int KeyType;
typedef struct {
  KeyType key;
} DataType;
typedef struct {
  DataType r[MAXSIZE + 1];  // r[0]闲置或充当前哨站
  int length;
} SqList;

//直接插入排序
void StraightInsertSort(SqList* s) {
  int i, j;
  for (i = 2; i <= s->length; i++) {
    s->r[0] = s->r[i];  //充当哨兵
    j = i - 1;
    while (s->r[0].key < s->r[j].key) {
      s->r[j + 1] = s->r[j];
      j--;
    }
    s->r[j + 1] = s->r[0];  //复制回去，注意这里的j+1，因为j指向的是被对比的位置
  }
}
//折半插入排序
void BinaryInsertSort(SqList* s) {
  int low, mid, high;
  for (int i = 2; i <= s->length; i++) {
    s->r[0] = s->r[i];  //设置哨兵
    low = 1;
    high = i - 1;  //注意high
    while (low <= high) {
      mid = (low + high) / 2;
      if (s->r[0].key >= s->r[mid].key) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    //将[low,i-1]的元素，全部向前移
    for (int j = i - 1; j >= high + 1; j--) {
      s->r[j + 1] = s->r[j];
    }
    s->r[low] = s->r[0];
  }
}
//希尔排序 步长gap
void ShellInsert(SqList* s, int gap) {
  int i, j, d;
  for (d = gap; d >= 1; d = d / 2) {  //对步长关系的确定
    for (i = d + 1; i <= s->length;i++) {  //对各表的遍历，这个i的定义很有意思，把表弄成临流的了
      if (s->r[i].key < s->r[i - d].key) {  //如果前面大于后面，需要交换了
        s->r[0].key = s->r[i].key;
        //下面的循环非常巧妙
        for (j = i - d; j > 0 && s->r[0].key < s->r[j].key; j -= d) {
          s->r[j + d].key = s->r[j].key;  //记录后移，查找插入的位置
        }
        //查找完之后，j的位置，是应该存放元素的位置了
        s->r[j + d].key = s->r[0].key;//这里是j+d是因为在for循环中为了判断j>0多用了一次j-=d；
      }
    }
  }
}

//赋值操作 n为数组内元素的个数
void InitList(SqList* s, int a[], int n) {
  s->length = 0;
  for (int i = 1; i <= n; i++) {
    s->r[i].key = a[i];
    s->length++;
  }
}
//显示
void PrintfList(SqList s) {
  KeyType k;
  for (int i = 1; i <= s.length; i++) {
    k = s.r[i].key;
    printf("%d ", k);
  }
}

int main(int argc, char** argv) {
  SqList s, q, p;
  int a[10] = {0, 1, 8, 3, 7, 5, 6, 4, 2, 9};
  InitList(&s, a, 10);
  InitList(&p, a, 10);
  InitList(&q, a, 10);
  //直接插入排序
  StraightInsertSort(&s);
  printf("直接插入排序结果为：");
  PrintfList(s);
  //折半插入排序
  BinaryInsertSort(&p);
  printf("\n折半插入排序结果为：");
  PrintfList(p);
  //哈希
  ShellInsert(&q, 4);
  printf("\n哈希排序结果为：");
  PrintfList(q);
  system("pause");
  return 0;
}
