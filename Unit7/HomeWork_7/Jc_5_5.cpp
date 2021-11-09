#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "ALGraphFunction.h"
#include "StackFunction.h"
//ʵ�ֹ�����ȱ���Ѱ�����·��
typedef enum { False, True }boolean;
boolean visited[MaxVertexNum];
//���������ж��Ƿ񹹳ɻ�
void IsCircle(ALGraph* G) {
	int i, j, count = 0;
	int indegree[MaxVertexNum];
	PSeqStack S = Init_SeqStack();
	EdgeNode* p;
	//��������ʼ��
	for (i = 0; i < G->VertexNum; i++) {
		indegree[i] = 0;
	}
	//�������
	for (i = 0; i < G->VertexNum; i++) {
		for (p = G->adjlist[i].firstedge; p; p = p->next) {
			indegree[p->adjvertex]++;  //ÿ������һ���ߣ������һ�����
		}
	}
	//�����Ϊ0�Ķ�����ջ
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
	//�ж��Ƿ��л���ͼ
	if (count < G->VertexNum) {
		printf("��������");
		//������򻷵Ķ���
		for (i = 0; i < G->VertexNum; i++)
		{
			if (!visited[i]) {
				printf("%c", G->adjlist[i].vertex.infotype);
			}
		}
	}
	else {
		printf("����������");
	}
}



int main(int argc, char** argv)
{

	system("pause");
	return 0;
}

