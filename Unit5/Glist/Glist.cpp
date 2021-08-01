#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define  Datatype int
typedef struct GenealNode {
  int tag;//ȡֵ0����1
  union {
    Datatype data;
    struct {
      struct GenealNode *hp, *tp;
    }ptr;
  };
}*Glist;
 //ȡ��ͷ ��ʱ����null�����򷵻ر�ͷָ��
Glist GetHead(Glist p) {
  if (!p||p->tag==0) {
    printf("��Ϊ�ձ����ֻ����һ��ԭ��");
    return (NULL);
  }
  return p->ptr.hp;//�ǿձ����ر�ͷ����ͷָ��
}
//ȡ��β �ձ���ߵ���ԭ�� û���� ���򷵻ر�βָ��
Glist GetTail(Glist p) {
  if (!p || p->tag == 0) {
    printf("��Ϊ�ձ����ֻ����һ��ԭ��");
    return (NULL);
  }
  return p->ptr.tp;//���ر�βָ��
}
//�������
int depth(Glist ls) {
  int max=0;
  Glist tmp = ls;
  if (tmp==NULL) {//�ձ�
    return 1;
  }
  if (tmp->tag==0) {//ֻ��һ��ԭ��
    return 0;
  }
  while (tmp!=NULL) {
    int dep = depth(tmp->ptr.hp);//��ai�����
    if (dep>max) {
      max = dep;
    }
    tmp = tmp->ptr.tp;//����һ��ָ��
  }
  return max + 1;//Ҫ���������������
}

int main(int argc, char** argv) {
  system("pause");
  return 0;
}
