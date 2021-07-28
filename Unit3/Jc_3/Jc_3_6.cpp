#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//�ַ�������
void swap(char* str, int i, int j) {
  char temp = str[i];
  str[i] = str[j];
  str[j] = temp;
}
//�ַ�������
void CharConvert(char* str, int start, int end) {
  if ((end - start) < 1)  //�ж��Ƿ����
  {
    return;
  } else {
    swap(str, start, end);                 //�����ַ�����
    CharConvert(str, start + 1, end - 1);  //�����ݹ�
  }
}

int main(int argc, char** argv) {
  char str[] = "abcd";
  CharConvert(str, 0, 3);
  printf("%s", str);
  system("pause");
  return 0;
}
