#include "list.h"

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

int List_empty(Linklist *L)
{
	return L->next == NULL?1:0;
}

int NodeNum(Linklist *L)
{
	int count = 1;
	Linklist *s = L;
	while(s->next !=NULL){
		count++;
		s = s->next;
	}
	return count;
}

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

int Linklist_delete(Linklist *L)
{
	Linklist *p =NULL;
	Linklist *s = L;
	while(s->next !=NULL){
		p = s->next;
		s = p->next;
		free(p);
	}

	return 1;
}
