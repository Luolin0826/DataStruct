#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StringFunction.h"
//��һ�����ϴ�����һ��������
//����������ʵ��
//��λ�ַ�
char SubStr(char* a, int i, int len) {
  int slen = StrLength(a);
  char c;
  if (len > slen - 1 + i) {
    printf("��������");
    return (0);
  } else {
    c = a[i-1];
  }
  return c;
}

void CheckChar_base(char* a, char* b, char* r) {
  int pos = 1, i, j;
  for (i = 1; i <= strlen(a); i++) {//ע�� i�������λ�� ��1��ʻ
    char m = SubStr(a, i, 1);
    j = StrIndex(b, &m);
    if (j==-1) {
      StrInsert(r, &m, pos);
      pos++;
    }
  }
}

//��һ������ ����ַ�
int Checkrep(char c, char* b) {
  int i = 0, blen = strlen(b);
  while (b[i] != '\0' && b[i] != c) {
    i++;
  }
  if (i < blen) {
    return 1;
  } else {
    return 0;
  }
}
//˳��ṹ����ʵ��
void CheckChar_sub(char* a, char* b, char* r) {
  int i = 0, j = 0;
  while (a[i] != '\0') {
    if (Checkrep(a[i], b)) {
      i++;
    } else {
      r[j++] = a[i++];
    }
  }
}

int main(int argc, char** argv) {
  char a[10] = "maanshan";
  char b[10] = "dasadn";
  char r[10] = "";
  CheckChar_base(a, b, r);
  system("pause");
  return 0;
}
