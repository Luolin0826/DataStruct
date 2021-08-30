#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SqListFunction.h"
//���к����ж��Ƿ�Ϊ��ĸ�ַ����� �ǵĻ�����1 ���򷵻�0
int fch(char c) {
  if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
    return 1;
  } else {
    return 0;
  }
}
//���к����ж��Ƿ�Ϊ����
int fnum(char c) {
  if (c >= '0' && c <= '9') {
    return 1;
  } else {
    return 0;
  }
}
//���ÿ���������㷨�������� ֵ��ע����� ��Ҫ���������������ν��������߷ֿ�
void QuickSort_num_ch(PSqeList L, int low, int high) {
  char key;
  //��һ�� ���ַ�����ַ��ֿ� �������ַ���ǰ�� ��������ǰ��ĵ�һ�����ַ�
  //�ʹӺ���ǰ�����ַ�
  while (low < high) {
    while (low < high && fch(L->data[low])) {  //��ǰ��Ѱ�ҵ�һ�����ַ�
      low++;
    }
    while (low < high && !fch(L->data[high])) {  //Ѱ���ַ�
      high--;
    }
    //ֹͣ���� ˵���ֱ��ҵ��� ��ô�Ի�λ�� ��ʱҪע����Ǽ����ж�����
    //��ֹ�����������µ�low>high
    while (low < high) {
      key = L->data[low];
      L->data[low] = L->data[high];
      L->data[high] = key;
    }
  }
  //��ʱ ���ǵ���ĸ�����ĸ�Ѿ����к��� ����ĸ�л������ַ�������
  //��ʱ������Ҫ�����������ֿ� ע��
  //lowָ��ָ����������ǵ�һ������ĸ���±꿪ͷ��low�Ͳ���Ҫ�䶯��
  //����high��Ҫ���� ��������ܲ�����
  //���ǵ�Ŀ���ǽ����ֺͷ������ֿ���������ǰ������
  //����ҪѰ��˳�����ĵ�һ�����ź��������ĵ�һ������
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
    //�˺����߼���ûʲô���� ���¸�дchar�����е��鷳 �Ͳ����в�����
  system("pause");
  return 0;
}
