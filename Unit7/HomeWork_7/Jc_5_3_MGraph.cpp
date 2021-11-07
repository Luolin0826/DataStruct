#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "MGraphFunction.h"
#include "QueueFunction.h"
typedef enum { False, True }boolean;
boolean visited[MaxVertexNum];
//判断邻接矩阵存储的表i与j是否有路径
int IsPath_DFS(MGraph* G, int i, int j) {
	int k;
	visited[i] = True;//已被访问
	for (k = 0; k < G->VertexNum; k++)
	{
		if (G->arcs[i][k] = 1 && !visited[k])//相通并且没有被访问
		{
			if (k == j)
			{
				return 1;//相通
			}
			else {
				return IsPath_DFS(G, k, j);//检查K有没有到J的结点，即一直往下延伸
			}
		}
	}
	return 0;//不存在通路
}

int IsPath_BFS(MGraph* G, int i, int j) {
	int k;
	PSqeQueue Q = Init_SeqQueue();
	visited[i] = True;
	In_SeqQueue(Q, i);//顶点入队
	while (!Empty_SeqQueue(Q))
	{
		Out_SeqQueue(Q, &i);
		for (k = 0; k < G->VertexNum; k++)
		{
			if (G->arcs[i][k] == 1 && !visited[k])//两顶点连通且没有被访问
			{
				if (k == j) {
					return 1;
				}
				visited[k] = True;
				In_SeqQueue(Q, k);//继续入队
			}
		}
	}
	return 0;
}

int main(int argc, char** argv)
{
	system("pause");
	return 0;
}