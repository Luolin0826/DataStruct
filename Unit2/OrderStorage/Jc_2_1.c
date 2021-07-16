#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "ListFunction.h"
bool answer(dynlist *L)
{
    if (L->length == 0)
    {
        printf("No Data!");
        return false;
    }
}
//去重函数
void DelSame(dynlist *L)
{
    for (int i = 0; i < L->length; i++)
    {
        for (int j = i + 1; j < L->length; j++)
        {
            if (L->data[i] == L->data[j]) //匹配到一样的元素
            {
                for (int n = j; n + 1 < L->length; n++)
                {
                    L->data[n] = L->data[n + 1]; //将重复项删除
                }
                L->length--;
                j--; //注意，这步操作是对连续两个重复的元素进行约束
            }
        }
    }
}
//查询函数
int GetLocation(dynlist L, Elemtype e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
        {
            return (i + 1); //返回下标
        }
        else if (i >= L.length)
        {
            return 0;
        }
    }
}
//求交集函数 1
// bool Intersection(dynlist A,dynlist B,dynlist *C){
//     Elemtype tmp=0;
//     //我们先对函数做一个去重操作
//     DelSame(&A);
//     DelSame(&B);
//     for (int i = 0; i < A.length; i++)
//     {
//         for (int j = 0; j < B.length; j++)
//         {
//             if (A.data[i]==B.data[j])
//             {
//                 C->data[tmp]=A.data[i];
//                 tmp++;
//             }
//             else
//             continue;
//         }
//     }
//     C->length=tmp;
// }
//求交集函数2
bool Intersection(dynlist A, dynlist B)
{
    Elemtype tmp = 0;
    for (int i = 0; i < A.length; i++)
    {
        for (int j = 0; j < B.length; j++)
        {
            if (!GetLocation(B, A.data[i]))
            {
                for (int n = i; n + 1 < A.length; n++)
                {
                    A.data[n] = A.data[n + 1];
                }
                tmp++;
            }
        }
    }
    A.length -= tmp;
    printf("交集是");
    printflist(&A);
    return true;
}
// //求并集操作 1,将两个元素合并之后去重
// bool Union(dynlist *A,dynlist B){
//     for (int i = 0; i < B.length; i++)
//     {
//         A->data[A->length]=B.data[i];
//         A->length++;
//     }
//     DelSame(A);
// }
//求并集操作 2,求出B中A未出现的元素，加到B中
bool Union(dynlist A, dynlist B)
{
    Elemtype tmp = 0;
    for (int i = 0; i < B.length; i++)
    {
        if (!GetLocation(A, B.data[i]))
        {
            B.data[i] = B.data[i + 1];
            tmp++;
        }
    }
    B.length = tmp;
    for (int i = 0; i < tmp; i++)
    {
        A.data[A.length + i] = B.data[i];
    }
    A.length=A.length+tmp;
    printf("并集是");
    printflist(&A);
}
int main(int argc, char const *argv[])
{
    dynlist A, B, C;
    Elemtype e = -1;
    Elemtype data1[10] = {2, 1, 3, 5, 4, 6, 8, 7, 9, 10};
    Elemtype data2[10] = {1, 4, 12, 5, 7, 9, 2, 7, 8, 11};
    InitList(&A);
    InitList(&B);
    InitList(&C);
    addDataToList(&A, data1, 10);
    addDataToList(&B, data2, 10);

    Intersection(A, B);

    Union(A, B);

    return 0;
}