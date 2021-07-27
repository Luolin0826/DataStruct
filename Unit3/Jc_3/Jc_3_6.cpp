#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//×Ö·û´®½»»»
void swap(char* str, int i, int j) {
  char temp = str[i];
  str[i] = str[j];
  str[j] = temp;
}
//×Ö·û´®ÄæÖÃ
void CharConvert(char* str, int start, int end) {
  if ((end - start) < 1)  //ÅĞ¶ÏÊÇ·ñ½áÊø
  {
    return;
  } else {
    swap(str, start, end);                 //½»»»×Ö·û´ÎĞò
    CharConvert(str, start + 1, end - 1);  //¼ÌĞøµİ¹é
  }
}

int main(int argc, char** argv) {
  char str[] = "abcd";
  CharConvert(str, 0, 3);
  printf("%s", str);
  system("pause");
  return 0;
}
