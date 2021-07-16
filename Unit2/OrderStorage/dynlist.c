#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define InitSize 30
typedef int Elemtype;
typedef struct
{
    int *data;   //指示动态分配数组的指针
    int MaxSize; //最大容量
    int length;  //当前长度
} dynlist;
//初始化动态链表
void InitList(dynlist *L)
{
    L->data = (int *)malloc(InitSize * sizeof(int));
    L->length = 0;
    L->MaxSize = InitSize;
};
//插入数据
bool ListInsert(dynlist *L, int i, Elemtype e)
{
    if (i < 1 || i > L->length) //判断i的范围
    {
        return false;
    }
    if (L->length >= L->MaxSize)
    {
        return false;
    }
    for (int j = L->length; j >= i; j--)
    {
        L->data[j] = L->data[j - 1]; //将第I个元素及其之后的元素后移一位
    }
    L->data[i - 1] = e; //放置元素
    L->length++;
    return true;
}
//增加动态数组的长度
void IncreaseSize(dynlist *L, int len)
{
    int *p = L->data;
    L->data = (int *)malloc((L->MaxSize + len) * sizeof(int));
    if (L->data == NULL)
    {
        printf("Memory allocation failed!"); //内存空间判别
        exit(1);
    }

    for (int i = 0; i < L->length; i++)
    {
        L->data[i] = p[i]; //数据复制到新区域
    }
    L->MaxSize = L->MaxSize + len; //将新分配的数据地址给到data的头指针
    free(p);                       //释放p指针
}
//句尾插入单个数据
bool InsertDataToList(dynlist *L, Elemtype data)
{
    L->data[L->length] = data;
    L->length++;
}
//添加批量数据 n代表元素的个数
void addDataToList(dynlist *L, Elemtype *data, int n)
{
    for (int i = 0; i < n; i++)
    {
        InsertDataToList(L, data[i]);
        if (L->length == L->MaxSize)
        {
            printf("Apply new Memory!");
            IncreaseSize(L, InitSize);
        }
    }
}
//删除数据
bool ListDelect(dynlist *L, int i, Elemtype *e)
{
    if (i < 1 || i > L->length) //判断i的范围
    {
        return false;
    }
    *e = L->data[i - 1]; //将被删除的元素赋值给e  注意要使用*e
    for (int j = i; j < L->length; j++)
    {
        L->data[j - 1] = L->data[j]; //将第I个元素及其之后的元素前移一位
    }
    L->length--;
    return true;
}
//按值查找
int LocateElem(dynlist L, int e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == e) //在C语言中，不能直接用==来判断结构体的等价情况
        {
            return i + 1; //数组下标为i的元素值等于e,返回位序i+1
        }
        return 0; //退出循环，说明查找失败
    }
}
//按位查找
int GetElem(dynlist L, int i)
{
    return L.data[i - 1];
}

//打印数组
void printflist(dynlist *L)
{
    if (L->length == 0)
    {
        printf("NO DATA");
    }
    else
    {
        for (int i = 0; i < L->length; i++)
        {
            printf("%d\t", L->data[i]);
            if (i % 10 == 0)
            {
                printf("\n");
            }
        }
    }
}
int main()
{
    dynlist L;
    Elemtype data[20];
    InitList(&L);
    //手动增加数据
    // for (int i = 0; i < 10; i++)
    // {
    //     scanf("%d",&L.data[i]);
    //     L.length++;
    // }
    //调用增加数据
    //InsertDataToList(&L,1);
    //批量增加
    for (int i = 0; i < 20; i++)
    {
        data[i] = i;
    }
    addDataToList(&L, data, 20);

    int e = -1;
    ListDelect(&L, 3, &e);
    ListInsert(&L,12,3);
    printflist(&L);
    return 0;
}
