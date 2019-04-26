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
typedef struct node{
    int data;  /*节点中存放的数据*/
	struct node *next;  /*下一节点*/
}Linklist;

extern Linklist* List_create();
extern int List_empty(Linklist *L);
extern int NodeNum(Linklist *L);
extern int Node_insert(Linklist *L,int num,int data);
extern void List_traverse(Linklist *L);
extern int Node_delete(Linklist *L,int num);
extern int Node_found(Linklist *L,int num);
extern int Node_set(Linklist *L,int num,int data);
extern void Linklist_delete(Linklist *L);

#endif
