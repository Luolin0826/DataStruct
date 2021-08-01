#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "QueueFunction.h"
//用一个一维数组存储顶点信息，二维数组寸尺顶点间的邻接关系
//此处还需要右图的定点数和边数
#define MaxVertexNum 30
typedef int EdgeType;
typedef char InfoType;  //顶点类型
typedef struct {
  int no;  //顶点号
  InfoType InfoType;
} VertexType;
//邻接矩阵的存储
typedef struct {
  VertexType vertexs[MaxVertexNum];           //存储顶点信息
  EdgeType arcs[MaxVertexNum][MaxVertexNum];  //存储边的关系
  int vertexNum, edgeNum;                     //顶点数和边数
} MGraph;
//创建邻接矩阵
void CreateMGraph(MGraph* G) {
  /* i,j,k为控制变量，w用于保存用户输入的边的权值*/
  int i, j, k, w;
  printf("输入顶点数和边数：");
  scanf("%d%d", &G->vertexNum, &G->edgeNum);
  printf("\n输入所有的顶点：");
  /*输入所有的顶点*/
  for (i = 0; i < G->vertexNum; i++)
    scanf("%s", &G->vertexs[i]);
  /*初始化邻接矩阵*/
  for (i = 0; i < G->vertexNum; i++)
    for (j = 0; j < G->vertexNum; j++)
      G->arcs[i][j] = 0;
  /*建立邻接矩阵*/
  for (k = 0; k < G->edgeNum; k++) {
    printf("输入边<Vi,Vj>的行下标i，列下标j和权值w：");
    scanf("%d%d%d", &i, &j, &w);
    G->arcs[i][j] = w;
    G->arcs[j][i] = G->arcs[i][j];
    printf("\n");
  }
}
//展示邻接矩阵
void DisplayGraph(MGraph G) {
  int i, j;
  /*输出网中的顶点数，边数和所有的顶点*/
  printf("无向网含有%d个顶点和%d条边，顶点依次为：", G.vertexNum, G.edgeNum);
  for (i = 0; i < G.vertexNum; i++)
    printf("%c,", G.vertexs[i]);
  printf("\n");
  printf("无向图的：\n");
  printf("序号i=");
  /*输出列号*/
  for (i = 0; i < G.vertexNum; i++)
    printf("%8d", i);
  printf("\n");
  /*输出邻接矩阵中的每一行*/
  for (i = 0; i < G.vertexNum; i++) {
    /*输出行号*/
    printf("%8d", i);
    for (j = 0; j < G.vertexNum; j++)
      printf("%8d", G.arcs[i][j]);
    /*换行，准备输出下一行*/
    printf("\n");
  }
}

//邻接矩阵的广度优先遍历
#define Flase 0
#define True 1
int visited[MaxVertexNum];  //定义已经被遍历过的数组
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
