#pragma once
#define MaxVertexNum 30
typedef int EdgeType;//边信息
typedef char InfoType;//顶点信息
typedef struct {
	int no;//顶点号
	InfoType infotype;//字符型 表示这个数代表的顶点A,B...
}VertexType;//顶点
typedef struct 
{
	VertexType vertexs[MaxVertexNum];//存储顶点信息
	EdgeType arcs[MaxVertexNum][MaxVertexNum];//存储边界点信息
	int VertexNum, EdgeNum;//存储顶点和边数量
}MGraph;