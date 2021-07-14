#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "ListFunction.h"
//判断一个最小数，删除并将其返回，空出的数由最后一元素补齐，顺序表为空则提示出错并退出运行
bool answer(dynlist *L, Elemtype *e)
{
    int *p = L->data;
    *e = L->data[0]; //假设0号最小
    Elemtype pst;    //定位
    if (L->length == 0)
    {
        printf("No Data!");
        return false;
    }
    else
    {
        for (int i = 1; i < L->length; i++)
        {
            if (L->data[i] < *e)
            {
                *e = L->data[i];
                pst = i; //记录定位
            }
            else
                continue;
        }
        L->data[pst]=L->data[L->length-1];
        return true;
    }
}
int main(int argc, char const *argv[])
{
    dynlist L;
    Elemtype e = -1;
    Elemtype data[10] = {2, 1, 3, 5, 4, 6, 8, 7, 9, 10};
    InitList(&L);
    addDataToList(&L, data, 10);
    answer(&L, &e);
    printf("The minnum is %d\n", e);
    printflist(&L);
    return 0;
}
