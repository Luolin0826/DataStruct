#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxSize 256

//求串长
int StrLength(char* s) {
  int i = 0;
  while (s[i] != '\0') {
    i++;
  }
  return i;
}
//串赋值 将S2中的数据给s1，s1中原本的数据被覆盖掉
int StrAssign(char* s1, char* s2) {
  int i = 0;
  while (s2[i] != '\0') {
    s1[i] = s2[i];
    i++;
  }
  return 1;
}
//连接操作 将s1和s2连接成一个新串s 即s<s1+s2
int StrConcat(char* s1, char* s2, char* s) {
  int i = 0, j = 0, len1, len2;
  len1 = StrLength(s1);
  len2 = StrLength(s2);
  if (len1 + len2 > MaxSize) {
    printf("内存不足");
    return 0;
  }
  while (s1[i] != '\0') {
    s[i] = s1[i];
    i++;
  }
  while (s2[j] != '\0') {
    s[i] = s2[j];
    i++;
    j++;
  }
  s[i] = '\0';
  return 1;
}
//求子串
//产生一个新串t，t是从串s的第i个字符长度开始的长度为len的字串，len=0时得到的空串
int StrSub(char* t, char* s, int i, int len) {
  int slen = StrLength(s);
  if (len > slen - 1 + i) {
    printf("参数错误！");
    return (0);
  } else {
    for (int j = 0; j < len; j++) {
      t[j] = s[i + j - 1];
    }
    t[len] = '\0';
  }
  return (1);
}
//串比较 s1>s2 略有不同 是需要比较元素的所有元素都相同 如果相同返回非0
//不相同返回0
int StrCmp(char* s1, char* s2) {
  int i = 0;
  while (s1[i] == s2[i] && s1[i] != '\0') {
    i++;
  }
  return (s1[i] == s2[2]);
}
//字串定位 找子串t在s中首次出现的位置
int StrIndex(char* s, char* t) {
  int tlen = StrLength(t);
  int slen = StrLength(s);
  if (slen < 0 || tlen < 0) {
    printf("字符串错误");
    return (0);
  } else {
    int i = 0, j;
    char rt[5];
    while (s[i] != '\0' && (i + tlen) <= slen) {
      j = i + 1;
      StrSub(rt, s, j, tlen);
      if (StrCmp(rt, t)) {
        return j;
      } else {
        i++;
      }
    }
    if (s[i] == '\0') {
      return -1;
    }
  }
}

//串插人 将串t插入到串s的第i个字符上，s的串发生变化
int StrInsert(char* s, char* t, int i) {
  int slen = StrLength(s);
  int tlen = StrLength(t);
  if (i <= 0 ||
      i > slen + 1) {  //这里要注意是 i>slen+1,为的是别人要插入到最后一个字符后
    printf("参数错误");
    return 0;
  } else {
    for (int j = slen - 1; j >= i - 1; j--) {  //后移
      s[j + tlen] = s[j];
    }
    for (int j = 0; j < tlen; j++) {
      s[i - 1] = t[j];
      i++;
    }
  }
  s[slen + tlen] = '\0';
  return (1);
}
//串删除字符串中删除从第i个字符串开始的长度为len的字串，s的串改变
int StrDelete(char* s, int i, int len) {
  int slen = StrLength(s);
  if (i <= 0 || i > slen) {
    printf("参数i错误");
    return (0);
  } else if (len < 0 || len > slen - i + 1) {
    printf("参数len错误");
    return (0);
  } else {
    for (int j = i + len - 1; j < slen; j++) {  //此处犯过迷糊 要注意语法
      s[j - len] = s[j];
    }
    s[slen - len] = '\0';  //一定记得要加结尾标识符，避免脏数据
  }
  return (1);
}
//串替代操作 串r替代串s中所有出现的与t相等的不重叠子串，s的串改变
int StrRep(char* s, char* t, char* r) {
  int i = 0, j;  // j表示位置
  int tlen = StrLength(t);
  int slen = StrLength(s);
  int rlen = StrLength(r);
  char rt[5];
  if (slen < 0 || tlen < 0 || rlen < 0) {
    printf("字符串错误");
    return (0);
  } else {
    while (s[i] != '\0' && (i + rlen) <= slen) {
      j = i + 1;
      StrSub(rt, s, j, tlen);
      if (StrCmp(rt, t)) {
        StrDelete(s, j, tlen);
        StrInsert(s, r, j);
        i = i + tlen;
      } else {
        i++;
      }
    }
    return (1);
  }
}
//打印串
void StrPrintf(char* s) {
  int i = 0;
  while (s[i] != '\0') {
    printf("%c", s[i]);
    i++;
  }
}

int main(int argc, char** argv) {
  char s1[255] = "welcome ";
  char s2[255] = "maanshan";
  char s[255] = "";
  char bth[10] = "an";
  char th[10] = "TH";
  int s1len = StrLength(s1);
  printf("s1的长度是%d\n", s1len);
  StrConcat(s1, s2, s);
  printf("拼接之后为：");
  StrPrintf(s);
  printf("\n");
  int result = StrCmp(s1, s2);
  printf("两者比较%d\n", result);
  StrAssign(s1, s2);
  printf("赋值s1之后为：");
  StrPrintf(s1);
  printf("\n");
  StrSub(s, s1, 2, 3);
  printf("提取后的字符串s为");
  StrPrintf(s);
  printf("\n");
  StrInsert(s1, s, 3);
  printf("将s插入到s1的第三个字符为");
  StrPrintf(s1);
  printf("\n");

  int pos = StrIndex(s1, bth);
  printf("s中an的位置为");
  printf("%d", pos);
  printf("\n");

  StrDelete(s1, 3, 3);
  printf("将s从s1删除后为");
  StrPrintf(s1);
  printf("\n");
  StrRep(s1, bth, th);
  printf("替换an后的s1是");
  StrPrintf(s1);
  printf("\n");
  system("pause");
  return 0;
}
