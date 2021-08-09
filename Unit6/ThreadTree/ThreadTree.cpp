#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//����������
typedef char DataType;
typedef struct Threadnode {
  DataType data;                       //����λ
  int ltag, rtag;                      //��ʶ��
  struct Threadnode *lchild, *rchild;  //���ӽ����Һ��ӽ��
} Threadnode, *ThreadTree;

//��ʾ������
void Visit(ThreadTree t) {
  printf("%c\t", t->data);
}
//��������������
// preָ��t��ָ��ǰ���ڵ㣬��������ǰpreΪ��
void InThread(ThreadTree t, ThreadTree pre) {
  if (t) {
    InThread(t->lchild, pre);  //����������
    if (t->lchild == NULL) {
      t->ltag = 1;
      t->lchild = pre;  //����ָ��ǰ���ڵ� �ʼָ��null
    }
    if (t->rchild == NULL) {  //β�˵����⴦��
      t->rtag = 1;
    }
    if (pre && pre->rtag == 1) {  //ǰ���ڵ�û����������ʱ��
      pre->rchild = t;            //Ϊǰ���ڵ㽨�����
    }
    pre = t;                   //ǰ��ָ��͵�ǰָ��ָ��һ��
    InThread(t->rchild, pre);  //����������
  }
}
//��������������
// preָ��t��ָ��ǰ���ڵ㣬��������ǰpreΪ��
void PreThread(ThreadTree t, ThreadTree pre) {
  if (t) {
    if (t->lchild == NULL) {
      t->ltag = 1;
      t->lchild = pre;  //����ָ��ǰ���ڵ� �ʼָ��null
    }
    if (t->rchild == NULL) {  //β�˵����⴦��
      t->rtag = 1;
    }
    if (pre && pre->rtag == 1) {  //ǰ���ڵ�û����������ʱ��
      pre->rchild = t;            //Ϊǰ���ڵ㽨�����
    }
    pre = t;                      //ǰ��ָ��͵�ǰָ��ָ��һ��
    if (t->ltag == 0) {           //���Ⱞ��ħ��תȦȦ
      PreThread(t->lchild, pre);  //����������
    }
    PreThread(t->rchild, pre);  //����������
  }
}
//��������������
// preָ��t��ָ��ǰ���ڵ㣬��������ǰpreΪ��
void PreThread(ThreadTree t, ThreadTree pre) {
  if (t) {
    PreThread(t->lchild, pre);  //����������
    PreThread(t->rchild, pre);  //����������
    if (t->lchild == NULL) {
      t->ltag = 1;
      t->lchild = pre;  //����ָ��ǰ���ڵ� �ʼָ��null
    }
    if (t->rchild == NULL) {  //β�˵����⴦��
      t->rtag = 1;
    }
    if (pre && pre->rtag == 1) {  //ǰ���ڵ�û����������ʱ��
      pre->rchild = t;            //Ϊǰ���ڵ㽨�����
    }
    pre = t;  //ǰ��ָ��͵�ǰָ��ָ��һ��
  }
}
//������ǰ��
//��ǰָ���ltag==1ʱ ǰ��������
// ��ǰָ���ltag=0ʱ
// ǰ���ǵ�ǰָ��������������һ���Һ��ӽ��
//���������û���Һ��ӣ��Ǿ������Լ�
ThreadTree InPreNode(ThreadTree p) {
  ThreadTree pre;
  pre = p->lchild;//ָ������
  if (p->ltag == 1) {//�����ʶ��Ϊ1
    return pre;
  } else {
    while (pre->rtag == 0) {//pre->rtag == 0�����Һ���
      pre = pre->rchild;//һֱѰ���Һ���
    }
    return pre;
  }
}
//�����Һ��
//��ǰָ���rtag==1ʱ ������Һ���
// ��ǰָ���rtag=0ʱ
// ����ǵ�ǰָ��������������һ�����ӽ��
//���������û�����ӣ��Ǿ������Լ�
ThreadTree InPostNode(ThreadTree p) {
  ThreadTree pre;
  pre = p->rchild;     //ָ���Һ���
  if (p->rtag == 1) {  //�����ʶ��Ϊ1
    return pre;
  } else {
    while (pre->ltag == 0) {  // pre->ltag == 0��������
      pre = pre->lchild;      //һֱѰ������
    }
    return pre;
  }
}
//����ʵ�ֱ���
void InOrderTh(ThreadTree t) {
  ThreadTree p;
  if (t) {
    p = t;
    while (p->ltag==0) {//Ѱ������ڵ�
      p = p->lchild;
    }
    while (p) {//����
      Visit(p);//��ӡ
      p = InPostNode(p);//Ѱ�Һ����ڵ�
    }
  }
}
//������������������ʵ�ֲ���ֵΪx��ֵ
ThreadTree Search(ThreadTree t,DataType x) {
  ThreadTree p;
  if (t) {
    p = t;
    while (p->ltag == 0) {  //Ѱ������ڵ�
      p = p->lchild;
    }
    while (p&&p->data!=x) {           //����
      p = InPostNode(p);  //Ѱ�Һ����ڵ�
    }
    return p;
  }
}

int main(int argc, char** argv) {
  system("pause");
  return 0;
}
