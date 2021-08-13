#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Maxsize 100
typedef int KeyType;
//�ؼ��ֶ�
typedef struct {
  KeyType key;
} DataType;
typedef struct {
  DataType r[Maxsize];  //����Ԫ�صĴ洢�ռ�
  int length;
} Sqlist;

//˳�����
//���ҹؼ���k ����ҵ��� ����λ�ã����û�ҵ� ����-1
int SeqSeqrch(Sqlist S, KeyType K) {
  int i;
  for (i = 0; i < S.length; i++) {
    if (S.r[i].key == K) {
      return i;  //���ҳɹ�
    }
  }
  return -1;  //����ʧ��
}
//���ڱ��Ĳ��� �����ж������Ƿ�Խ�� Ч�ʸ�һ��
int SeqSearch_gai(Sqlist S, KeyType K) {
  int n, i = 0;
  n = S.length;
  S.r[n].key = K;  //����ǰ��ս �����������һ�� ��Ҫע��
  while (S.r[i].key != K) {  //ע�����������������Ա� �Ͳ����ڱ�����΢��һ��
    i++;
  }
  if (i == n) {  //����ʧ��
    return -1;
  } else {
    return i;  //���ҳɹ�
  }
}

//�۰���ҷ�
int BinSearch(Sqlist S, KeyType K) {
  int low, mid, high;  //��������
  low = 0;
  high = S.length - 1;
  while (low < high) {
    mid = (low + high) / 2;  //ȡ�м��
    if (S.r[mid].key == K) {
      return mid;
    } else if (S.r[mid].key < K) {  //���м���
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}
//�ݹ���۰����ʵ�� lowΪ��ʹ��λ highΪ��λ
int BinSearch_Recur(Sqlist S, KeyType K,int low,int high) {
  int  mid;  //��������
  while (low < high) {
    mid = (low + high) / 2;  //ȡ�м��
    if (S.r[mid].key == K) {
      return mid;
    } else if (S.r[mid].key < K) {  //���м���
      low = mid + 1;
      return (S, K, low, high);
    } else {
      high = mid - 1;
      return (S, K, low, high);
    }
  }
  return -1;
}



int main(int argc, char** argv) {
  system("pause");
  return 0;
}
