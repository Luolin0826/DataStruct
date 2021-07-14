#include <stdio.h>
#define MaxSize 10
typedef struct
{
    int data[MaxSize];
    int length;
} SqList;

void InitList(SqList *L) //定义一个无参数返回的函数，L为SqList结构体类型
{
    //L=(SqList *)malloc(sizeof(SqList)); //为L分配的空间，包括一段连续的数组空间和整型int的空间
    L->length = 0; //空表长度初始化为零
}

int main()
{
    SqList L;
    InitList(&L);
    for (int i = 0; i < MaxSize; i++)
    {
        printf("data[%d]=%d\n", i, L.data[i]);
    }

    return 0;
}
