#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BTreeFunction.h"
#include "StackFunction.h"
//��ӡֵΪx�Ľڵ����������
//�������ķǵݹ������� ��������ֵΪx�Ľ��ʱ��ջ��ʣ���Ԫ�ؾ���
void PostSearchX(BTree T, char x) {
  PSeqStack S = Init_SeqStack();
  ElementType Sq;//Ϊ����ջ�д洢��������
  Bnode* p = T;
  while (p || !Empyt_SeqStack(S)) {
    if (p) {
      Sq.flag = 0;
      Sq.node = p;
      Push_SeqStack(S, Sq);  //��pָ���Լ�flagѹ��ջ��
      p = p->lchild;
    } else {
      Pop_SeqStack(S, &Sq);
      p = Sq.node;
      if (Sq.flag == 0) {
        Sq.flag = 1;
        Push_SeqStack(S, Sq);  //�ٴν�ջ
        p = p->rchild;
      } else {
        if (p->data == x) {  //�ҵ���
          break;
        }
        p = NULL;  //��p��ֵΪ�ձ�ʾ��ǰ�ڵ㴦�������Ҫ��ջ�е����¸��ڵ�
      }
    }
  }  // end while
  if (Empyt_SeqStack(S)) {
    printf("�ս���xΪ���ڵ������û��x");
    return;
  }
  while (!Empyt_SeqStack(S)) {
    Pop_SeqStack(S, &Sq);
    printf("%c ", Sq.node->data);
  }
  Destroy_SeqStack(&S);
}

int main(int argc, char** argv) {
  char x = 'F';
  printf("�����һ����:");
  BTree T = CreateBinTree();
  PostSearchX(T, x);
  system("pause");
  return 0;
}
