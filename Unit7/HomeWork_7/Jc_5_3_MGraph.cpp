#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "MGraphFunction.h"
#include "QueueFunction.h"
typedef enum { False, True }boolean;
boolean visited[MaxVertexNum];
//�ж��ڽӾ���洢�ı�i��j�Ƿ���·��
int IsPath_DFS(MGraph* G, int i, int j) {
	int k;
	visited[i] = True;//�ѱ�����
	for (k = 0; k < G->VertexNum; k++)
	{
		if (G->arcs[i][k] = 1 && !visited[k])//��ͨ����û�б�����
		{
			if (k == j)
			{
				return 1;//��ͨ
			}
			else {
				return IsPath_DFS(G, k, j);//���K��û�е�J�Ľ�㣬��һֱ��������
			}
		}
	}
	return 0;//������ͨ·
}

int IsPath_BFS(MGraph* G, int i, int j) {
	int k;
	PSqeQueue Q = Init_SeqQueue();
	visited[i] = True;
	In_SeqQueue(Q, i);//�������
	while (!Empty_SeqQueue(Q))
	{
		Out_SeqQueue(Q, &i);
		for (k = 0; k < G->VertexNum; k++)
		{
			if (G->arcs[i][k] == 1 && !visited[k])//��������ͨ��û�б�����
			{
				if (k == j) {
					return 1;
				}
				visited[k] = True;
				In_SeqQueue(Q, k);//�������
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