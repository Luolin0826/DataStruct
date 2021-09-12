#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSTRLEN 80  //��255��Χ�ڶ�����󴮳�(255Ϊ1���ֽ�)
typedef char SString[MAXSTRLEN + 1];  //λ��0��Ŵ��ĳ���

//���ַ�ƥ�� ƥ�䵽������ʼλ�� ûƥ�䵽����-1
int Strindex_bf(SString s, SString t) {
  int i = 1, j = 1;
  while (i <= s[0] && j <= t[0]) {  //û�����յ�
    if (s[i] == t[j]) {
      i++;
      j++;
    } else {
      i = i - j + 2;
      j = 1;
    }
  }
  if (j > t[0]) {  //ƥ�䵽�յ���
    return (i - t[0]);
  } else {
    return -1;
  }
}

//��ȡnext����
void GetNext(SString s, int next[]) {
  int i = 1, j = 0;
  next[1] = 0;
  while (i < s[0]) {
    if (s[i] == s[j] || j == 0) {
      next[++i] = ++j;
    } else {
      j = next[j];
    }
  }
}

// KMP ƥ�䵽������ʼλ�� ûƥ�䵽����-1
int Strindex_kmp(SString s, SString t) {
  int i = 1, j = 1;
  int next[20];
  GetNext(t, next);
  while (i <= s[0] && j <= t[0]) {  //û�����յ�
    if (s[i] == t[j] || j == 0) {   //�ǵô˴�Ҫ����j==0
      i++;
      j++;
    } else {
      j = next[j];
    }
  }
  if (j > t[0]) {  //ƥ�䵽�յ���
    return (i - t[0]);
  } else {
    return -1;
  }
}
//�󴮳�
int StrLength(char* s) {
  int i = 0;
  while (s[i] != '\0') {
    i++;
  }
  return i;
}
//����ֵ
void StrAssign(SString T, char* chars) {
  int i;
  if (StrLength(chars) > MAXSTRLEN) {
    for (i = 1; i <= MAXSTRLEN; ++i)
      T[i] = *(chars + i - 1);
    T[0] = MAXSTRLEN;
  } else {
    T[0] = StrLength(chars);  // ��ʱT[0]�������int���͵�����,��ӡ%sʱ�޷���ʾ
    for (i = 1; i <= MAXSTRLEN; ++i)
      T[i] = *(chars + i - 1);
  }
}

int main(int argc, char** argv) {
  SString S1, T;
  char str1[20] = "maanshanxueyuan";
  char str2[13] = "xxyxy";
  StrAssign(S1, str1);
  StrAssign(T, str2);
  /*
  int bf = Strindex_bf(S1, T);
    printf("bfƥ��%d\n", bf);
  */

  int kmp = Strindex_kmp(S1, T);
  printf("kmpƥ��%d\n", kmp);
  system("pause");
  return 0;
}
