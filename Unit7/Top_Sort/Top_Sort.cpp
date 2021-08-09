#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SeqQueue.h"
#define MaxVertexNum 30
#define Flase 0
#define True 1
//表结点
typedef char InfoType;
typedef struct node {
  int adjvertex;  //邻接点域，一般存放顶点对应的序号或者在相关的表头向量中的下标
  struct node* next;  //与下一个节点相关的信息
} EdgeNode;
//表的形式
typedef struct vnode {
  int indegree;         //入度
  int vertex;           //顶点域
  EdgeNode* firstedge;  //边表头指针
} VertexNode;
//邻接表定义
typedef struct {
  VertexNode adjlist[MaxVertexNum];  //定义一个邻接表
  int vertexNum, edgeNum;            //定义定点数和边数
} ALGraph;
//寻找入度
void FindInDegree(ALGraph* G) {
  int i;
  EdgeNode* p;
  //入度数组初始化
  for (i = 0; i < G->vertexNum; i++) {
    G->adjlist[i].indegree = 0;
  }
  //计算入度
  for (i = 0; i < G->vertexNum; i++) {
    for (p = G->adjlist[i].firstedge; p; p = p->next) {
      G->adjlist[i].indegree++;  //每遍历到一个边，都会加一个入度
    }
  }
}

void Top_Sort(ALGraph G) {
  int i, j, k, count = 0;
  int top = -1;
  EdgeNode* p;
  PSqeQueue Q = Init_SeqQueue();  //初始化顺序队列
  FindInDegree(&G);               //计算入度
  for (i = 0; i < G.vertexNum; i++) {
    if (G.adjlist[i].indegree == 0) {
      In_SeqQueue(Q, i);  //将入度为0的顶点入队
    }
  }
  while (!Empty_SeqQueue(Q)) {           //队列不空
    Out_SeqQueue(Q, &j);                 //出队
    printf("%3d", G.adjlist[j].vertex);  //输出顶点
    count++;
    for (p = G.adjlist[j].firstedge; p; p = p->next) {
      k = p->adjvertex;
      G.adjlist[k].indegree--;
      if (G.adjlist[k].indegree == 0) {
        In_SeqQueue(Q, k);  //将入度为0的顶点入队
      }
    }
  }
  //判断是否有环形图
  if (count < G.vertexNum) {
    printf("存在有向环");
  } else {
    printf("不存在有向环");
  }
}

int main(int argc, char** argv) {
  system("pause");
  return 0;
}
