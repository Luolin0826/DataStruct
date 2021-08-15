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
BinSTree BSTreeSearch(BinSTree t, KeyType k) {
  if (t == NULL) {  //��Ϊ��
    return NULL;
  }
  if (t->Elem.key == k) {  //���ڵ�������ͬ
    return t;
  }
  if (t->Elem.key > k) {  //����Ԫ�ش���k
    return BSTreeSearch(t->lchild, k);
  } else {  //����Ԫ��С��k
    return BSTreeSearch(t->rchild, k);
  }
}
//���� ע�� �����t����Ҫ����������
//�α��е��ٿ�����k�Ѿ��ڶ����������д��ڵ����
void BSTreeInsert(BinSTree* t, KeyType k) {
  BinSTree r;
  if (t == NULL) {
    r = (BinSTree)malloc(sizeof(struct BinSTreeNode));
    r->Elem.key = k;
    r->lchild = r->rchild = NULL;
    *t = r;  //ע��������*t ����ָ���൱�ڰ�ԭ�����Ǹ�ָ������������ʽ
    return;  //��������ѭ��
  } else {
    if (k < (*t)->Elem.key) {  //����������
      BSTreeInsert(&((*t)->lchild), k);
    } else if (k = (*t)->Elem.key) {
      printf("Ԫ���Ѿ������������ˣ�");
    } else {
      BSTreeInsert(&((*t)->rchild), k);  //����������
    }
  }
}
//ʹ�÷ǵݹ���ʵ�ֶ����������Ĳ������
void BSTreeInsert_FDG(BinSTree* t, KeyType k) {
  //��һ�����ǽڵ�Ϊ�յ����
  if (*t == NULL) {
    BinSTree q;
    q = (BinSTree)malloc(sizeof(struct BinSTreeNode));
    q->Elem.key = k;
    q->lchild = q->rchild = NULL;
    *t = q;
  } else {
    BinSTree p = *t;  //����һ�Ÿ�����
    while (p) {
      if (k == p->Elem.key) {
        printf("Ԫ���Ѿ������������ˣ�");
        return;
      } else if (k < p->Elem.key) {
        if (p->lchild != NULL) {  //��������Ϊ��ʱ������������������ɨ��
          p = p->lchild;
        } else {  //������������Ϊ�յ����
          BinSTree m;
          m = (BinSTree)malloc(sizeof(struct BinSTreeNode));
          m->Elem.key = k;
          m->lchild = m->rchild = NULL;
          p->lchild = m;  //������ȥ
        }
      } else {//������Ԫ�ش��ڸ��ڵ�����
        if (p->rchild != NULL) {  //��������Ϊ��ʱ������������������ɨ��
          p = p->rchild;
        } else {  //������������Ϊ�յ����
          BinSTree m;
          m = (BinSTree)malloc(sizeof(struct BinSTreeNode));
          m->Elem.key = k;
          m->lchild = m->rchild = NULL;
          p->rchild = m;  //������ȥ
        }
      }
    }
  }
}

//�������������� ���� nΪa��Ԫ�ظ���
BinSTree BSTreeCreat(KeyType a[], int n) {
  BinSTree t;
  t = NULL;
  for (int i = 0; i < n; i++) {
    BSTreeInsert(&t, a[i]);
  }
  return t;
}
//������������ɾ������ ɾ��ֵΪk�ĵ� �ɹ�����1 ʧ�ܷ���0
// �����ֿ���
// Ҷ�ӽڵ㣺ֱ��ɾ��
// ֻ������������������ֱ����������ȡ����
//������������������������ֱ��ǰ���滻��
int BSTreeDelete(BinSTree* bt, KeyType k) {
  BinSTree f, p, q, s;
  p = *bt;
  f = NULL;
  while (p && p->Elem.key != k) {  //��p������ֵ��Ϊk ��ҪȥѰ��k
    f = p;                         // fΪָ����*p��˫�׽���ָ��
    if (p->Elem.key > k) {
      p = p->lchild;  //ȥ������
    } else {
      p = p->rchild;
    }
  }
  //������ ���ҹ����Ѿ����� ����鵽�� pָ��ָ��ĵط����ǣ����û�鵽
  //��ôp�϶�Ϊ��
  if (p == NULL) {
    return 0;
  }
  //����Ϊ�ǿյ����
  if (p->lchild == NULL) {        //������Ϊ��
    if (f = NULL) {               //��ɾ���Ľڵ��Ǹ��ڵ�
      *bt = p->rchild;            //�����������̳�
    } else if (f->lchild == p) {  //��ɾ�������������Ľ��
      f->lchild = p->rchild;
    } else {
      f->rchild = p->rchild;
    }
  } else {  //������Ϊ�� ��������
    q = p;
    s = q->lchild;
    //����ѭ�������������� ���ñ�����ʹsΪnull�����
    while (s->rchild) {  //ȥ��ֱ��ǰ�� �������������нڵ���
      q = s;             // q��s��˫�׽��
      s = s->rchild;
    }
    //������������Ϊ�˽�s���߼���ɾ��
    if (q == p) {  //��˼�ǣ�q����s�����Ƚڵ���Ҵ�ʱs�������Ѿ�����
      q->lchild = s->lchild;
    } else {
      q->rchild = s->lchild;  //ע���˴�������� sΪp�������������������
    }
    p->Elem.key = s->Elem.key;  //Ԫ�ظ�ֵ
    free(s);                    //�������ͷ�
    return 1;
  }
}

int main(int argc, char** argv) {
  system("pause");
  return 0;
}
