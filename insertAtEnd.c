#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
} node;

void insert(node **head, int data)
{
	node *ptr, *temp;
	ptr = malloc(sizeof(node));
	ptr -> data = data;
	ptr -> next = 0;

	if(*head == 0)
	{
		*head = ptr;
	}
	else
	{
		temp = *head;
		while(temp -> next)
		{
			temp = temp -> next;
		}
		temp -> next = ptr;
	}
}

void print(node *ptr)
{
	if(ptr == 0)
	{	
		printf("empty!!\n");
		return;
	}
	while(ptr)
	{
		printf("%d\n",ptr -> data);
		ptr = ptr -> next;
	}
}

void main()
{
	node *head;
	int i = 0;
	while(i < 5)
	{
		insert(&head,i);
		i++;
	}

	print(head);
}
