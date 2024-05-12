#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
} node;

void makenodes(node **ptr, int data)
{
	node *new, *temp;
	new = malloc(sizeof(node));
	new -> data = data;
	new -> next = 0;

	if(*ptr == 0)
		*ptr = new;
	else
	{
		temp = *ptr;
		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}
		temp -> next = new;
	}
}

void search(node *ptr, int data)
{
	int i = 0;
	while(ptr)
	{
		if(ptr->data == data)
		{	
			printf("data at index %d\n",i);
			return;
		}
		i++;
		ptr = ptr -> next;
	}
	printf("data not found!!\n");
}

void main()
{
	node *head;
	int i = 0;
	while(i < 5)
	{
		makenodes(&head,i);
		i++;
	}
	int n;
	printf("enter number to be found :");
	scanf("%d",&n);
	search(head, n);
}	
