#pragma once
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define Maxsize 30
#define DataType int
//定义结构体
typedef struct {
    DataType data[Maxsize];
    int front, rear;
} SqeQueue, * PSqeQueue;
//初始化队列
PSqeQueue Init_SeqQueue() {
    PSqeQueue Q;
    Q = (SqeQueue*)malloc(sizeof(SqeQueue));
    if (Q) {
        Q->front = 0;
        Q->rear = 0;
    }
    return Q;
}
//判断对空 0代表假 非0代表真
int Empty_SeqQueue(PSqeQueue Q) {
    if (Q && Q->front == Q->rear) {
        return (1);
    }
    else {
        return (0);
    }
}
//判断队满 0表示假 非0表示真
int Full_SeqQueue(PSqeQueue Q) {
    if ((Q->rear + 1) % Maxsize == Q->front) {
        return (1);
    }
    else {
        return (0);
    }
}
//入队操作 0表示队满 1表示成功
int In_SeqQueue(PSqeQueue Q, DataType x) {
    if (Full_SeqQueue(Q)) {
        printf("队满");
        return (0);
    }
    else {
        Q->rear = (Q->rear++) % Maxsize;
        Q->data[Q->rear] = x;
    }
    return (1);
}
//出队操作 此处犯过错误
int Out_SeqQueue(PSqeQueue Q, DataType* x) {
    if (Empty_SeqQueue(Q)) {
        printf("队空");
        return (0);
    }
    else {
        Q->front =
            (Q->front + 1) %
            Maxsize;  //牺牲的是头指针数组，front指向的空间里没有数值，所以要看下一个
        *x = Q->data[Q->front];
        return (1);
    }
}
//读取头元素
int Front_SeqQueue(PSqeQueue Q, DataType* x) {
    if (Empty_SeqQueue(Q)) {
        printf("队空");
        return (0);
    }
    else {
        *x = Q->data[(Q->front + 1) % Maxsize];  //注意此处防范假溢出
        return (1);
    }
}
//销毁队列
void Destroy_SeqQueue(PSqeQueue* Q) {
    if (*Q) {
        free(*Q);
    }
    *Q = NULL;
}
//遍历输出队列
int Print_SeqQuene(PSqeQueue Q) {
    int temp;
    if (Empty_SeqQueue(Q)) {
        printf("队空");
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