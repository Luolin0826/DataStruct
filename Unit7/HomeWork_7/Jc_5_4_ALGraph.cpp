#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "ALGraphFunction.h"
#include "QueueFunction.h"
//实现广度优先遍历寻找最短路径
typedef enum { False, True }boolean;
boolean visited[MaxVertexNum];
int Tree[MaxVertexNum];//生成树的双亲表示法存储结构
int PathValue[MaxVertexNum];//数到各个顶点的路径长度
//邻接表
int ShortPath_ALG(ALGraph* G, int i, int j) {
	EdgeNode* p;
	int k;
	PSqeQueue Q = Init_SeqQueue();
	Tree[i] = -1;
	visited[i] = True;
	In_SeqQueue(Q, i);
	while (!Empty_SeqQueue(Q))
	{
		Out_SeqQueue(Q, &i);
		p = G->adjlist[i].firstedge;
		for (; p != NULL; p = p->next)
		{
			if (!visited[p->adjvertex]) {
				visited[p->adjvertex] = True;
				Tree[p->adjvertex] = i;//双亲树构建
				if (p->adjvertex == j)//有直接到的路径
				{
					OutPath(i, j);
					return 1;//找到最短路径
				}
				In_SeqQueue(Q, p->adjvertex);//新节点入队
			}
		}
	}
	return 0;
}

void OutPath(int i, int j) {
	printf("终点：%d", j);
	while (Tree[j] != -1)//到起始点为止
	{
		PathValue[i]++;//分别统计各个顶点的路径值
		j = Tree[j];//访问j的双亲结点
		printf("途径：%d", Tree[j]);//输出路径中的结点
	}
	printf("起始点：%d", i);
}

int main(int argc, char** argv)
{

	system("pause");
	return 0;
}

