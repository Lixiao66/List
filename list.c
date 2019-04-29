/*********************
    File Name:list.c
    Author:��Ф
    Mail:mark.li@fanvil.com
    Description: �����ܺ����ӿڵ�ʵ��*********************/

#include "list.h"

/**
*@Description:����һ������
*@return: �ɹ�:ָ�������ָ��   ʧ��:NULL
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
*Description:�ж������Ƿ�Ϊ������.
*@param L - ָ�������ָ��
*@return: ����Ϊ��:1 ����Ϊ��:0.
*/
int EmptyList (LinkList *L)
{
    return (L->next == NULL)?1:0;
}

/**
*Description:��������Ľڵ���
*@param L - ָ�������ָ��
*@return: �ɹ�:����Ľڵ���� ʧ��:0
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
*Description:�������в���һ���ڵ�*@param L - ָ�������ָ��
*@param num - ����ڵ�����
*@param data - ����ڵ������
*@return: �ɹ�:1  ʧ��:0.
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
*Description:���������������д洢�����ݴ�ӡ����
*@param L - ָ�������ָ��
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
*Description:ɾ�������е�ĳһ�ڵ�
*@param L - ָ�������ָ��
*@param num - ����Ľڵ����
*@return: �ɹ�:1  ʧ��:0
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
*Description:�鿴������ĳһ�ڵ��ŵ�����
*@param L - ָ�������ָ��
*@param num - ����Ľڵ����
*@return:  �ɹ�:�ڵ��д�ŵ�����  ʧ��:0.
*/
int FoundNode(LinkList *L, int num)
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
*Description:�޸�������ĳһ�ڵ������
*@param L - ָ�������ָ��
*@param num - ����Ľڵ����
*@param data - �޸ĵ�����
*@return:   �ɹ�:1  ʧ��:0
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
*Description:ɾ������
*@param L - ָ�������ָ��
*/
void DeleteLinkList(LinkList *L)
{
    LinkList *p = NULL;  
    LinkList *s = L;
    while(s->next != NULL)
    {
        p = s->next;
        s = p->next;
        free(p);
    }
}

