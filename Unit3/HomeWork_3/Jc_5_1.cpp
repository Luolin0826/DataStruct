#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "StackFunction.h"
//判断字符串是否是回文序列 
void huiwen(PSeqStack S) {

}




int main(int argc, char** argv) {
  PSeqStack S = Init_SeqStack();
  char ch[10] = {'c', 's', 'w', 's', 's', 'w', 'a', 'e', 'e', 'q'};
  for (int i = 0; i < 10; i++) {
    Push_SeqStack(S, ch[i]);
  }
  Printf_SeqStack(S);
  system("pause");
  return 0;
}
