#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "ListFunction.h"
bool answer(dynlist *L, dynlist *P, dynlist *Q)
{
    int i = 0, j = 0, m = 0;
    if (P->length == 0 || Q->length == 0)
    {
        printf("No Data!");
        return false;
    }
    else if (P->length + Q->length > L->MaxSize)
    {
        printf("Memory overflow!");
        return false;
    }
    else
    {
        while (i < P->length && j < Q->length)
        {
            if (P->data[i] <= Q->data[j])
            {
                L->data[m++] = P->data[i++];
            }
            else
            {
                L->data[m++] = Q->data[j++];
            }
        }
        //此时出现了其中一个表到头了但是另一个还没结束的情况，将他们加在表后面
        while (i<P->length)
        {
            L->data[m++]=P->data[i++];
        }
        while (j<Q->length)
        {
            L->data[m++]=Q->data[j++];
        }
        L->length = m;
        return true;
    }
}
int main(int argc, char const *argv[])
{
    dynlist L, P, Q;
    Elemtype e = -1;
    Elemtype data1[8] = {1, 3, 5, 6, 8, 8, 9, 10};
    Elemtype data2[9] = {3, 4, 5, 7, 9, 12, 13, 15, 16};
    InitList(&L);
    InitList(&P);
    InitList(&Q);
    addDataToList(&P, data1, 8);
    addDataToList(&Q, data2, 9);
    answer(&L, &P, &Q);
    printflist(&L);
    return 0;
}