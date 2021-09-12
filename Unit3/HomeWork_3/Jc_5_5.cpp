#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StackFunction.h"

int IsSingal(char ch) {
  if (ch == '(') {
    return 1;
  } else {
    return 0;
  }
}

void MatchSingal(char* Str) {
  char ch, tmp;
  PSeqStack S = Init_SeqStack();
  ch = *Str++;
  while (ch != '\0') {
    if (IsSingal(ch)) {  //�����Ž�ջ
      Push_SeqStack(S, ch);
    } else if (ch == ')') {
      if (!Pop_SeqStcak(S, &tmp)) {//����������Ҫ
        printf("ƥ��ʧ�ܣ�");
        return;//ֱ������ѭ�� �������ʾ�������
      }
    }
    ch = *Str++;
  }
  if (!Empty_SeqStack(S)) {
    printf("ƥ��ʧ�ܣ�");
  } else {
    printf("ƥ��ɹ���");
  }
}

int main(int argc, char** argv) {
  char str[MaxSize] = {"((3+2)*5))"};
  MatchSingal(str);
  system("pause");
  return 0;
}
