#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "ALGraphFunction.h"
//��ת����ͼ
ALGraph* Covert(ALGraph* G) {
	int i,j;
	EdgeNode* q, * p;
	ALGraph* G1;
	G1 = (ALGraph*)malloc(sizeof(ALGraph));//����ռ�
	//ת����Ϣ
	G1->VertexNum = G->VertexNum;
	G1->EdgeNum = G->EdgeNum;
	for ( i = 0; i < G->VertexNum; i++)
	{
		G1->adjlist[i].vertex = G->adjlist[i].vertex;
		G1->adjlist[i].firstedge = NULL;//�߱�ָ���ÿ�
	}
	for ( i = 0; i < G->VertexNum; i++)
	{
		for (p = G->adjlist[i].firstedge; p != NULL; p = p->next) {
			j = p->adjvertex;//�߽��pָ��Ķ���
			q = (EdgeNode*)malloc(sizeof(EdgeNode));
			q->adjvertex = i;//����ת��
			q->next = G1->adjlist[j].firstedge;
			G1->adjlist[j].firstedge = q;//��β����
		}
	}
	return G1;
}

int main(int argc, char** argv)
{

	system("pause");
	return 0;
}

