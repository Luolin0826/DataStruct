#pragma once
#define MaxVertexNum 30
//����
typedef char InfoType;//������Ϣ
typedef struct node
{
	int adjvertex;//�ڽӵ���
	InfoType info;//��Ż��������Ϣ
	struct  node* next;//����һ�ڵ���ص���Ϣ
}EdgeNode;

//������
typedef struct {
	int no;//�����
	InfoType infotype;//�ַ��� ��ʾ���������Ķ���A,B...
}VertexType;//����
typedef struct vnode {
	VertexType vertex;//������
	EdgeNode* firstedge;//��ͷָ���
}VertexNode;

//�ڽӱ���
typedef struct 
{
	VertexNode adjlist[MaxVertexNum];//����һ���ڽӱ�
	int VertexNum, EdgeNum;//��������Ͷ�����
}ALGraph;