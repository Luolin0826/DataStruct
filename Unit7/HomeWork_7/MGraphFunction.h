#pragma once
#define MaxVertexNum 30
typedef int EdgeType;//����Ϣ
typedef char InfoType;//������Ϣ
typedef struct {
	int no;//�����
	InfoType infotype;//�ַ��� ��ʾ���������Ķ���A,B...
}VertexType;//����
typedef struct 
{
	VertexType vertexs[MaxVertexNum];//�洢������Ϣ
	EdgeType arcs[MaxVertexNum][MaxVertexNum];//�洢�߽����Ϣ
	int VertexNum, EdgeNum;//�洢����ͱ�����
}MGraph;