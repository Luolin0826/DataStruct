#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "StackFunction.h"

//��ֵת�� SΪ˳��ջ�����ָ�� NΪ������� r��ת���Ľ���
void Data_convert(PSeqStakck S, DataType N, DataType r) {
  DataType tmp=N;
  while (tmp/r!=0) {
    Push_SeqStack(S, tmp % r);//ѹ��ջ
    tmp /= r;//���㹫ʽ
  }
}

int main(int argc, char** argv) {
  PSeqStakck S;
  S = Init_SeqStack();
  Data_convert(S, 10, 2);
  Printf_SeqStack(S);
  system("pause");
  return 0;
}
