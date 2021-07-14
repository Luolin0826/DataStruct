#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "ListFunction.h"
bool answer(dynlist *L){
    if (L->length == 0)
    {
        printf("No Data!");
        return false;
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