#pragma once
//����˳���
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define Maxsize 20
#define Datatype int
typedef struct node {
    Datatype data[Maxsize];  //ָʾ��̬���������ָ��
    int length;   //��ǰ����
} SqeList, * PSqeList;

//��ʼ����̬����
PSqeList InitList() {
    PSqeList L;
    L = (PSqeList)malloc(sizeof(SqeList));
    //L->data = (int*)malloc(Maxsize * sizeof(int));
    if (L) {
        L->length = 0;
    }
    return L;
}
//����
bool ListInsert(SqeList* L, int i, Datatype e) {
    if (i < 1 || i > L->length)  //�ж�i�ķ�Χ
    {
        return false;
    }
    if (L->length >= Maxsize) {
        return false;
    }
    for (int j = L->length; j >= i; j--) {
        L->data[j] = L->data[j - 1];  //����I��Ԫ�ؼ���֮���Ԫ�غ���һλ
    }
    L->data[i - 1] = e;  //����Ԫ��
    L->length++;
    return true;
}
//ɾ��
bool ListDelect(PSqeList L, int i, int* e) {
    if (i < 1 || i > L->length)  //�ж�i�ķ�Χ
    {
        return false;
    }
    *e = L->data[i - 1];  //����ɾ����Ԫ�ظ�ֵ��e
    for (int j = i; j < L->length; j++) {
        L->data[j - 1] = L->data[j];  //����I��Ԫ�ؼ���֮���Ԫ��ǰ��һλ
    }
    L->length--;
    return true;
}
//����
int LocateElem(SqeList L, int e) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e)  //��C�����У�����ֱ����==���жϽṹ��ĵȼ����
        {
            return i + 1;  //�����±�Ϊi��Ԫ��ֵ����e,����λ��i+1
        }
        return 0;  //�˳�ѭ����˵������ʧ��
    }
}
//��ʾ
void PrintfList(PSqeList S) {
    for (int i = 0; i < S->length; i++) {
        printf("%d ", S->data[i]);
    }
}