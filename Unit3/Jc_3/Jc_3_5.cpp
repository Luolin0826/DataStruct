#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

//ջ�ĵݹ�֮ȫ�����㷨 
//�������������ݽ���
void Swap(int a[], int i, int j) {
  int x = a[j];
  a[j] = a[i];
  a[i] = x;
}

//���������±�k~m��Ԫ�ص�ȫ����
void Perm(int List[], int k, int m) {
  int i;
  //��k==m�Ǳ�ʾ��ǰȫ���н���������������
  //�������˳���ǰջ Ȼ������������
  if (k==m) {
    for ( i = 0; i <= m; i++) {
      printf("%d", List[i]);
    }
    printf("\n");
  } else {
    for ( i = k; i <= m; i++) {
      //���ν���ri���ƶ��������������һλ�ã����±�Ϊk��
      Swap(List, k, i);
      //�ݹ���Perm(Ri),���ɣ�ri��Prem(Ri)
      //ע���ջ���ù�ϵ �γɲ㼶����
      Perm(List, k + 1, m);
      //����ri������ԭλ��
      Swap(List, k, i);
    }
  }
}

int main(int argc, char** argv) {
  int a[3] = {1, 2, 3};
  Perm(a, 0, 2);
  system("pause");
  return 0;
}
