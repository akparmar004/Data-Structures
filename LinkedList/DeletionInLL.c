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

struct Node * DeleteAtFirst(struct Node * head)
{
	struct Node * ptr = head;
	head = head -> next;
	free(ptr);
	return head;	
}

struct Node * DeleteInBitween(struct Node * head,int index)
{
	struct Node * p = head;
	
	int i = 0;
	
	while(i != index - 1)
	{
		p = p -> next;
	}
	struct Node *q = p -> next;
	p -> next = q -> next;
	free(q);
	return head;	
}

struct Node * DeleteLast(struct Node * head)
{
	struct Node * p = head;
	struct Node * q = head->next;
	
	while(q->next != NULL)
	{
		p = p->next;
		q = q->next;
	}
	
	p->next = NULL;
	free(q);
	
	return head;
}

struct Node * DeleteNodeOnValue(struct Node * head,int value)
{
	struct Node * p = head;
	struct Node * q = head->next;
	
	while(q->data != value && q->next != NULL)
	{
		p = p->next;
		q = q->next;
	}
	
	if(q->data == value)
	{
		p->next=q->next;
		free(q);
	}
	
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
	printf("\n");
	//head = DeleteAtFirst(head);
	//head = DeleteInBitween(head,1);
	//head = DeleteLast(head);
	head = DeleteNodeOnValue(head,8);
	LLTra(head);
}
