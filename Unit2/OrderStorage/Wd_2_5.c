#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "ListFunction.h"
bool answer(dynlist *L, Elemtype min, Elemtype max)
{
    Elemtype tmp = 0; //注意要给tmp赋初值
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
        for (int i = 0; i < L->length; i++)
        {
            if (min < L->data[i] && L->data[i] < max)
            {
                tmp++;
            }
            else
            {
                L->data[i - tmp] = L->data[i];
            }
        }
        L->length = L->length - tmp;
    }
    return true;
}
int main(int argc, char const *argv[])
{
    dynlist L;
    Elemtype min = 8, max = 5;
    Elemtype data[10] = {2, 1, 3, 5, 4, 6, 8, 7, 9, 10};
    InitList(&L);
    addDataToList(&L, data, 10);
    answer(&L, min, max);
    printflist(&L);
    return 0;
}