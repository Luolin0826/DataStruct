#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 20
typedef int KeyType;
typedef struct {
  KeyType key;
} DataType;
typedef struct {
  DataType r[MAXSIZE + 1];  // r[0]���û�䵱ǰ��վ
  int length;
} SqList;
//����ѡ������
void SelectSort(SqList* s) {
  int i, j, t;
  for (i = 1; i < s->length; i++) {
    for (j = i + 1, t = i; j <= s->length; j++) {
      if (s->r[t].key>s->r[j].key) {//ѡȡ��Сֵ
        t = j;
      }
    }
    s->r[0] = s->r[i];
    s->r[i] = s->r[t];
    s->r[t] = s->r[0];
  }
}

//������
//���������




//��ֵ���� nΪ������Ԫ�صĸ���
void InitList(SqList* s, int a[], int n) {
  s->length = 0;
  s->r[0].key = 0;
  for (int i = 1; i <= n; i++) {
    s->r[i].key = a[i - 1];
    s->length++;
  }
}
//��ʾ
void PrintfList(SqList s) {
  for (int i = 1; i <= s.length; i++) {
    printf("%d ", s.r[i].key);
  }
}

int main(int argc, char** argv) {
  SqList s, p;
  int a[10] = {0, 1, 8, 3, 7, 5, 6, 4, 2, 9};
  InitList(&s, a, 10);
  InitList(&p, a, 10);
  //ֱ�Ӳ�������
  SelectSort(&s);
  printf("��ѡ��������Ϊ��");
  PrintfList(s);
  system("pause");
  return 0;
}
