#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "ALGraphFunction.h"
#include "StackFunction.h"
//实现广度优先遍历寻找最短路径
typedef enum { False, True }boolean;
boolean visited[MaxVertexNum];
//拓扑排序判断是否构成环
void IsCircle(ALGraph* G) {
	int i, j, count = 0;
	int indegree[MaxVertexNum];
	PSeqStack S = Init_SeqStack();
	EdgeNode* p;
	//入度数组初始化
	for (i = 0; i < G->VertexNum; i++) {
		indegree[i] = 0;
	}
	//计算入度
	for (i = 0; i < G->VertexNum; i++) {
		for (p = G->adjlist[i].firstedge; p; p = p->next) {
			indegree[p->adjvertex]++;  //每遍历到一个边，都会加一个入度
		}
	}
	//将入度为0的顶点入栈
	for (i = 0; i < G->VertexNum; i++) {
		if (indegree[i] == 0) {
			Push_SeqStack(S, i);
		}
	}
	while (!Empyt_SeqStack(S))
	{
		Pop_SeqStack(S, &i);
		visited[i] = True;
		count++;
		for (p = G->adjlist[i].firstedge; p != NULL; p = p->next)
		{
			j = p->adjvertex;
			indegree[j]--;
			if (indegree[j] == 0)
			{
				Push_SeqStack(S, j);
			}
		}
	}
	//判断是否有环形图
	if (count < G->VertexNum) {
		printf("存在有向环");
		//输出有向环的顶点
		for (i = 0; i < G->VertexNum; i++)
		{
			if (!visited[i]) {
				printf("%c", G->adjlist[i].vertex.infotype);
			}
		}
	}
	else {
		printf("不存在有向环");
	}
}



int main(int argc, char** argv)
{

	system("pause");
	return 0;
}

