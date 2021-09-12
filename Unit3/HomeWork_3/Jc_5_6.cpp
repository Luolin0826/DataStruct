#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DataType int
#define MaxSize 20
typedef struct {
  DataType data[MaxSize];
  int Stack0, Stack1;  //��ʶָʾ����ջ
  int length,Maxsize;          //Ԫ�ظ���
} UnionStack, *PUnionStack;
//��ʼ��
PUnionStack InitStack() {
  PUnionStack P;
  P = (UnionStack*)malloc(sizeof(UnionStack) * MaxSize);//ע��Sizeof��������� �����DataType�������ڴ�й©
  P->length = 0;
  P->Maxsize = MaxSize;
  P->Stack0 = -1;
  P->Stack1 = MaxSize - 1;
  return P;
}
//��ջ���� i=0��1����ͬ��ջ
void Push(PUnionStack P, int i, DataType x) {
  if (P->length <= MaxSize) {  //ջ�л��пռ�
    if (i == 0) {              //ͷ����ջ
      P->data[++P->Stack0] = x;
      P->length++;
    } else if (i == 1) {  //β����ջ
      P->data[P->Stack1--] = x;
      P->length++;
    } else {  //����
      printf("��������");
      return;
    }
  } else {
    printf("ջ������ջ�����ڣ�");
    return;
  }
}
//��ջ����
void Pop(PUnionStack P, int i) {
  if (P->length > 0) {  //ջ�д���Ԫ��
    if (i == 0) {
      P->Stack0--;  //�߼���ɾ��0ջ�е�Ԫ��
      P->length--;
    } else if (i == 1) {
      P->Stack1++;
      P->length--;
    } else {
      printf("��������");
      return;
    }
  } else {
    printf("ջ�ջ���ջ�����ڣ�");
    return;
  }
}

//�����ʾ
void Printf_Union(PUnionStack P) {
  int i, j;
  printf("\nջ0�е�Ԫ���У�");
  for (i = 0; i <= P->Stack0; i++) {
    printf("%d ", P->data[i]);
  }
  printf("\nջ1�е�Ԫ���У�");
  for (j = P->Maxsize-1; j > P->Stack1; j--) {
    printf("%d ", P->data[j]);
  }
}

int main(int argc, char** argv) {
  PUnionStack P = InitStack();
  for (int i = 0; i < 5; i++) {
    Push(P, 0, i);
  }
  for (int j = 8; j < 14; j++) {
    Push(P, 1, j);
  }
  Printf_Union(P);
//  Pop(P,0);
//  Pop(P, 1);
//  Printf_Union(P);
  system("pause");
  return 0;
}
