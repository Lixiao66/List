/*********************
    File Name:list.h
    Author:��Ф
    Mail:mark.li@fanvil.com
    Description: ��������ڵ�Ľṹ���Լ���������������ӿڵ�����
*********************/
#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

/*��������ڵ�Ľṹ��*/
typedef struct node
{
    int data;  /*�ڵ��д�ŵ�����*/
	struct node *next;  /*��һ�ڵ�*/
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
