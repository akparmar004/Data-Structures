#include<stdio.h>
#include<stdlib.h>
typedef struct queue
{
	int rollno;
	struct queue *next;
} que;
void enqueue(que**);
void dequeue(que**);
void display(que*);

void main()
{
	que *headptr=0;
	int op;
	while(1)
	{	
		printf("enter your choice : \n");
		printf("1)enqueue 2)dequeue 3)display 4)clear screen 0)exit\n");
		scanf("%d",&op);
		
		switch(op)
		{
			case 1:enqueue(&headptr); break;
			case 2:dequeue(&headptr); break;
			case 3:display(headptr); break;
			case 4:system("clear"); break;
			case 0:exit(0);
			default:printf("invalid option\n");
		}
	}
}

void enqueue(que **ptr)
{
	que *new,*last;
	new=malloc(sizeof(que));
	printf("enter number : ");
	scanf("%d",&new->rollno);
	
	if(*ptr == 0)
	{
		new->next=(*ptr);
		*ptr=new;
	}
	else
	{
		last = *ptr;
		while(last->next)
		{
			last=last->next;
		}
		new->next=0;
		last->next=new;
	}
	
	
}

void dequeue(que **ptr)
{
	if(*ptr == 0)
	{
		printf("stack is empty\n");
		return;
	}
	
	que *del = *ptr; //del pointing to first node
	*ptr = (*ptr) -> next; //update head ptr
	printf("deleted number : %d\n",del->rollno);
	free(del); //delete del ptr
	del=0;
}

void display(que *ptr)
{
	if(ptr==0)
	{
		printf("stack is empty\n");\
		return;
	}
	while(ptr)
	{
		printf("%d ",ptr->rollno);
		ptr=ptr->next;
	}
	printf("\n");
}
