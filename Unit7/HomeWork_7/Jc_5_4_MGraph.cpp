#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "MGraphFunction.h"
#include "QueueFunction.h"
//ʵ�ֹ�����ȱ���Ѱ�����·��
typedef enum { False, True }boolean;
boolean visited[MaxVertexNum];
int Tree[MaxVertexNum];//��������˫�ױ�ʾ���洢�ṹ
int PathValue[MaxVertexNum];//�������������·������
//�ڽӾ���
void ShortPath_MG(MGraph* G, int i,int j) {
	PSqeQueue Q = Init_SeqQueue();
	int u, v, j;
	In_SeqQueue(Q, i);
	Tree[i] = -1;
	visited[i] = True;
	while (!Empty_SeqQueue(Q))//������������tree
	{
		Out_SeqQueue(Q, &u);
		for (v = 0; v < G->VertexNum; v++)
		{
			if (G->arcs[u][v] == 1 && !visited[v])
			{
				visited[v] = True;
				Tree[v] = u;//���˫��
				In_SeqQueue(Q, v);
			}
		}
	}
	printf("�յ㣺%d", j);
	for (i = 0; i < G->VertexNum; i++)//һ�μ����Vi��������������·��
	{
		j = i;
		while (Tree[j] != -1)//����ʼ��Ϊֹ
		{
			PathValue[i]++;//�ֱ�ͳ�Ƹ��������·��ֵ
			j = Tree[j];//����j��˫�׽��
			printf(";����%d", Tree[j]);//���·���еĽ��
		}
	}
	printf("��ʼ�㣺%d", i);
}


int main(int argc, char** argv)
{

	system("pause");
	return 0;
}

