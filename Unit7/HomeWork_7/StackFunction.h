#pragma once
#pragma warning(disable : 6386)
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define MaxSize 20
#define DataType int
typedef struct {
    DataType data[MaxSize];  //申请一个数组空间
    int top;                 //指向栈顶的下标-1
} SeqStack, * PSeqStack;

//初始化栈空
PSeqStack Init_SeqStack(void) {
    PSeqStack S;  //定义一个指向顺序栈的指针
    S = (SeqStack*)malloc(MaxSize * sizeof(SeqStack));  //分配空间
    if (S) {
        S->top = -1;  //初始栈顶指向-1
    }
    return S;  //返回指针地址
}
//判栈空 1表示空 0 表示非空
int Empyt_SeqStack(PSeqStack S) {
    if (S->top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}
//入栈 x存储输入的值
int Push_SeqStack(PSeqStack S, DataType x) {
    if (S->top == MaxSize - 1) {
        return 0;
    }
    else {
        S->data[++S->top] = x;
        return 1;
    }
}
//出栈 x存储删除的值 因为要带值回去，所以设置成指针形式
int Pop_SeqStack(PSeqStack S, DataType* x) {
    if (Empyt_SeqStack(S)) {
        return 0;
    }
    else {
        *x = S->data[S->top];  //因为要带值回去
        S->top--;
        return 1;
    }
}
//取栈顶指针
int GetTop_SeqStack(PSeqStack S, DataType* x) {
    if (Empyt_SeqStack(S)) {
        return 0;
    }
    else {
        *x = S->data[S->top];  //因为要带值回去
        return 1;
    }
}
//销毁栈
//由于要修改栈的指针变量，所以要将指针地址传给函数，依次释放，最后讲顺序栈指针赋0
void Destroy_SeqStack(PSeqStack* S) {
    if (*S) {
        free(*S);
    }
    else {
        *S = NULL;
    }
}
//打印输出栈
void Printf_SeqStack(PSeqStack S) {
    int tmp;
    for (int i = 0; i <= S->top; i++) {
        tmp = S->data[i];
        printf("%d\t", tmp);
    }
}