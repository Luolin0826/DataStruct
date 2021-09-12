#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//�������ݽṹ
#define DataType int
#define MaxSize 20
typedef struct {
  DataType Data[MaxSize];
  int rear, front;
} SpecialQuenue, *PSpecialQuenue;
//��ʼ��
PSpecialQuenue InitSpeQuenue() {
  PSpecialQuenue PQ;
  PQ = (PSpecialQuenue)malloc(sizeof(DataType) * MaxSize);
  PQ->rear = 0;   // rearָ���ͷ����ǰһ��λ��
  PQ->front = 1;  //����1Ϊ��ͷ
  return PQ;
}
//��Ӳ���
void In_SpeQuenue(PSpecialQuenue PQ, DataType x) {
  if (!PQ) {
    printf("���в�����");
    return;
  } else {
    if (PQ->front == MaxSize - 1) {
      printf("����");
      return;
    } else {
      PQ->Data[PQ->rear] = x;
      for (int i = PQ->front; i >= 0; i--) {
        PQ->Data[i + 1] = PQ->Data[i];
      }
      if (PQ->Data[PQ->front + 1] != NULL) {  //��һ��Ԫ�����⴦��
        PQ->front++;
      }
    }
  }
}

//��ȷ������  �����𰸴���  û��⵽��Ŀ����˼
int In_SpeQuenue(DataType se[], int* rear, int* front, DataType x) {
  int m = MaxSize;
  if ((*rear + 1) % m == *front) {
    printf("����������");
    return 0;
  } else {
    *rear = (*rear + 1) % m;  //��ͷָ�������һλ
    se[*rear] = x;
    return 1;
  }
}

int Out_SpeQuenue(DataType se[], int* rear, int* front, DataType* x) {
  int m = MaxSize;
  if (*rear = *front) {
    printf("�ӿ�!");
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
