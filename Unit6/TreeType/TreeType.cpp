#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define DataType char
//˫�ױ�ʾ��
//Ѱ��˫�ױȽ����� Ѱ���ӽڵ�Ƚ�����
#define MaxNodeNum 100
typedef struct {
  DataType data;
  int parent;
}ParentList;
typedef struct {
  ParentList elem[MaxNodeNum];
  int n;//��ǰ�ڵ���
}ParentTree;
//���ӱ�ʾ��
struct CTNode {
  int child;//���ӽڵ��������е�λ��
  struct CTNode *node;//��һ������
};
typedef struct {
  DataType data;
  struct CTNode *firstChild;//��һ������
}CTBox;
typedef struct {
  CTBox nodes[MaxNodeNum];
  int n, r;//������͸���λ��
}CTree;
//�����ֵܱ�ʾ��
typedef struct tnode {
  DataType data;
  struct tnode *firstnode,*nextnode;
}Tnode;

int main(int argc, char** argv) {
  system("pause");
  return 0;
}
