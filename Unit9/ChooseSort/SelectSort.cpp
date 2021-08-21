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
//快速选择排序
void SelectSort(SqList* s) {
  int i, j, t;
  for (i = 1; i < s->length; i++) {
    for (j = i + 1, t = i; j <= s->length; j++) {
      if (s->r[t].key > s->r[j].key) {  //选取最小值
        t = j;
      }
    }
    s->r[0] = s->r[i];
    s->r[i] = s->r[t];
    s->r[t] = s->r[0];
  }
}

//堆排序
//大根堆调整 n是断点结点的位置 m是元素个数
void HeapAdjust(SqList* s, int n, int m) {
  int i, j;
  DataType tmp = s->r[n];
  i = n;
  for (j = i * 2; j <= m; j = j * 2) {             // i是双亲，j是子节点
    if (j < m && s->r[j].key < s->r[j + 1].key) {  // j<m是为了有右子树
      j++;
    }
    //这里有错误 不能用s->r[i].key >= s->r[j].key
    //因为在二层循环时，s.r[i]是没有被赋值成顶点值的，对比元素依旧会按照原来的那个子节点元素来
    //所以必须要用最开始记录的tmp的值来做对比
    if (tmp.key >= s->r[j].key) {
      break;
    } else {
      s->r[i].key = s->r[j].key;
      //把 孩子赋值给双亲之后 还要继续判断是否能把双亲插入到孩子结点上
      i = j;  //如此作为下一级循环的条件 在满足2j<len的条件下 i作为双亲
    }
  }
  //在循环结束后，我们得到了可插入的位置i，将最开始存储的元素tmp复制到该位置上
  //因为在终止条件的作用下 j=j*2,得到的j已经是子节点的下标了；
  s->r[i] = tmp;
}

//建立大根堆
void HeapBuild(SqList* s) {
  for (int i = s->length / 2; i > 0; i--) {
    HeapAdjust(s, i, s->length);
  }
}

//大根堆排序算法
void HeapSort(SqList* s) {
  int j;
  DataType tmp;
  //建立大根堆
  HeapBuild(s);
  //根据大根堆排序
  for (j = s->length; j > 0; j--) {
    //因为大根堆的顶点总是最大值，所以将顶点与最后的节点交换
    tmp = s->r[j];
    s->r[j] = s->r[1];
    s->r[1] = tmp;
    //下面在排序一趟 让1的位置又是最大支 注意长度要-1
    //因为那个位置已经填入了有序的最大值
    HeapAdjust(s, 1, j - 1);
  }
}

//大根堆插入元素 插入的元素的key
void HeapInsert(SqList* s, KeyType key) {
  HeapBuild(s);
  s->length++;
  s->r[s->length].key = key;  //将关键子存在堆的最后一个位置
  int t = s->length,i;
  DataType tmp ;
  for (i = t / 2; i > 0; i = i / 2) {  //这里i是双亲结点
    if (s->r[i].key > s->r[t].key) {  //双亲结点的值大于插入的结点
      break;
    } else {
      tmp = s->r[i];
      s->r[i] = s->r[t];
      s->r[t] = tmp;
      t = i;
    }
  }
}

//赋值操作 n为数组内元素的个数
void InitList(SqList* s, int a[], int n) {
  s->length = 0;
  s->r[0].key = 0;
  for (int i = 1; i <= n; i++) {
    s->r[i].key = a[i - 1];
    s->length++;
  }
}
//显示
void PrintfList(SqList s) {
  for (int i = 1; i <= s.length; i++) {
    printf("%d ", s.r[i].key);
  }
}

int main(int argc, char** argv) {
  SqList s, p;
  int a[10] = {0, 1, 8, 3, 7, 5, 6, 4, 2, 9};
  InitList(&s, a, 10);
  InitList(&p, a, 10);
  //直接插入排序
  SelectSort(&s);
  printf("简单选择排序结果为：");
  PrintfList(s);
  //堆排序
//  HeapSort(&p);
  HeapInsert(&p, 5);
  HeapSort(&p);
  printf("\n堆排序结果为：");
  PrintfList(p);
  system("pause");
  return 0;
}
