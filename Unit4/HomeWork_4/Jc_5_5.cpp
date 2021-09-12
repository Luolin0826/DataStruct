#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//��ĸƵ�ȱ�
//�ж��Ǵ�д����Сд���������ַ� ����Ǵ�д ����ch-65 Сд ����ch-97
//�����ַ�����-1
int PredictCh(char ch) {
  if ('A' <= ch && ch <= 'Z') {
    return ch - 65;
  } else if ('a' <= ch && ch <= 'z') {
    return ch - 97;
  } else {
    return -1;
  }
}
// s�Ǳ�ͳ���ַ���f��Ƶ�ȱ�
void frequency(char* s) {
  int f[26] = {}, i = 0, tmp;  //ע��f�ĳ�ʼ����ʽ
  while (s[i] != '\0') {
    tmp = PredictCh(s[i]);
    if (tmp != -1) {
      f[tmp]++;
      i++;
    } else {
      i++;
    }
  }
}

int main(int argc, char** argv) {
  char str[60] = "vsxasgyjafasd2m34asfa45saf45a56656ns56h34a2dasdnasasvsa5";
  frequency(str);
  system("pause");
  return 0;
}
