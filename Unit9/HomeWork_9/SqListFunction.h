#pragma once
//定义顺序表
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define Maxsize 20
#define Datatype int
typedef struct node {
    Datatype data[Maxsize];  //指示动态分配数组的指针
    int length;   //当前长度
} SqeList, * PSqeList;

//初始化动态链表
PSqeList InitList() {
    PSqeList L;
    L = (PSqeList)malloc(sizeof(SqeList));
    //L->data = (int*)malloc(Maxsize * sizeof(int));
    if (L) {
        L->length = 0;
    }
    return L;
}
//插入
bool ListInsert(SqeList* L, int i, Datatype e) {
    if (i < 1 || i > L->length)  //判断i的范围
    {
        return false;
    }
    if (L->length >= Maxsize) {
        return false;
    }
    for (int j = L->length; j >= i; j--) {
        L->data[j] = L->data[j - 1];  //将第I个元素及其之后的元素后移一位
    }
    L->data[i - 1] = e;  //放置元素
    L->length++;
    return true;
}
//删除
bool ListDelect(PSqeList L, int i, int* e) {
    if (i < 1 || i > L->length)  //判断i的范围
    {
        return false;
    }
    *e = L->data[i - 1];  //将被删除的元素赋值给e
    for (int j = i; j < L->length; j++) {
        L->data[j - 1] = L->data[j];  //将第I个元素及其之后的元素前移一位
    }
    L->length--;
    return true;
}
//查找
int LocateElem(SqeList L, int e) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e)  //在C语言中，不能直接用==来判断结构体的等价情况
        {
            return i + 1;  //数组下标为i的元素值等于e,返回位序i+1
        }
        return 0;  //退出循环，说明查找失败
    }
}
//显示
void PrintfList(PSqeList S) {
    for (int i = 0; i < S->length; i++) {
        printf("%d ", S->data[i]);
    }
}