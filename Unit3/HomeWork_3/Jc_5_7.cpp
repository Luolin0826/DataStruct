#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//�������е�n��Ԫ���������Сֵ ע��max��min��������Ƶ�����
void GetMaxMin(int* a, int n, int* max, int* min) {
  if (n == 1) {
    *max = a[0];
    *min = a[0];
  } else {
    //��n��Ԫ��ʱ���Ȼ��ǰn-1�����е����Ԫ��max����СԪ��min
    GetMaxMin(a, n - 1, max, min);
    //�����n��Ԫ�ش���max������n��Ԫ��������Ԫ��Ϊmax
    if (a[n - 1] > *max) {
      *max = a[n - 1];
    }
    //�����n��Ԫ��С��max������n��Ԫ������С��Ԫ��Ϊmin
    if (a[n - 1] < *min) {
      *min = a[n - 1];
    }
  }
}

int main(int argc, char** argv) {
  int a[5] = {5, 4, 7, 1, 3};
  int max[1];
  int min[1];
  GetMaxMin(a, 5, max, min);
  system("pause");
  return 0;
}
