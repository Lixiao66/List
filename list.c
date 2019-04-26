/*********************
    File Name:list.c
    Author:李肖
    Mail:mark.li@fanvil.com
    Description: 链表操作函数接口的定义
*********************/

#include "list.h"

/**
*@Description:创建链表的头节点.
*@return 成功:链表的首地址，失败:NULL.
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
*Description:判断链表是否为.
*@param L - 指向链表的头节点.
*@return 链表为空:1 链表不为空:0.
*/
int List_empty(Linklist *L)
{
    return L->next == NULL?1:0;
}

/**
*Description:计算链表的节点数
*@param L - 指向链表的头节点.
*@return 链表不存在:0 链表存在:链表的节点数
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
*Description:向链表中插入节点.
*@param L - 指向链表的头节点.
*@param num - 节点插入的位置.
*@param data - 插入节点的数据.
*@return 成功:0  失败:-1.
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
*Description:遍历链表，打印节点序号以及节点存放的数据.
*@param L - 指向链表的头节点.
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
*Description:删除链表中的某一节点.
*@param L - 指向链表的头节点.
*@param num - 待删除节点的序号
*@return 成功:0  失败:-1
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
*Description:查看链表中某一节点存放的数据.
*@param L - 指向链表的头节点.
*@param num - 待查看节点的序号.
*@return  成功:节点存放的数据  失败:0.
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
*Description:修改链表中某一节点的数据.
*@param L - 指向链表的头节点.
*@param num - 待修改节点的序号
*@param data - 节点修改后的数据
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
*Description:删除整个链表.
*@param L - 指向链表的头节点.
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
