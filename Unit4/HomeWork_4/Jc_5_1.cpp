#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//字符串删除
void StrDelect(char* s, int i, int m) {
  int length;
  length = strlen(s);
  if (i >= length) {
    printf("参数错误！");
    return;
  } else if (i + m >= length) {  //如果超出最大长度
    s[i - 1] = '\0';             //注意是i-1
  } else {                       //正常删除
    /*我的写法
        for ( j = i+m-1; j <length; j++) {
      s[j - m] = s[j];
    }
    //删除后加空位符
    for (n = length-m; n <= length; n++) {
      strcpy(&s[n], nul);  //置空
    }
    s[length-m] = '\0';
    */
      //书上的
    char* temp = (char*)malloc(length - m + 1);
    s[i - 1] = '\0';  //注意是i-1
    strcpy(temp, s);//将s的前部分给temp
    strcpy(temp + i - 1, s + i - 1 + m);//将后半部分给temp 拼在一起
    strcpy(s, temp);//还回来
    free(temp);//释放辅助空间
  }
}

int main(int argc, char** argv) {
  char s[10] = "saccsdxzc";
  StrDelect(s, 3, 5);
  for (int i = 0; i < 5; i++) {
    printf("%c", s[i]);
  }

  system("pause");
  return 0;
}
