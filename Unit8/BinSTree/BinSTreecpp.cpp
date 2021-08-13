#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//���������
typedef int KeyType;
//�ؼ��ֶ�
typedef struct {
  KeyType key;
} DataType;
typedef struct BinSTreeNode {
  DataType Elem;
  struct BinSTreeNode* lchild;
  struct BinSTreeNode* rchild;
} * BinSTree;

//���Ҳ���
BinSTree BTreeSearch(BinSTree t, KeyType k) {
  if (t == NULL) {  //��Ϊ��
    return NULL;
  }
  if (t->Elem.key == k) {  //���ڵ�������ͬ
    return t;
  }
  if (t->Elem.key > k) {  //����Ԫ�ش���k
    return BTreeSearch(t->lchild, k);
  } else {  //����Ԫ��С��k
    return BTreeSearch(t->rchild, k);
  }
}
//���� ע�� �����t����Ҫ����������
//�α��е��ٿ�����k�Ѿ��ڶ����������д��ڵ����
void BTreeInsert(BinSTree* t, KeyType k) {
  BinSTree r;
  if (t == NULL) {
    r = (BinSTree)malloc(sizeof(struct BinSTreeNode));
    r->Elem.key = k;
    r->lchild = r->rchild = NULL;
    *t = r;  //ע��������*t ����ָ���൱�ڰ�ԭ�����Ǹ�ָ������������ʽ
    return;  //��������ѭ��
  } else {
    if (k < (*t)->Elem.key) {  //����������
      BTreeInsert(&((*t)->lchild), k);
    } else if (k = (*t)->Elem.key) {
      printf("Ԫ���Ѿ������������ˣ�");
    } else {
      BTreeInsert(&((*t)->rchild), k);//����������
    }
  }
}
//��������������


int main(int argc, char** argv) {
  system("pause");
  return 0;
}
