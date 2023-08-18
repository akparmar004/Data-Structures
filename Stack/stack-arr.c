#include<stdio.h>
#include<stdlib.h>
void push(int*);
void pop(int*);
void display(int*);
#define size 5

int TOP = -1;

void main()
{
	int stk[size],op;
	while(1)
	{
		printf("enter choice : \n");
		printf("1)push 2)pop 3)display 4)clear screen 0)exit\n");
		scanf("%d",&op);
		
		switch(op)
		{
			case 1:push(stk); break;
			case 2:pop(stk); break;
			case 3:display(stk); break;
			case 4:system("clear"); break;
			case 0:exit(0); 
			default:printf("invalid option\n");
		}
	}
}

void push(int *ptr)
{
	if(TOP >= size-1)
	{
		printf("stack is overflow\n");
		return;
	}
	int num;
	TOP++;
	
	printf("enter number to push : ");
	scanf("%d",&num);
	
	ptr[TOP] = num;
}

void pop(int *ptr)
{
	if(TOP <= -1)
	{
		printf("stack is empty\n");
		return;
	}
	int num;
	num = ptr[TOP];
	TOP--;
	printf("poped num : %d\n",num);
}

void display(int *ptr)
{
	int i;
	if(TOP <= -1)
	{
		printf("stack is empty\n");
		return;
	}
	for(i=0;i<=TOP;i++)
	{
		printf("%d ",ptr[i]);
	}
	printf("\n");
}
