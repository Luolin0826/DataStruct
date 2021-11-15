#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "LinkListFunction.h"

//��ѡ������ ѡ��һ����ֵ�����뵽����������
//���� �����ڴ˷ֱ������ֵ���н���
void SelectSort(LinkList H) {
    LinkList p, q, min;
    Datatype tmp;
    p = H->next;
    min = Creat_LinkList();
    while (p != NULL) {
        //�ڴ˷�������һ����Ŀ��  ������ҪѰ��һ����Сֵ ����Сֵ��p�����ݽ��н���
        q = p;
        min = q;   //���������������� ע��ÿ��ѭ���ĳ�ʼ������Ȼ������ϴ�ѭ������������ ���ʧ��
        while (q != NULL) {  //Ѱ����Сֵ
            if (min->data > q->data) {
                min = q;
            }
            q = q->next;
        }
        //��ʱ �����Ѿ��ҵ�����α��������е���С�ڵ�q��Ӧ�ĵ�ַmin
        //�����ǽ����ߵ�ֵ�ӻ�һ�°�
        tmp = min->data;
        min->data = p->data;
        p->data = tmp;
        //������һ�����еĶԱ�
        p = p->next;
    }
}

int main(int argc, char** argv)
{
    LinkList L, S;
    S = Creat_LinkList();
    L = Creat_LinkList();
    int a[15] = { 1, 2, 5, 6, 4, 7, 8, 9, 0, 2, 5, 4, 1, 8, 7 };
    int b[15] = { 1, 4, 5, 6, 6, 7, 8, 9, 10, 20, 5, 7, 8, 32, 5 };
    for (int i = 0; i < 15; i++) {
        ListInsert(L, i + 1, a[i]);
        ListInsert(S, i + 1, b[i]);
    }
    SelectSort(S);
    PrintfList(S);
    system("pause");
    return 0;
}

