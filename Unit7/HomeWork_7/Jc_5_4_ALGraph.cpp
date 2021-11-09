#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "ALGraphFunction.h"
#include "QueueFunction.h"
//ʵ�ֹ�����ȱ���Ѱ�����·��
typedef enum { False, True }boolean;
boolean visited[MaxVertexNum];
int Tree[MaxVertexNum];//��������˫�ױ�ʾ���洢�ṹ
int PathValue[MaxVertexNum];//�������������·������
//�ڽӱ�
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
				Tree[p->adjvertex] = i;//˫��������
				if (p->adjvertex == j)//��ֱ�ӵ���·��
				{
					OutPath(i, j);
					return 1;//�ҵ����·��
				}
				In_SeqQueue(Q, p->adjvertex);//�½ڵ����
			}
		}
	}
	return 0;
}

void OutPath(int i, int j) {
	printf("�յ㣺%d", j);
	while (Tree[j] != -1)//����ʼ��Ϊֹ
	{
		PathValue[i]++;//�ֱ�ͳ�Ƹ��������·��ֵ
		j = Tree[j];//����j��˫�׽��
		printf(";����%d", Tree[j]);//���·���еĽ��
	}
	printf("��ʼ�㣺%d", i);
}

int main(int argc, char** argv)
{

	system("pause");
	return 0;
}

