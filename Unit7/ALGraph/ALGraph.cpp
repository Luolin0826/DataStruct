#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "QueueFunction.h"
#define MaxVertexNum 30
#define Flase 0
#define True 1
//表结点
typedef char InfoType;
typedef struct node {
  int adjvertex;//邻接点域，一般存放顶点对应的序号或者在相关的表头向量中的下标
  InfoType info;//存放边弧相关信息
  struct node* next;//与下一个节点相关的信息
}EdgeNode;

//顶点结点
typedef struct {
  int no;  //顶点信息存储
  InfoType InfoType;
} VertexType;
typedef struct vnode {
  VertexType vertex;//定点域
  EdgeNode* firstedge;//边表头指针
}VertexNode;

//邻接表定义
typedef struct {
  VertexNode adjlist[MaxVertexNum];//定义一个邻接表
  int vertexNum, edgeNum;//定义定点数和边数
}ALGraph;

//创建有向图存储的邻接表
void CreateALGraph(ALGraph* G) {
  int i, j, k;
  EdgeNode* p;//创建一个表结点
  printf("输入顶点数和边数：");
  scanf("%d%d", &G->vertexNum, &G->edgeNum);
  //建立有n个顶点的顶点表
  printf("\n输入所有的顶点：");
  for ( i = 0; i < G->vertexNum; i++) {
    scanf("%s", &G->adjlist[i].vertex);//读入顶点信息
    G->adjlist[i].firstedge = NULL;//定点表的表头指针置空
  }
  //建立边表
  for ( k = 0; k < G->edgeNum; k++) {
    printf("\n输入边<Vi,Vj>的行下标i，列下标j：");
    scanf("%d%d", &i, &j);
    p = (EdgeNode*)malloc(sizeof(EdgeNode));//分配空间
    p->adjvertex = j;//邻接点序号
    p->next = G->adjlist[i].firstedge;//首尾相接
    G->adjlist[i].firstedge = p;
  }
}

//打印表结点
void Visit(ALGraph G, int v) {
  printf("%c", G.adjlist[v].vertex.InfoType);  //显示当前遍历到的
}

//深度优先遍历 借用递归实现
//从第V个结点遍历
int visited[MaxVertexNum];//定义已经被遍历过的数组
void DFS(ALGraph G, int v) {
  EdgeNode* p;
  int w;
  Visit(G, v);
  visited[v] = True;//标记已经被访问了
  for ( p = G.adjlist[v].firstedge; p ; p=p->next) {
    w = p->adjvertex;
    if (!visited[w]) {//对尚未遍历到的进行遍历操作
      DFS(G, w);
    }
  }
}
void DFStraverse(ALGraph G) {
  int v;
  for ( v = 0; v < G.vertexNum; v++) {//对存储是否访问的数组进行初始化
    visited[v] = Flase;
  }
  for ( v = 0; v < G.vertexNum; v++) {
    if (!visited[v]) {
      DFS(G, v);
    }
  }
}


//广度优先遍历 借用队列实现 先进先出的属性
void BFS(ALGraph G, int v) {
  EdgeNode* p;
  int u, w, v;
  PSqeQueue Q = Init_SeqQueue();
  Visit(G, v);
  visited[v] = True;
  In_SeqQueue(Q, v);
  while (!Empty_SeqQueue(Q)) {
    Out_SeqQueue(Q, &u);//取出队列中的下标值
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
