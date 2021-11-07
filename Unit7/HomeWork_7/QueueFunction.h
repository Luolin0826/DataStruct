#pragma once
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define Maxsize 30
#define DataType int
//����ṹ��
typedef struct {
    DataType data[Maxsize];
    int front, rear;
} SqeQueue, * PSqeQueue;
//��ʼ������
PSqeQueue Init_SeqQueue() {
    PSqeQueue Q;
    Q = (SqeQueue*)malloc(sizeof(SqeQueue));
    if (Q) {
        Q->front = 0;
        Q->rear = 0;
    }
    return Q;
}
//�ж϶Կ� 0����� ��0������
int Empty_SeqQueue(PSqeQueue Q) {
    if (Q && Q->front == Q->rear) {
        return (1);
    }
    else {
        return (0);
    }
}
//�ж϶��� 0��ʾ�� ��0��ʾ��
int Full_SeqQueue(PSqeQueue Q) {
    if ((Q->rear + 1) % Maxsize == Q->front) {
        return (1);
    }
    else {
        return (0);
    }
}
//��Ӳ��� 0��ʾ���� 1��ʾ�ɹ�
int In_SeqQueue(PSqeQueue Q, DataType x) {
    if (Full_SeqQueue(Q)) {
        printf("����");
        return (0);
    }
    else {
        Q->rear = (Q->rear++) % Maxsize;
        Q->data[Q->rear] = x;
    }
    return (1);
}
//���Ӳ��� �˴���������
int Out_SeqQueue(PSqeQueue Q, DataType* x) {
    if (Empty_SeqQueue(Q)) {
        printf("�ӿ�");
        return (0);
    }
    else {
        Q->front =
            (Q->front + 1) %
            Maxsize;  //��������ͷָ�����飬frontָ��Ŀռ���û����ֵ������Ҫ����һ��
        *x = Q->data[Q->front];
        return (1);
    }
}
//��ȡͷԪ��
int Front_SeqQueue(PSqeQueue Q, DataType* x) {
    if (Empty_SeqQueue(Q)) {
        printf("�ӿ�");
        return (0);
    }
    else {
        *x = Q->data[(Q->front + 1) % Maxsize];  //ע��˴����������
        return (1);
    }
}
//���ٶ���
void Destroy_SeqQueue(PSqeQueue* Q) {
    if (*Q) {
        free(*Q);
    }
    *Q = NULL;
}
//�����������
int Print_SeqQuene(PSqeQueue Q) {
    int temp;
    if (Empty_SeqQueue(Q)) {
        printf("�ӿ�");
        return (0);
    }
    else {
        while ((Q->front) % 10 != Q->rear) {
            temp = Q->data[Q->front + 1];
            printf("%d ", temp);
            Q->front++;
        }
        return (1);
    }
}