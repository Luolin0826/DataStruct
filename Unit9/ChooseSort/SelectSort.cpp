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
      if (s->r[t].key > s->r[j].key) {  //ѡȡ��Сֵ
        t = j;
      }
    }
    s->r[0] = s->r[i];
    s->r[i] = s->r[t];
    s->r[t] = s->r[0];
  }
}

//������
//����ѵ��� n�Ƕϵ����λ�� m��Ԫ�ظ���
void HeapAdjust(SqList* s, int n, int m) {
  int i, j;
  DataType tmp = s->r[n];
  i = n;
  for (j = i * 2; j <= m; j = j * 2) {             // i��˫�ף�j���ӽڵ�
    if (j < m && s->r[j].key < s->r[j + 1].key) {  // j<m��Ϊ����������
      j++;
    }
    //�����д��� ������s->r[i].key >= s->r[j].key
    //��Ϊ�ڶ���ѭ��ʱ��s.r[i]��û�б���ֵ�ɶ���ֵ�ģ��Ա�Ԫ�����ɻᰴ��ԭ�����Ǹ��ӽڵ�Ԫ����
    //���Ա���Ҫ���ʼ��¼��tmp��ֵ�����Ա�
    if (tmp.key >= s->r[j].key) {
      break;
    } else {
      s->r[i].key = s->r[j].key;
      //�� ���Ӹ�ֵ��˫��֮�� ��Ҫ�����ж��Ƿ��ܰ�˫�ײ��뵽���ӽ����
      i = j;  //�����Ϊ��һ��ѭ�������� ������2j<len�������� i��Ϊ˫��
    }
  }
  //��ѭ�����������ǵõ��˿ɲ����λ��i�����ʼ�洢��Ԫ��tmp���Ƶ���λ����
  //��Ϊ����ֹ������������ j=j*2,�õ���j�Ѿ����ӽڵ���±��ˣ�
  s->r[i] = tmp;
}

//���������
void HeapBuild(SqList* s) {
  for (int i = s->length / 2; i > 0; i--) {
    HeapAdjust(s, i, s->length);
  }
}

//����������㷨
void HeapSort(SqList* s) {
  int j;
  DataType tmp;
  //���������
  HeapBuild(s);
  //���ݴ��������
  for (j = s->length; j > 0; j--) {
    //��Ϊ����ѵĶ����������ֵ�����Խ����������Ľڵ㽻��
    tmp = s->r[j];
    s->r[j] = s->r[1];
    s->r[1] = tmp;
    //����������һ�� ��1��λ���������֧ ע�ⳤ��Ҫ-1
    //��Ϊ�Ǹ�λ���Ѿ���������������ֵ
    HeapAdjust(s, 1, j - 1);
  }
}

//����Ѳ���Ԫ�� �����Ԫ�ص�key
void HeapInsert(SqList* s, KeyType key) {
  HeapBuild(s);
  s->length++;
  s->r[s->length].key = key;  //���ؼ��Ӵ��ڶѵ����һ��λ��
  int t = s->length,i;
  DataType tmp ;
  for (i = t / 2; i > 0; i = i / 2) {  //����i��˫�׽��
    if (s->r[i].key > s->r[t].key) {  //˫�׽���ֵ���ڲ���Ľ��
      break;
    } else {
      tmp = s->r[i];
      s->r[i] = s->r[t];
      s->r[t] = tmp;
      t = i;
    }
  }
}

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
  //������
//  HeapSort(&p);
  HeapInsert(&p, 5);
  HeapSort(&p);
  printf("\n��������Ϊ��");
  PrintfList(p);
  system("pause");
  return 0;
}
