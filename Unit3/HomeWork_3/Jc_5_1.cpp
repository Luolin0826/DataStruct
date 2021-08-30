#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "StackFunction.h"
//判断字符串是否是回文序列 
void PredictHuiWen(char ch[10]) {
  int i,j,k=0;
  char tmp;
  PSeqStack S = Init_SeqStack();
  for (i = 0; ch[i] !='@'; i++) {
    Push_SeqStack(S, ch[i]);//进栈
  }
  for ( j = 0; j <i; j++) {//出栈做对比
    Pop_SeqStcak(S, &tmp);//不能写成tmp = Pop_SeqStcak(S, &tmp); 犯过错
    if (tmp!=ch[j]) {//这里出过错
      printf("非回文序列");
      return;
    }
  }
  if (Empty_SeqStack(S)) {//对比完了最后一个字母都相同
    printf("是回文序列");
  }
  Destroy_SeqStack(&S);//创建包销毁
}




int main(int argc, char** argv) {
  char ch[10] = {'c', 's', 'w', 's', 's', 'w', 'a', 'e', 'e', '@'};
  char ch1[10] = "abcddcba@";
  PredictHuiWen(ch1);

  system("pause");
  return 0;
}
