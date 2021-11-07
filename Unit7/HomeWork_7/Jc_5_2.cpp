#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "ALGraphFunction.h"
//添加一个节点
int AddVertex(ALGraph* G, VertexType x) {
	if (G->VertexNum >= MaxVertexNum)
	{
		printf("表中元素已满");
		return 0;
	}
	G->adjlist[G->VertexNum].vertex = x;
	G->adjlist[G->VertexNum].firstedge = NULL;
	G->VertexNum++;
	return 1;
}

//往图中插入一条边
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
		printf("节点不存在");
	}
	else {
		s = G->adjlist[i].firstedge;//辅助变量
		while (s && (s->adjvertex != j))//查看这条路径是否已经存在
		{
			s = s->next;
		}
		if (!s)//图中没有这条路经
		{
			EdgeNode* p, * q;//申请两个边界点
			//以下是对邻接表第I行进行处理
			p = (EdgeNode*)malloc(sizeof(EdgeNode));//申请空间
			p->adjvertex = j;//目的结点
			p->next = G->adjlist[i].firstedge;
			G->adjlist[i].firstedge = p;//首尾相接
			//以下是对邻接表第J行进行处理
			q = (EdgeNode*)malloc(sizeof(EdgeNode));
			q->adjvertex = i;//目的结点序号
			q->next = G->adjlist[j].firstedge;
			G->adjlist[j].firstedge = q;//首尾相接
			G->EdgeNum++;//边数++
			return 1;
		}
		else
		{
			printf("图中已存在这条边");
			return 0;
		}
	}
}

//删除一个节点
int DelVertex(ALGraph* G, VertexType X) {
	int i = -1, j, k;
	EdgeNode* s, * p, * q;
	for (k = 0; k < G->VertexNum; k++)//查询X的编号
	{
		if (G->adjlist[k].vertex == X)
		{
			i = k;
		}
	}
	if (i == -1)
	{
		printf("节点不存在");
		return 0;
	}
	else
	{
		//删除与X相关的边
		s = G->adjlist[i].firstedge;
		while (s)
		{
			p = G->adjlist[s->adjvertex].firstedge;
			if (p->adjvertex == i)//是第一个边表结点，修改头节点
			{
				G->adjlist[s->adjvertex].firstedge = p->next;
				free(p);
			}
			else//不是第一个边表结点
			{
				while (p->next->adjvertex != i);//找到那个结点的前驱
				{
					p = p->next;
				}
				q = p->next;
				p->next = q->next;//逻辑上删除q结点
				free(q);
				G->EdgeNum--;//删去一条边数
			}
		}
	}
	//调整顶点表
	for (j = i; j < G->VertexNum - 1; j++)//这里要注意
	{
		G->adjlist[j].firstedge = G->adjlist[j + 1].firstedge;
		G->adjlist[j].vertex = G->adjlist[j + 1].vertex;
	}
	G->VertexNum--;//顶点减少一个
	//以下是依次对adjvertex >i 域值进行修改
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

//删除一条边
//删除adjlist[i].firstedge为头指针的链表中删除值为j的边表结点
int DelArc(ALGraph* G, int i, int j) {
	EdgeNode* s, * p;
	s = G->adjlist[i].firstedge;
	if (s && s->adjvertex == j)//是第一个节点
	{
		G->adjlist[s->adjvertex].firstedge = s->next;
		free(s);
		return 1;
	}
	else//不是第一个节点
	{
		while (s && s->next && s->next->adjvertex != j)
		{
			s = s->next;
		}
		if (s->next == NULL && s == NULL)
		{
			printf("没有这个节点");
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
//删除X与Y之间的边
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
		printf("节点不存在");
	}
	if (DelArc(G, i, j) && DelArc(G, j, i))
	{
		G->EdgeNum--;
		return 1;//删除成功
	}
	else
	{
		return 0;//删除失败
	}
}
int main(int argc, char** argv)
{
	system("pause");
	return 0;
}