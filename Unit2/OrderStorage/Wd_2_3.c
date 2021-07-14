#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "ListFunction.h"
bool answer(dynlist *L, Elemtype e)
{
    Elemtype tmp = 0; //辅助
    if (L->length == 0)
    {
        printf("No Data!");
        return false;
    }
    else
    {
        // for (int i = 0; i < L->length; i++)
        // {
        //     if (L->data[i] == e)
        //     {
        //         for (int j = i; j < L->length; j++)
        //         {
        //             L->data[j] = L->data[j+1]; //将第I个元素及其之后的元素前移一位
        //         }
        //         L->length--;
        //     }
        // }
        for (int i = 0; i < L->length; i++)
        {
            if (L->data[i] == e)
            {
                tmp++;
            }
            else
                L->data[i - tmp] = L->data[i];
        }
        L->length = L->length - tmp;
        return true;
    }
}
int main(int argc, char const *argv[])
{
    dynlist L;
    Elemtype e = 3;
    Elemtype data[10] = {2, 1, 3, 5, 4, 6, 8, 7, 9, 10};
    InitList(&L);
    addDataToList(&L, data, 10);
    answer(&L, e);
    printflist(&L);
    return 0;
}