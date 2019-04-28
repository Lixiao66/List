/*********************
    File Name:list.h
    Author:李肖
    Mail:mark.li@fanvil.com
    Description: 定义链表节点的结构体以及对链表操作函数接口的声明
*********************/
#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

/*定义链表节点的结构体*/
typedef struct node
{
    int data;  /*节点中存放的数据*/
	struct node *next;  /*下一节点*/
}LinkList;

extern LinkList* CreateList();
extern int EmptyList(LinkList *L);
extern int NodeNum(LinkList *L);
extern int InsertNode(LinkList *L, int num, int data);
extern void TraverseList(LinkList *L);
extern int DeleteNode(LinkList *L, int num);
extern int FoundNode(LinkList *L, int num);
extern int SetNode(LinkList *L, int num, int data);
extern void DeleteLinkList(LinkList *L);

#endif
