#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GListFunction.h"

//����һ�������
Glist GlistCopy(Glist L) {
  Glist p;
  if (L == NULL) {  //���ó���
    return NULL;
  }
  p = (Glist)malloc(sizeof(Glist));//����ռ�
  p->tag = L->tag;
  if (p->tag == 0) {  //������е��ǵ���ԭ��
    p->data = L->data;
  } else {
    p->ptr.hp = GlistCopy(L->ptr.hp);  //ѭ������
    p->ptr.tp = GlistCopy(L->ptr.tp);  //���ƹ����
  }
  return p;
}

int main(int argc, char** argv) {
  system("pause");
  return 0;
}
