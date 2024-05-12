#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
} node;

void main()
{
	node *first,*second,*third;
	
	first = (node *)malloc(sizeof(node));
	second = (node *)malloc(sizeof(node));
	third = (node *)malloc(sizeof(node));
	
	first -> data = 10;
	first -> next = second;
	
	second -> data = 20;
	second -> next = third;
	
	third -> data = 30;
	third -> next = NULL;
	
	int i = 0;
	node *p = first; 
	while(p -> data != 30)
	{
		p = p -> next;
		i++;
	}
	
	printf("target present at index : %d\n",i);
}
