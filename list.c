/*********************
    File Name:list.c
    Author:李肖
    Mail:mark.li@fanvil.com
    Description: 链表功能(创建，增，删，改，查)函数接口的实现
*********************/

#include "list.h"

/**
*@Description:创建一个链表.
*@return: 成功:指向创建的链表  失败:NULL.
*/
LinkList *CreateList ()
{
    LinkList *L = NULL;
    L = (LinkList *)malloc(sizeof(LinkList));
    if (L == NULL)
    {
        printf("failed to malloc\n");
        return NULL;
    }
    L->next = NULL;
    
    return L;
}

/**
*Description:判断链表是否为空链表.
*@param L - 指向链表的指针.
*@return: 空链表:1 非空链表:0.
*/
int EmptyList (LinkList *L)
{
    return (L->next == NULL)?1:0;
}

/**
*Description:计算链表的节点数
*@param L - 指向链表的指针.
*@return: 成功:链表的节点的总个数 失败:0
*/
int NodeNum (LinkList *L)
{
    int count = 1;
    LinkList *s = L;
    if (NULL == s)
    {
        return 0;
    }
    
    while (s->next != NULL)
    {
        count++;
        s = s->next;
    }
    
    return count;
}

/**
*Description:向链表中插入一个节点
*@param L - 指向链表的指针
*@param num - 待插入的节点序号.
*@param data - 插入的数据
*@return: 成功:1  失败:0.
*/
int InsertNode(LinkList *L, int num, int data)
{
    LinkList *p = NULL;
    LinkList *s = L;
    int i = 0;
    if (1==num || (NodeNum(L)+1)<num)
    {
        printf ("num is wrong\n");
        return 0;
    }
    p = (LinkList *)malloc(sizeof(LinkList));
    p->next = NULL;

    for (i=2; i<num; i++)
    {
        s = s->next;
    }

    p->data = data;
    p->next = s->next;
    s->next = p;

    return 1;
}

/**
*Description:遍历链表
*@param L - 指向链表的指针
*/
void TraverseList(LinkList *L)
{
    LinkList *p = L;
    int num = 0;
    if (EmptyList(L))
    {
        printf ("list is empty\n");
        return; 
    }
    num = 2;
    while (p->next != NULL)
    {
        p = p->next;
        printf("nodenum:%d  data = %d\n", num, p->data);
        num++;
    }
}

/**
*Description:删除链表中的某一节点
*@param L - 指向链表的指针
*@param num - 待删除的节点序号
*@return: 成功:1  失败:0
*/
int DeleteNode (LinkList *L, int num)
{
    LinkList *s = L;
    LinkList *p = NULL;
    int i = 0;
    if (1==num || NodeNum(L)<num)
    {
        printf("num is wrong\n");
        return -1;
    }

    for (i=2; i<num; i++)
    {
        s = s->next;             
    }
    p = s->next;
    s->next = p->next;
    free(p);
    printf ("data = %d\n", s->next->data);
    return 0;
}

/**
*Description:查找链表中的某个节点
*@param L - 指向链表的指针
*@param num - 待查找的节点序号
*@return:  成功:节点里的数据  失败:0.
*/
int FoundNode(LinkList *L,int num)
{
    LinkList *s = L;
    int i =0;   
    if (1 == num){
        printf("this node is headnode\n");
        return 0;
    }

    if (num<1 || num>NodeNum(L))
    {
        printf("this node does not exist"); 
        return -1;
    }

    for (i=1; i<num; i++){
        s = s->next;
    }

    return s->data;
}

/**
*Description:修改链表中某一节点的数据
*@param L - 指向链表的指针
*@param num - 待修改的节点序号
*@param data - 修改的数据
*@return:   成功:1  失败:0
*/
int SetNode(LinkList *L, int num, int data)
{
    LinkList *s = L;
    int i =0;
    if (num<=1 || num>NodeNum(L))
    {
        printf("this nodenum is wrong\n");
        return 0;
    }

    for (i=1; i<num; i++)
    {
        s = s->next;
    }
    s->data = data;

    return 1;
}

/**
*Description:删除一个链表.
*@param L - 指向链表的指针.
*/
void DeleteLinkList(LinkList *L)
{
    LinkList *p =NULL;  
    LinkList *s = L;
    while(s->next != NULL)
    {
        p = s->next;
        s = p->next;
        free(p);
    }
}
