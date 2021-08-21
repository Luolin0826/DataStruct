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

//ֱ�Ӳ�������
void StraightInsertSort(SqList* s) {
  int i, j;
  for (i = 2; i <= s->length; i++) {
    s->r[0] = s->r[i];  //�䵱�ڱ�
    j = i - 1;
    while (s->r[0].key < s->r[j].key) {
      s->r[j + 1] = s->r[j];
      j--;
    }
    s->r[j + 1] = s->r[0];  //���ƻ�ȥ��ע�������j+1����Ϊjָ����Ǳ��Աȵ�λ��
  }
}
//�۰��������
void BinaryInsertSort(SqList* s) {
  int low, mid, high;
  for (int i = 2; i <= s->length; i++) {
    s->r[0] = s->r[i];  //�����ڱ�
    low = 1;
    high = i - 1;  //ע��high
    while (low <= high) {
      mid = (low + high) / 2;
      if (s->r[0].key >= s->r[mid].key) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    //��[low,i-1]��Ԫ�أ�ȫ����ǰ��
    for (int j = i - 1; j >= high + 1; j--) {
      s->r[j + 1] = s->r[j];
    }
    s->r[low] = s->r[0];
  }
}
//ϣ������ ����gap
void ShellInsert(SqList* s, int gap) {
  int i, j, d;
  for (d = gap; d >= 1; d = d / 2) {  //�Բ�����ϵ��ȷ��
    for (i = d + 1; i <= s->length;i++) {  //�Ը���ı��������i�Ķ��������˼���ѱ�Ū����������
      if (s->r[i].key < s->r[i - d].key) {  //���ǰ����ں��棬��Ҫ������
        s->r[0].key = s->r[i].key;
        //�����ѭ���ǳ�����
        for (j = i - d; j > 0 && s->r[0].key < s->r[j].key; j -= d) {
          s->r[j + d].key = s->r[j].key;  //��¼���ƣ����Ҳ����λ��
        }
        //������֮��j��λ�ã���Ӧ�ô��Ԫ�ص�λ����
        s->r[j + d].key = s->r[0].key;//������j+d����Ϊ��forѭ����Ϊ���ж�j>0������һ��j-=d��
      }
    }
  }
}

//��ֵ���� nΪ������Ԫ�صĸ���
void InitList(SqList* s, int a[], int n) {
  s->length = 0;
  for (int i = 1; i <= n; i++) {
    s->r[i].key = a[i];
    s->length++;
  }
}
//��ʾ
void PrintfList(SqList s) {
  KeyType k;
  for (int i = 1; i <= s.length; i++) {
    k = s.r[i].key;
    printf("%d ", k);
  }
}

int main(int argc, char** argv) {
  SqList s, q, p;
  int a[10] = {0, 1, 8, 3, 7, 5, 6, 4, 2, 9};
  InitList(&s, a, 10);
  InitList(&p, a, 10);
  InitList(&q, a, 10);
  //ֱ�Ӳ�������
  StraightInsertSort(&s);
  printf("ֱ�Ӳ���������Ϊ��");
  PrintfList(s);
  //�۰��������
  BinaryInsertSort(&p);
  printf("\n�۰����������Ϊ��");
  PrintfList(p);
  //��ϣ
  ShellInsert(&q, 4);
  printf("\n��ϣ������Ϊ��");
  PrintfList(q);
  system("pause");
  return 0;
}
