#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "ListFunction.h"
//约瑟夫问题 起始数S,计数值M
bool answer(dynlist *L,Elemtype S,Elemtype M){
    int S1,w;//w存储出列的值
    if (L->length == 0)
    {
        printf("No Data!");
        return false;
    }
    S1=S-1;//数组下标
    printf("约瑟夫数列： ");
    for (int i = L->length; i > 0; i--)
    {
        S1 = (S1+M-1)%i;//M-1是因为自己也需要报数，对i取模运算来实现到头后的循环，至此，我们找到了一个要出去的数组下标
        w=L->data[S1];
        printf("%d ",w);
        for (int n = S1; n < L->length; n++)
        {
            L->data[n]=L->data[n+1];
        }
        L->length--;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    dynlist L;
    Elemtype data[10] = {2, 1, 3, 5, 4, 6, 8, 7, 9, 10};
    InitList(&L);
    addDataToList(&L, data, 10);
    answer(&L,3,5);
    return 0;
}