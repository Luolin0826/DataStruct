#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "ALGraphFunction.h"
//���һ���ڵ�
int AddVertex(ALGraph* G, VertexType x) {
	if (G->VertexNum >= MaxVertexNum)
	{
		printf("����Ԫ������");
		return 0;
	}
	G->adjlist[G->VertexNum].vertex = x;
	G->adjlist[G->VertexNum].firstedge = NULL;
	G->VertexNum++;
	return 1;
}

//��ͼ�в���һ����
int AddArc(ALGraph* G, VertexType X, VertexType Y) {
	int i, j, k;
	EdgeNode* s;
	i = -1; j = -1;
	for (k = 0; k < G->VertexNum; k++)
	{
		if (G->adjlist[k].vertex == X) {
			i = k;
		}
		if (G->adjlist[k].vertex == Y) {
			j = k;
		}
	}
	if (i == -1 || j == -1)
	{
		printf("�ڵ㲻����");
	}
	else {
		s = G->adjlist[i].firstedge;//��������
		while (s && (s->adjvertex != j))//�鿴����·���Ƿ��Ѿ�����
		{
			s = s->next;
		}
		if (!s)//ͼ��û������·��
		{
			EdgeNode* p, * q;//���������߽��
			//�����Ƕ��ڽӱ��I�н��д���
			p = (EdgeNode*)malloc(sizeof(EdgeNode));//����ռ�
			p->adjvertex = j;//Ŀ�Ľ��
			p->next = G->adjlist[i].firstedge;
			G->adjlist[i].firstedge = p;//��β���
			//�����Ƕ��ڽӱ��J�н��д���
			q = (EdgeNode*)malloc(sizeof(EdgeNode));
			q->adjvertex = i;//Ŀ�Ľ�����
			q->next = G->adjlist[j].firstedge;
			G->adjlist[j].firstedge = q;//��β���
			G->EdgeNum++;//����++
			return 1;
		}
		else
		{
			printf("ͼ���Ѵ���������");
			return 0;
		}
	}
}

//ɾ��һ���ڵ�
int DelVertex(ALGraph* G, VertexType X) {
	int i = -1, j, k;
	EdgeNode* s, * p, * q;
	for (k = 0; k < G->VertexNum; k++)//��ѯX�ı��
	{
		if (G->adjlist[k].vertex == X)
		{
			i = k;
		}
	}
	if (i == -1)
	{
		printf("�ڵ㲻����");
		return 0;
	}
	else
	{
		//ɾ����X��صı�
		s = G->adjlist[i].firstedge;
		while (s)
		{
			p = G->adjlist[s->adjvertex].firstedge;
			if (p->adjvertex == i)//�ǵ�һ���߱��㣬�޸�ͷ�ڵ�
			{
				G->adjlist[s->adjvertex].firstedge = p->next;
				free(p);
			}
			else//���ǵ�һ���߱���
			{
				while (p->next->adjvertex != i);//�ҵ��Ǹ�����ǰ��
				{
					p = p->next;
				}
				q = p->next;
				p->next = q->next;//�߼���ɾ��q���
				free(q);
				G->EdgeNum--;//ɾȥһ������
			}
		}
	}
	//���������
	for (j = i; j < G->VertexNum - 1; j++)//����Ҫע��
	{
		G->adjlist[j].firstedge = G->adjlist[j + 1].firstedge;
		G->adjlist[j].vertex = G->adjlist[j + 1].vertex;
	}
	G->VertexNum--;//�������һ��
	//���������ζ�adjvertex >i ��ֵ�����޸�
	for (j = 0; j < G->VertexNum; j++)
	{
		p = G->adjlist[j].firstedge;
		while (p)
		{
			if (p->adjvertex > i) {
				p->adjvertex = p->adjvertex - 1;
			}
			p = p->next;
		}
	}
	return 1;
}

//ɾ��һ����
//ɾ��adjlist[i].firstedgeΪͷָ���������ɾ��ֵΪj�ı߱���
int DelArc(ALGraph* G, int i, int j) {
	EdgeNode* s, * p;
	s = G->adjlist[i].firstedge;
	if (s && s->adjvertex == j)//�ǵ�һ���ڵ�
	{
		G->adjlist[s->adjvertex].firstedge = s->next;
		free(s);
		return 1;
	}
	else//���ǵ�һ���ڵ�
	{
		while (s && s->next && s->next->adjvertex != j)
		{
			s = s->next;
		}
		if (s->next == NULL && s == NULL)
		{
			printf("û������ڵ�");
			return 0;
		}
		else
		{
			p = s->next;
			s->next = p->next;
			free(p);
			return 1;
		}
	}
}
//ɾ��X��Y֮��ı�
int DelEdge(ALGraph* G, VertexType X, VertexType Y) {
	int i, j, k;
	EdgeNode* s;
	i = -1; j = -1;
	for (k = 0; k < G->VertexNum; k++)
	{
		if (G->adjlist[k].vertex == X) {
			i = k;
		}
		if (G->adjlist[k].vertex == Y) {
			j = k;
		}
	}
	if (i == -1 || j == -1)
	{
		printf("�ڵ㲻����");
	}
	if (DelArc(G, i, j) && DelArc(G, j, i))
	{
		G->EdgeNum--;
		return 1;//ɾ���ɹ�
	}
	else
	{
		return 0;//ɾ��ʧ��
	}
}
int main(int argc, char** argv)
{
	system("pause");
	return 0;
}