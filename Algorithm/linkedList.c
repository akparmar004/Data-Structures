#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int val;
	struct node *next;
}node;

void makenode(node **ptr,int data)
{
	node *new = malloc(sizeof(node));
	new -> val = data;
	new -> next = *ptr;
	*ptr = new;
}

void print(node *ptr)
{
	if(ptr == NULL)
	{
		printf("there is nothing to print..\n");
		return;
	}
	while(ptr)
	{
		printf("%d\n",ptr -> val);
		ptr = ptr -> next;
	}
}

void addEnd(node **ptr, int data)
{
	node *new = malloc(sizeof(node)), *temp = *ptr;
	new -> val = data;
	new -> next = NULL;

	if(*ptr == NULL)
	{
		*ptr = new;
		return;
	}

	while(temp -> next != NULL)
	{
		temp = temp -> next;
	}
	temp -> next = new;
}

void delete(node **ptr,int index)
{
	node *cur = *ptr, *prev = NULL;
	int i = 0;
	while(i != index)
	{
		prev = cur;
		cur = cur -> next;
		i++;
	}
	prev -> next = cur -> next;
	free(cur);
	return;
}

void delete_all(node **ptr)
{
	if(*ptr == 0)
	{
		printf("there is nothing to be deleted..\n");
		return;
	}
	node *del; 
	while(*ptr)
	{
		del = *ptr;
		*ptr = (*ptr) -> next;
		free(del);
		del = 0;
	}
}

void main()
{
	node *head = NULL;
	for(int i = 0;i < 5;i++)
		addEnd(&head,i);
	
	print(head);
	printf("after delete node.\n");
	delete(&head,4);
	print(head);
	delete_all(&head);
	print(head);
}
