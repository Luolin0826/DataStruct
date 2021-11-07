#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "ALGraphFunction.h"
//翻转有向图
ALGraph* Covert(ALGraph* G) {
	int i,j;
	EdgeNode* q, * p;
	ALGraph* G1;
	G1 = (ALGraph*)malloc(sizeof(ALGraph));//申请空间
	//转移信息
	G1->VertexNum = G->VertexNum;
	G1->EdgeNum = G->EdgeNum;
	for ( i = 0; i < G->VertexNum; i++)
	{
		G1->adjlist[i].vertex = G->adjlist[i].vertex;
		G1->adjlist[i].firstedge = NULL;//边表指针置空
	}
	for ( i = 0; i < G->VertexNum; i++)
	{
		for (p = G->adjlist[i].firstedge; p != NULL; p = p->next) {
			j = p->adjvertex;//边结点p指向的顶点
			q = (EdgeNode*)malloc(sizeof(EdgeNode));
			q->adjvertex = i;//方向转向
			q->next = G1->adjlist[j].firstedge;
			G1->adjlist[j].firstedge = q;//首尾相连
		}
	}
	return G1;
}

int main(int argc, char** argv)
{

	system("pause");
	return 0;
}

