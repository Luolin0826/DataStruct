#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�ж��Ƿ�������
int IsNum(char c) {  //ע��û���Ǻ�
  if ('0' <= c && c <= '9') {
    return 1;
  } else {
    return 0;
  }
}
int CountInt(char* s, int a[]) {
  int i = 0, j = 0;
  while (s[j] != '\0') {
    if (IsNum(s[j])) {  //������ ����������������ƴ������
      int num = 0;      //��ʼ��
      while (IsNum(s[j])) {
        num = num * 10 + s[j] - '0';
        j++;
      }
      a[i++] = num;
    } else {
      j++;
    }
  }
  for (int m = 0; m < i; m++) {  //���
    printf("��%d������%d\n", m + 1, a[m]);
  }
  return i;  //����
}

int main(int argc, char** argv) {
  char str[40] = "12m34a4545a56656ns56h34a235n645";
  int a[10];
  int result = CountInt(str, a);
  system("pause");
  return 0;
}
