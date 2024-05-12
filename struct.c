#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};

void  main()
{
	struct node *head, *ptr;
	head = NULL;

	int i = 0;
	while(i < 5)
	{
		ptr = (struct node *)malloc(sizeof(struct node));
		ptr -> data = i;
		ptr -> next = head;
		head = ptr;
		i++;
	}
	ptr = head;
	while(ptr)
	{
		printf("%d\n",ptr->data);
		ptr = ptr -> next;
	}
}
