#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "ListFunction.h"
bool answer(dynlist *L, Elemtype min, Elemtype max)
{
    Elemtype i, j; //注意要给tmp赋初值
    if (L->length == 0)
    {
        printf("No Data!");
        return false;
    }
    else if (min >= max)
    {
        printf("Cheack the min and max!");
        return false;
    }
    else
    {
        for (i = 0; i < L->length && L->data[i] <= min; i++)
            ;               //先寻找大于min的第一个元素 等于号的妙用，在i=min的时候能够+1
        if (i == L->length) //没找到，给定的最小值都大于函数最大值
        {
            return false;
        }
        else //找到了最小值，开始找最大值
        {
            for (j = i + 1; j < L->length && L->data[j] < max; j++)
                ;                           //寻找小于max的第一个语句
            for (; j < L->length; i++, j++) //注意双重条件语句
            {
                L->data[i] = L->data[j];
            }
        }
        L->length = L->length - j + i;
    }
}
int main(int argc, char const *argv[])
{
    dynlist L;
    Elemtype min = 2, max = 5;
    Elemtype data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    InitList(&L);
    addDataToList(&L, data, 10);
    answer(&L, min, max);
    printflist(&L);
    return 0;
}