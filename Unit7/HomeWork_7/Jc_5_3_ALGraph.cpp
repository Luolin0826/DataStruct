#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "ALGraphFunction.h"
#include "QueueFunction.h"	
typedef enum { False, True }boolean;
boolean visited[MaxVertexNum];
//深度遍历寻找两结点之间的路径
int IsPath_DFS(ALGraph* G, int i, int j) {
	EdgeNode* p;
	visited[i] = True;
	p = G->adjlist[i].firstedge;
	while (p)
	{
		if (!visited[p->adjvertex]) {
			if (p->adjvertex == j)
			{
				return 1;//找到了
			}
			else
			{
				return IsPath_DFS(G, p->adjvertex, j);
			}
		}
		p = p->next;//访问P的下一节点
	}
	return 0;
}

//广度遍历
int IsPath_BFS(ALGraph* G, int i, int j) {
	EdgeNode* p;
	PSqeQueue Q = Init_SeqQueue();
	visited[i] = True;
	In_SeqQueue(Q, i);
	while (!Empty_SeqQueue(Q))
	{
		Out_SeqQueue(Q, &i);
		p = G->adjlist[i].firstedge;
		for (; p != NULL; p = p->next)
		{
			if (!visited[p->adjvertex]) {
				if (p->adjvertex = j)
				{
					return 1;//存在通路
				}
				visited[p->adjvertex] = True;
				In_SeqQueue(Q, p->adjvertex);
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

