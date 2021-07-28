#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "QueueFunction.h"

//��һ����������ѭ��kλ
//aΪ���� nΪ�����λ�� kΪǨ�Ƶĸ��� �ɹ�����1 ʧ�ܷ���0
int Array_LeftCircle_Move(int a[],DataType n, DataType k) {
  if (!a||k>=n||k<0) {
    printf("��������");
    return (0);
  }
  PSqeQueue Q = Init_SeqQueue();
  for (int i = 0; i < n; i++) {//�͵���������ȥ
    In_SeqQueue(Q, a[i]);
  }
  for (int i = k; i < n; i++) {//����������
    a[i-k] = a[i];
  }
  for (int i = n-k; i < n; i++) {//ƴ��һ��
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
