#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node * next;
};

void LLTra(struct Node* ptr)
{
	while(ptr != NULL)
	{
		printf("%d ",ptr -> data);
		ptr = ptr -> next;
	} 
}
void main()
{
	struct Node * head,* second,* third;
	//struct Node * second;
	//struct Node * third;
	
	
	//allocates memory for nodes in linked list heap 
	head = (struct Node *)malloc(sizeof(struct Node));
	second = (struct Node *)malloc(sizeof(struct Node));
	third = (struct Node *)malloc(sizeof(struct Node));
	
	head -> data = 7;
	head -> next = second;
	
	second -> data = 8;
	second -> next = third;
	
	third -> data = 9;
	third -> next = NULL;
	
	LLTra(head);	
}
