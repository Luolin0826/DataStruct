#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SeqQueue.h"
#define MaxVertexNum 30
#define Flase 0
#define True 1
//����
typedef char InfoType;
typedef struct node {
  int adjvertex;  //�ڽӵ���һ���Ŷ����Ӧ����Ż�������صı�ͷ�����е��±�
  struct node* next;  //����һ���ڵ���ص���Ϣ
} EdgeNode;
//�����ʽ
typedef struct vnode {
  int indegree;         //���
  int vertex;           //������
  EdgeNode* firstedge;  //�߱�ͷָ��
} VertexNode;
//�ڽӱ���
typedef struct {
  VertexNode adjlist[MaxVertexNum];  //����һ���ڽӱ�
  int vertexNum, edgeNum;            //���嶨�����ͱ���
} ALGraph;
//Ѱ�����
void FindInDegree(ALGraph* G) {
  int i;
  EdgeNode* p;
  //��������ʼ��
  for (i = 0; i < G->vertexNum; i++) {
    G->adjlist[i].indegree = 0;
  }
  //�������
  for (i = 0; i < G->vertexNum; i++) {
    for (p = G->adjlist[i].firstedge; p; p = p->next) {
      G->adjlist[i].indegree++;  //ÿ������һ���ߣ������һ�����
    }
  }
}

void Top_Sort(ALGraph G) {
  int i, j, k, count = 0;
  int top = -1;
  EdgeNode* p;
  PSqeQueue Q = Init_SeqQueue();  //��ʼ��˳�����
  FindInDegree(&G);               //�������
  for (i = 0; i < G.vertexNum; i++) {
    if (G.adjlist[i].indegree == 0) {
      In_SeqQueue(Q, i);  //�����Ϊ0�Ķ������
    }
  }
  while (!Empty_SeqQueue(Q)) {           //���в���
    Out_SeqQueue(Q, &j);                 //����
    printf("%3d", G.adjlist[j].vertex);  //�������
    count++;
    for (p = G.adjlist[j].firstedge; p; p = p->next) {
      k = p->adjvertex;
      G.adjlist[k].indegree--;
      if (G.adjlist[k].indegree == 0) {
        In_SeqQueue(Q, k);  //�����Ϊ0�Ķ������
      }
    }
  }
  //�ж��Ƿ��л���ͼ
  if (count < G.vertexNum) {
    printf("��������");
  } else {
    printf("����������");
  }
}

int main(int argc, char** argv) {
  system("pause");
  return 0;
}
