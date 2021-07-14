#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "ListFunction.h"
bool answer(dynlist *L){
    Elemtype tmp=0;
    if (L->length == 0)
    {
        printf("No Data!");
        return false;
    }
    for (int i = 0; i < L->length; i++)
    {
        if (L->data[i+1]==L->data[i])
        {
            tmp++;
        }
        else
        {
            L->data[i-tmp]=L->data[i];
        }
    }
    L->length=L->length-tmp;
    return true;
}
int main(int argc, char const *argv[])
{
    dynlist L;
    Elemtype e = -1;
    Elemtype data[10] = {1, 1, 2, 2, 2, 6, 8, 9, 9, 10};
    InitList(&L);
    addDataToList(&L, data, 10);
    answer(&L);
    printflist(&L);
    return 0;
}