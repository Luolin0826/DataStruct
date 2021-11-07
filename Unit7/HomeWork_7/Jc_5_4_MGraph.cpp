#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "MGraphFunction.h"
#include "QueueFunction.h"
//实现广度优先遍历寻找最短路径
typedef enum { False, True }boolean;
boolean visited[MaxVertexNum];
int Tree[MaxVertexNum];//生成树的双亲表示法存储结构
int PathValue[MaxVertexNum];//数到各个顶点的路径长度
//邻接矩阵
void ShortPath_MG(MGraph* G, int i,int j) {
	PSqeQueue Q = Init_SeqQueue();
	int u, v, j;
	In_SeqQueue(Q, i);
	Tree[i] = -1;
	visited[i] = True;
	while (!Empty_SeqQueue(Q))//构筑辅助数组tree
	{
		Out_SeqQueue(Q, &u);
		for (v = 0; v < G->VertexNum; v++)
		{
			if (G->arcs[u][v] == 1 && !visited[v])
			{
				visited[v] = True;
				Tree[v] = u;//标记双亲
				In_SeqQueue(Q, v);
			}
		}
	}
	printf("终点：%d", j);
	for (i = 0; i < G->VertexNum; i++)//一次计算从Vi到各个顶点的最短路径
	{
		j = i;
		while (Tree[j] != -1)//到起始点为止
		{
			PathValue[i]++;//分别统计各个顶点的路径值
			j = Tree[j];//访问j的双亲结点
			printf("途径：%d", Tree[j]);//输出路径中的结点
		}
	}
	printf("起始点：%d", i);
}


int main(int argc, char** argv)
{

	system("pause");
	return 0;
}

