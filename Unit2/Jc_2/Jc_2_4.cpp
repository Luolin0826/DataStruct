#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkListFunction.h"

//���Һ��� 0��ʾʧ�� ��0��ʾ�ɹ�
LinkList GetLocation(LinkList A, ElemType e) {
  LNode* p = A->next;
  while (p != NULL && p->data != e) {
    p = p->next;
  }
  return (p);
}
//�󽻼����� ���A���е�Bû�У���ôɾ����
void Intersection(LinkList A, LinkList B) {
  int tmp;
<<<<<<< HEAD
  LinkList per, p;  //ǰ���ڵ�per����ǰ���p
  per = A;
  p = per->next;  //�����p��������Ч��ֹ���ֿ�ָ������
=======
  LinkList per, p;
  per = A;
  p = per->next;
>>>>>>> 80e2f9eb531533168205961d972fb2f5f9c82d5f
  while (p) {
    tmp = p->data;
    if (!GetLocation(B, tmp)) {
      per->next = p->next;
      free(p);
<<<<<<< HEAD
      p = per->next;  //����Ҫע�⣬���ֹ��ڴ�й©�����⣬��仰�ı����ǿ�����һ�ڵ�
    } else  //�ҵ���һ��ͬ���Ľ�㣬����ڵ�ĵ�ַ��p
    {
      per = p;  //�˴����Ϊper��pָ��ĸ���ָ�룬ȷ��perʼ����pָ��ĵ�ǰ��ָ�룬����������޸ģ���ûƥ�䵽��ʱ����޷�ɾ��������
      p = p->next;  //������һ�����
    }
  }
}
//�󲢼����� ɾ��B�е�A���ֹ���Ԫ�أ��ٽ�B�������ӵ�A�������
void Union(LinkList A, LinkList B) {
  LinkList per, p;
  per = B;
  p =  B->next;
  ElemType tmp;  //�������������Դ洢ֵ
  while (p) {
    tmp = p->data;
    if (GetLocation(A, tmp)) {//��λ������ͬ��Ԫ�أ���Ҫִ��ɾ������
      per->next = p->next;//ɾ��
      free(p);//�ͷ�
      p = per->next;//��ָ��
    } else {
      per = p;//Ϊ��ִ�к����������Ⱦ�����
      p = p->next;//������һ�ڵ�
    }
  }
  //�˴� �����跨������������������
  while (A->next!=NULL) {
    A = A->next;
  }
  A->next = B->next;
=======
      p=per->next;//����Ҫע�⣬���ֹ��ڴ�й©�ĵ����⣬��仰�ı����ǿ�����һ�ڵ�
    } else  //�ҵ���һ��ͬ���Ľ�㣬����ڵ�ĵ�ַ��p
    {
      per = p;
      p = p->next;
    }
  }
>>>>>>> 80e2f9eb531533168205961d972fb2f5f9c82d5f
}

int main(int argc, char** argv) {
  LinkList A, B;
  InitialLNode(A);
  InitialLNode(B);
  for (int i = 0; i < 10; i++) {
    InsertNextNode(A, i);
  }
  for (int i = 4; i < 12; i++) {
    InsertNextNode(B, i);
  }
<<<<<<< HEAD
  //Intersection(A, B);
  //printf("�����ǣ�");
  //printfLinkList(A);
  printf("\n�����ǣ�");
  Union(A, B);
=======
  Intersection(A, B);
>>>>>>> 80e2f9eb531533168205961d972fb2f5f9c82d5f
  printfLinkList(A);
  system("pause");
  return 0;
}
