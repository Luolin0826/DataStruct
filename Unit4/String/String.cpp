#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxSize 256

//�󴮳�
int StrLength(char* s) {
  int i = 0;
  while (s[i] != '\0') {
    i++;
  }
  return i;
}
//����ֵ ��S2�е����ݸ�s1��s1��ԭ�������ݱ����ǵ�
int StrAssign(char* s1, char* s2) {
  int i = 0;
  while (s2[i] != '\0') {
    s1[i] = s2[i];
    i++;
  }
  return 1;
}
//���Ӳ��� ��s1��s2���ӳ�һ���´�s ��s<s1+s2
int StrConcat(char* s1, char* s2, char* s) {
  int i = 0, j = 0, len1, len2;
  len1 = StrLength(s1);
  len2 = StrLength(s2);
  if (len1 + len2 > MaxSize) {
    printf("�ڴ治��");
    return 0;
  }
  while (s1[i] != '\0') {
    s[i] = s1[i];
    i++;
  }
  while (s2[j] != '\0') {
    s[i] = s2[j];
    i++;
    j++;
  }
  s[i] = '\0';
  return 1;
}
//���Ӵ�
//����һ���´�t��t�ǴӴ�s�ĵ�i���ַ����ȿ�ʼ�ĳ���Ϊlen���ִ���len=0ʱ�õ��Ŀմ�
int StrSub(char* t, char* s, int i, int len) {
  int slen = StrLength(s);
  if (len > slen - 1 + i) {
    printf("��������");
    return (0);
  } else {
    for (int j = 0; j < len; j++) {
      t[j] = s[i + j - 1];
    }
    t[len] = '\0';
  }
  return (1);
}
//���Ƚ� s1>s2 ���в�ͬ ����Ҫ�Ƚ�Ԫ�ص�����Ԫ�ض���ͬ �����ͬ���ط�0
//����ͬ����0
int StrCmp(char* s1, char* s2) {
  int i = 0;
  while (s1[i] == s2[i] && s1[i] != '\0') {
    i++;
  }
  return (s1[i] == s2[2]);
}
//�ִ���λ ���Ӵ�t��s���״γ��ֵ�λ��
int StrIndex(char* s, char* t) {
  int tlen = StrLength(t);
  int slen = StrLength(s);
  if (slen < 0 || tlen < 0) {
    printf("�ַ�������");
    return (0);
  } else {
    int i = 0, j;
    char rt[5];
    while (s[i] != '\0' && (i + tlen) <= slen) {
      j = i + 1;
      StrSub(rt, s, j, tlen);
      if (StrCmp(rt, t)) {
        return j;
      } else {
        i++;
      }
    }
    if (s[i] == '\0') {
      return -1;
    }
  }
}

//������ ����t���뵽��s�ĵ�i���ַ��ϣ�s�Ĵ������仯
int StrInsert(char* s, char* t, int i) {
  int slen = StrLength(s);
  int tlen = StrLength(t);
  if (i <= 0 ||
      i > slen + 1) {  //����Ҫע���� i>slen+1,Ϊ���Ǳ���Ҫ���뵽���һ���ַ���
    printf("��������");
    return 0;
  } else {
    for (int j = slen - 1; j >= i - 1; j--) {  //����
      s[j + tlen] = s[j];
    }
    for (int j = 0; j < tlen; j++) {
      s[i - 1] = t[j];
      i++;
    }
  }
  s[slen + tlen] = '\0';
  return (1);
}
//��ɾ���ַ�����ɾ���ӵ�i���ַ�����ʼ�ĳ���Ϊlen���ִ���s�Ĵ��ı�
int StrDelete(char* s, int i, int len) {
  int slen = StrLength(s);
  if (i <= 0 || i > slen) {
    printf("����i����");
    return (0);
  } else if (len < 0 || len > slen - i + 1) {
    printf("����len����");
    return (0);
  } else {
    for (int j = i + len - 1; j < slen; j++) {  //�˴������Ժ� Ҫע���﷨
      s[j - len] = s[j];
    }
    s[slen - len] = '\0';  //һ���ǵ�Ҫ�ӽ�β��ʶ��������������
  }
  return (1);
}
//��������� ��r�����s�����г��ֵ���t��ȵĲ��ص��Ӵ���s�Ĵ��ı�
int StrRep(char* s, char* t, char* r) {
  int i = 0, j;  // j��ʾλ��
  int tlen = StrLength(t);
  int slen = StrLength(s);
  int rlen = StrLength(r);
  char rt[5];
  if (slen < 0 || tlen < 0 || rlen < 0) {
    printf("�ַ�������");
    return (0);
  } else {
    while (s[i] != '\0' && (i + rlen) <= slen) {
      j = i + 1;
      StrSub(rt, s, j, tlen);
      if (StrCmp(rt, t)) {
        StrDelete(s, j, tlen);
        StrInsert(s, r, j);
        i = i + tlen;
      } else {
        i++;
      }
    }
    return (1);
  }
}
//��ӡ��
void StrPrintf(char* s) {
  int i = 0;
  while (s[i] != '\0') {
    printf("%c", s[i]);
    i++;
  }
}

int main(int argc, char** argv) {
  char s1[255] = "welcome ";
  char s2[255] = "maanshan";
  char s[255] = "";
  char bth[10] = "an";
  char th[10] = "TH";
  int s1len = StrLength(s1);
  printf("s1�ĳ�����%d\n", s1len);
  StrConcat(s1, s2, s);
  printf("ƴ��֮��Ϊ��");
  StrPrintf(s);
  printf("\n");
  int result = StrCmp(s1, s2);
  printf("���߱Ƚ�%d\n", result);
  StrAssign(s1, s2);
  printf("��ֵs1֮��Ϊ��");
  StrPrintf(s1);
  printf("\n");
  StrSub(s, s1, 2, 3);
  printf("��ȡ����ַ���sΪ");
  StrPrintf(s);
  printf("\n");
  StrInsert(s1, s, 3);
  printf("��s���뵽s1�ĵ������ַ�Ϊ");
  StrPrintf(s1);
  printf("\n");

  int pos = StrIndex(s1, bth);
  printf("s��an��λ��Ϊ");
  printf("%d", pos);
  printf("\n");

  StrDelete(s1, 3, 3);
  printf("��s��s1ɾ����Ϊ");
  StrPrintf(s1);
  printf("\n");
  StrRep(s1, bth, th);
  printf("�滻an���s1��");
  StrPrintf(s1);
  printf("\n");
  system("pause");
  return 0;
}
