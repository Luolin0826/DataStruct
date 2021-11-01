#pragma once
#define MaxVertexNum 30
//表结点
typedef char InfoType;//顶点信息
typedef struct node
{
	int adjvertex;//邻接点域
	InfoType info;//存放弧的相关信息
	struct  node* next;//与下一节点相关的信息
}EdgeNode;

//顶点结点
typedef struct {
	int no;//顶点号
	InfoType infotype;//字符型 表示这个数代表的顶点A,B...
}VertexType;//顶点
typedef struct vnode {
	VertexType vertex;//顶点域
	EdgeNode* firstedge;//表头指针表
}VertexNode;

//邻接表定义
typedef struct 
{
	VertexNode adjlist[MaxVertexNum];//定义一个邻接表
	int VertexNum, EdgeNum;//定义边数和顶点数
}ALGraph;