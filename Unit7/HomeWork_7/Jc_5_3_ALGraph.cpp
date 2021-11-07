#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "ALGraphFunction.h"
#include "QueueFunction.h"	
typedef enum { False, True }boolean;
boolean visited[MaxVertexNum];
//��ȱ���Ѱ�������֮���·��
int IsPath_DFS(ALGraph* G, int i, int j) {
	EdgeNode* p;
	visited[i] = True;
	p = G->adjlist[i].firstedge;
	while (p)
	{
		if (!visited[p->adjvertex]) {
			if (p->adjvertex == j)
			{
				return 1;//�ҵ���
			}
			else
			{
				return IsPath_DFS(G, p->adjvertex, j);
			}
		}
		p = p->next;//����P����һ�ڵ�
	}
	return 0;
}

//��ȱ���
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
					return 1;//����ͨ·
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

