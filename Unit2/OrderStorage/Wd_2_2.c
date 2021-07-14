#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "ListFunction.h"
bool answer(dynlist *L){
    Elemtype e;
    for (int i = 0; i < L->length/2; i++)
    {
        e=L->data[i];
        L->data[i]=L->data[L->length-i-1];
        L->data[L->length-i-1]=e;
    }
}
int main(int argc, char const *argv[])
{
    dynlist L;
    Elemtype e = -1;
    Elemtype data[10] = {2, 1, 3, 5, 4, 6, 8, 7, 9, 10};
    InitList(&L);
    addDataToList(&L, data, 10);
    answer(&L);
    printflist(&L);
    return 0;
}