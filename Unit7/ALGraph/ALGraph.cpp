#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "QueueFunction.h"
#define MaxVertexNum 30
#define Flase 0
#define True 1
//����
typedef char InfoType;
typedef struct node {
  int adjvertex;//�ڽӵ���һ���Ŷ����Ӧ����Ż�������صı�ͷ�����е��±�
  InfoType info;//��ű߻������Ϣ
  struct node* next;//����һ���ڵ���ص���Ϣ
}EdgeNode;

//������
typedef struct {
  int no;  //������Ϣ�洢
  InfoType InfoType;
} VertexType;
typedef struct vnode {
  VertexType vertex;//������
  EdgeNode* firstedge;//�߱�ͷָ��
}VertexNode;

//�ڽӱ���
typedef struct {
  VertexNode adjlist[MaxVertexNum];//����һ���ڽӱ�
  int vertexNum, edgeNum;//���嶨�����ͱ���
}ALGraph;

//��������ͼ�洢���ڽӱ�
void CreateALGraph(ALGraph* G) {
  int i, j, k;
  EdgeNode* p;//����һ������
  printf("���붥�����ͱ�����");
  scanf("%d%d", &G->vertexNum, &G->edgeNum);
  //������n������Ķ����
  printf("\n�������еĶ��㣺");
  for ( i = 0; i < G->vertexNum; i++) {
    scanf("%s", &G->adjlist[i].vertex);//���붥����Ϣ
    G->adjlist[i].firstedge = NULL;//�����ı�ͷָ���ÿ�
  }
  //�����߱�
  for ( k = 0; k < G->edgeNum; k++) {
    printf("\n�����<Vi,Vj>�����±�i�����±�j��");
    scanf("%d%d", &i, &j);
    p = (EdgeNode*)malloc(sizeof(EdgeNode));//����ռ�
    p->adjvertex = j;//�ڽӵ����
    p->next = G->adjlist[i].firstedge;//��β���
    G->adjlist[i].firstedge = p;
  }
}

//��ӡ����
void Visit(ALGraph G, int v) {
  printf("%c", G.adjlist[v].vertex.InfoType);  //��ʾ��ǰ��������
}

//������ȱ��� ���õݹ�ʵ��
//�ӵ�V��������
int visited[MaxVertexNum];//�����Ѿ���������������
void DFS(ALGraph G, int v) {
  EdgeNode* p;
  int w;
  Visit(G, v);
  visited[v] = True;//����Ѿ���������
  for ( p = G.adjlist[v].firstedge; p ; p=p->next) {
    w = p->adjvertex;
    if (!visited[w]) {//����δ�������Ľ��б�������
      DFS(G, w);
    }
  }
}
void DFStraverse(ALGraph G) {
  int v;
  for ( v = 0; v < G.vertexNum; v++) {//�Դ洢�Ƿ���ʵ�������г�ʼ��
    visited[v] = Flase;
  }
  for ( v = 0; v < G.vertexNum; v++) {
    if (!visited[v]) {
      DFS(G, v);
    }
  }
}


//������ȱ��� ���ö���ʵ�� �Ƚ��ȳ�������
void BFS(ALGraph G, int v) {
  EdgeNode* p;
  int u, w, v;
  PSqeQueue Q = Init_SeqQueue();
  Visit(G, v);
  visited[v] = True;
  In_SeqQueue(Q, v);
  while (!Empty_SeqQueue(Q)) {
    Out_SeqQueue(Q, &u);//ȡ�������е��±�ֵ
    for ( p = G.adjlist[u].firstedge; p ; p=p->next) {
      w = p->adjvertex;
      if (!visited[w]) {
        Visit(G, w); 
        visited[w] = True;
        In_SeqQueue(Q, w);
      }
    }
  }
}

int main(int argc, char** argv) {
  ALGraph ALG;
  CreateALGraph(&ALG);
  system("pause");
  return 0;
}
