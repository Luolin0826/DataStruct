#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int ElemType;

typedef struct Node
{
    ElemType data;     //数据域
    struct Node *next; //指针域
} Node, *LinkList;
LinkList createFromTail();
void printLinkList(LinkList L);

//菜单栏
void menu()
{
    printf("\n******操作菜单*******\n");
    printf("*1: 输出单链表。\n");
    printf("*2: 用位置查找数值。\n");
    printf("*3: 插入数值。\n");
    printf("*4: 删除数值。\n");
    printf("*0: 结束程序。\n");
    printf("********************\n");
}

int main()
{
    printf("*****************");
    printf("正在创建一个单链表，请稍后。。。\n");
    LinkList L;
    L = createFromTail();
    int flag;
    while (flag != 0)
    {
        menu();
        scanf("%d", &flag);
        switch (flag)
        {
        case 1:
            printLinkList(L);
            break;
        case 2:
        {
            int i;
            printf("输入想要查找的元素位置：");
            scanf("%d", &i);
            GetElem_L(L, i);
        }
        break;
        case 3:
        {
            int i;
            ElemType e;
            printf("请输入要插入的数值：");
            scanf("%d", &e);
            printf("请输入要插入的位置：");
            scanf("%d", &i);
            ListInsert_L(L, i, e);
        }
        break;
        case 4:
        {
            int i;
            printf("请输入要删除的位置：");
            scanf("%d", &i);
            ListDelete_L(L, i);
        }
        }
    }
    return 0;
}

//创建单链表
LinkList createFromTail()

{

    LinkList L;
    Node *r, *s;
    int flag = 1;
    int d;
    L = (Node *)malloc(sizeof(Node)); //该结点为头结点
    L->next = NULL;
    r = L;
    printf("请输入链表数值，输入-1结束:\n");
    while (flag)

    {
        scanf("%d", &d);
        if (d != -1)
        {

            s = (Node *)malloc(sizeof(Node));
            s->data = d;
            r->next = s;
            r = s;
        }
        else
        {
            flag = 0;
            r->next = NULL;
        }
    }
    return L;
}

//输出
void printLinkList(LinkList L)
{
    Node *p;

    p = L->next;
    if (p == NULL)
    {
        printf("该链表已被销毁！");
        return 0;
    }
    while (p != NULL)
    {
        printf("%d  ", p->data);
        p = p->next;
    }
}

//查找
void GetElem_L(LinkList L, int i)
{
    //当第i个元素存在时，其值赋给e并返回OK，否则返回ERROR
    int j, e;
    Node *p;
    p = L->next;
    j = 1; //初始化
    while (p && j < i)
    { //向后扫描，直到p指向第i个元素或p为空
        p = p->next;
        ++j;
    }
    if (!p || j > i)
        return 0; //第i个元素不存在
    e = p->data;  //取第i个元素
    printf("%d", e);
}

//插入
void ListInsert_L(LinkList L, int i, ElemType e)
{
    Node *p, *s;
    int j;
    p = L;
    j = 0;
    while (j < i - 1)
    {
        p = p->next;
        ++j;
    } //寻找第i−1个结点
    if (!p)
    {
        printf("数据溢出表长");
        return 0;
    }
    s = (Node *)malloc(sizeof(Node)); //生成新结点*s
    s->data = e;                      //将结点*s的数据域置为e
    s->next = p->next;                //将结点*s插入L中
    p->next = s;
}

//删除
void ListDelete_L(LinkList L, int i)
{
    Node *p, *r;
    int j;
    p = L;
    j = 0;
    while (p->next && j < i - 1)
    { //寻找第i个结点，并令p指向其前驱
        p = p->next;
        ++j;
    }
    if (!(p->next) || j > i - 1)
    {
        printf("删除数据不合理！\n");
        return 0; //删除位置不合理
    }
    r = p->next;       //临时保存被删结点的地址以备释放
    p->next = r->next; //改变删除结点前驱结点的指针域
    free(r);           //释放结点
    return 1;
}