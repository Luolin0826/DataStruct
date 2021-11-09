#pragma once
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//定义顺序表
#define Maxsize 20
#define Datatype int
//链表
typedef struct node {
    Datatype data;
    struct node* next;
} Lnode, * LinkList;
//创建
LinkList Creat_LinkList() {
    LinkList L;
    L = (LinkList)malloc(sizeof(LinkList));
    if (L) {
        L->next = NULL;
    }
    return L;
}
LinkList GetElem(LinkList L, Datatype i) {
    LinkList P;  // pointer scanner node now
    int j = 0;
    P = L;              // L is pointer to heading node,0 node
    while (P && j < i)  // if e == 0 ,return heading node
    {
        P = P->next;
        j++;
    }
    if (j != i || !P) {
        printf("I have error or list dont existence");
    }
    return (P);
}
// located by e
LinkList LocateElem(LinkList L, Datatype e) {
    Lnode* p = L->next;
    while (p != NULL && p->data != e) {
        p = p->next;
    }
    return (p);
}
// get list length
int Length(LinkList L) {
    int len = 0;
    Lnode* p = L->next;
    while (p != NULL) {
        p = p->next;
        len++;
    }
    return len;
}
// Post-insert operation e is element
bool InsertNextNode(LinkList P, Datatype e) {
    Lnode* s = (Lnode*)malloc(sizeof(Lnode));
    if (s == NULL) {
        printf("Fail to distribute memory");
        return false;
    }
    s->data = e;
    s->next = P->next;
    P->next = s;
    return true;
}
// Prior-insert operation,insert element e to prior of p node;
bool InsertPriorNode(LinkList P, Datatype e) {
    Lnode* s = (Lnode*)malloc(sizeof(Lnode));
    if (s == NULL) {
        printf("Fail to distribute memory");
        return false;
    }
    s->next = P->next;
    P->next = s;
    s->data = P->data;
    P->data = e;
    return true;
}
// insert e to the postion of i(have heading node)
bool ListInsert(LinkList L, Datatype i, Datatype e) {
    Lnode* P;
    if (i < 1) {
        printf("Having trouble whit i");
        return false;
    }
    P = GetElem(L, i - 1);  // call functions
    InsertNextNode(P, e);
    return true;
}
// insert e to the postion of i(dont have heading node)
bool ListInsertNH(LinkList L, Datatype i, Datatype e) {
    Lnode* P;
    if (i < 1) {
        printf("Having trouble whit i");
        return false;
    }
    if (i == 1) {
        Lnode* s = (Lnode*)malloc(sizeof(Lnode));
        s->data = e;
        s->next = L;
        return true;
    }
    P = GetElem(L, i - 1);  // call functions
    InsertNextNode(P, e);
    return true;
}
// deleted i node , i is location;e need back
bool DelList(LinkList L, Datatype i, Datatype* e) {
    Lnode* P;
    if (i < 1) {
        printf("Having trouble whit i");
        return false;
    }
    P = GetElem(L, i - 1);  // call functions
    Lnode* Q = P->next;     // make Q pointer to an node which will been deleted
    *e = Q->data;
    P->next = Q->next;
    free(Q);
    return true;
}
// deleted special node p
bool DeLnode(Lnode* p) {
    if (p = NULL) {
        return false;
    }
    Lnode* q = p->next;
    p->data = q->data;  // if p is finally node,bug will occur
    p->next = q->next;
    free(q);
    return true;
}
//尾插法
LinkList List_TailInsert(LinkList L) {
    int x;
    L = (Lnode*)malloc(sizeof(Lnode));
    Lnode* s, * r = L;
    printf("Please input the element");
    scanf_s("%d", &x);
    while (x != 9999) {
        s = (Lnode*)malloc(sizeof(Lnode));
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
    L = (Lnode*)malloc(sizeof(Lnode));
    L->next = NULL;
    Lnode* s;
    printf("Please input the element");
    scanf_s("%d", &x);
    while (x != 9999) {
        s = (Lnode*)malloc(sizeof(Lnode));
        s->data = x;
        s->next = L->next;  //重点，改变这段指针
        L->next = s;
        scanf_s("%d", &x);
    }
    return L;
}

//显示
void PrintfList(LinkList L) {
    LinkList p;
    p = L->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
}