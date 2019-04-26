/*********************
    File Name:list.c
    Author:��Ф
    Mail:mark.li@fanvil.com
    Description: ������������ӿڵĶ���
*********************/

#include "list.h"

/**
*@Description:���������ͷ�ڵ�.
*@return �ɹ�:������׵�ַ��ʧ��:NULL.
*/
Linklist* List_create()
{
    Linklist *L = NULL;
    L = (Linklist *)malloc(sizeof(Linklist));
    if(L == NULL){
        printf("failed to malloc\n");
        return NULL;
}
    L->next = NULL;
    return L;
}

/**
*Description:�ж������Ƿ�Ϊ.
*@param L - ָ�������ͷ�ڵ�.
*@return ����Ϊ��:1 ����Ϊ��:0.
*/
int List_empty(Linklist *L)
{
    return L->next == NULL?1:0;
}

/**
*Description:��������Ľڵ���
*@param L - ָ�������ͷ�ڵ�.
*@return ��������:0 �������:����Ľڵ���
*/
int NodeNum(Linklist *L)
{
    int count = 1;
    Linklist *s = L;
    if(NULL == s)
        return 0;
    while(s->next !=NULL){
        count++;
        s = s->next;
}
    return count;
}

/**
*Description:�������в���ڵ�.
*@param L - ָ�������ͷ�ڵ�.
*@param num - �ڵ�����λ��.
*@param data - ����ڵ������.
*@return �ɹ�:0  ʧ��:-1.
*/
int Node_insert(Linklist *L,int num,int data)
{
    Linklist *p = NULL;
    Linklist *s = L;
    int i = 0;
    if(1 == num || (NodeNum(L)+1 < num)){
        printf("num is wrong\n");
        return -1;
}
    p = (Linklist *)malloc(sizeof(Linklist));
    p->next = NULL;

    for(i = 2;i < num;i++){
        s = s->next;
}

    p->data = data;
    p->next = s->next;
    s->next = p;

    return 0;
}

/**
*Description:����������ӡ�ڵ�����Լ��ڵ��ŵ�����.
*@param L - ָ�������ͷ�ڵ�.
*/
void List_traverse(Linklist *L)
{
    Linklist *p = L;
    int num = 0;
    if(List_empty(L)){
        printf("list is empty\n");
        return; 
}
    num = 2;
    while(p->next != NULL){
        p = p->next;
        printf("nodenum:%d  data = %d\n",num,p->data);
        num++;
    }
}

/**
*Description:ɾ�������е�ĳһ�ڵ�.
*@param L - ָ�������ͷ�ڵ�.
*@param num - ��ɾ���ڵ�����
*@return �ɹ�:0  ʧ��:-1
*/
int Node_delete(Linklist *L,int num)
{
    Linklist *s = L;
    Linklist *p = NULL;
    int i = 0;
    if(1 == num || NodeNum(L) < num){
        printf("num is wrong\n");
        return -1;
    }

    for(i=2;i<num;i++){
        s = s->next;             
}
    p = s->next;
    s->next = p->next;
    free(p);
    printf("data = %d\n",s->next->data);
    return 0;
}

/**
*Description:�鿴������ĳһ�ڵ��ŵ�����.
*@param L - ָ�������ͷ�ڵ�.
*@param num - ���鿴�ڵ�����.
*@return  �ɹ�:�ڵ��ŵ�����  ʧ��:0.
*/
int Node_found(Linklist *L,int num)
{
    Linklist *s = L;
    int i =0;   
    if(1 == num){
        printf("this node is headnode\n");
        return 0;
    }

    if(num < 1 || num > NodeNum(L)){
        printf("this node does not exist"); 
        return -1;
    }

    for(i = 1;i < num;i++){
        s = s->next;
    }

    return s->data;
}

/**
*Description:�޸�������ĳһ�ڵ������.
*@param L - ָ�������ͷ�ڵ�.
*@param num - ���޸Ľڵ�����
*@param data - �ڵ��޸ĺ������
*/
int Node_set(Linklist *L,int num,int data)
{
    Linklist *s = L;
    int i =0;
    if(num <= 1 || num > NodeNum(L)){
        printf("this nodenum is wrong\n");
        return 0;
    }

    for(i = 1;i < num;i++){
        s = s->next;
    }
    s->data = data;

    return 1;
}

/**
*Description:ɾ����������.
*@param L - ָ�������ͷ�ڵ�.
*/
void Linklist_delete(Linklist *L)
{
    Linklist *p =NULL;  
    Linklist *s = L;
    while(s->next !=NULL){
        p = s->next;
        s = p->next;
        free(p);
    }
}
