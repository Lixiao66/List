/*********************
    File Name:list.c
    Author:ÀîĞ¤
    Mail:mark.li@fanvil.com
    Description: Á´±í¹¦ÄÜº¯Êı½Ó¿ÚµÄÊµÏÖ*********************/

#include "list.h"

/**
*@Description:´´½¨Ò»¸öÁ´±í
*@return: ³É¹¦:Ö¸ÏòÁ´±íµÄÖ¸Õë	§Ê§°Ü:NULL.
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
*Description:ÅĞ¶ÏÁ´±íÊÇ·ñÎª¿ÕÁ´±í.
*@param L - Ö¸ÏòÁ´±íµÄÖ¸Õë
*@return: Á´±íÎª¿Õ:1 Á´±í²»Îª¿Õ:0.
*/
int EmptyList (LinkList *L)
{
    return (L->next == NULL)?1:0;
}

/**
*Description:¼ÆËãÁ´±íµÄ½ÚµãÊı
*@param L - Ö¸ÏòÁ´±íµÄÖ¸Õë
*@return: ³É¹¦:Á´±íµÄ½Úµã¸öÊı Ê§°Ü:0
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
*Description:ÏòÁ´±íÖĞ²åÈëÒ»¸ö½Úµã*@param L - Ö¸ÏòÁ´±íµÄÖ¸Õë
*@param num - ²åÈë½ÚµãµÄĞòºÅ
*@param data - ²åÈë½ÚµãµÄÊı¾İ
*@return: ³É¹¦:1  Ê§°Ü:0.
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
*Description:±éÀúÁ´±í£¬°ÑÁ´±íÖĞ´æ´¢µÄÊı¾İ´òÓ¡³öÀ´
*@param L - Ö¸ÏòÁ´±íµÄÖ¸Õë
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
*Description:É¾³ıÁ´±íÖĞµÄÄ³Ò»½Úµã
*@param L - Ö¸ÏòÁ´±íµÄÖ¸Õë
*@param num - Á´±íµÄ½ÚµãĞòºÅ
*@return: ³É¹¦¹ı:1  Ê§°Ü:0
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
*Description:²é¿´Á´±íÖĞÄ³Ò»½Úµã´æ·ÅµÄÊı¾İ
*@param L - Ö¸ÏòÁ´±íµÄÖ¸Õë
*@param num - Á´±íµÄ½ÚµãĞòºÅ
*@return:  ³É¹¦:½ÚµãÖĞ´æ·ÅµÄÊı¾İ  Ê§°Ü:0.
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
*Description:ĞŞ¸ÄÁ´±íÖĞÄ³Ò»½ÚµãµÄÊı¾İ
*@param L - Ö¸ÏòÁ´±íµÄÖ¸Õë
*@param num - Á´±íµÄ½ÚµãĞòºÅ
*@param data - ĞŞ¸ÄµÄÊı¾İ
*@return:   ³É¹¦:1  Ê§°Ü:0
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
*Description:É¾³ıÁ´±í
*@param L - Ö¸ÏòÁ´±íµÄÖ¸Õë
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

