#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StackFunction.h"

int IsNum(char s) {
  if ('0' <= s && s <= '9') {  //����ҵĹ�ϵ�㷴�� ��Ӧ�ã�
    return 1;
  } else {
    return 0;
  }
}

void GetResult_BoLan(char* str) {
  double pre, hind, result = 0;  //��������,result�ĳ�ʼ��Ҫע��
  char ch;
  int i = 0;
  if (!str) {
    printf("�ַ��������� ");
    return;
  } else {
    PSeqStack S = Init_SeqStack();
    while (str[i] != '$') {
      ch = str[i];
      if (IsNum(ch)) {
        Push_SeqStack(S, ch - '0');  //���� �ַ�����ջת����double��ʽ
      } else {
        Pop_SeqStcak(S, &hind);  //�ȳ�ջ���Ǻ����
        Pop_SeqStcak(S, &pre);   //���ջ����ǰ��
        switch (ch) {
          case '+':
            result = pre + hind;  //ע���������Ĳ���˳�򣡣���
            break;
          case '-':
            result = pre - hind;
            break;
          case '*':
            result = pre * hind;
            break;
          case '/':
            result = pre / hind;
            break;
          default:
            printf("���ݱ�����");
            break;
        }
        Push_SeqStack(S, result);
      }
      i++;
    }
    GetTop_SeqStack(S, &result);
    Destroy_SeqStack(&S);
    printf("%f", result);
  }
}

int main(int argc, char** argv) {
  char ch[10] = {'1', '4', '+', '3', '*', '5', '6', '/', '+', '$'};
  GetResult_BoLan(ch);
  system("pause");
  return 0;
}
