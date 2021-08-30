#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StackFunction.h"

//��ֵת�� SΪ˳��ջ�����ָ�� NΪ������� r��ת���Ľ���
void Data_convert(PSeqStack S, DataType N, DataType r) {
  DataType tmp = N;
  while (tmp != 0) {
    Push_SeqStack(S, tmp % r);  //ѹ��ջ
    tmp = tmp / r;              //���㹫ʽ
  }
}

int main(int argc, char** argv) {
  PSeqStack S;
  S = Init_SeqStack();
  Data_convert(S, 50, 8);
  Printf_SeqStack(S);
  Destroy_SeqStack(&S);
  system("pause");
  return 0;
}
