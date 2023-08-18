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

struct Node * insertAtFirst(struct Node *p,int data)
{
	struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
	ptr -> next = p;
	ptr -> data = data;
	return ptr;
}

struct Node * insertAtLast(struct Node *head,int data)
{
	struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
	struct Node *p = head;
	ptr -> data = data;
	while(p->next != NULL)
	{
		p=p->next;
	}
	p -> next = ptr;
	ptr -> next = NULL; 
	return head;
}

struct Node * insertAfterNode(struct Node *head,struct Node *prevNode,int data)
{
	struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
	ptr -> data = data;
	
	if(prevNode -> next != NULL)
	{
		ptr->next = prevNode->next;
		prevNode -> next = ptr;
	}
	else
	{
		ptr->next = NULL;
		prevNode -> next = ptr;
	}
	return head;
}

struct Node * insertAtBitween(struct Node *head,int data,int index)
{
	struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
	struct Node * p = head;
	
	int i = 0;
	
	while(i != index-1)
	{
		p = p -> next;
		i++;
	} 
	
	ptr -> data = data;
	ptr -> next = p -> next;
	p -> next = ptr;
	return head;
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
	//printf("\n");
	//head = insertAtFirst(head,6);
	//head = insertAtLast(head,10);
	head = insertAfterNode(head,third,20);
	//head = insertAtBitween(head,7,1);
	printf("\n");
	LLTra(head);
}
