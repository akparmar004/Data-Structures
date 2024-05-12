#include<stdio.h>
#include<stdlib.h>
#define size 5
int TOP = -1;
void enqueue(int*);
void dequeue(int*);
void display(int*);

void main()
{
	int que[size],op;
	
	while(1)
	{
		printf("enter choice : \n");
		printf("1)enqueue 2)dequeue 3)display 4)clear screen 0)exit\n");
		scanf("%d",&op);
		
		switch(op)
		{
			case 1:enqueue(que); break;
			case 2:dequeue(que); break;
			case 3:display(que); break;
			case 4:system("clear"); break;
			case 0:exit(0);
			default:printf("invalid option\n");
		}	
	}
}

void enqueue(int *ptr)
{
	if(TOP >= size-1)
	{
		printf("Queue is overflow\n");
		return;
	}
	
	int num;
	TOP++;
	
	printf("enter number : ");
	scanf("%d",&num);
	ptr[TOP]=num;
}

void dequeue(int *ptr)
{
	if(TOP <= -1)
	{
		printf("Queue is empty\n");
		return;
	}
	int num,i;
	num=ptr[0];
	printf("deleted number : %d\n",num);
	
	for(i=0;i<TOP;i++)
	{
		ptr[i]=ptr[i+1];
	}
	TOP--;
}

void display(int *ptr)
{
	if(TOP <= -1)
	{
		printf("Queue is empty\n");
		return;
	}
	int i;
	for(i=0;i<=TOP;i++)
		printf("%d ",ptr[i]);
		
	printf("\n");
}
