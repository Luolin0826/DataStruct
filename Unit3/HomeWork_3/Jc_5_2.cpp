#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//定义数据结构
#define DataType int
#define MaxSize 20
typedef struct {
  DataType Data[MaxSize];
  int rear, front;
} SpecialQuenue, *PSpecialQuenue;
//初始化
PSpecialQuenue InitSpeQuenue() {
  PSpecialQuenue PQ;
  PQ = (PSpecialQuenue)malloc(sizeof(DataType) * MaxSize);
  PQ->rear = 0;   // rear指向对头结点的前一个位置
  PQ->front = 1;  //设置1为队头
  return PQ;
}
//入队操作
void In_SpeQuenue(PSpecialQuenue PQ, DataType x) {
  if (!PQ) {
    printf("队列不存在");
    return;
  } else {
    if (PQ->front == MaxSize - 1) {
      printf("队满");
      return;
    } else {
      PQ->Data[PQ->rear] = x;
      for (int i = PQ->front; i >= 0; i--) {
        PQ->Data[i + 1] = PQ->Data[i];
      }
      if (PQ->Data[PQ->front + 1] != NULL) {  //第一个元素特殊处理
        PQ->front++;
      }
    }
  }
}

//正确答案如下  上述答案错误  没理解到题目的意思
int In_SpeQuenue(DataType se[], int* rear, int* front, DataType x) {
  int m = MaxSize;
  if ((*rear + 1) % m == *front) {
    printf("队列已满！");
    return 0;
  } else {
    *rear = (*rear + 1) % m;  //队头指针向后移一位
    se[*rear] = x;
    return 1;
  }
}

int Out_SpeQuenue(DataType se[], int* rear, int* front, DataType* x) {
  int m = MaxSize;
  if (*rear = *front) {
    printf("队空!");
    return 0;
  } else {
    *front = *front + 1 % m;
    *x = se[*front];
    return 1;
  }
}

int main(int argc, char** argv) {
  PSpecialQuenue p = InitSpeQuenue();
  for (int i = 0; i < 10; i++) {
    In_SpeQuenue(p, i);
  }
  system("pause");
  return 0;
}
