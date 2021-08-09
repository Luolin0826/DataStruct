#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "QueueFunction.h"
//��һ��һά����洢������Ϣ����ά�����߶������ڽӹ�ϵ
//�˴�����Ҫ��ͼ�Ķ������ͱ���
#define MaxVertexNum 30
typedef int EdgeType;
typedef char InfoType;  //��������
typedef struct {
  int no;  //�����
  InfoType InfoType;
} VertexType;
//�ڽӾ���Ĵ洢
typedef struct {
  VertexType vertexs[MaxVertexNum];           //�洢������Ϣ
  EdgeType arcs[MaxVertexNum][MaxVertexNum];  //�洢�ߵĹ�ϵ
  int vertexNum, edgeNum;                     //�������ͱ���
} MGraph;
//�����ڽӾ���
void CreateMGraph(MGraph* G) {
  /* i,j,kΪ���Ʊ�����w���ڱ����û�����ıߵ�Ȩֵ*/
  int i, j, k, w;
  printf("���붥�����ͱ�����");
  scanf("%d%d", &G->vertexNum, &G->edgeNum);
  printf("\n�������еĶ��㣺");
  /*�������еĶ���*/
  for (i = 0; i < G->vertexNum; i++)
    scanf("%s", &G->vertexs[i]);
  /*��ʼ���ڽӾ���*/
  for (i = 0; i < G->vertexNum; i++)
    for (j = 0; j < G->vertexNum; j++)
      G->arcs[i][j] = 0;
  /*�����ڽӾ���*/
  for (k = 0; k < G->edgeNum; k++) {
    printf("�����<Vi,Vj>�����±�i�����±�j��Ȩֵw��");
    scanf("%d%d%d", &i, &j, &w);
    G->arcs[i][j] = w;
    G->arcs[j][i] = G->arcs[i][j];
    printf("\n");
  }
}
//չʾ�ڽӾ���
void DisplayGraph(MGraph G) {
  int i, j;
  /*������еĶ����������������еĶ���*/
  printf("����������%d�������%d���ߣ���������Ϊ��", G.vertexNum, G.edgeNum);
  for (i = 0; i < G.vertexNum; i++)
    printf("%c,", G.vertexs[i]);
  printf("\n");
  printf("����ͼ�ģ�\n");
  printf("���i=");
  /*����к�*/
  for (i = 0; i < G.vertexNum; i++)
    printf("%8d", i);
  printf("\n");
  /*����ڽӾ����е�ÿһ��*/
  for (i = 0; i < G.vertexNum; i++) {
    /*����к�*/
    printf("%8d", i);
    for (j = 0; j < G.vertexNum; j++)
      printf("%8d", G.arcs[i][j]);
    /*���У�׼�������һ��*/
    printf("\n");
  }
}

//�ڽӾ���Ĺ�����ȱ���
#define Flase 0
#define True 1
int visited[MaxVertexNum];  //�����Ѿ���������������
void Visit(MGraph G, int v) {
  printf("%c", G.vertexs[v].InfoType);
}

void BFS(MGraph G, int v) {
  int i, j;
  PSqeQueue Q = Init_SeqQueue();
  Visit(G, v);
  visited[v] = True;
  In_SeqQueue(Q, v);
  while (!Empty_SeqQueue(Q)) {
    Out_SeqQueue(Q, &i);
    for (j = 0; j < G.vertexNum; j++) {
      if (G.arcs[i][j] == 1 && !visited[j]) {
        Visit(G, j);
        visited[j] = True;
        In_SeqQueue(Q, j);
      }
    }
  }
}

void BFStraverse(MGraph G) {
  int v;
  for (v = 0; v < G.vertexNum; v++) {
    visited[v] = Flase;
  }
  for ( v = 0; v < G.vertexNum; v++) {
    if (!visited[v]) {
      BFS(G, v);
    }
  }
}

int main(int argc, char** argv) {
  MGraph MG;
  CreateMGraph(&MG);
  DisplayGraph(MG);
  system("pause");
  return 0;
}
