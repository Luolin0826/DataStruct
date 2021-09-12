#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//���ַ�ƥ��
int StrIndex_bf(char* s, char* t) {
  int tlen = strlen(t);
  int i = 0, j = 0;
  while (s && j < tlen) {  //ע�� j < tlen ������
    if (s[i] == t[j]) {
      i++;
      j++;
    } else {
      i = i - j + 2;
      j = 0;
    }
  }
  if (s) {  //�ҵ���
    return i - j + 1;
  } else {
    return 0;
  }
}

// KMP�㷨
void GetNext(char* t, int* next) {  //ע��next��int����
  int tlen = strlen(t), i = 0, j = 0;
  next[0] = 0;  //ע������
  while (i < tlen - 1) {
    if (t[i] == t[j] || j == 0) {
      next[++i] = ++j;
    } else {
      j = next[j - 1];
    }
  }
}
int StrIndex_KMP(char* s, char* t) {
  int next[10];
  int tlen = strlen(t), slen = strlen(s);
  GetNext(t, next);
  int i = 0, j = 0;
  while (i < slen && j < tlen) {  //ע�� j < tlen ������
    if (s[i] == t[j] || j == 0) {
      i++;
      j++;
    } else {
      j = next[j];
    }
  }
  if (s) {  //�ҵ���
    return i - j + 1;
  } else {
    return 0;
  }
}

int main(int argc, char** argv) {
  char str1[10] = "maanshan";
  char str2[3] = "an";
  // int result = StrIndex_bf(str1, str2);
  int result = StrIndex_KMP(str1, str2);
  system("pause");
  return 0;
}
