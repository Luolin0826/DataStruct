#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�ַ���ɾ��
void StrDelect(char* s, int i, int m) {
  int length;
  length = strlen(s);
  if (i >= length) {
    printf("��������");
    return;
  } else if (i + m >= length) {  //���������󳤶�
    s[i - 1] = '\0';             //ע����i-1
  } else {                       //����ɾ��
    /*�ҵ�д��
        for ( j = i+m-1; j <length; j++) {
      s[j - m] = s[j];
    }
    //ɾ����ӿ�λ��
    for (n = length-m; n <= length; n++) {
      strcpy(&s[n], nul);  //�ÿ�
    }
    s[length-m] = '\0';
    */
      //���ϵ�
    char* temp = (char*)malloc(length - m + 1);
    s[i - 1] = '\0';  //ע����i-1
    strcpy(temp, s);//��s��ǰ���ָ�temp
    strcpy(temp + i - 1, s + i - 1 + m);//����벿�ָ�temp ƴ��һ��
    strcpy(s, temp);//������
    free(temp);//�ͷŸ����ռ�
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
