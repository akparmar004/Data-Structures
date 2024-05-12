#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
	int rollno;
	struct stack *next;
} stk;
void push(stk**);
void pop(stk**);
void display(stk*);

void main()
{
	stk *headptr=0;
	int op;
	while(1)
	{	
		printf("enter your choice : \n");
		printf("1)push 2)pop 3)display 4)clear screen 0)exit\n");
		scanf("%d",&op);
		
		switch(op)
		{
			case 1:push(&headptr); break;
			case 2:pop(&headptr); break;
			case 3:display(headptr); break;
			case 4:system("clear"); break;
			case 0:exit(0);
			default:printf("invalid option\n");
		}
	}
}

void push(stk **ptr)
{
	stk *new;
	new=malloc(sizeof(stk));
	printf("enter number : ");
	scanf("%d",&new->rollno);
	
	new->next=(*ptr);
	*ptr=new;
}

void pop(stk **ptr)
{
	if(*ptr == 0)
	{
		printf("stack is empty\n");
		return;
	}
	
	stk *del = *ptr; //del pointing to first node
	*ptr = (*ptr) -> next; //update head ptr
	printf("deleted number : %d\n",del->rollno);
	free(del); //delete del ptr
	del=0;
}

void display(stk *ptr)
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
