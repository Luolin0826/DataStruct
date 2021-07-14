#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNode //Defined the nodetype of SingleList;
{
    ElemType data;      //Data domain
    struct LNode* next; //Pointer domain
} LNode, * LinkList;
//Initialization the SingleNode which no heading Node
bool InitialNHNode(LinkList L)
{
    L = NULL;
    return true;
}
//Initialization the SingleNode which have heading Node
LinkList InitialLNode(void)
{
    LinkList L;
    L = (LNode*)malloc(sizeof(LNode)); //Distribute HeadingNode
    if (L == NULL)                      //failed to create
    {
        printf("Error");
    }
    L->next = NULL; //there has no data
    return L;
}
//Located by i
LinkList GetElem(LinkList L, ElemType i)
{
    LinkList P; //pointer scanner node now
    int j = 0;
    P = L;             //L is pointer to heading node,0 node
    while (P && j < i) //if e == 0 ,return heading node
    {
        P = P->next;
        j++;
    }
    if (j != i || !P)
    {
        printf("I have error or list dont existence");
        
    }
    return (P);
}
//located by e
LinkList LocateElem(LinkList L, ElemType e)
{
    LNode* p = L->next;
    while (p != NULL && p->data != e)
    {
        p = p->next;
    }
    return (p);
}
//get list length
int Length(LinkList L)
{
    int len = 0;
    LNode* p = L->next;
    while (p != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}
//Post-insert operation e is element
bool InsertNextNode(LinkList P, ElemType e)
{
    LNode* s = (LNode*)malloc(sizeof(LNode));
    if (s == NULL)
    {
        printf("Fail to distribute memory");
        return false;
    }
    s->data = e;
    s->next = P->next;
    P->next = s;
    return true;
}
//Prior-insert operation,insert element e to prior of p node;
bool InsertPriorNode(LinkList P, ElemType e)
{
    LNode* s = (LNode*)malloc(sizeof(LNode));
    if (s == NULL)
    {
        printf("Fail to distribute memory");
        return false;
    }
    s->next = P->next;
    P->next = s;
    s->data = P->data;
    P->data = e;
    return true;
}
//insert e to the postion of i(have heading node)
bool ListInsert(LinkList L, ElemType i, ElemType e)
{
    LNode* P;
    if (i < 1)
    {
        printf("Having trouble whit i");
        return false;
    }
    P = GetElem(L, i - 1); //call functions
    InsertNextNode(P, e);
    return true;
}
//insert e to the postion of i(dont have heading node)
bool ListInsertNH(LinkList L, ElemType i, ElemType e)
{
    LNode* P;
    if (i < 1)
    {
        printf("Having trouble whit i");
        return false;
    }
    if (i == 1)
    {
        LNode* s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        s->next = L;
        return true;
    }
    P = GetElem(L, i - 1); //call functions
    InsertNextNode(P, e);
    return true;
}
//deleted i node , i is location;e need back
bool DelList(LinkList L, ElemType i, ElemType* e)
{
    LNode* P;
    if (i < 1)
    {
        printf("Having trouble whit i");
        return false;
    }
    P = GetElem(L, i - 1); //call functions
    LNode* Q = P->next;    //make Q pointer to an node which will been deleted
    *e = Q->data;
    P->next = Q->next;
    free(Q);
    return true;
}
//deleted special node p
bool DelNode(LNode* p)
{
    if (p = NULL)
    {
        return false;
    }
    LNode* q = p->next;
    p->data = q->data; //if p is finally node,bug will occur
    p->next = q->next;
    free(q);
    return true;
}
//尾插法
LinkList List_TailInsert(LinkList L) {
    int x;
    L = (LNode*)malloc(sizeof(LNode));
    LNode* s, * r = L;
    printf("Please input the element");
    scanf_s("%d", &x);
    while (x != 9999)
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf_s("%d", &x);
    }
    r->next = NULL;
    return L;
}
//头插法
LinkList List_HeadInsert(LinkList L) {
    int x;
    L = (LNode*)malloc(sizeof(LNode));
    L->next = NULL;
    LNode* s;
    printf("Please input the element");
    scanf_s("%d", &x);
    while (x != 9999)
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;//重点，改变这段指针
        L->next = s;
        scanf_s("%d", &x);
    }
    return L;
}
int main(int argc, char const* argv[])
{
    
    LinkList L=InitialLNode();
    List_TailInsert(L);
    return 0;
}
