#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}Linklist;

extern Linklist* List_create();
extern int List_empty(Linklist *L);
extern int NodeNum(Linklist *L);
extern int Node_insert(Linklist *L,int num,int data);
extern void List_traverse(Linklist *L);
extern int Node_delete(Linklist *L,int num);
extern int Node_found(Linklist *L,int num);
extern int Node_set(Linklist *L,int num,int data);
extern int Linklist_delete(Linklist *L);

#endif
