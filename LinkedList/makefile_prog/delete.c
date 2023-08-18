#include"header.h"
void delete_all(sll **ptr)
{
	if(*ptr==0)
	{
		printf("No records available to delete");
		return;
	}
	sll *del;
	while(*ptr)
	{
		del=*ptr;
		*ptr=(*ptr)->next;
		free(del);
		del=0;
	}
}

void delete_node(sll **ptr)
{
	sll *p,*q;
	p=q=*ptr;
	int op;	
	
	if(*ptr==0)
	{
		printf("no nodes are available to delete\n");
		return;
	}
	
	printf("Enter information related to student : \n");
	printf("1)rollno 2)name 3)marks : \n");
	scanf("%d",&op);
	
	switch(op)
	{
		case 1: int num;
			printf("Enter roll no : ");
			scanf("%d",&num);
	
			while(p)
			{
				if(p->rollno==num)
				{
					if(p==*ptr)
					*ptr=p->next;
					else
					q->next=p->next;
					free(p);
					p=0;
					return;	
				}
			q=p;
			p=p->next;
			}
			if(p==0)
			printf("rollno not found in records..\n");
		break;
		case 2: char name[10];
			printf("Enter name : ");
			scanf("%s",name);
			
			while(p)
			{
				if(strcmp(p->name,name)==0)
				{
					if(p==*ptr)
					*ptr=p->next;
					else
					q->next=p->next;
					
					free(p);
					p=0;
					return;	
				}
			q=p;
			p=p->next;
			}
			if(p==0)
			printf("name not found in records..\n");
		break;
		
		case 3:float marks;
			printf("Enter marks : ");
			scanf("%f",&marks);
			
			while(p)
			{
				if(p->marks==marks)
				{
					if(p==*ptr)
					*ptr=p->next;
					else
					q->next=p->next;
					free(p);
					p=0;
					return;	
				}
			q=p;
			p=p->next;
			}
			if(p==0)
			printf("marks not found in records..\n");
			break;
		default : printf("invalid option");
			  return;
			
	}
}
