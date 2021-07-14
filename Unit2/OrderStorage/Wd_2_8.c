#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "ListFunction.h"
bool answer(dynlist *L){
    Elemtype tmp,m,n;
    if (L->length == 0)
    {
        printf("No Data!");
        return false;
    }
    for (int i = 0; L->data[i] < L->data[i+1]; i++)//找到一个数，i+2为下标，在数组中是a[i+1]
    {
        m=i+2;//记录下b的下标
    }
    n=L->length-m;
    for (int i = 0; i < L->length/2; i++)
    {
        tmp=L->data[m+n-1-i];
        L->data[m+n-1-i]=L->data[i];
        L->data[i]=tmp;
    }
    for (int i = 0; i < n/2; i++)
    {
        tmp=L->data[n-1-i];
        L->data[n-1-i]=L->data[i];
        L->data[i]=tmp;
    }
    for (int i = 0; i < m/2; i++)
    {
        tmp=L->data[m+n-1-i];
        L->data[m+n-1-i]=L->data[n+i];
        L->data[n+i]=tmp;
    }
    return true;
    // for (int i = 0; tmp < L->length; i++)//后半部分前移
    // {
    //     data1[i]=L->data[tmp++];
    // }
    // for (int i = 0; i < tmp; i++)
    // {
    //     Elemtype m =L->length-tmp;
    //     data1[m++]=L->data[i];
    // }
    // for (int i = 0; i < L->length; i++)
    // {
    //     L->data[i]=data1[i];
    // }
}
int main(int argc, char const *argv[])
{
    dynlist L;
    Elemtype data[10] = {1, 2, 3, 5, 1, 6, 8, 7, 9, 10};
    InitList(&L);
    addDataToList(&L, data, 10);
    answer(&L);
    printflist(&L);
    return 0;
}